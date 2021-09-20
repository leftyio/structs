java_library(
    name = "opencensus_api",
    exports = [
        "//3rdparty/jvm/io/grpc:grpc_context",
        "//external:jar/io/opencensus/opencensus_api"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "opencensus_contrib_http_util",
    exports = [
        "//3rdparty/jvm/com/google/guava:guava",
        "//external:jar/io/opencensus/opencensus_contrib_http_util",
        ":opencensus_api"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "opencensus_proto",
    exports = [
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/io/grpc:grpc_protobuf",
        "//3rdparty/jvm/io/grpc:grpc_stub",
        "//external:jar/io/opencensus/opencensus_proto"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


