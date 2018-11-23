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

enum class CassandraPluginRun {
  kTable,
  kJava,
  kSparkJava
};

class CassandraPlugin : public BasePlugin {
 public:
  explicit CassandraPlugin(CassandraPluginRun run);
  ~CassandraPlugin() override;

  int DoRun() override;

 private:
  void Generate(const Descriptor* msg, const CassandraSchema& s);
  // parse the parameter string. 
  void ParseSchema();
  void WriteFiles();
  void WriteCQLFile(const MessageGen& msg);
  void WriteJavaFile(const MessageGen& msg);
  void WriteSparkJavaFile(const MessageGen& msg);

  const CassandraPluginRun run_;

  std::map<std::string, CassandraSchema> schemas_;
  std::vector<MessageGen> msgs_;
};
}  // structs
