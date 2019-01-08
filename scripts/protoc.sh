#!/bin/bash

protoc --cpp_out=. structs/structs.proto
protoc --cpp_out=. structs/bigquery/bigquery.proto
protoc --cpp_out=. structs/cassandra/cassandra.proto
