#!/bin/bash

set -e

declare -a sources=(
    "structs/base/base_plugin.h"
    "structs/base/base_plugin.cc"

)

for val in "${sources[@]}"; do
  echo "Formatting: " $val
  clang-format-6.0 -style=file -i -fallback-style=none  $val
done

declare -a builds=(
    "java/generated/BUILD"
    "javatest/BUILD"
)

for val in "${builds[@]}"; do
  buildifier $val
done
