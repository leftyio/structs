java_library(
    name = "jffi",
    exports = [
        "//external:jar/com/github/jnr/jffi"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jffi_jar_native",
    exports = [
        "//external:jar/com/github/jnr/jffi_jar_native"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jnr_a64asm",
    exports = [
        "//external:jar/com/github/jnr/jnr_a64asm"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jnr_constants",
    exports = [
        "//external:jar/com/github/jnr/jnr_constants"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jnr_ffi",
    exports = [
        "//3rdparty/jvm/org/ow2/asm:asm",
        "//3rdparty/jvm/org/ow2/asm:asm_analysis",
        "//3rdparty/jvm/org/ow2/asm:asm_commons",
        "//3rdparty/jvm/org/ow2/asm:asm_tree",
        "//3rdparty/jvm/org/ow2/asm:asm_util",
        "//external:jar/com/github/jnr/jnr_ffi",
        ":jffi",
        ":jffi_jar_native",
        ":jnr_a64asm",
        ":jnr_x86asm"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jnr_posix",
    exports = [
        "//external:jar/com/github/jnr/jnr_posix",
        ":jnr_constants",
        ":jnr_ffi"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)



java_library(
    name = "jnr_x86asm",
    exports = [
        "//external:jar/com/github/jnr/jnr_x86asm"
    ],
    visibility = [
        "//3rdparty/jvm:__subpackages__"
    ]
)


