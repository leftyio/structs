#!/bin/bash
make protoc-gen-structs-cassandra
export GLOG_logtostderr=1
protoc --plugin=protoc-gen-structs-cassandra                                                                    \
    --proto_path=structs/cassandra/testdata                                                                     \
    --proto_path=/usr/local/include                                                                             \
    --structs-cassandra_out="schema=structs/cassandra/testdata/structs/testdata/fields_structs_test.cassandra.pbtext:." \
    structs/testdata/fields_structs_test.proto 
