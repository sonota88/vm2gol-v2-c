#!/bin/bash

ERRS=""

test_all() {
  echo "==== json ===="
  ./test_json.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_json"
    return
  fi

  echo "==== lex ===="
  ./test_lex.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_lex"
    return
  fi

  echo "==== parse ===="
  ./test_parse.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_parser"
    return
  fi

  echo "==== compile ===="
  ./test_compile.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_compile"
    return
  fi
}

# --------------------------------

test_all

if [ "$ERRS" = "" ]; then
  echo "----"
  echo "ok"
else
  echo "----"
  echo "FAILED: ${ERRS}" | sed -e 's/,/\n  /g'
  exit 1
fi
