#include <stdio.h> 

#include "gflags/gflags.h"
#include "glog/logging.h"

#include "structs/cassandra/cassandra_plugin.h"

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  structs::CassandraPlugin plugin;
  return plugin.Run();
}
