#include "structs/cassandra/renderers/java_file.h"

#include <sstream>
#include <string>

namespace structs {
namespace {
void Newline(std::ostringstream* out) {
  (*out) << "\n";
}
}  // anonymous namespace

std::string JavaContent(const MessageGen* msg) {
  std::ostringstream out;
  out << "package " << msg->JavaPkg() << ";\n";
  Newline(&out);
  out << "public final class " << msg->JavaClass() << " {\n";
  Newline(&out);
  out << "  private final Session session;\n";
  out << "  private final PreparedStatement insertStmt;\n";
  out << "  private final PreparedStatement loadStmt;\n";  
  Newline(&out);
  out << "  private " << msg->JavaClass() << "(Session session) {\n";
  out << "    this.session = session;\n";
  out << "  }\n";
  Newline(&out);
  out << "  public static " << msg->JavaClass() << " of(Session session) {\n";
  out << "    return new " << msg->JavaClass() << "(session);\n";
  out << "  }\n";
  Newline(&out);
  out << "  public void insert(" << msg->JavaClass() << " t) {\n";
  out << "  }\n";
  out << "}\n";
  return out.str();
}
}  // namespace structs
