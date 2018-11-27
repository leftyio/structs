#include "structs/cassandra/renderers/java_file.h"

#include "glog/logging.h"

#include "structs/base/code_builder.h"

namespace structs {
namespace {
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
}  // anonymous

std::string JavaContent(const MessageGen* msg) {
  CodeBuilder cb;

  cb << "package " << msg->JavaPkg() << ";";
  cb.BreakLine() << "import com.datastax.spark.PreparedStatement;";
  cb.BreakLine();

  cb << "public final class " << msg->JavaClass() << " {";
  cb.Newline();
  cb.Indent() <<  "public static " << msg->JavaClassOfMessage() << " of(ResultSet rs) throws com.google.protobuf.InvalidProtocolBufferException {";
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
