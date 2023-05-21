require "rake/clean"

def reject_h_files(files)
  files.reject { |f| f.end_with?(".h") }
end

ENV["LANG"] = "C"

CC = "gcc -Wall"

CLEAN.include "bin/json_tester"
CLEAN.include "bin/codegen"
CLEAN.include "bin/parser"
CLEAN.include "bin/parser_lrama"
CLEAN.include "bin/lexer"
CLEAN.include "mrcl_parser_lrama.c"

SRC_UTILS = "lib/utils.c"
SRC_TYPES = "lib/types.c"
SRC_JSON  = "lib/json.c"

H_UTILS = "lib/utils.h"
H_TYPES = "lib/types.h"
H_JSON  = "lib/json.h"

task :default => :build

desc "Build executable files"
task :build => [
       "bin/lexer",
       "bin/parser",
       "bin/parser_lrama",
       "bin/json_tester",
       "bin/codegen"
     ]

file "bin/lexer" => [
       "mrcl_lexer.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/parser" => [
       "mrcl_parser.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON,
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "mrcl_parser_lrama.c" => ["mrcl_parser_lrama.y"] do |t|
  src_files = t.prerequisites.join(" ")
  sh %(lrama #{src_files} -o #{t.name})
end

file "bin/parser_lrama" => [
       "mrcl_parser_lrama.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON,
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/json_tester" => [
       "json_tester.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end

file "bin/codegen" => [
       "mrcl_codegen.c",
       SRC_UTILS, SRC_TYPES, SRC_JSON,
       H_UTILS,   H_TYPES,   H_JSON
     ] do |t|
  src_files = reject_h_files(t.prerequisites).join(" ")
  sh %(#{CC} #{src_files} -o #{t.name})
end
