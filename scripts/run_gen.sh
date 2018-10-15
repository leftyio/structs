#!/bin/bash

bazel build //structs/cassandra:protoc-gen-structs-cassandra
export GLOG_logtostderr=1
protoc --plugin=bazel-bin/structs/cassandra/protoc-gen-structs-cassandra --structs-cassandra_out="schema=data/structs_test.cassandra.pbtext:." data/structs_test.proto
