#pragma once

#include <map>
#include <string>

#include "google/protobuf/compiler/code_generator.h"
#include "google/protobuf/descriptor.h"

#include "structs/bigquery/bigquery.pb.h"

namespace structs {
using google::protobuf::Descriptor;
using google::protobuf::FileDescriptor;
using google::protobuf::compiler::CodeGenerator;
using google::protobuf::compiler::GeneratorContext;

class BigQueryPlugin : public CodeGenerator {
 public:
  BigQueryPlugin();
  ~BigQueryPlugin() override;

  // implementation of CodeGenerator.
  bool Generate(const FileDescriptor* file,
                const std::string& parameter,
                GeneratorContext* ctx,
                std::string* error) const override;

 private:
  std::map<std::string, BigQuerySchema> ParseSchema(const std::string& file_name) const;
};
}  // structs
