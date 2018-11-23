#include "structs/cassandra/renderers/spark_java_file.h"

#include <string>

#include "absl/strings/str_join.h"
#include "glog/logging.h"

#include "structs/base/code_builder.h"

namespace structs {
namespace {
std::string PathToField(const FieldGen& field) {
  return absl::StrJoin(field.path(), "_");
}

std::string JavaTypeOfCassandra(const std::string cassandra_type) {
  std::map<std::string, std::string> types;
  types["timestamp"] = "java.util.Date";
  types["double"] = "double";
  types["float"] = "float";
  types["bigint"] = "long";
  types["varint"] = "java.math.BigInteger";
  types["int"] = "int";
  types["boolean"] = "boolean";
  types["text"] = "String";
  types["blob"] = "java.nio.ByteBuffer";

  auto it = types.find(cassandra_type);
  CHECK(it != types.end()) << "unsupported type: " << cassandra_type;
  return it->second;
}

std::string GetFromCassandraRow(const std::string cassandra_type) {
  std::map<std::string, std::string> types;
  types["timestamp"] = "getDate";
  types["double"] = "getDouble";
  types["float"] = "getFloat";
  types["bigint"] = "getLong";
  types["varint"] = "getVarInt";
  types["int"] = "getInt";
  types["boolean"] = "getBoolean";
  types["text"] = "getString";
  types["blob"] = "getBytes";

  auto it = types.find(cassandra_type);
  CHECK(it != types.end()) << "unsupported type: " << cassandra_type;
  return it->second;
}

void SetListFromCassandraRow(const FieldGen& field,
                             const std::string& builder,
                             const std::string& value,
                             CodeBuilder& cb) {
  // TODO(christian) implement this.
}

void SetFromValue(const FieldGen& field,
                  const std::string& builder,
                  const std::string& value,
                  CodeBuilder& cb) {
  cb << builder << ".";
  field.SetFromJavaStmt(value, cb);
  cb << ";";
}

void SetFromCassandraRow(const FieldGen& field,
                         const std::string& builder,
                         const std::string& row,
                         CodeBuilder& cb) {
  if (field.IsList()) {
    SetListFromCassandraRow(field, builder, row, cb);
  } else {
    cb.BreakLine().Newline() << "{";
    cb.Indent() << "int idx = " << row << ".indexOf(\""
        << PathToField(field) << "\");";
    cb.Newline() << "if (!row.isNullAt(idx)) {";

    cb.Indent() << JavaTypeOfCassandra(field.CassandraType())
        << " value = "
        << row
        << "."
        << GetFromCassandraRow(field.CassandraType())
        << "(idx);";

    cb.Newline();
    SetFromValue(field, "b", "value", cb);
    cb.Outdent() << "}";
    cb.Outdent() << "}";
  }
}
}  // anonymous namespace

std::string SparkJavaContent(const MessageGen* msg) {
  CodeBuilder cb;
  cb << "package " << msg->JavaPkg() << ";";
  cb.BreakLine() << "import com.datastax.spark.connector.japi.CassandraRow;";
  cb.BreakLine();

  cb << "public final class " << msg->JavaClass() << " {";
  cb.Newline();
  cb.Indent() <<  "public static " << msg->JavaClassOfMessage() << " of(CassandraRow row) throws com.google.protobuf.InvalidProtocolBufferException {";
  cb.Indent() << msg->JavaClassOfMessage() << ".Builder b = " << msg->JavaClassOfMessage() << ".newBuilder();";
   
  for (const FieldGen* field : msg->Fields()) {
    SetFromCassandraRow(*field, "b", "row", cb);
  }

  cb.BreakLine();
  cb.Newline() << "return b.build();";
  cb.Outdent() << "}";
  cb.Outdent() << "}";

  return cb.ToString();
}
}  // namespace structs
