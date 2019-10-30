#include <stdio.h> 

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "inja/inja.hpp"

#include "structs/bigquery/bigquery_plugin.h"

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  structs::BigQueryPlugin plugin;
  return plugin.Run();
}
