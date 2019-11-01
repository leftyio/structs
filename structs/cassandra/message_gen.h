#pragma once

#include <string>
#include <vector>

#include "google/protobuf/descriptor.h"

#include "structs/cassandra/cassandra.pb.h"
#include "structs/cassandra/field_gen.h"
#include "structs/sugar/sugar.h"

namespace structs {
using google::protobuf::Descriptor;

class MessageGen {
 public:
  MessageGen(const CassandraSchema* schema,
             const Descriptor* descriptor);
  ~MessageGen();

  void AddField(const FieldGen& field);

  // Getters for the renderers.
  string CompressionStrategy() const;
  string CompactionStrategy() const;
  string TableName() const;
  string Pkg() const;
  string JavaClass() const;
  string JavaClassOfMessage() const;
  string JavaPkg() const;

  vector<const FieldGen*> Fields() const;
  vector<const FieldGen*> IdFields() const;
  vector<string> Ids() const;

 private:
  // Id fields, ordered by cardinality.
  // Finds the field named 'id', or returns null.
  const FieldGen* FieldNamedId() const;

  const CassandraSchema* schema_;
  const Descriptor* descriptor_;
  vector<FieldGen> fields_;
};
}  // namespace structs
