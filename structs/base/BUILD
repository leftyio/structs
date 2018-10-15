
# load('@com_github_glog_glog//:bazel/glog.bzl', 'glog_library')
# glog_library()

cc_library(
    name = "base",
    srcs = [
      "base_plugin.cc",
      "utils.cc",
    ],
    hdrs = [
      "base_plugin.h",
      "utils.h",
    ],
    deps = [
      "@com_google_absl//absl/strings",
      "@com_google_protobuf//:protobuf",
      "@com_google_protobuf//:protoc_lib",
      "@com_github_gflags_gflags//:gflags",
      "@com_github_glog_glog//:glog",
    ],
    visibility = ["//visibility:public"],
)
