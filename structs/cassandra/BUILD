
# load('@com_github_glog_glog//:bazel/glog.bzl', 'glog_library')
# glog_library()

cc_library(
  name = "proto_lib",
  srcs = [
    "cassandra.pb.cc",
    "cassandra_internal.pb.cc",
  ],
  hdrs = [
    "cassandra.pb.h",
    "cassandra_internal.pb.h",
  ],
  deps = [
    "@com_google_protobuf//:protobuf",
    "@com_google_protobuf//:protoc_lib",
  ]
)

cc_library(
    name = "cassandra_lib",
    srcs = [
      "cassandra_plugin.cc",
      "field_gen.cc",
      "message_gen.cc",
      "renderers/java_file.cc",
      "renderers/cql_file.cc",
    ],
    hdrs = [
      "cassandra_plugin.h",      
      "field_gen.h",
      "message_gen.h",
      "renderers/java_file.h",
      "renderers/cql_file.h",
    ],
    deps = [
      ":proto_lib",
      "//structs/base",
      "@com_google_absl//absl/algorithm:container",
      "@com_google_absl//absl/strings",
      "@com_google_protobuf//:protobuf",
      "@com_google_protobuf//:protoc_lib",
      "@com_github_gflags_gflags//:gflags",
      "@com_github_glog_glog//:glog",
    ]
)

cc_binary(
    name = "protoc-gen-structs-cassandra",
    srcs = [
      "protoc_gen_structs_cassandra.cc"
    ],
    deps = [
        ":cassandra_lib",
    ],
)

filegroup(
  name = "test_protos",
  srcs = [
    "testdata/structs/testdata/base_structs_test.proto",
    "testdata/structs/testdata/base_structs_test.cassandra.pbtext",
    "testdata/structs/testdata/fields_structs_test.proto",
    "testdata/structs/testdata/fields_structs_test.cassandra.pbtext",
  ],
)


cc_test(
  name = "protoc-gen-structs-cassandra_test",
  srcs = [
    "protoc_gen_structs_cassandra_test.cc"
  ],
  deps = [
    ":proto_lib",
    "//structs/base",
    "@com_google_absl//absl/strings",
    "@com_github_glog_glog//:glog",
    "@com_google_googletest//:gtest",
    "@com_google_googletest//:gtest_main",
  ],
  data = [
    ":test_protos",
    ":protoc-gen-structs-cassandra",
    "@com_google_protobuf//:protoc",
  ],
)
