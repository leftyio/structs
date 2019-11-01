#!/bin/bash

set -e

declare -a sources=(
    "structs/base/base_plugin.h"
    "structs/base/base_plugin.cc"
    "structs/base/code_builder.h"
    "structs/base/code_builder.cc"
    "structs/base/utils.h"
    "structs/base/utils.cc"

    "structs/bigquery/bigquery_plugin.h"
    "structs/bigquery/bigquery_plugin.cc"
    "structs/bigquery/protoc_gen_structs_bigquery_schema.cc"

    "structs/cassandra/renderers/cql_file.h"
    "structs/cassandra/renderers/cql_file.cc"
    "structs/cassandra/renderers/java_file.h"    
    "structs/cassandra/renderers/java_file.cc"    
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
