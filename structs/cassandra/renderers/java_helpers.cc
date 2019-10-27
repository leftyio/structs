#include "structs/cassandra/renderers/java_helpers.h"

#include <set>

#include "google/protobuf/compiler/java/java_names.h"

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

void SetSpecialMessageFromJavaStmt(const FieldGen& field, const std::string& value_name, CodeBuilder& cb) {
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

  auto it = simple_primitives.find(field.proto_field()->message_type()->full_name());
  if (it != simple_primitives.end()) {
    MutablePathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
    
    if (field.proto_field()->message_type()->full_name() != "google.protobuf.BytesValue") {
      cb << "get" << field_name << "Builder()" << ".setValue(" << value_name << ")";
    } else {
      cb << "get" << field_name << "Builder()" << ".setValue(com.google.protobuf.ByteString.copyFrom("
         << value_name << "))";
    }

    return;
  }

  // case of a timestamp.
  MutablePathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  
  cb << "set" << field_name << "(com.google.protobuf.util.Timestamps.fromMillis("
     << value_name << ".getTime())" << ")";
}

void SetEnumFromJavaStmt(const FieldGen& field, const std::string& value_name, CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);
  
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  std::string enum_java_name = google::protobuf::compiler::java::ClassName(field.proto_field()->enum_type());

  cb << "set" << field_name << "(" << enum_java_name << ".forNumber(" << value_name << "))";
}

void SetPrimitiveFromJavaStmt(const FieldGen& field, const std::string& value_name, CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);
  
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "set" << field_name << "(" << value_name << ")"; 
}

void SetMessageFromJavaStmt(const FieldGen& field, const std::string& value_name, CodeBuilder& cb) {
  MutablePathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

  cb << "get" << field_name << "Builder()" << ".mergeFrom(com.google.protobuf.ByteString.copyFrom("
     << value_name << "))";
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
  return field.proto_field()->type() != FieldDescriptor::Type::TYPE_MESSAGE
      && field.proto_field()->type() != FieldDescriptor::Type::TYPE_ENUM;
}

void GetPrimitiveFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  cb << getted_name << " = " << obj_name << ".";

  PathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "get" << field_name << "();";
}

void GetEnumFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  std::string enum_java_name = google::protobuf::compiler::java::ClassName(field.proto_field()->enum_type());
  cb << enum_java_name << " val = " << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "get" << field_name << "();";

  cb.Newline() << "if (val != " << enum_java_name << ".UNRECOGNIZED) {";
  cb.Indent() << getted_name << " = val.getNumber();";
  cb.Outdent() << "}";
}

void GetSpecialMessageFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  if (field.proto_field()->message_type()->full_name() == "google.protobuf.Timestamp") {
    cb << getted_name << " = new java.util.Date(com.google.protobuf.util.Timestamps.toMillis(" << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "()));";
  } else if (field.proto_field()->message_type()->full_name() == "google.protobuf.BytesValue") {
    LOG(FATAL) << "UNIMPLEMENTED";
  } else {
    cb << getted_name << " = " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "().getValue();";
  }
}

void GetRegularMessageFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  LOG(FATAL) << "UNIMPLEMENTED: " << field.PathAsString();
}
      
void GetMessageFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  if (field.IsSpecialMessage()) {
    GetSpecialMessageFromJavaObj(field, obj_name, getted_name, cb);
  } else {
    GetRegularMessageFromJavaObj(field, obj_name, getted_name, cb);
  }
}

void GetListFromJavaObj(const FieldGen& field, const std::string& obj_name, const std::string& getted_name, CodeBuilder& cb) {
  if (IsPurePrimitive(field) || field.IsSpecialMessage()) {
    cb.Newline() << "{";
    cb.Indent() << "java.util.List<" << field.JavaBaseType() << "> list = new java.util.ArrayList<>();";
    cb.Newline() << "for (" << field.JavaBaseType() << " x : " << obj_name << ".";
    PathToFieldMinusOne(field, cb);
    std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
    cb << "get" << field_name << "List()) {";
    cb.Indent() << "list.add(x);";
  
    cb.OutdentBracket();
    cb.Newline() << getted_name << " = list;";
    cb.OutdentBracket();
    return;
  }
  
  std::string msg_java_name = google::protobuf::compiler::java::ClassName(field.proto_field()->message_type());

  cb.Newline() << "{";
  cb.Indent() << "java.util.List<" << field.JavaBaseType() << "> list = new java.util.ArrayList<>();";
  cb.Newline() << "for (" << msg_java_name << " x : " << obj_name << ".";
  PathToFieldMinusOne(field, cb);
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);
  cb << "get" << field_name << "List()) {";
  cb.Indent() << "list.add(x.toByteString().asReadOnlyByteBuffer());";
  
  cb.OutdentBracket();
  cb.Newline() << getted_name << " = list;";
  cb.OutdentBracket();
}
}  // namespace

void SetListFromJavaStmt(const FieldGen& field,
                         const std::string& builder,
                         const std::string& value_name,
                         CodeBuilder& cb) {
  std::string field_name = UnderscoresToCamelCase(field.path().back(), true);

  cb << "for (" << field.JavaBaseType() << " x : " << value_name << ") {";
  cb.Indent() << builder << ".";
  MutablePathToFieldMinusOne(field, cb);
  cb << "add" << field_name << "(";

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE) {
    std::string msg_java_name = google::protobuf::compiler::java::ClassName(field.proto_field()->message_type());
    cb << msg_java_name << ".parseFrom(x));";
  } else {
    cb << "x);";
  }

  cb.OutdentBracket();
}

// statement to set this field from a java value.
void SetFromJavaStmt(const FieldGen& field,
                     const std::string& value_name,
                     CodeBuilder& cb) {
  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE && !field.IsSpecialMessage()) {
    SetMessageFromJavaStmt(field, value_name, cb);
    return;
  }

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_MESSAGE && field.IsSpecialMessage()) {
    SetSpecialMessageFromJavaStmt(field, value_name, cb);
    return;
  }

  if (field.proto_field()->type() == FieldDescriptor::Type::TYPE_ENUM) {
    SetEnumFromJavaStmt(field, value_name, cb);
    return;
  }

  // case of a primitive.
  SetPrimitiveFromJavaStmt(field, value_name, cb);
}

void GetFromJavaObj(const FieldGen& field,
                    const std::string& obj_name,
                    const std::string& getted_name,
                    CodeBuilder& cb) {
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

void GetterFromCassandraRow(const FieldGen& field,
                            const std::string& row_name,
                            const std::string& idx_name,
                            CodeBuilder& cb) {
  if (!field.IsList()) {
    std::map<std::string, std::string> type_to_getter;
    type_to_getter["java.util.Date"] = "getTimestamp";
    type_to_getter["double"] = "getDouble";
    type_to_getter["float"] = "getFloat";
    type_to_getter["long"] = "getLong";
    type_to_getter["java.math.BigInteger"] = "getVarInt";
    type_to_getter["int"] = "getInt";
    type_to_getter["boolean"] = "getBool";
    type_to_getter["String"] = "getString";
    type_to_getter["java.nio.ByteBuffer"] = "getBytes";

    auto it = type_to_getter.find(field.JavaType());
    CHECK(it != type_to_getter.end()) << "unsupported type: " << field.JavaType();
    std::string getter = it->second;
  
    cb << row_name
        << "."
        << getter
        << "(" << idx_name << ");";
    return;
  }

  // case of a list.
  cb << row_name
     << ".getList("
     << idx_name
     << ", "
     << TokenName(field.JavaBaseType())
     << ");";
}

std::string TokenName(const std::string& java_type) {
  std::map<std::string, std::string> type_to_token_name;
  type_to_token_name["java.util.Date"] = "listOfTimestamps";
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
}  // namespace structs
