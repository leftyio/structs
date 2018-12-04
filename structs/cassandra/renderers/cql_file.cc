#include "structs/cassandra/renderers/cql_file.h"

#include <sstream>
#include <string>

#include "absl/strings/str_join.h"

namespace structs {
std::string CQLContent(const MessageGen* msg) {
  std::ostringstream out;
  out << "CREATE TABLE " << msg->TableName() << " (" << std::endl;

  for (const auto* field : msg->Fields()) {
    out << "  " << field->CassandraName() << " " << field->CassandraType() << "," << std::endl;
  }

  std::string ids = absl::StrJoin(msg->Ids(), ", ");
  out << "  PRIMARY KEY (" << ids << ")" << std::endl;
  out << ") WITH compression = { 'sstable_compression' : '" << msg->CompressionStrategy() << "' }" << std::endl;
  out << "  AND compaction = { 'class' : '" << msg->CompactionStrategy() << "' }" << std::endl;
  out << ";" << std::endl;

  return out.str();
}
}  // namespace structs
