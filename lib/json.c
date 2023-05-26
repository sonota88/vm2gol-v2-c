#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utils.h"

#define INPUT_MAX (1024 * 20)

// --------------------------------

typedef struct {
  NodeList* list;
  int size;
} ParseRetval;

ParseRetval* ParseRetval_new() {
  return (ParseRetval*) malloc(sizeof(ParseRetval));
}

// --------------------------------

static void must_not_happen(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

ParseRetval* parse_array(char* rest) {
  int pos = 1;
  NodeList* list;
  char temp[INPUT_MAX];
  ParseRetval* pr;
  int idx;
  char temp_str[64];
  int n;
  list = NodeList_new();

  while (pos <= strlen(rest)) {
    substring(temp, rest, pos, INPUT_MAX);

    if (temp[0] == '[') {
      pr = parse_array(temp);
      NodeList_add_list(list, pr->list);
      pos += pr->size;

    } else if (temp[0] == ']') {
      pos++;
      break;

    } else if (match_any_char(" ,\n", temp[0])) {
      pos++;

    } else if (
         temp[0] == '-'
      || is_numeric(temp[0])
    ) {
      idx = find_non_numeric_index(temp);
      substring(temp_str, temp, 0, idx);
      n = s_to_i(temp_str);
      NodeList_add_int(list, n);
      pos += strlen(temp_str);

    } else if (temp[0] == '"') {
      idx = find_index(temp, '"', 1);
      substring(temp_str, temp, 1, idx);
      NodeList_add_str(list, temp_str);
      pos += strlen(temp_str) + 2;

    } else if (temp[0] == '\0') {
      break;

    } else {
      fprintf(stderr, "temp[0] (%c)\n", temp[0]);
      must_not_happen("Unexpected token", __LINE__);
    }
  }

  pr = ParseRetval_new();
  pr->list = list;
  pr->size = pos;
  return pr;
}

NodeList* Json_parse(char* json) {
  ParseRetval* pr;
  if (json[0] == '[') {
    pr = parse_array(json);
    return pr->list;
  } else {
    fprintf(stderr, "Unexpected token\n");
    exit(1);
  }
}

void print_indent(int lv) {
  for (int i = 0; i < lv; i++) {
    printf("  ");
  }
}

void _print_as_json(NodeList* list, int lv, int pretty) {
  NodeItem* item;

  if (pretty) { print_indent(lv); }
  printf("[");
  if (pretty) { printf("\n"); }
  for (int i = 0; i < NodeList_len(list); i++) {
    item = NodeList_get(list, i);

    if (item->kind == NODE_INT) {
      if (pretty) { print_indent(lv + 1); }
      printf("%d", item->int_val);
    } else if (item->kind == NODE_STR) {
      if (pretty) { print_indent(lv + 1); }
      printf("\"%s\"", item->str_val);
    } else if (item->kind == NODE_LIST) {
      _print_as_json(item->list, lv + 1, pretty);
    } else {
      must_not_happen("Invalid node kind", __LINE__);
      exit(1);
    }
    if (i < (NodeList_len(list) - 1)) {
      if (pretty) {
        printf(",");
      } else {
        printf(", ");
      }
    }
    if (pretty) { printf("\n"); }
  }

  if (NodeList_len(list) == 0) {
    if (pretty) { printf("\n"); }
  }

  if (pretty) { print_indent(lv); }
  printf("]");
}

void Json_print(NodeList* list, int pretty) {
  _print_as_json(list, 0, pretty);
  printf("\n");
}

void list_to_json_line (char* dest, NodeList* list) {
  NodeItem* item;
  char temp[64];
  int i = 0;
  dest[i] = '[';
  i++;

  for (int li = 0; li < NodeList_len(list); li++) {
    item = NodeList_get(list, li);

    if (1 <= li) {
      dest[i] = ',';
      i++;
      dest[i] = ' ';
      i++;
    }

    to_json_line(temp, item);
    for (int ci = 0; ci < strlen(temp); ci++) {
      dest[i] = temp[ci];
      i++;
    }
  }

  dest[i] = ']';
  i++;
  dest[i] = '\0'; // TODO
  i++;
}
