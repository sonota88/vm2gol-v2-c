#!/bin/bash

set -o nounset

ERRS=""

# --------------------------------

postproc() {
  if [ "$ERRS" = "" ]; then
    echo "----"
    echo "ok"
  else
    echo "----"
    echo "FAILED: ${ERRS}" | sed -e 's/,/\n  /g'
    exit 1
  fi
}

# --------------------------------

test_json() {
  ./test_json.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},${nn}_json"
    return
  fi
}

# --------------------------------

test_all() {
  echo "==== json ===="
  test_json

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

main() {
  local cmd="$1"; shift

  case $cmd in
    json | j* )     #task: Run json tests
      test_json "$@"
      postproc "json"

  ;; all | a* )     #task: Run all tests
      test_all
      postproc "all"

  ;; * )
       echo "Tasks:"
       grep '#task: ' $0 | grep -v grep
       ;;
  esac
}

main "$@"
