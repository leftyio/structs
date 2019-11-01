CREATE TABLE inner_containers (
  id text,
  inner_value int,
  inner_value_str text,
  inner_as_bytes blob,
  PRIMARY KEY (id)
) WITH compression = { 'sstable_compression' : 'SnappyCompressor' }
  AND compaction = { 'class' : 'LeveledCompactionStrategy' }
;
