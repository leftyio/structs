#pragma once

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "google/protobuf/descriptor.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/compiler/plugin.pb.h"

namespace structs {
using google::protobuf::Descriptor;
using google::protobuf::DescriptorPool;
using google::protobuf::FileDescriptor;
using google::protobuf::FileDescriptorProto;  
using google::protobuf::compiler::CodeGeneratorRequest;
using google::protobuf::compiler::CodeGeneratorResponse;

class BasePlugin {
 public:
  BasePlugin();
  virtual ~BasePlugin();

  int Run();
  virtual int DoRun() = 0;
  
 protected:
  const CodeGeneratorRequest* req() const { return req_.get(); }
  CodeGeneratorResponse* resp() const { return resp_.get(); }

  std::vector<const FileDescriptor*> FilesToGenerate();
  
 private:
  void Init();
  bool IsToGenerate(const FileDescriptorProto& file);
  
  std::unique_ptr<CodeGeneratorRequest> req_{new CodeGeneratorRequest()};
  std::unique_ptr<CodeGeneratorResponse> resp_{new CodeGeneratorResponse()};

  std::set<std::string> files_to_generate_;
  DescriptorPool pool_;
};
}  // structs
