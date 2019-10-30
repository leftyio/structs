CREATE TABLE most_basics (
  id text,
  PRIMARY KEY (id)
) WITH compression = { 'sstable_compression' : 'SnappyCompressor' }
  AND compaction = { 'class' : 'LeveledCompactionStrategy' }
;
