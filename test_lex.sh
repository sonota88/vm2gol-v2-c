#!/bin/bash

print_project_dir() {
  (cd "$(dirname "$0")"; pwd)
}

export PROJECT_DIR="$(print_project_dir)"
export TEST_DIR="${PROJECT_DIR}/test"
export TEST_COMMON_DIR="${PROJECT_DIR}/test_common"
export TEMP_DIR="${PROJECT_DIR}/z_tmp"

MAX_ID=4
ERRS=""

test_nn() {
  local nn="$1"; shift

  echo "test_${nn}"

  local temp_tokens_file="${TEMP_DIR}/test.tokens.txt"
  local exp_tokens_file="${TEST_COMMON_DIR}/lex/exp_${nn}.txt"

  cat ${TEST_COMMON_DIR}/lex/${nn}.mrcl \
    | bin/lexer \
    > $temp_tokens_file
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_lex"
    return
  fi

  ruby ${TEST_COMMON_DIR}/diff.rb text $exp_tokens_file $temp_tokens_file
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
  echo "lex: ok"
else
  echo "----"
  echo "FAILED: ${ERRS}" | sed -e 's/,/\n  /g'
  exit 1
fi
