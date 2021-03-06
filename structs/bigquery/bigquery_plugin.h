#pragma once

#include <map>
#include <string>

#include "google/protobuf/compiler/code_generator.h"
#include "google/protobuf/descriptor.h"

#include "structs/base/base_plugin.h"
#include "structs/bigquery/bigquery.pb.h"

namespace structs {
using google::protobuf::Descriptor;
using google::protobuf::FileDescriptor;

class BigQueryPlugin : public BasePlugin {
 public:
  BigQueryPlugin();
  ~BigQueryPlugin() override;

  int DoRun() override;

 private:
  void Generate(const Descriptor* msg, const BigQuerySchema& s);

  std::map<std::string, BigQuerySchema> ParseSchema(const std::string& file_name) const;
};
}  // structs
