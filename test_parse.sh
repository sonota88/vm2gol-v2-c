#!/bin/bash

print_project_dir() {
  (cd "$(dirname "$0")"; pwd)
}

export PROJECT_DIR="$(print_project_dir)"
export TEST_DIR="${PROJECT_DIR}/test"
export TEMP_DIR="${PROJECT_DIR}/z_tmp"

MAX_ID=1
ERRS=""

test_nn() {
  local nn="$1"; shift

  echo "test_${nn}"

  local temp_tokens_file="${TEMP_DIR}/test.tokens.txt"
  local temp_vgt_file="${TEMP_DIR}/test.vgt.json"
  local exp_vga_file="${TEST_DIR}/parse/exp_${nn}.vgt.json"
  local local_errs=""

  echo "  tok" >&2
  cat ${TEST_DIR}/parse/${nn}.vg.txt | bin/lexer > $temp_tokens_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_lex"
    local_errs="${local_errs},${nn}_lex"
    return
  fi

  echo "  parse" >&2
  cat $temp_tokens_file | bin/parser > $temp_vgt_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_parse"
    local_errs="${local_errs},${nn}_parse"
    return
  fi

  if [ "$local_errs" = "" ]; then
    ruby test/diff.rb json $exp_vga_file $temp_vgt_file
    if [ $? -ne 0 ]; then
      # meld $exp_vga_file $temp_vga_file &

      ERRS="${ERRS},${nn}_diff"
      return
    fi
  fi
}

# --------------------------------

mkdir -p z_tmp

rake build 1>&2
if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi

export DO_BUILD=0

ids=

if [ $# -eq 1 ]; then
  ids="$1"
else
  ids="$(seq 1 ${MAX_ID})"
fi

for id in $ids; do
  test_nn $(printf "%02d" $id)
done

if [ "$ERRS" = "" ]; then
  echo "parse: ok"
else
  echo "----"
  echo "FAILED: ${ERRS}" | sed -e 's/,/\n  /g'
  exit 1
fi
