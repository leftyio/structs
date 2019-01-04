#include <stdio.h> 

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "google/protobuf/compiler/plugin.h"

#include "structs/bigquery/bigquery_plugin.h"

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  structs::BigQueryPlugin plugin;
  return google::protobuf::compiler::PluginMain(argc, argv, &plugin);
}
