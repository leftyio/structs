java_library(
    name = "generated",
    srcs = glob(
        [
            "**/*.java",
        ],
    ),
    visibility = ["//visibility:public"],
    deps = [
        "//3rdparty/jvm/com/scylladb:java_driver_core",
        "//3rdparty/jvm/com/google/guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/io/grpc:grpc_all",
    ],
)
