#include "structs/bigquery/bigquery_plugin.h"

#include <string>
#include <utility>
#include <vector>

#include "glog/logging.h"
#include "google/protobuf/text_format.h"

#include "structs/base/utils.h"
#include "structs/bigquery/bigquery.pb.h"

namespace structs {
using google::protobuf::TextFormat;

BigQueryPlugin::BigQueryPlugin() {
}

BigQueryPlugin::~BigQueryPlugin() {
}

bool BigQueryPlugin::Generate(const FileDescriptor* file,
                              const std::string& parameter,
                              GeneratorContext* ctx,
                              std::string* error) const {
  std::vector<std::pair<std::string, std::string>> params;
  google::protobuf::compiler::ParseGeneratorParameter(parameter, &params);

  const std::string* schema_file_name = nullptr;
  for (const auto& it : params) {
    if ("schema" == it.first) {
      schema_file_name = &it.second;
      break;
    }
  }

  CHECK(schema_file_name != nullptr) << "schema= option is missing";

  const std::map<std::string, BigQuerySchema> schemas = ParseSchema(*schema_file_name);
  for (int i = 0; i < file->message_type_count(); ++i) {
    const Descriptor* msg = file->message_type(i);

    auto it = schemas.find(msg->full_name());
    if (it == schemas.end()) {
      LOG(INFO) << "message name: " << msg->full_name() << " has no schema, skipping...";      
    } else {
      LOG(INFO) << "message name: " << msg->full_name() << " has a schema, generating...";      
    }
  }
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
