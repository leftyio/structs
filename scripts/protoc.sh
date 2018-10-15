#!/bin/bash

protoc --cpp_out=. structs/cassandra/cassandra.proto
protoc --cpp_out=. structs/cassandra/cassandra_internal.proto
