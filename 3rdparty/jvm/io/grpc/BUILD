java_library(
    name = "grpc_all",
    exports = [
        "//external:jar/io/grpc/grpc_all",
        ":grpc_api",
        ":grpc_auth",
        ":grpc_context",
        ":grpc_core",
        ":grpc_grpclb",
        ":grpc_netty",
        ":grpc_okhttp",
        ":grpc_protobuf",
        ":grpc_services",
        ":grpc_stub",
        ":grpc_testing",
        ":grpc_xds"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_alts",
    exports = [
        "//3rdparty/jvm/com/google/auth:google_auth_library_oauth2_http",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/org/apache/commons:commons_lang3",
        "//3rdparty/jvm/org/conscrypt:conscrypt_openjdk_uber",
        "//external:jar/io/grpc/grpc_alts",
        ":grpc_auth",
        ":grpc_grpclb",
        ":grpc_netty_shaded",
        ":grpc_protobuf",
        ":grpc_stub"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_api",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_api",
        ":grpc_context"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_auth",
    exports = [
        "//3rdparty/jvm/com/google/auth:google_auth_library_credentials",
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_auth",
        ":grpc_api"
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
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_core",
    exports = [
        "//3rdparty/jvm/com/google/android:annotations",
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/code/gson:gson",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/io/perfmark:perfmark_api",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_core",
        ":grpc_api"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_grpclb",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_grpclb",
        ":grpc_core",
        ":grpc_protobuf",
        ":grpc_stub"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_netty",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/io/netty:netty_codec_http2",
        "//3rdparty/jvm/io/netty:netty_handler_proxy",
        "//3rdparty/jvm/io/perfmark:perfmark_api",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_netty",
        ":grpc_core"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_netty_shaded",
    exports = [
        "//external:jar/io/grpc/grpc_netty_shaded",
        ":grpc_core"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_okhttp",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/squareup/okhttp:okhttp",
        "//3rdparty/jvm/com/squareup/okio:okio",
        "//3rdparty/jvm/io/perfmark:perfmark_api",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
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
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_protobuf",
        ":grpc_api",
        ":grpc_protobuf_lite"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_protobuf_lite",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_protobuf_lite",
        ":grpc_api"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_services",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_services",
        ":grpc_core",
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
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_stub",
        ":grpc_api"
    ],
    visibility = [
        "//visibility:public"
    ]
)



java_library(
    name = "grpc_testing",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/errorprone:error_prone_annotations",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/io/opencensus:opencensus_api",
        "//3rdparty/jvm/junit:junit",
        "//3rdparty/jvm/org/codehaus/mojo:animal_sniffer_annotations",
        "//external:jar/io/grpc/grpc_testing",
        ":grpc_context",
        ":grpc_core",
        ":grpc_stub"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "grpc_xds",
    exports = [
        "//3rdparty/jvm/com/google/code/gson:gson",
        "//3rdparty/jvm/com/google/protobuf:protobuf_java_util",
        "//3rdparty/jvm/com/google/re2j:re2j",
        "//3rdparty/jvm/io/opencensus:opencensus_proto",
        "//3rdparty/jvm/org/bouncycastle:bcpkix_jdk15on",
        "//external:jar/io/grpc/grpc_xds",
        ":grpc_alts",
        ":grpc_auth",
        ":grpc_core",
        ":grpc_netty_shaded",
        ":grpc_protobuf",
        ":grpc_services",
        ":grpc_stub"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


