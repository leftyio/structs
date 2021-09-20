java_library(
    name = "cassandra_driver_core",
    exports = [
        "//3rdparty/jvm/com/github/jnr:jnr_ffi",
        "//3rdparty/jvm/com/github/jnr:jnr_posix",
        "//external:jar/com/datastax/cassandra/cassandra_driver_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "cassandra_driver_mapping",
    exports = [
        "//external:jar/com/datastax/cassandra/cassandra_driver_mapping",
        ":cassandra_driver_core"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


