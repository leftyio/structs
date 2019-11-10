cmake_minimum_required (VERSION 2.8)
project (structs)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  third_party/inja/include
)

add_definitions("-std=c++14")
add_definitions(-DGTEST_HAS_TR1_TUPLE=1)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(third_party/json)

add_subdirectory(third_party/abseil-cpp)

add_library (structs_base_lib
  structs/base/base_plugin.cc
  structs/base/code_builder.cc
  structs/base/utils.cc
)

target_link_libraries(structs_base_lib
  glog
  gflags
  protobuf
  protoc
  absl::base
  absl::synchronization
  absl::strings

  nlohmann_json::nlohmann_json
)

add_library (structs_lib
  structs/structs.pb.cc
  structs/bigquery/bigquery.pb.cc
  structs/bigquery/bigquery_plugin.cc
  structs/cassandra/cassandra.pb.cc
  structs/cassandra/cassandra_plugin.cc
  structs/cassandra/field_gen.cc
  structs/cassandra/message_gen.cc
  structs/cassandra/renderers/cql_file.cc
  structs/cassandra/renderers/java_file.cc
  structs/cassandra/renderers/java_helpers.cc
  structs/cassandra/renderers/spark_java_file.cc
)

target_link_libraries(structs_lib
  structs_base_lib
  glog
  gflags
  protobuf
  protoc
  absl::base
  absl::synchronization
  absl::strings
  absl::str_format
)

add_executable(protoc-gen-structs-bigquery-schema
  structs/bigquery/protoc_gen_structs_bigquery_schema.cc
)

target_link_libraries (protoc-gen-structs-bigquery-schema
  structs_lib
)

add_executable(protoc-gen-structs-cassandra-table
  structs/cassandra/protoc_gen_structs_cassandra_table.cc
)

target_link_libraries (protoc-gen-structs-cassandra-table
  structs_lib
)

add_executable(protoc-gen-structs-cassandra-java
  structs/cassandra/protoc_gen_structs_cassandra_java.cc
)

target_link_libraries (protoc-gen-structs-cassandra-java
  structs_lib
)

add_executable(protoc-gen-structs-cassandra-spark-java
  structs/cassandra/protoc_gen_structs_cassandra_spark_java.cc
)

target_link_libraries (protoc-gen-structs-cassandra-spark-java
  structs_lib
)