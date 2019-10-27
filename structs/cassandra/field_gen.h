#pragma once

#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "google/protobuf/descriptor.h"

#include "structs/base/code_builder.h"
#include "structs/cassandra/cassandra.pb.h"

namespace structs {
using google::protobuf::Descriptor;    
using google::protobuf::FieldDescriptor;

class FieldGen {
 public:
  FieldGen(const CassandraSchema& schema,
           std::vector<std::string> path,
           const FieldDescriptor* proto_field);
  ~FieldGen();

  bool IsTransient();
  bool WillRecurse();
  bool IsId() const;
  int IdCardinality() const;
  bool IsList() const;
  bool IsSpecialMessage() const;

  const Descriptor* MessageType() const;
  
  const std::vector<std::string>& path() const { return path_; }
  std::string PathAsString() const { return absl::StrJoin(path_, "."); }
  const FieldDescriptor* proto_field() const { return proto_field_; }

  std::string CassandraName() const;
  std::string JavaName() const;
  // Java type as it would come from as cassandra row.
  std::string JavaType() const;
  std::string JavaBaseType() const;

  std::string CassandraType() const;
  std::string NonRepeatedCassandraType() const;

 private:
  std::vector<std::string> path_;
  // not owned
  const CassandraField* field_schema_{nullptr};
  // not owned
  const FieldDescriptor* proto_field_{nullptr};
};
}  // structs
