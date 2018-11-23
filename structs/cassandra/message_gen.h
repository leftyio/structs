#pragma once

#include <string>
#include <vector>

#include "google/protobuf/descriptor.h"

#include "structs/cassandra/cassandra.pb.h"
#include "structs/cassandra/field_gen.h"

namespace structs {
using google::protobuf::Descriptor;

class MessageGen {
 public:
  MessageGen(const CassandraSchema* schema,
             const Descriptor* descriptor);
  ~MessageGen();

  void AddField(const FieldGen& field);

  // Getters for the renderers.
  std::string CompressionStrategy() const;
  std::string CompactionStrategy() const;
  std::string TableName() const;
  std::string Pkg() const;
  std::string JavaClass() const;
  std::string JavaClassOfMessage() const;
  std::string JavaPkg() const;

  std::vector<const FieldGen*> Fields() const;
  std::vector<std::string> Ids() const;

 private:
  // Id fields, ordered by cardinality.
  std::vector<const FieldGen*> IdFields() const;
  // Finds the field named 'id', or returns null.
  const FieldGen* FieldNamedId() const;

  const CassandraSchema* schema_;
  const Descriptor* descriptor_;
  std::vector<FieldGen> fields_;
};
}  // namespace structs
