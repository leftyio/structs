java_library(
    name = "java_tests",
    srcs = glob(
        [
            "**/*.java",
        ],
    ),
    resources = glob([
        "**/*.properties",
        "io/structs/cassandra.truststore",
    ]),
    deps = [
        "//3rdparty/jvm/com/scylladb:java_driver_core",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/junit",
        "//java/generated",
    ],
)

java_test(
    name = "CassandraJavaTest",
    size = "small",
    test_class = "io.structs.CassandraJavaTest",
    runtime_deps = [
        ":java_tests",
    ],
)
