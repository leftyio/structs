#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "google/protobuf/descriptor.h"

#include "structs/base/base_plugin.h"
#include "structs/cassandra/cassandra.pb.h"
#include "structs/cassandra/message_gen.h"

namespace structs {
using google::protobuf::Descriptor;

class CassandraPlugin : public BasePlugin {
 public:
  CassandraPlugin();
  ~CassandraPlugin() override;

  int DoRun() override;

 private:
  void Generate(const Descriptor* msg, const CassandraSchema& s);
  // parse the parameter string. 
  void ParseSchema();
  void WriteCQLFiles();
  void WriteCQLFile(const MessageGen& msg);
  void WriteJavaFile(const MessageGen& msg);

  std::map<std::string, CassandraSchema> schemas_;
  std::vector<MessageGen> msgs_;
};
}  // structs
