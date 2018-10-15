#include <stdlib.h>
#include <map>
#include <string>

#include "absl/strings/match.h"
#include "glog/logging.h"
#include "google/protobuf/text_format.h"
#include "gtest/gtest.h"

#include "structs/base/utils.h"
#include "structs/cassandra/cassandra_internal.pb.h"

using google::protobuf::TextFormat;
using structs::CassandraInternalField;
using structs::CassandraInternalMessage;
using structs::CassandraInternalMessages;

class CassandraTest : public testing::Test {
 protected:
  CassandraInternalMessages GenerateMessagesOrDie(const std::string& proto_file,
                                                  const std::string& schema_file) {
    std::string bazel_base = "bazel-bin/structs/cassandra/protoc-gen-structs-cassandra_test.runfiles/__main__/";
    std::string protoc = bazel_base + "external/com_google_protobuf/protoc";
    std::string plugin = bazel_base + "structs/cassandra/protoc-gen-structs-cassandra";
    std::string schema = bazel_base + schema_file;
    std::string out = "--structs-cassandra_out=\"schema=" + schema + ":testdir/generated\"";
    std::string proto_path = bazel_base + "structs/cassandra/testdata";
    std::string input = proto_file;

    std::string cmd = "GLOG_logtostderr=1 " + protoc
        + " --proto_path=/usr/local/include:" + proto_path
        + " --plugin=" + plugin + " " + out + " " + input;
    CHECK(system(cmd.c_str()) == 0);

    std::string out_file = "testdir/generated/data/generated/cassandra_messages.out.pbtext";
    std::string out_content = structs::ReadFile(out_file);
    CassandraInternalMessages out_msgs;
    CHECK(TextFormat::ParseFromString(out_content, &out_msgs));
    LOG(INFO) << "Checking the generated message: " << out_msgs.DebugString();
    
    return out_msgs;
  }
};

CassandraInternalField FindFieldByName(const CassandraInternalMessage& msg, const std::string& name) {
  for (const auto& field : msg.fields()) {
    if (field.name() == name) {
      return field;
    }
  }

  LOG(FATAL) << "Field not found: " << name;
  return CassandraInternalField();  // unreachable
}

// Tests factorial of positive numbers.
TEST_F(CassandraTest, TestBasicTableNames) {
  const CassandraInternalMessages out_msgs = GenerateMessagesOrDie(
      "structs/testdata/base_structs_test.proto",
      "structs/cassandra/testdata/structs/testdata/base_structs_test.cassandra.pbtext");

  ASSERT_EQ(3, out_msgs.messages_size());
  ASSERT_EQ("structs_testdata_StructTest1", out_msgs.messages(0).table_name());
  ASSERT_EQ("name_of_struct2", out_msgs.messages(1).table_name());
  ASSERT_EQ("name_of_struct3", out_msgs.messages(2).table_name());

  ASSERT_EQ("structs.testdata", out_msgs.messages(0).pkg());
  
  // Packages.
  ASSERT_EQ("structs.testdata", out_msgs.messages(0).java_package());
  ASSERT_EQ("io.structs.testdata", out_msgs.messages(1).java_package());
}

TEST_F(CassandraTest, TestFields) {
  const CassandraInternalMessages out_msgs = GenerateMessagesOrDie(
      "structs/testdata/fields_structs_test.proto",
      "structs/cassandra/testdata/structs/testdata/fields_structs_test.cassandra.pbtext");

  ASSERT_EQ(3, out_msgs.messages_size());
  CassandraInternalMessage msg = out_msgs.messages(0);
  // ASSERT_EQ(7, msg.fields_size());

  for (const auto& field : msg.fields()) {
    ASSERT_FALSE(absl::StrContains(field.name(), "transient"));
  }

  ASSERT_EQ("id", msg.fields(0).name());
  ASSERT_EQ("inner_inner_field", msg.fields(1).name());
  ASSERT_EQ("inner_inside_inner_field", msg.fields(2).name());

  // Map of a field name to its expected cassandra type.
  std::map<std::string, std::string> field_to_types;
  field_to_types["field_float"] = "float";
  field_to_types["field_double"] = "double";
  field_to_types["field_int32"] = "int";
  field_to_types["field_int64"] = "bigint";
  field_to_types["field_uint32"] = "bigint";
  field_to_types["field_uint64"] = "varint";
  field_to_types["field_sint32"] = "int";
  field_to_types["field_sint64"] = "bigint";
  field_to_types["field_fixed32"] = "bigint";
  field_to_types["field_fixed64"] = "varint";
  field_to_types["field_sfixed32"] = "int";
  field_to_types["field_sfixed64"] = "bigint";
  field_to_types["field_bool"] = "boolean";
  field_to_types["field_string"] = "text";
  field_to_types["field_bytes"] = "blob";    

  // Enums
  field_to_types["field_enum"] = "int";
  
  // Special messages
  field_to_types["field_timestamp"] = "timestamp";
  field_to_types["field_double_value"] = "double";
  field_to_types["field_float_value"] = "float";
  field_to_types["field_int64_value"] = "bigint";
  field_to_types["field_uint64_value"] = "varint";
  field_to_types["field_int32_value"] = "int";
  field_to_types["field_uint32_value"] = "bigint";
  field_to_types["field_bool_value"] = "boolean";
  field_to_types["field_string_value"] = "text";
  field_to_types["field_bytes_value"] = "blob";

  // marked as bytes
  field_to_types["field_inner_as_bytes"] = "blob";
  
  // repeated fields
  field_to_types["field_double_list"] = "list<double>";
  field_to_types["field_float_list"] = "list<float>";
  field_to_types["field_int32_list"] = "list<int>";
  field_to_types["field_int64_list"] = "list<bigint>";
  field_to_types["field_uint32_list"] = "list<bigint>";
  field_to_types["field_uint64_list"] = "list<varint>";
  field_to_types["field_sint32_list"] = "list<int>";
  field_to_types["field_sint64_list"] = "list<bigint>";
  field_to_types["field_fixed32_list"] = "list<bigint>";
  field_to_types["field_fixed64_list"] = "list<varint>";
  field_to_types["field_sfixed32_list"] = "list<int>";
  field_to_types["field_sfixed64_list"] = "list<bigint>";
  field_to_types["field_bool_list"] = "list<boolean>";
  field_to_types["field_string_list"] = "list<text>";
  field_to_types["field_bytes_list"] = "list<blob>";
  


  for (const auto& it : field_to_types) {
    const auto& field = FindFieldByName(msg, it.first);
    ASSERT_EQ(it.second, field.cassandra_type());
  }
}

TEST_F(CassandraTest, TestIds) {
  const CassandraInternalMessages out_msgs = GenerateMessagesOrDie(
    "structs/testdata/fields_structs_test.proto",
    "structs/cassandra/testdata/structs/testdata/fields_structs_test.cassandra.pbtext");

  ASSERT_EQ(3, out_msgs.messages_size());
  CassandraInternalMessage msg = out_msgs.messages(1);
  std::vector<std::string> ids(msg.ids().begin(), msg.ids().end());
  ASSERT_EQ(std::vector<std::string>({"field_1", "field_4"}), ids);

  msg = out_msgs.messages(2);
  ids = std::vector<std::string>(msg.ids().begin(), msg.ids().end());
  ASSERT_EQ(std::vector<std::string>({"id"}), ids);
}
