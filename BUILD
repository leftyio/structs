
java_library(
    name = "structs_lib",
    srcs = glob(
        [
            "src/main/java/**/*.java",
        ],
    ),
    deps = [
        ":com_google_guava_guava",
    ],
    visibility = ["//visibility:public"],
)

java_library(
    name = "tortuga_generated_lib",
    srcs = glob(
        [
            "src/generated/java/**/*.java",
        ],
    ),
    deps = [
        ":structs_lib",
        ":com_google_guava_guava",
    ],
    visibility = ["//visibility:public"],
)
