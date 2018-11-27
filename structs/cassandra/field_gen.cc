#include "structs/cassandra/field_gen.h"

#include <set>
#include <string>

#include "absl/strings/str_join.h"
#include "glog/logging.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/compiler/java/java_names.h"

#include "structs/base/utils.h"

using google::protobuf::FieldDescriptorProto;
using google::protobuf::FieldDescriptorProto_Type_TYPE_MESSAGE;
using google::protobuf::FieldDescriptorProto_Label_LABEL_REPEATED;

namespace structs {
namespace {
const CassandraField* FindField(const CassandraSchema& schema,
                                const std::vector<std::string>& path) {
  const std::string exp_path = absl::StrJoin(path, ".");

  for (const auto& field : schema.fields()) {
    if (field.path() == exp_path) {
      return &field;
    }
  }

  return nullptr;
}

bool IsSpecialMessage(const FieldDescriptor* field) {
  std::set<std::string> special_names{
      "google.protobuf.Timestamp",
      "google.protobuf.DoubleValue",
      "google.protobuf.FloatValue",
      "google.protobuf.Int64Value",
      "google.protobuf.UInt64Value",
      "google.protobuf.Int32Value",
      "google.protobuf.UInt32Value",
      "google.protobuf.BoolValue",
      "google.protobuf.StringValue",
      "google.protobuf.BytesValue"
  };

  return special_names.find(field->message_type()->full_name()) != special_names.end();
}

std::string SpecialMessageCassandraType(const FieldDescriptor* field) {
  std::map<std::string, std::string> types;
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
  CHECK(it != types.end()) << "not a special type: " << field->message_type()->full_name();
  return it->second;
}
}  // namespace

FieldGen::FieldGen(const CassandraSchema& schema,
                   std::vector<std::string> path,
                   const FieldDescriptor* proto_field) : proto_field_(proto_field) {
  path.push_back(proto_field->name());
  std::swap(path, path_);

  field_schema_ = FindField(schema, path_);
}

FieldGen::~FieldGen() {
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

bool FieldGen::IsList() const {
  return proto_field_->type() != FieldDescriptor::Type::TYPE_MESSAGE && proto_field_->is_repeated();
}

bool FieldGen::WillRecurse() {
  if (proto_field_->type() != FieldDescriptor::Type::TYPE_MESSAGE) {
    return false;
  }

  if (IsSpecialMessage(proto_field_)) {
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

std::string FieldGen::CassandraName() const {
  if (field_schema_ != nullptr && !field_schema_->field_name().empty()) {
    return field_schema_->field_name();
  }

  return absl::StrJoin(path_, "_");
}

std::string FieldGen::JavaName() const {
  return UnderscoresToCamelCase(CassandraName(), false);
}

std::string FieldGen::CassandraType() const {
  if (!proto_field_->is_repeated()) {
    return NonRepeatedCassandraType();
  }
  
  return "list<" + NonRepeatedCassandraType() + ">";
}

std::string FieldGen::NonRepeatedCassandraType() const {
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
      if (IsSpecialMessage(proto_field_)) {
        return SpecialMessageCassandraType(proto_field_);
      } else {
        // If it is not special and we're asking the type it means we didn't recurse, so it
        // must be of type bytes.
        return "blob";
      }
    default:
      LOG(FATAL) << "unhandled type: " << proto_field_->type();
  }
}

void FieldGen::SetFromJavaStmt(const std::string& value_name, CodeBuilder& cb) const {
  if (proto_field_->type() == FieldDescriptor::Type::TYPE_MESSAGE && !IsSpecialMessage(proto_field_)) {
    SetMessageFromJavaStmt(value_name, cb);
    return;
  }

  if (proto_field_->type() == FieldDescriptor::Type::TYPE_MESSAGE && IsSpecialMessage(proto_field_)) {
    SetSpecialMessageFromJavaStmt(value_name, cb);
    return;
  }

  if (proto_field_->type() == FieldDescriptor::Type::TYPE_ENUM) {
    SetEnumFromJavaStmt(value_name, cb);
    return;
  }

  // case of a primitive.
  SetPrimitiveFromJavaStmt(value_name, cb);
}

void FieldGen::SetEnumFromJavaStmt(const std::string& value_name, CodeBuilder& cb) const {
  PathToFieldMinusOne(cb);
  
  std::string field = UnderscoresToCamelCase(path_.back(), true);
  std::string enum_java_name = google::protobuf::compiler::java::ClassName(proto_field_->enum_type());

  cb << "set" << field << "(" << enum_java_name << ".forNumber(" << value_name << "))";
}

void FieldGen::SetPrimitiveFromJavaStmt(const std::string& value_name, CodeBuilder& cb) const {
  PathToFieldMinusOne(cb);
  
  std::string field = UnderscoresToCamelCase(path_.back(), true);
  cb << "set" << field << "(" << value_name << ")"; 
}

void FieldGen::SetMessageFromJavaStmt(const std::string& value_name, CodeBuilder& cb) const {
  PathToFieldMinusOne(cb);
  std::string field = UnderscoresToCamelCase(path_.back(), true);

  cb << "get" << field << "Builder()" << ".mergeFrom(com.google.protobuf.ByteString.copyFrom("
     << value_name << "))";
}

void FieldGen::SetSpecialMessageFromJavaStmt(const std::string& value_name, CodeBuilder& cb) const {
  std::set<std::string> simple_primitives;
  simple_primitives.insert("google.protobuf.DoubleValue");
  simple_primitives.insert("google.protobuf.FloatValue");
  simple_primitives.insert("google.protobuf.Int64Value");
  simple_primitives.insert("google.protobuf.UInt64Value");
  simple_primitives.insert("google.protobuf.Int32Value");
  simple_primitives.insert("google.protobuf.UInt32Value");
  simple_primitives.insert("google.protobuf.BoolValue");
  simple_primitives.insert("google.protobuf.StringValue");
  simple_primitives.insert("google.protobuf.BytesValue");

  auto it = simple_primitives.find(proto_field_->message_type()->full_name());
  if (it != simple_primitives.end()) {
    PathToFieldMinusOne(cb);
    std::string field = UnderscoresToCamelCase(path_.back(), true);
    
    if (proto_field_->message_type()->full_name() != "google.protobuf.BytesValue") {
      cb << "get" << field << "Builder()" << ".setValue(" << value_name << ")";
    } else {
      cb << "get" << field << "Builder()" << ".setValue(com.google.protobuf.ByteString.copyFrom("
         << value_name << "))";
    }

    return;
  }

  // case of a timestamp.
  PathToFieldMinusOne(cb);
  std::string field = UnderscoresToCamelCase(path_.back(), true);
  
  cb << "set" << field << "(com.google.protobuf.util.Timestamps.fromMillis("
     << value_name << ".getTime())" << ")";
}

void FieldGen::PathToFieldMinusOne(CodeBuilder& cb) const {
  if (path_.size() == 1) {
    return;
  }

  for (int i = 0; i < path_.size() - 1; ++i) {
    std::string field = UnderscoresToCamelCase(path_[i], true);
    cb << "get" << field << "Builder()";
    cb << ".";
  }
}

bool FieldGen::IsPurePrimitive() const {
  return proto_field_->type() != FieldDescriptor::Type::TYPE_MESSAGE
      && proto_field_->type() != FieldDescriptor::Type::TYPE_ENUM;
}

void FieldGen::GetFromJavaObj(const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) const {
  if (IsPurePrimitive()) {
    GetPrimitiveFromJavaObj(obj_name, getted_name, cb);
  } else if (proto_field_->type() == FieldDescriptor::Type::TYPE_ENUM) {
    GetEnumFromJavaObj(obj_name, getted_name, cb);
  } else {
    LOG(FATAL) << "UNIMPLEMENTED YET";
  }
}

void FieldGen::GetPrimitiveFromJavaObj(const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) const {
  cb << getted_name << " = " << obj_name << ".";

  PathToFieldMinusOneNotBuilder(cb);
  std::string field = UnderscoresToCamelCase(path_.back(), true);
  cb << "get" << field << "();";
}

void FieldGen::GetEnumFromJavaObj(const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) const {
  std::string enum_java_name = google::protobuf::compiler::java::ClassName(proto_field_->enum_type());
  cb << enum_java_name << " val = " << obj_name << ".";
  PathToFieldMinusOneNotBuilder(cb);
  std::string field = UnderscoresToCamelCase(path_.back(), true);
  cb << "get" << field << "();";

  cb.Newline() << "if (val != " << enum_java_name << ".UNRECOGNIZED) {";
  cb.Indent() << getted_name << " = val.getNumber();";
  cb.Outdent() << "}";
}

void FieldGen::PathToFieldMinusOneNotBuilder(CodeBuilder& cb) const {
  if (path_.size() == 1) {
    return;
  }

  for (int i = 0; i < path_.size() - 1; ++i) {
    std::string field = UnderscoresToCamelCase(path_[i], true);
    cb << "get" << field << "()";
    cb << ".";
  }
}
}  // namespace structs
