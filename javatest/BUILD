java_library(
    name = "io_netty_netty_tcnative_boringssl_static",
    visibility = ["//visibility:public"],
    exports = [
        "@io_netty_netty_tcnative_boringssl_static//jar",
    ],
)

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
        ":io_netty_netty_tcnative_boringssl_static",
        "//3rdparty/jvm/com/datastax/cassandra:cassandra_driver_core",
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
