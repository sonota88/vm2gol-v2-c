require "rake/clean"

def reject_h_files(files)
  files.reject { |f| f.end_with?(".h") }
end

ENV["LANG"] = "C"

CC = "gcc -Wall"

CLEAN.include "bin/test_json"
CLEAN.include "bin/vgcg"
CLEAN.include "bin/vgparser"
CLEAN.include "bin/vgtokenizer"

SRC_UTILS = "lib/utils.c"
SRC_TYPES = "lib/types.c"
SRC_JSON  = "lib/json.c"

H_UTILS = "lib/utils.h"
H_TYPES = "lib/types.h"
H_JSON  = "lib/json.h"

task :default => :build

desc "Build executable files"
task :build => [
       "bin/vgtokenizer",
       "bin/vgparser",
       "bin/test_json",
       "bin/vgcg"
     ]

file "bin/vgtokenizer" => [
       "vgtokenizer.c",
       SRC_UTILS,
       H_UTILS,
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/vgparser" => [
       "vgparser.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON,
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/test_json" => [
       "lib/test_json.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/vgcg" => [
       "vgcg.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end
