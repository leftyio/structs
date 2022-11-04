#include "structs/cassandra/renderers/java_helpers.h"

#include <set>

#include "absl/strings/str_format.h"
#include "absl/strings/str_join.h"
#include "google/protobuf/compiler/java/names.h"
#include "structs/base/code_builder.h"
#include "structs/base/utils.h"
#include "structs/cassandra/field_gen.h"

namespace structs {
namespace {
void MutablePathToFieldMinusOne(const FieldGen& field, CodeBuilder& cb) {
  const auto& path = field.path();

  if (path.size() == 1) {
    return;
  }

  for (int i = 0; i < path.size() - 1; ++i) {
    std::string field_name = UnderscoresToCamelCase(path[i], true);
    cb << "get" << field_name << "Builder()";
    cb << ".";
  }
}

void SetSpecialMessageFromJavaStmt(const FieldGen& field,
                                   const std::string& value_name,
                                   CodeBuilder& cb,
                                   bool is_for_spark) {
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

  auto it =
      simple_primitives.find(field.proto_field()->message_type()->full_name());
  if (it != simple_primitives.end()) {
    MutablePathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

    if (field.proto_field()->message_type()->full_name() !=
        "google.protobuf.BytesValue") {
      cb << "get" << field_name << "Builder()"
         << ".setValue(" << value_name << ")";
    } else {
      cb << "get" << field_name << "Builder()"
         << ".setValue(com.google.protobuf.ByteString.copyFrom(" << value_name
         << "))";
    }

    return;
  }

  // case of a timestamp.
  MutablePathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

  if (!is_for_spark) {
    cb << "set" << field_name
       << "(com.google.protobuf.util.Timestamps.fromMillis(" << value_name
       << ".toEpochMilli())"
       << ")";
  } else {
    cb << "set" << field_name
       << "(com.google.protobuf.util.Timestamps.fromMillis(" << value_name
       << ".getTime())"
       << ")";
  }
}

void SetEnumFromJavaStmt(const FieldGen& field, const std::string& value_name,
                         CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);

  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  // std::string enum_java_name =
  // google::protobuf::compiler::java::ClassName(field.proto_field()->enum_type());

  cb << "set" << field_name << "Value(" << value_name << ")";
}

void SetPrimitiveFromJavaStmt(const FieldGen& field,
                              const std::string& value_name, CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);

  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

  if (field.proto_field()->type() != FieldDescriptor::Type::TYPE_BYTES) {
    cb << "set" << field_name << "(" << value_name << ")";
  } else {
    cb << "set" << field_name << "(com.google.protobuf.ByteString.copyFrom("
       << value_name << "))";
  }
}

void SetMessageFromJavaStmt(const FieldGen& field,
                            const std::string& value_name, CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  LOG(INFO) << field.PathAsString();
  cb << "get" << field_name << "Builder()"
     << ".mergeFrom(com.google.protobuf.ByteString.copyFrom(" << value_name
     << "))";
}

void PathToFieldMinusOne(const FieldGen& field, CodeBuilder& cb) {
  const auto& path = field.path();

  if (path.size() == 1) {
    return;
  }

  for (int i = 0; i < path.size() - 1; ++i) {
    std::string field_name = UnderscoresToCamelCase(path[i], true);
    cb << "get" << field_name << "()";
    cb << ".";
  }
}

bool IsPurePrimitive(const FieldGen& field) {
  return field.proto_field()->type() != FieldDescriptor::Type::TYPE_MESSAGE &&
         field.proto_field()->type() != FieldDescriptor::Type::TYPE_ENUM;
}

bool IsEnum(const FieldGen& field) {
  return field.proto_field()->type() == FieldDescriptor::Type::TYPE_ENUM;
}

void GetPrimitiveFromJavaObj(const FieldGen& field, const std::string& obj_name,
                             const std::string& getted_name, CodeBuilder& cb) {
  cb << getted_name << " = " << obj_name << ".";

  PathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

  if (field.proto_field()->type() != FieldDescriptor::Type::TYPE_BYTES) {
    cb << "get" << field_name << "();";
  } else {
    cb << "get" << field_name << "().asReadOnlyByteBuffer();";
  }
}

void GetEnumFromJavaObj(const FieldGen& field, const std::string& obj_name,
                        const std::string& getted_name, CodeBuilder& cb) {
  static int val_number = 1;
  const string val_name = absl::StrFormat("val%d", val_number++);

  cb << "int " << val_name << " = " << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "get" << field_name << "Value();";

  cb.Newline() << getted_name << " = " << val_name << ";";
}

void GetSpecialMessageFromJavaObj(const FieldGen& field, const string& obj_name,
                                  const string& getted_name, CodeBuilder& cb) {
  string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "if (" << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  cb << "has" << field_name << "()) {";
  cb.Indent();

  if (field.proto_field()->message_type()->full_name() ==
      "google.protobuf.Timestamp") {
    cb << getted_name
       << " = "
          "java.time.Instant.ofEpochMilli(com.google.protobuf.util.Timestamps."
          "toMillis("
       << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "()));";
  } else if (field.proto_field()->message_type()->full_name() ==
             "google.protobuf.BytesValue") {
    cb << getted_name << " = " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "().getValue().asReadOnlyByteBuffer();";
  } else {
    cb << getted_name << " = " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "().getValue();";
  }

  cb.Outdent() << "}";
}

void GetRegularMessageFromJavaObj(const FieldGen& field, const string& obj_name,
                                  const string& getted_name, CodeBuilder& cb) {
  string field_name = UnderscoresToCamelCase(field.path().back(), true);

  cb << "if (" << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  cb << "has" << field_name << "()) {";
  cb.Indent();
  cb << getted_name << " = " << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  cb << "get" << field_name << "().toByteString().asReadOnlyByteBuffer();";
  cb.Outdent();
  cb << "}";
}

void GetMessageFromJavaObj(const FieldGen& field, const string& obj_name,
                           const string& getted_name, CodeBuilder& cb) {
  LOG(INFO) << field.PathAsString();

  if (field.IsSpecialMessage()) {
    GetSpecialMessageFromJavaObj(field, obj_name, getted_name, cb);
  } else {
    GetRegularMessageFromJavaObj(field, obj_name, getted_name, cb);
  }
}

void GetListFromJavaObj(const FieldGen& field, const string& obj_name,
                        const string& getted_name, CodeBuilder& cb) {
  if (IsPurePrimitive(field) || field.IsSpecialMessage()) {
    cb.Newline() << "{";
    cb.Indent() << "java.util.List<" << WrapperTypeOf(field.JavaBaseType())
                << "> list = new java.util.ArrayList<>();";
    cb.Newline() << "for (" << WrapperTypeOf(field.JavaBaseType())
                 << " x : " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "List()) {";
    cb.Indent() << "list.add(x);";

    cb.OutdentBracket();
    cb.Newline() << getted_name << " = list;";
    cb.OutdentBracket();
    return;
  }

  if (IsEnum(field)) {
    cb.Newline() << "{";
    cb.Indent() << "java.util.List<" << WrapperTypeOf(field.JavaBaseType())
                << "> list = new java.util.ArrayList<>();";
    cb.Newline() << "for (" << WrapperTypeOf(field.JavaBaseType())
                 << " x : " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "ValueList()) {";
    cb.Indent() << "list.add(x);";

    cb.OutdentBracket();
    cb.Newline() << getted_name << " = list;";
    cb.OutdentBracket();
    return;
  }

  string msg_java_name = google::protobuf::compiler::java::ClassName(
      field.proto_field()->message_type());

  cb.Newline() << "{";
  cb.Indent() << "java.util.List<" << field.JavaBaseType()
              << "> list = new java.util.ArrayList<>();";
  cb.Newline() << "for (" << msg_java_name << " x : " << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "get" << field_name << "List()) {";
  cb.Indent() << "list.add(x.toByteString().asReadOnlyByteBuffer());";

  cb.OutdentBracket();
  cb.Newline() << getted_name << " = list;";
  cb.OutdentBracket();
}

void SetEnumListFromJavaStmt(const FieldGen& field, const string& builder,
                             const string& value_name, CodeBuilder& cb) {
  string field_name = UnderscoresToCamelCase(field.path().back(), true);

  cb << "for (" << field.JavaBaseType() << " x : " << value_name << ") {";
  cb.Indent() << builder << ".";
  MutablePathToFieldMinusOne(field, cb);
  cb << "add" << field_name << "Value(x);";

  cb.OutdentBracket();
}
}  // namespace

void SetListFromJavaStmt(const FieldGen& field, const string& builder,
                         const string& value_name, CodeBuilder& cb) {
  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_ENUM) {
    SetEnumListFromJavaStmt(field, builder, value_name, cb);
    return;
  }

  string field_name = UnderscoresToCamelCase(field.path().back(), true);

  cb << "for (" << field.JavaBaseType() << " x : " << value_name << ") {";
  cb.Indent() << builder << ".";
  MutablePathToFieldMinusOne(field, cb);
  cb << "add" << field_name << "(";

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE) {
    string msg_java_name = google::protobuf::compiler::java::ClassName(
        field.proto_field()->message_type());
    cb << msg_java_name << ".parseFrom(x));";
  } else {
    cb << "x);";
  }

  cb.OutdentBracket();
}

// statement to set this field from a java value.
void SetFromJavaStmt(const FieldGen& field, const string& value_name,
                     CodeBuilder& cb, bool is_from_spark) {
  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE &&
      !field.IsSpecialMessage()) {
    SetMessageFromJavaStmt(field, value_name, cb);
    return;
  }

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE &&
      field.IsSpecialMessage()) {
    SetSpecialMessageFromJavaStmt(field, value_name, cb, is_from_spark);
    return;
  }

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_ENUM) {
    SetEnumFromJavaStmt(field, value_name, cb);
    return;
  }

  // case of a primitive.
  SetPrimitiveFromJavaStmt(field, value_name, cb);
}

void GetFromJavaObj(const FieldGen& field, const string& obj_name,
                    const string& getted_name, CodeBuilder& cb) {
  if (field.IsList()) {
    GetListFromJavaObj(field, obj_name, getted_name, cb);
    return;
  }

  if (IsPurePrimitive(field)) {
    GetPrimitiveFromJavaObj(field, obj_name, getted_name, cb);
  } else if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_ENUM) {
    GetEnumFromJavaObj(field, obj_name, getted_name, cb);
  } else {
    GetMessageFromJavaObj(field, obj_name, getted_name, cb);
  }
}

void GetterFromCassandraRow(const FieldGen& field, const string& row_name,
                            const string& idx_name, CodeBuilder& cb) {
  if (!field.IsList()) {
    std::map<string, string> type_to_getter;
    type_to_getter["java.time.Instant"] = "getInstant";
    type_to_getter["double"] = "getDouble";
    type_to_getter["float"] = "getFloat";
    type_to_getter["long"] = "getLong";
    type_to_getter["java.math.BigInteger"] = "getVarInt";
    type_to_getter["int"] = "getInt";
    type_to_getter["boolean"] = "getBoolean";
    type_to_getter["String"] = "getString";
    type_to_getter["java.nio.ByteBuffer"] = "getByteBuffer";

    auto it = type_to_getter.find(field.JavaType());
    CHECK(it != type_to_getter.end())
        << "unsupported type: " << field.JavaType();
    std::string getter = it->second;

    cb << row_name << "." << getter << "(" << idx_name << ");";
    return;
  }

  // case of a list.
  cb << row_name << ".get(" << idx_name << ", "
     << TokenName(field.JavaBaseType()) << ");";
}

std::string TokenName(const std::string& java_type) {
  std::map<std::string, std::string> type_to_token_name;
  type_to_token_name["java.time.Instant"] = "listOfTimestamps";
  type_to_token_name["double"] = "listOfDoubles";
  type_to_token_name["float"] = "listOfFloats";
  type_to_token_name["long"] = "listOfLongs";
  type_to_token_name["java.math.BigInteger"] = "listOfBigIntegers";
  type_to_token_name["int"] = "listOfInts";
  type_to_token_name["boolean"] = "listOfBools";
  type_to_token_name["String"] = "listOfStrings";
  type_to_token_name["java.nio.ByteBuffer"] = "listOfBlobs";

  auto it = type_to_token_name.find(java_type);
  CHECK(it != type_to_token_name.end()) << java_type;
  return it->second;
}

std::string WrapperTypeOf(const std::string& java_type) {
  LOG(INFO) << "CHECKING: " << java_type;

  std::map<std::string, std::string> type_to_token_name;
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
}  // namespace structs
