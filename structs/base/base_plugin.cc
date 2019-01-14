#include "structs/base/base_plugin.h"

#include <unistd.h>
#include <map>
#include <memory>
#include <string>

#include "glog/logging.h"
#include "google/protobuf/compiler/code_generator.h"

namespace structs {
BasePlugin::BasePlugin() {
  CHECK(req_->ParseFromFileDescriptor(STDIN_FILENO));
}

BasePlugin::~BasePlugin() {
  CHECK(resp_->SerializeToFileDescriptor(STDOUT_FILENO));
  LOG(INFO) << "we're all done, bye bye!";
}

std::map<std::string, std::string> BasePlugin::ParseParams() {
  std::map<std::string, std::string> res;

  std::vector<std::pair<std::string, std::string>> params;
  google::protobuf::compiler::ParseGeneratorParameter(req()->parameter(), &params);

  for (const auto& it : params) {
    res[it.first] = it.second;
  }

  return res;
}

int BasePlugin::Run() {
  Init();

  const std::map<std::string, std::string> params = ParseParams();

  for (const auto* file : FilesToGenerate()) {
    GenerateFile(file);
  }

  // always a success since the plugins panic in case of error...
  return 0;
}

void BasePlugin::Init() {
  for (const auto& file : req()->proto_file()) {
    pool_.BuildFile(file);
  }

  for (const auto& name : req_->file_to_generate()) {
    files_to_generate_.insert(name);
  }
}

bool BasePlugin::IsToGenerate(const FileDescriptorProto& file) {
  return files_to_generate_.find(file.name()) != files_to_generate_.end();
}

std::vector<const FileDescriptor*> BasePlugin::FilesToGenerate() {
  std::vector<const FileDescriptor*> res;
  for (const auto& file : req()->proto_file()) {
    if (IsToGenerate(file)) {
      const auto* file_desc = pool_.FindFileByName(file.name());
      CHECK(file_desc != nullptr);
      res.push_back(file_desc);
    }
  }

  return res;
}
}  // structs
