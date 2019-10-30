#!/bin/bash

# generates our bazel dependencies. It is expected that ~/opt/bazel-deps has been checked out
# (from: https://github.com/johnynek/bazel-deps) and built.

$HOME/opt/bazel-deps/bazel-bin/src/scala/com/github/johnynek/bazel_deps/parseproject \
    generate -r `pwd` -s 3rdparty/workspace.bzl -d scripts/bazel/deps.yaml
