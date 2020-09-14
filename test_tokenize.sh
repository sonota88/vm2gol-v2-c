#!/bin/bash

print_project_dir() {
  (cd "$(dirname "$0")"; pwd)
}

export PROJECT_DIR="$(print_project_dir)"
export TEST_DIR="${PROJECT_DIR}/test"
export TEMP_DIR="${PROJECT_DIR}/z_tmp"

MAX_ID=2
ERRS=""

test_nn() {
  local nn="$1"; shift

  echo "test_${nn}"

  local temp_tokens_file="${TEMP_DIR}/test.tokens.txt"
  local exp_tokens_file="${TEST_DIR}/tokenize_exp_${nn}.txt"

  cat ${TEST_DIR}/tokenize_${nn}.vg.txt \
    | bin/vgtokenizer \
    > $temp_tokens_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_tokenize"
    return
  fi

  ruby test/diff.rb $exp_tokens_file $temp_tokens_file
  if [ $? -ne 0 ]; then
    # meld $exp_tokens_file $temp_tokens_file &

    ERRS="${ERRS},${nn}_diff"
    return
  fi
}

# --------------------------------

mkdir -p z_tmp

rake build 1>&2
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
  echo "tokenize: ok"
else
  echo "----"
  echo "FAILED: ${ERRS}"
  exit 1
fi
