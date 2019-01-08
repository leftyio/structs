#include "structs/bigquery/bigquery_plugin.h"

#include <string>
#include <utility>
#include <vector>

#include "glog/logging.h"
#include "google/protobuf/text_format.h"
#include "nlohmann/json.hpp"

#include "structs/base/utils.h"
#include "structs/bigquery/bigquery.pb.h"

namespace structs {
using google::protobuf::FieldDescriptor;
using google::protobuf::TextFormat;
using google::protobuf::compiler::CodeGeneratorResponse_File;

BigQueryPlugin::BigQueryPlugin() {
}

BigQueryPlugin::~BigQueryPlugin() {
}

int BigQueryPlugin::DoRun() {
  std::string param = req()->parameter();
  std::vector<std::pair<std::string, std::string>> params;
  google::protobuf::compiler::ParseGeneratorParameter(param, &params);

  const std::string* schema_file_name = nullptr;
  for (const auto& it : params) {
    if ("schema" == it.first) {
      schema_file_name = &it.second;
      break;
    }
  }

  CHECK(schema_file_name != nullptr) << "schema= option is missing";
  const std::map<std::string, BigQuerySchema> schemas = ParseSchema(*schema_file_name);

  std::vector<const FileDescriptor*> to_gen = FilesToGenerate();

  for (const auto* file : to_gen) {
    for (int i = 0; i < file->message_type_count(); ++i) {
      const Descriptor* msg = file->message_type(i);

      auto it = schemas.find(msg->full_name());
      if (it == schemas.end()) {
        LOG(INFO) << "message name: " << msg->full_name() << " has no schema, skipping...";      
      } else {
        LOG(INFO) << "message name: " << msg->full_name() << " has a schema, generating...";
        Generate(msg, it->second);  
      }
    }
  }

  return 0;
}

namespace {
std::string OutputLocation(const FileDescriptor* file, const std::string& opt_name) {
  std::string pkg = file->package();
  std::replace(pkg.begin(), pkg.end(), '.', '/');
  return pkg + "/" + opt_name + ".bigquery.json";
}

std::string FieldName(const FieldDescriptor* field) {
  // proto3 json defines that field names that are named lower underscore
  // shall be named lower camel case in json.

  std::ostringstream r;

  bool next_upper = false;
  for (char c : field->name()) {
    if (c == '_') {
      next_upper = true;
      continue;
    }

    if (!next_upper) { 
      r << c;
      continue;
    }

    next_upper = false;
    r << ((char) toupper(c));
  }

  return r.str();
}

std::string BigQueryMessageType(const FieldDescriptor* field) {
  CHECK(field->type() == FieldDescriptor::TYPE_MESSAGE);

  const Descriptor* desc = field->message_type();

  if (desc->full_name() == "google.protobuf.Timestamp") {
    return "TIMESTAMP";
  } else if (desc->full_name() == "google.protobuf.FloatValue") {
    return "FLOAT64";
  } else if (desc->full_name() == "google.protobuf.Int32Value") {
    return "INTEGER";
  } else if (desc->full_name() == "google.protobuf.BoolValue") {
    return "BOOLEAN";
  }

  // Note(christian) add more special types (those from duration.proto,
  // wrappers.proto) as we need them.

  return "RECORD";
}

std::string BigQueryType(const FieldDescriptor* field) {
  switch (field->type()) {
    case FieldDescriptor::TYPE_DOUBLE:
    case FieldDescriptor::TYPE_FLOAT:
      return "FLOAT";
    case FieldDescriptor::TYPE_INT32:
    case FieldDescriptor::TYPE_UINT32:
    case FieldDescriptor::TYPE_FIXED32:
    case FieldDescriptor::TYPE_SFIXED32:
    case FieldDescriptor::TYPE_SINT32:
      return "INTEGER";
    // Note(christian) the formal proto3 json spec is that int64 are
    // serialized as strings. However for bigquery it is better to have
    // them as int64 (since bigquery supports them) so we have our own
    // fork of proto's json format that will serialize int64 and their
    // variants to ints.
    case FieldDescriptor::TYPE_INT64:
    case FieldDescriptor::TYPE_SINT64:
    case FieldDescriptor::TYPE_SFIXED64:
    case FieldDescriptor::TYPE_FIXED64:
      return "INTEGER";
    case FieldDescriptor::TYPE_UINT64:
      // the considerations above do not hold for unsigned int64
      // since bigquery doesn't support them, so we keep them as string
      // (as of now we don't use those anyways).
      return "STRING";
    case FieldDescriptor::TYPE_BOOL:
      return "BOOLEAN";
    case FieldDescriptor::TYPE_STRING:
    case FieldDescriptor::TYPE_BYTES:
    case FieldDescriptor::TYPE_ENUM:
      return "STRING";
    case FieldDescriptor::TYPE_MESSAGE:
      return BigQueryMessageType(field);
    case FieldDescriptor::TYPE_GROUP:
      LOG(FATAL) << "group is not supported";
  }

  return "";
}

nlohmann::json ToJson(const Descriptor* desc) {
  // The top level schema is always a list of fields.
  nlohmann::json r = nlohmann::json::array();

  for (int i = 0; i < desc->field_count(); ++i) {
    const FieldDescriptor* field = desc->field(i);
    nlohmann::json v;
    v["mode"] = field->is_repeated() ? "REPEATED" : "NULLABLE";
    v["name"] = FieldName(field);
    const std::string bigquery_type = BigQueryType(field);
    v["type"] = bigquery_type;

    if (bigquery_type == "RECORD") {
      // recurse into the child's schema.
      v["fields"] = ToJson(field->message_type());
    }

    r[i] = v;
  }

  return r;
}

/*
std::string JsonToString(const Json::Value& json) {
  Json::StreamWriterBuilder builder;
  builder["commentStyle"] = "None";
  builder["indentation"] = "  ";
  std::unique_ptr<Json::StreamWriter> writer(
      builder.newStreamWriter());
  std::ostringstream os;
  writer->write(json, &os);
  return os.str();
} */
}  // anonymous namespace

void BigQueryPlugin::Generate(const Descriptor* msg, const BigQuerySchema& s) {
  CHECK(!s.bigquery_table_name().empty());

  nlohmann::json schema = ToJson(msg);

  std::string output_file = OutputLocation(msg->file(), s.bigquery_table_name());

  CodeGeneratorResponse_File* file = resp()->add_file();
  file->set_name(output_file);
  file->set_content(schema.dump(2));
  LOG(INFO) << "added file: " << output_file << " with content:\n" << schema.dump(2);
}

std::map<std::string, BigQuerySchema> BigQueryPlugin::ParseSchema(const std::string& file_name) const {
  LOG(INFO) << "we will be using the following schema file: " << file_name;

  std::string schema_content = ReadFile(file_name);
  TextFormat::Parser p;
  BigQuerySchemas schema_message;
  CHECK(p.ParseFromString(schema_content, &schema_message));
  LOG(INFO) << "we will be using the following schema: " << schema_message.DebugString();

  std::map<std::string, BigQuerySchema> parsed;
  for (const auto& s : schema_message.schema()) {
    const std::string& message_name = s.structs_schema().message_name();
    CHECK(!message_name.empty());
    auto it = parsed.find(message_name);
    CHECK(it == parsed.end()) << "duplicate message: " << message_name;
    parsed[message_name] = s;
  }

  return parsed;
}
}  // structs
