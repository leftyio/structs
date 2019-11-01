java_library(
    name = "grpc_all",
    exports = [
        "//external:jar/io/grpc/grpc_all",
        ":grpc_auth",
        ":grpc_context",
        ":grpc_core",
        ":grpc_netty",
        ":grpc_okhttp",
        ":grpc_protobuf",
        ":grpc_protobuf_nano",
        ":grpc_stub",
        ":grpc_testing"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_auth",
    exports = [
        "//3rdparty/jvm/com/google/auth:google_auth_library_credentials",
        "//external:jar/io/grpc/grpc_auth",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_context",
    exports = [
        "//external:jar/io/grpc/grpc_context"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_core",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/code/gson:gson",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/io/opencensus:opencensus_api",
        "//3rdparty/jvm/io/opencensus:opencensus_contrib_grpc_metrics",
        "//external:jar/io/grpc/grpc_core",
        ":grpc_context"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_netty",
    exports = [
        "//3rdparty/jvm/io/netty:netty_codec_http2",
        "//3rdparty/jvm/io/netty:netty_handler_proxy",
        "//external:jar/io/grpc/grpc_netty",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_okhttp",
    exports = [
        "//3rdparty/jvm/com/squareup/okhttp:okhttp",
        "//3rdparty/jvm/com/squareup/okio:okio",
        "//external:jar/io/grpc/grpc_okhttp",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_protobuf",
    exports = [
        "//3rdparty/jvm/com/google/api/grpc:proto_google_common_protos",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//external:jar/io/grpc/grpc_protobuf",
        ":grpc_core",
        ":grpc_protobuf_lite"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_protobuf_lite",
    exports = [
        "//3rdparty/jvm/com/google/guava:guava",
        "//external:jar/io/grpc/grpc_protobuf_lite",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_protobuf_nano",
    exports = [
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf/nano:protobuf_javanano",
        "//external:jar/io/grpc/grpc_protobuf_nano",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_services",
    exports = [
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/com/google/re2j:re2j",
        "//external:jar/io/grpc/grpc_services",
        ":grpc_protobuf",
        ":grpc_stub"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_stub",
    exports = [
        "//external:jar/io/grpc/grpc_stub",
        ":grpc_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_testing",
    exports = [
        "//3rdparty/jvm/junit:junit",
        "//3rdparty/jvm/org/mockito:mockito_core",
        "//external:jar/io/grpc/grpc_testing",
        ":grpc_core",
        ":grpc_stub"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


