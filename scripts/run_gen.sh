#!/bin/bash

make
export GLOG_logtostderr=1

#protoc --plugin=protoc-gen-structs-cassandra-spark-java                                                         \
#    --proto_path=structs/cassandra/testdata                                                                     \
#    --proto_path=/usr/local/include                                                                             \
#    --structs-cassandra-spark-java_out="schema=structs/cassandra/testdata/structs/testdata/fields_structs_test.cassandra.pbtext:." \
#    structs/testdata/fields_structs_test.proto 

#protoc --plugin=protoc-gen-structs-cassandra-java                                                               \
#    --proto_path=structs/cassandra/testdata                                                                     \
#    --proto_path=/usr/local/include                                                                             \
#    --structs-cassandra-java_out="schema=structs/cassandra/testdata/structs/testdata/fields_structs_test.java.pbtext:." \
#    structs/testdata/fields_structs_test.proto 

protoc --proto_path=.                                                                         \
    --java_out="java/generated"                                                               \
    structs/proto/testing.proto 

protoc --plugin=protoc-gen-structs-cassandra-java                                             \
    --proto_path=.                                                                            \
    --structs-cassandra-java_out="schema=structs/proto/most_basic.java.pbtext:java/generated" \
    structs/proto/testing.proto 