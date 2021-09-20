java_library(
    name = "google_http_client",
    exports = [
        "//3rdparty/jvm/com/google/code/findbugs:jsr305",
        "//3rdparty/jvm/com/google/guava:guava",
        "//3rdparty/jvm/com/google/j2objc:j2objc_annotations",
        "//3rdparty/jvm/io/opencensus:opencensus_api",
        "//3rdparty/jvm/io/opencensus:opencensus_contrib_http_util",
        "//3rdparty/jvm/org/apache/httpcomponents:httpclient",
        "//3rdparty/jvm/org/apache/httpcomponents:httpcore",
        "//external:jar/com/google/http_client/google_http_client"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "google_http_client_jackson2",
    exports = [
        "//3rdparty/jvm/com/fasterxml/jackson/core:jackson_core",
        "//external:jar/com/google/http_client/google_http_client_jackson2",
        ":google_http_client"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


