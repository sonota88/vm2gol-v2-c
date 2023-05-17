#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/utils.h"
#include "lib/types.h"
#include "lib/json.h"

#define INPUT_SIZE 8192
#define HEAD_SIZE 1024

int is_space_char(char ch) {
  return (
       ch == ' '
    || ch == '\n'
  );
}

int match_space(char* rest) {
  int i;
  for (i = 0; i < strlen(rest); i++) {
    if (is_space_char(rest[i])) {
      ;
    } else {
      break;
    }
  }
  return i;
}

int match_comment(char* rest) {
  if (strncmp(rest, "//", 2) != 0) {
    return 0;
  }

  return find_index(rest, '\n', 2);
}

int match_str(char* rest) {
  if (rest[0] != '"') {
    return 0;
  }

  return find_index(rest, '"', 1) - 1;
}

int is_kw(char* str) {
  return (
       str_eq(str, "set")
    || str_eq(str, "call")
    || str_eq(str, "call_set")
    || str_eq(str, "return")
    || str_eq(str, "while")
    || str_eq(str, "case")
    || str_eq(str, "var")
    || str_eq(str, "func")
    || str_eq(str, "_cmt")
  );
}

int match_int(char* rest) {
  if (
       rest[0] == '-'
    || is_numeric(rest[0])
  ) {
    // matched
  } else {
    return 0;
  }

  return find_non_numeric_index(rest);
}

int match_symbol(char* str) {
  if (
       strncmp(str, "==", 2) == 0
    || strncmp(str, "!=", 2) == 0
  ) {
    return 2;
  } else if (match_any_char(";(){},+*=", str[0])) {
    return 1;
  } else {
    return 0;
  };
}

int is_ident_char(char ch) {
  return (
       ('a' <= ch && ch <= 'z')
    || ('0' <= ch && ch <= '9')
    || ch == '_'
  );
}

int match_ident(char* rest) {
  int i;
  for (i = 1; i < strlen(rest); i++) {
    if (is_ident_char(rest[i])) {
      ;
    } else {
      break;
    }
  }
  return i;
}

void print_token(char* kind, char* value, int lineno) {
  NodeList* token = NodeList_new();
  NodeList_add_int(token, lineno);
  NodeList_add_str(token, kind);
  NodeList_add_str(token, value);
  print_as_json(token, 0);
}

int main(void) {
  char input[INPUT_SIZE];
  int pos = 0;
  int src_len;
  char rest[INPUT_SIZE];
  char temp[256];
  int size;
  int lineno = 1;

  read_stdin_all(input, INPUT_SIZE);

  src_len = strlen(input);

  while (pos < src_len) {
    substring(rest, input, pos, INPUT_SIZE);

    if (rest[0] == '\n') {
      lineno++;
      pos++;
      continue;
    }

    size = match_space(rest);
    if (0 < size) {
      pos += size;
      continue;
    }

    size = match_comment(rest);
    if (0 < size) {
      pos += size;
      continue;
    }

    size = match_str(rest);
    if (0 < size) {
      substring(temp, rest, 1, size + 1);
      print_token("str", temp, lineno);
      pos += size + 2;
      continue;
    }

    size = match_int(rest);
    if (0 < size) {
      substring(temp, rest, 0, size);
      print_token("int", temp, lineno);
      pos += size;
      continue;
    }

    size = match_symbol(rest);
    if (0 < size) {
      substring(temp, rest, 0, size);
      print_token("sym", temp, lineno);
      pos += size;
      continue;
    }

    size = match_ident(rest);
    if (0 < size) {
      substring(temp, rest, 0, size);
      if (is_kw(temp)) {
        print_token("kw", temp, lineno);
      } else {
        print_token("ident", temp, lineno);
      }
      pos += size;
      continue;
    }

    fprintf(stderr, "Unexpected pattern (%s)\n", rest);
    exit(1);
  }

  return 0;
}
