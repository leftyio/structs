#include "structs/base/base_plugin.h"

#include <unistd.h>
#include <memory>

#include "glog/logging.h"

namespace structs {
BasePlugin::BasePlugin() {
  CHECK(req_->ParseFromFileDescriptor(STDIN_FILENO));
}

BasePlugin::~BasePlugin() {
  CHECK(resp_->SerializeToFileDescriptor(STDOUT_FILENO));
  LOG(INFO) << "we're all done, bye bye!";
}

int BasePlugin::Run() {
  Init();
  return DoRun();
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
