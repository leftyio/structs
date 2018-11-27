#include "structs/cassandra/renderers/java_file.h"

#include "absl/strings/ascii.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "glog/logging.h"

#include "structs/base/code_builder.h"

namespace structs {
namespace {
void BindObject(const MessageGen& msg, CodeBuilder& cb) {
  cb.Newline() << "Object[] boundObjs = new Object[";

  const auto& fields = msg.Fields();
  std::string size_of_obj = absl::StrCat("", fields.size());
  cb << size_of_obj << "];";

  int i = 0;
  for (const FieldGen* field : fields) {
    cb.BreakLine() << "{";
    cb.Indent() << "Object o = null;";
    field->GetFromJavaObj("obj", "o", cb);

    std::string assigner = absl::StrCat("boundObjs[", i++, "]");
    cb.Newline() << assigner << " = o;";
    cb.Outdent() << "}";
  }
}

std::string PathToField(const FieldGen& field) {
  return absl::StrJoin(field.path(), "_");
}

std::string FieldEnumName(const FieldGen& field) {
  std::string path = absl::StrJoin(field.path(), "_");
  absl::AsciiStrToUpper(&path);
  return path;
}

void WriteFields(const MessageGen& msg, CodeBuilder& cb) {
  cb.Indent() << "public enum Fields {";

  const auto& fields = msg.Fields();

  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];

    std::string field_path = PathToField(*field);
    std::string field_enum_name = FieldEnumName(*field);

    if (i == 0) {
      cb.Indent();
    } else {
      cb.Newline();
    }

    cb << field_enum_name << "(\"" << field->CassandraName() << "\")";
    if (i != fields.size() - 1) {
      cb << ",";
    } else {
      cb << ";";
    }
  }

  cb.BreakLine() << "private String fieldName;"; 
  cb.BreakLine() << "Fields(String fieldName) {";
  cb.Indent() << "this.fieldName = fieldName;";
  cb.Outdent() << "}";

  cb.BreakLine() << "private static Iterable<Fields> all() {";
  cb.Indent() << "com.google.common.collect.ImmutableList.Builder<Fields> b = com.google.common.collect.ImmutableList.builder();";
  
  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];
    std::string field_enum_name = FieldEnumName(*field);
    
    cb.Newline() << "b.add(" << field_enum_name << ");";
  }

  cb.Newline() << "return b.build();";

  cb.Outdent() << "}";
  cb.Outdent() << "}";
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
  types["boolean"] = "getBool";
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
    cb.BreakLine() << "{";
    cb.Indent() << "int idx = " << row << ".getColumnDefinitions().getIndexOf(\""
        << field.CassandraName() << "\");";
    cb.Newline() << "if (!row.isNull(idx)) {";

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

void WhereClause(const MessageGen& msg, CodeBuilder& cb) {
  cb << " where ";

  const auto& fields = msg.IdFields();
  
  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];
    cb << field->CassandraName() << "=?";

    if (i != fields.size() - 1) {
      cb << " and ";
    }
  }
}

void LoadArguments(const MessageGen& msg, CodeBuilder& cb) {
  const auto& fields = msg.IdFields();
  
  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];
    cb << "String " << field->JavaName();

    if (i != fields.size() - 1) {
      cb << ", ";
    }
  }
}

void LoadArgumentsNoType(const MessageGen& msg, CodeBuilder& cb) {
  const auto& fields = msg.IdFields();
  
  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];
    cb << field->JavaName();

    if (i != fields.size() - 1) {
      cb << ", ";
    }
  }
}
}  // anonymous

std::string JavaContent(const MessageGen* msg) {
  CodeBuilder cb;

  cb << "package " << msg->JavaPkg() << ";";
  cb.BreakLine() << "import com.datastax.driver.core.BoundStatement;";
  cb.Newline() << "import com.datastax.driver.core.PreparedStatement;";
  cb.Newline() << "import com.datastax.driver.core.ResultSet;";
  cb.Newline() << "import com.datastax.driver.core.ResultSetFuture;";
  cb.Newline() << "import com.datastax.driver.core.Row;";
  cb.Newline() << "import com.datastax.driver.core.Session;";
  cb.BreakLine();

  cb << "public final class " << msg->JavaClass() << " {";
  WriteFields(*msg, cb);
  
  cb.BreakLine() << "private final Session session;";
  cb.Newline() << "private final com.google.common.base.Supplier<PreparedStatement> selectAllStmt;";
  cb.Newline() << "private final com.google.common.base.Supplier<PreparedStatement> insertAllStmt;";

  cb.BreakLine() << "public " << msg->JavaClass() << "(Session session) {";
  cb.Indent() << "this.session = session;";
  cb.Newline() << "this.selectAllStmt = com.google.common.base.Suppliers.memoize(() -> {";
  cb.Indent() << "return createSelectAllStmt(session);";
  cb.Outdent() << "});";
  cb.BreakLine() << "this.insertAllStmt = com.google.common.base.Suppliers.memoize(() -> {";
  cb.Indent() << "return createInsertAllStmt(session);";
  cb.Outdent() << "});";
  cb.Outdent() << "}";

  cb.BreakLine() << "private static PreparedStatement createSelectAllStmt(Session session) {";
  cb.Indent() << "Iterable<String> names = com.google.common.collect.Iterables.transform(Fields.all(), x -> x.fieldName);";
  cb.Newline() << "StringBuilder sb = new StringBuilder(\"select \");";
  cb.Newline() << "com.google.common.base.Joiner.on(',').appendTo(sb, names);";

  cb.Newline() << "sb.append(\" from " << msg->TableName();
  WhereClause(*msg, cb);
  cb << "\");";

  cb.Newline() << "return session.prepare(sb.toString());";
  cb.Outdent() << "}";

  std::string result_type = "java.util.Optional<" + msg->JavaClassOfMessage() + ">";
  cb.BreakLine() << "public " << result_type << " load(";
  LoadArguments(*msg, cb);
  cb << ") {";
  cb.Indent() << "PreparedStatement stmt = selectAllStmt.get();";
  cb.Newline() << "BoundStatement bound = stmt.bind(";
  LoadArgumentsNoType(*msg, cb);
  cb << ");";
  cb.Newline() << "ResultSet rs = session.execute(bound);";
  cb.Newline() << "Row row = rs.one();";
  cb.Newline() << "if (row == null) {";
  cb.Indent() << "return java.util.Optional.empty();";
  cb.Outdent() << "}";
  cb.BreakLine() << "return java.util.Optional.of(ofRow(row));";
  cb.Outdent() << "}";

  result_type = "com.google.common.util.concurrent.ListenableFuture<java.util.Optional<" + msg->JavaClassOfMessage() + ">>";
  cb.BreakLine() << "public " << result_type << " loadAsync(";
  LoadArguments(*msg, cb);
  cb << ") {";
  cb.Indent() << "PreparedStatement stmt = selectAllStmt.get();";
  cb.Newline() << "BoundStatement bound = stmt.bind(";
  LoadArgumentsNoType(*msg, cb);
  cb << ");";
  cb.Newline() << "ResultSetFuture rsF = session.executeAsync(bound);";
  cb.Newline() << "return com.google.common.util.concurrent.Futures.transform(rsF, rs -> {";
  cb.Indent() << "Row row = rs.one();";
  cb.Newline() << "if (row == null) {";
  cb.Indent() << "return java.util.Optional.empty();";
  cb.Outdent() << "}";
  cb.BreakLine() << "return java.util.Optional.of(ofRow(row));";
  cb.Outdent() << "});";
  cb.Outdent() << "}";

  cb.BreakLine() << "private static " << msg->JavaClassOfMessage() << " ofRow(Row row) {";
  cb.Indent() << msg->JavaClassOfMessage() << ".Builder b = " << msg->JavaClassOfMessage() << ".newBuilder();";
   
  for (const FieldGen* field : msg->Fields()) {
    SetFromCassandraRow(*field, "b", "row", cb);
  }

  cb.BreakLine();
  cb.Newline() << "return b.build();";
  cb.Outdent() << "}";

  cb.BreakLine() << "private static PreparedStatement createInsertAllStmt(Session session) {";
  cb.Indent() << "StringBuilder sb = new StringBuilder();";
  cb.Newline() << "sb.append(\"INSERT INTO " << msg->TableName() << " (\");";

  const auto& fields = msg->Fields();
  cb.Newline() << "sb.append(\"";
  for (int i = 0; i < fields.size(); ++i) {
    const FieldGen* field = fields[i];
    cb << field->CassandraName();

    if (i != fields.size() - 1) {
      cb << ", ";
    }
  }
  cb << ") \");";
  cb.Newline() << "sb.append(\"VALUES (";
  for (int i = 0; i < fields.size(); ++i) {
    cb << "?";

    if (i != fields.size() - 1) {
      cb << ", ";
    }
  }
  cb << ")\");";
  cb.BreakLine() << "return session.prepare(sb.toString());";

  cb.Outdent() << "}";

  cb.BreakLine() << "public void save(" << msg->JavaClassOfMessage() << " obj) {";
  cb.Indent() << "PreparedStatement stmt = insertAllStmt.get();";
  BindObject(*msg, cb);
  cb.BreakLine() << "BoundStatement bound = stmt.bind(boundObjs);";
  cb.Newline() << "session.execute(bound);";
  cb.Outdent() << "}";

  cb.BreakLine() << "public com.google.common.util.concurrent.ListenableFuture<Void> saveAsync(" << msg->JavaClassOfMessage() << " obj) {";
  cb.Indent() << "PreparedStatement stmt = insertAllStmt.get();";
  BindObject(*msg, cb);
  cb.BreakLine() << "BoundStatement bound = stmt.bind(boundObjs);";
  cb.Newline() << "ResultSetFuture rsF = session.executeAsync(bound);";
  cb.Newline() << "return com.google.common.util.concurrent.Futures.transform(rsF, x -> null);";
  cb.Outdent() << "}";

  cb.Outdent() << "}";
  cb.Newline();
  return cb.ToString();
}
}  // namespace structs
