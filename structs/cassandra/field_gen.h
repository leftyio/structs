#pragma once

#include <string>
#include <vector>

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
  const FieldDescriptor* proto_field() const { return proto_field_; }

  std::string CassandraName() const;
  std::string JavaName() const;
  std::string CassandraType() const;
  std::string NonRepeatedCassandraType() const;

 private:
  // Get from OBJ related methods.

  bool IsPurePrimitive() const;
  void GetPrimitiveFromJavaObj(const std::string& obj_name,
                               const std::string& getted_name,
                               CodeBuilder& cb) const;
  void GetEnumFromJavaObj(const std::string& obj_name,
                          const std::string& getted_name,
                          CodeBuilder& cb) const;

  void PathToFieldMinusOneNotBuilder(CodeBuilder& cb) const;

  std::vector<std::string> path_;
  // not owned
  const CassandraField* field_schema_{nullptr};
  // not owned
  const FieldDescriptor* proto_field_{nullptr};
};
}  // structs
