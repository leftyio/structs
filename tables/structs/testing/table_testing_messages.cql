CREATE TABLE testing_messages (
  id text,
  field_double double,
  field_float float,
  field_int32 int,
  field_int64 bigint,
  field_bool boolean,
  field_string text,
  field_bytes blob,
  field_enum int,
  field_timestamp timestamp,
  field_double_value double,
  field_float_value float,
  field_int64_value bigint,
  field_int32_value int,
  field_bool_value boolean,
  field_string_value text,
  list_of_double list<double>,
  list_of_float list<float>,
  list_of_int32 list<int>,
  list_of_int64 list<bigint>,
  list_of_bool list<boolean>,
  list_of_string list<text>,
  list_of_enum list<int>,
  PRIMARY KEY (id)
) WITH compression = { 'sstable_compression' : 'SnappyCompressor' }
  AND compaction = { 'class' : 'LeveledCompactionStrategy' }
;
