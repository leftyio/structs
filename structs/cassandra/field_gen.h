#pragma once

#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "google/protobuf/descriptor.h"

#include "structs/base/code_builder.h"
#include "structs/cassandra/cassandra.pb.h"
#include "structs/sugar/sugar.h"

namespace structs {
using google::protobuf::Descriptor;    
using google::protobuf::FieldDescriptor;

class FieldGen {
 public:
  FieldGen(const CassandraSchema& schema,
           vector<string> path,
           const FieldDescriptor* proto_field);
  ~FieldGen();

  bool IsTransient();
  bool WillRecurse();
  bool IsId() const;
  int IdCardinality() const;
  bool IsList() const;
  bool IsSpecialMessage() const;

  const Descriptor* MessageType() const;
  
  const vector<string>& path() const { return path_; }

  string PathAsString() const { return absl::StrJoin(path_, "."); }

  const FieldDescriptor* proto_field() const { return proto_field_; }

  string CassandraName() const;
  string JavaName() const;
  // Java type as it would come from as cassandra row.
  string JavaType() const;
  string JavaBaseType() const;

  string CassandraType() const;
  string NonRepeatedCassandraType() const;

 private:
  vector<string> path_;
  // not owned
  const CassandraField* field_schema_{nullptr};
  // not owned
  const FieldDescriptor* proto_field_{nullptr};
};
}  // structs
