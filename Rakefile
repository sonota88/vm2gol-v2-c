require "rake/clean"

ENV["LANG"] = "C"

CC = "gcc -Wall"

CLEAN.include "bin/test_json"
CLEAN.include "bin/vgcg"
CLEAN.include "bin/vgparser"
CLEAN.include "bin/vgtokenizer"

SRC_UTILS = "lib/utils.c"
SRC_TYPES = "lib/types.c"
SRC_JSON  = "lib/json.c"

task :default => :build

task :build => [
       "bin/vgtokenizer",
       "bin/vgparser",
       "bin/test_json",
       "bin/vgcg"
     ]

file "bin/vgtokenizer" => ["vgtokenizer.c", SRC_UTILS] do |t|
  src_files = t.prerequisites.join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/vgparser" => ["vgparser.c", SRC_UTILS, SRC_TYPES, SRC_JSON] do |t|
  src_files = t.prerequisites.join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/test_json" => ["lib/test_json.c", SRC_UTILS, SRC_TYPES, SRC_JSON] do |t|
  src_files = t.prerequisites.join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/vgcg" => ["vgcg.c", SRC_UTILS, SRC_TYPES, SRC_JSON] do |t|
  src_files = t.prerequisites.join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end
