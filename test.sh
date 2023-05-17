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
    ERRS="${ERRS},json"
    return
  fi
}

# --------------------------------

test_lex() {
  ./test_lex.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},lex"
    return
  fi
}

# --------------------------------

test_parse() {
  ./test_parse.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},parser"
    return
  fi
}

# --------------------------------

test_compile() {
  ./test_compile.sh
  if [ $? -ne 0 ]; then
    ERRS="${ERRS},compile"
    return
  fi
}

# --------------------------------

test_all() {
  echo "==== json ===="
  test_json

  echo "==== lex ===="
  test_lex

  echo "==== parse ===="
  test_parse

  echo "==== compile ===="
  test_compile
}

# --------------------------------

main() {
  local cmd=
  if [ $# -ge 1 ]; then
    cmd="$1"; shift
  else
    cmd="show_tasks"
  fi

  case $cmd in
    json | j* )      #task: Run json tests
      test_json "$@"
      postproc "json"

  ;; lex | l* )      #task: Run lex tests
      test_lex "$@"
      postproc "lex"

  ;; parse | p* )    #task: Run parse tests
      test_parse "$@"
      postproc "parse"

  ;; compile | c* )  #task: Run compile tests
      test_compile "$@"
      postproc "compile"

  ;; all | a* )      #task: Run all tests
      test_all
      postproc "all"

  ;; * )
       echo "Tasks:"
       grep '#task: ' $0 | grep -v grep
       ;;
  esac
}

main "$@"
