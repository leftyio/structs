#include "structs/cassandra/field_gen.h"

#include <set>
#include <string>

#include "absl/strings/str_join.h"
#include "glog/logging.h"
#include "google/protobuf/compiler/java/java_names.h"
#include "google/protobuf/descriptor.pb.h"
#include "structs/base/utils.h"

using google::protobuf::FieldDescriptorProto;
using google::protobuf::FieldDescriptorProto_Label_LABEL_REPEATED;
using google::protobuf::FieldDescriptorProto_Type_TYPE_MESSAGE;

namespace structs {
namespace {
const CassandraField* FindField(const CassandraSchema& schema,
                                const vector<string>& path) {
  const string exp_path = absl::StrJoin(path, ".");

  for (const auto& field : schema.fields()) {
    if (field.path() == exp_path) {
      return &field;
    }
  }

  return nullptr;
}

string SpecialMessageCassandraType(const FieldDescriptor* field) {
  std::map<string, string> types;
  types["google.protobuf.Timestamp"] = "timestamp";
  types["google.protobuf.DoubleValue"] = "double";
  types["google.protobuf.FloatValue"] = "float";
  types["google.protobuf.Int64Value"] = "bigint";
  types["google.protobuf.UInt64Value"] = "varint";
  types["google.protobuf.Int32Value"] = "int";
  types["google.protobuf.UInt32Value"] = "bigint";
  types["google.protobuf.BoolValue"] = "boolean";
  types["google.protobuf.StringValue"] = "text";
  types["google.protobuf.BytesValue"] = "blob";

  auto it = types.find(field->message_type()->full_name());
  CHECK(it != types.end()) << "not a special type: "
                           << field->message_type()->full_name();
  return it->second;
}
}  // namespace

FieldGen::FieldGen(const CassandraSchema& schema, vector<string> path,
                   const FieldDescriptor* proto_field)
    : proto_field_(proto_field) {
  path.push_back(proto_field->name());
  std::swap(path, path_);

  field_schema_ = FindField(schema, path_);
}

FieldGen::~FieldGen() {}

bool FieldGen::IsSpecialMessage() const {
  if (proto_field()->type() != FieldDescriptor::Type::TYPE_MESSAGE) {
    return false;
  }

  std::set<string> special_names{
      "google.protobuf.Timestamp",   "google.protobuf.DoubleValue",
      "google.protobuf.FloatValue",  "google.protobuf.Int64Value",
      "google.protobuf.UInt64Value", "google.protobuf.Int32Value",
      "google.protobuf.UInt32Value", "google.protobuf.BoolValue",
      "google.protobuf.StringValue", "google.protobuf.BytesValue"};

  return special_names.find(proto_field()->message_type()->full_name()) !=
         special_names.end();
}

bool FieldGen::IsTransient() {
  return field_schema_ != nullptr && field_schema_->is_transient();
}

bool FieldGen::IsId() const {
  return field_schema_ != nullptr && field_schema_->is_id();
}

int FieldGen::IdCardinality() const {
  return field_schema_ != nullptr ? field_schema_->id_cardinality() : 0;
}

bool FieldGen::IsList() const { return proto_field_->is_repeated(); }

bool FieldGen::WillRecurse() {
  if (proto_field_->type() != FieldDescriptor::Type::TYPE_MESSAGE) {
    return false;
  }

  if (IsSpecialMessage()) {
    return false;
  }

  // if we are saved as byte[] this means that we don't recurse into sub-fields.
  if (field_schema_ != nullptr && field_schema_->is_bytes()) {
    return false;
  }

  if (proto_field_->is_repeated()) {
    return false;
  }

  return true;
}

const Descriptor* FieldGen::MessageType() const {
  return proto_field_->message_type();
}

string FieldGen::CassandraName() const {
  if (field_schema_ != nullptr && !field_schema_->field_name().empty()) {
    return field_schema_->field_name();
  }

  return absl::StrJoin(path_, "_");
}

string FieldGen::JavaName() const {
  return UnderscoresToCamelCase(CassandraName(), false);
}

string FieldGen::JavaBaseType() const {
  std::map<string, string> types;
  types["timestamp"] = "java.time.Instant";
  types["double"] = "double";
  types["float"] = "float";
  types["bigint"] = "long";
  types["varint"] = "java.math.BigInteger";
  types["int"] = "int";
  types["boolean"] = "boolean";
  types["text"] = "String";
  types["blob"] = "java.nio.ByteBuffer";

  auto it = types.find(NonRepeatedCassandraType());
  CHECK(it != types.end()) << "unsupported type: "
                           << NonRepeatedCassandraType();
  return it->second;
}

namespace {
string WrapperTypeOf(const string& java_type) {
  LOG(INFO) << "CHECKING: " << java_type;

  std::map<string, string> type_to_token_name;
  type_to_token_name["double"] = "Double";
  type_to_token_name["float"] = "Float";
  type_to_token_name["long"] = "Long";
  type_to_token_name["int"] = "Integer";
  type_to_token_name["boolean"] = "Boolean";

  auto it = type_to_token_name.find(java_type);
  if (it == type_to_token_name.end()) {
    LOG(INFO) << "CHECKING: " << java_type << ", result not found";
    return java_type;
  }

  return it->second;
}
}  // namespace

string FieldGen::JavaType() const {
  if (!proto_field_->is_repeated()) {
    return JavaBaseType();
  }

  // case of a repeated.
  return absl::StrCat("java.util.List<", WrapperTypeOf(JavaBaseType()), ">");
}

string FieldGen::CassandraType() const {
  if (!proto_field_->is_repeated()) {
    return NonRepeatedCassandraType();
  }

  return "list<" + NonRepeatedCassandraType() + ">";
}

string FieldGen::NonRepeatedCassandraType() const {
  switch (proto_field_->type()) {
    case FieldDescriptor::Type::TYPE_FLOAT:
      return "float";
    case FieldDescriptor::Type::TYPE_DOUBLE:
      return "double";
    case FieldDescriptor::Type::TYPE_INT32:
      return "int";
    case FieldDescriptor::Type::TYPE_INT64:
      return "bigint";
    case FieldDescriptor::Type::TYPE_UINT32:
      return "bigint";
    case FieldDescriptor::Type::TYPE_UINT64:
      return "varint";
    case FieldDescriptor::Type::TYPE_SINT32:
      return "int";
    case FieldDescriptor::Type::TYPE_SINT64:
      return "bigint";
    case FieldDescriptor::Type::TYPE_FIXED32:
      return "bigint";
    case FieldDescriptor::Type::TYPE_FIXED64:
      return "varint";
    case FieldDescriptor::Type::TYPE_SFIXED32:
      return "int";
    case FieldDescriptor::Type::TYPE_SFIXED64:
      return "bigint";
    case FieldDescriptor::Type::TYPE_BOOL:
      return "boolean";
    case FieldDescriptor::Type::TYPE_STRING:
      return "text";
    case FieldDescriptor::Type::TYPE_BYTES:
      return "blob";

    case FieldDescriptor::Type::TYPE_ENUM:
      return "int";

    case FieldDescriptor::TYPE_MESSAGE:
      if (IsSpecialMessage()) {
        return SpecialMessageCassandraType(proto_field_);
      } else {
        // If it is not special and we're asking the type it means we didn't
        // recurse, so it must be of type bytes.
        return "blob";
      }
    default:
      LOG(FATAL) << "unhandled type: " << proto_field_->type();
  }
}
}  // namespace structs
