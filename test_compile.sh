#!/bin/bash

print_project_dir() {
  (cd "$(dirname "$0")"; pwd)
}

export PROJECT_DIR="$(print_project_dir)"
export TEST_DIR="${PROJECT_DIR}/test"
export TEMP_DIR="${PROJECT_DIR}/z_tmp"

MAX_ID=26
ERRS=""

test_compile_do_skip() {
  local nn="$1"; shift

  for skip_nn in 23 24 25; do
    if [ "$nn" = "$skip_nn" ]; then
      return 0
    fi
  done

  return 1
}

test_nn() {
  local nn="$1"; shift

  echo "test_${nn}"

  if (test_compile_do_skip "$nn"); then
    echo "  ... skip" >&2
    return
  fi

  local temp_tokens_file="${TEMP_DIR}/test.tokens.txt"
  local temp_vgt_file="${TEMP_DIR}/test.vgt.json"
  local temp_vga_file="${TEMP_DIR}/test.vga.txt"
  local exp_vga_file="${TEST_DIR}/compile/exp_${nn}.vga.txt"

  echo "  tok" >&2
  cat ${TEST_DIR}/compile/${nn}.vg.txt | bin/tokenizer > $temp_tokens_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_tokenize"
    return
  fi

  echo "  parse" >&2
  cat $temp_tokens_file | bin/parser > $temp_vgt_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_parse"
    return
  fi

  echo "  cg" >&2
  cat $temp_vgt_file | bin/codegen > $temp_vga_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_codegen"
    return
  fi

  ruby test/diff.rb asm $exp_vga_file $temp_vga_file
  if [ $? -ne 0 ]; then
    # meld $exp_vga_file $temp_vga_file &

    ERRS="${ERRS},${nn}_diff"
    return
  fi
}

# --------------------------------

mkdir -p z_tmp

rake build 1>&2
if [ $? -ne 0 ]; then
  echo "----" >&2
  echo "rake build failed" >&2
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
  echo "compile: ok"
else
  echo "----"
  echo "FAILED: ${ERRS}" | sed -e 's/,/\n  /g'
  exit 1
fi
