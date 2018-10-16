#include "structs/cassandra/cassandra_plugin.h"

#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "absl/algorithm/container.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_replace.h"
#include "glog/logging.h"
#include "google/protobuf/text_format.h"

#include "structs/base/utils.h"
#include "structs/cassandra/cassandra.pb.h"
#include "structs/cassandra/field_gen.h"
#include "structs/cassandra/message_gen.h"
#include "structs/cassandra/renderers/cql_file.h"
#include "structs/cassandra/renderers/java_file.h"

using google::protobuf::Descriptor;
using google::protobuf::FieldDescriptor;
using google::protobuf::FileDescriptor;
using google::protobuf::TextFormat;
using google::protobuf::compiler::CodeGeneratorRequest;
using google::protobuf::compiler::CodeGeneratorResponse;
using google::protobuf::compiler::CodeGeneratorResponse_File;

namespace structs {
namespace {
void VisitField(const CassandraSchema& schema,
                const FieldDescriptor* field,
                std::vector<std::string> path_so_far,
                MessageGen* msg) {
  FieldGen field_gen(schema, path_so_far, field);
  if (field_gen.IsTransient()) {
    LOG(INFO) << "ignoring field: , marked as transient.";
    return;
  }

  LOG(INFO) << "processing not transient field";
  if (field_gen.WillRecurse()) { 
    for (int i = 0; i < field_gen.MessageType()->field_count(); ++i) {
      const auto* subfield = field_gen.MessageType()->field(i);
      VisitField(schema, subfield, field_gen.path(), msg);
    }
  } else {
    msg->AddField(field_gen);
  }
}
}  // anonymous namespace

CassandraPlugin::CassandraPlugin() {
  ParseSchema();
}

CassandraPlugin::~CassandraPlugin() {
}

int CassandraPlugin::DoRun() {
  std::vector<const FileDescriptor*> to_gen = FilesToGenerate();

  for (const auto* file : to_gen) {
    LOG(INFO) << "generating for file: " << file->name();
    
    for (int i = 0; i < file->message_type_count(); ++i) {
      const Descriptor* msg = file->message_type(i);

      auto it = schemas_.find(msg->full_name());
      if (it == schemas_.end()) {
        LOG(INFO) << "message name: " << msg->full_name() << " has no schema, skipping...";      
      } else {
        LOG(INFO) << "message name: " << msg->full_name() << " has a schema, generating...";      
        Generate(msg, it->second);
      }
    }
  }

  WriteFiles();

  // success
  return 0;
}

void CassandraPlugin::WriteFiles() {
  for (const auto& msg : msgs_) {
    WriteCQLFile(msg);
    WriteJavaFile(msg);
  }
}

void CassandraPlugin::WriteCQLFile(const MessageGen& msg) {
  CodeGeneratorResponse_File* file = resp()->add_file();
  std::string pkg = msg.Pkg();
  absl::StrReplaceAll({{ ".", "/" }}, &pkg);
  file->set_name(pkg + "/table_" + msg.TableName() + ".cql");
  file->set_content(CQLContent(&msg));
}

void CassandraPlugin::WriteJavaFile(const MessageGen& msg) {
  CodeGeneratorResponse_File* file = resp()->add_file();
  std::string pkg = msg.JavaPkg();
  absl::StrReplaceAll({{ ".", "/" }}, &pkg);
  file->set_name(pkg + "/" + msg.JavaClass() + ".java");
  file->set_content(JavaContent(&msg));
}

void CassandraPlugin::Generate(const Descriptor* msg,
                               const CassandraSchema& schema) {
  msgs_.emplace_back(&schema, msg);
  MessageGen& to_gen = msgs_.back();

  std::vector<std::string> path;

  for (int i = 0; i < msg->field_count(); ++i) {
    const auto* field = msg->field(i);
    VisitField(schema, field, path, &to_gen);
  }
}

void CassandraPlugin::ParseSchema() {
  std::string param = req()->parameter();
  // schema=
  if (param.size() < 7) {
    LOG(FATAL) << "illegal option should contain at least one schema.";
  }

  std::string prefix = param.substr(0, 7);
  if (prefix != "schema=") {
    LOG(FATAL) << "illegal option should contain at least one schema.";    
  }

  std::string schema = param.substr(7);
  LOG(INFO) << "we will be using the following schema file: " << schema;

  std::string schema_content = ReadFile(schema);
  TextFormat::Parser p;
  CassandraSchemas schema_message;
  CHECK(p.ParseFromString(schema_content, &schema_message));
  LOG(INFO) << "we will be using the following schema: " << schema_message.DebugString();

  for (const auto& s : schema_message.schema()) {
    CHECK(!s.message_name().empty());
    auto it = schemas_.find(s.message_name());
    CHECK(it == schemas_.end()) << "duplicate message: " << s.message_name();
    schemas_[s.message_name()] = s;
  }
}
}  // structs
