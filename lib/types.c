#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utils.h"

static void must_not_happen(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

// --------------------------------

char* NodeKind_to_s(NodeKind kind) {
  if (kind == NODE_INT) {
    return "INT";
  } else if (kind == NODE_STR) {
    return "STR";
  } else if (kind == NODE_LIST) {
    return "LIST";
  } else {
    fprintf(stderr, "%s %d: must not happen\n", __FILE__, __LINE__);
    exit(1);
  }
}

NodeItem* NodeItem_new(NodeKind kind) {
  NodeItem* self = (NodeItem*) malloc(sizeof(NodeItem) * 1);
  self->kind = kind;
  return self;
}

NodeItem* NodeItem_new_int(int n) {
  NodeItem* self = NodeItem_new(NODE_INT);
  NodeItem_set_int_val(self, n);
  return self;
}

NodeItem* NodeItem_new_str(char* str) {
  NodeItem* self = NodeItem_new(NODE_STR);
  NodeItem_set_str_val(self, str);
  return self;
}

NodeItem* NodeItem_new_list(NodeList* list) {
  NodeItem* self = NodeItem_new(NODE_LIST);
  NodeItem_set_list(self, list);
  return self;
}

void NodeItem_kind_to_str(NodeItem* self, char* dest) {
  if (self->kind == NODE_INT) {
    strcpy(dest, "INT");
  } else if (self->kind == NODE_STR) {
    strcpy(dest, "STR");
  } else if (self->kind == NODE_LIST) {
    strcpy(dest, "LIST");
  } else {
    fprintf(stderr, "%s %d: must not happen\n", __FILE__, __LINE__);
    exit(1);
  }
}

void NodeItem_set_str_val(NodeItem* self, char* str) {
  strcpy(self->str_val, str);
}

void NodeItem_set_int_val(NodeItem* self, int n) {
  self->int_val = n;
}

void NodeItem_set_list(NodeItem* self, NodeList* list) {
  self->list = list;
}

int NodeItem_str_eq(NodeItem* self, char* str) {
  if (self->kind != NODE_STR) {
    fprintf(stderr,
            "Invalid type: must be NODE_STR (%s)",
            NodeKind_to_s(self->kind)
            );
  }

  return str_eq(self->str_val, str);
}

void NodeItem_dump(NodeItem* self) {
  char kind[8];
  NodeItem_kind_to_str(self, kind);

  fprintf(stderr, "  +---- dump item ----\n");
  fprintf(stderr, "  | kind: %d\n", self->kind);
  fprintf(stderr, "  | kind: %s\n", kind);

  if (self->kind == NODE_INT) {
    fprintf(stderr, "  | int: %d\n", self->int_val);
  } else if (self->kind == NODE_STR) {
    fprintf(stderr, "  | str: <%s>\n", self->str_val);
  } else if (self->kind == NODE_LIST) {
    fprintf(stderr, "  | list: %p\n", self->list);
  } else {
    fprintf(stderr, "  | ?\n");
  }

  fprintf(stderr, "  +---- dump item ----\n");
}

// --------------------------------

NodeList* NodeList_new() {
  NodeList* self = (NodeList*) malloc(sizeof(NodeList) * 1);
  self->len = 0;
  return self;
}

NodeList* NodeList_empty() {
  return NodeList_new();
}

void NodeList_add_item(NodeList* self, NodeItem* item) {
  int i = self->len;
  self->items[i] = item;
  self->len++;
}

void NodeList_add_all(NodeList* self, NodeList* list) {
  NodeItem* item;
  for (int i = 0; i < list->len; i++) {
    item = list->items[i];
    NodeList_add_item(self, item);
  }
}

void NodeList_add_int_item(NodeList* self, int n) {
  NodeItem* item = (NodeItem*) malloc(sizeof(NodeItem) * 1);
  item->kind = NODE_INT;
  NodeItem_set_int_val(item, n);

  NodeList_add_item(self, item);
}

void NodeList_add_str_item(NodeList* self, char* str) {
  NodeItem* item = (NodeItem*) malloc(sizeof(NodeItem) * 1);
  item->kind = NODE_STR;
  NodeItem_set_str_val(item, str);

  NodeList_add_item(self, item);
}

void NodeList_add_list_item(NodeList* self, NodeList* list) {
  NodeItem* item = NodeItem_new(NODE_LIST);
  NodeItem_set_list(item, list);

  NodeList_add_item(self, item);
}

NodeItem* NodeList_head(NodeList* self) {
  return self->items[0];
}

NodeList* NodeList_rest(NodeList* self) {
  NodeList* new_list = NodeList_new();
  NodeItem* item;

  for (int i = 1; i < self->len; i++) {
    item = self->items[i];
    NodeList_add_item(new_list, item);
  }

  return new_list;
}

NodeItem* NodeList_get(NodeList* self, int index) {
  return self->items[index];
}


void NodeList_dump(NodeList* self) {
  NodeItem* item;

  fprintf(stderr, "  +---- dump list ----\n");
  fprintf(stderr, "  | p: %p\n", self);

  if (self != NULL) {
    fprintf(stderr, "  | len: %d\n", self->len);

    for (int i = 0; i < self->len; i++) {
      item = self->items[i];
      fprintf(stderr, "  | (%d) (%p):", i, item);
      if (item != NULL) {
        fprintf(stderr, "  k(%d:%s)",
                item->kind,
                NodeKind_to_s(item->kind)
                );
        if (item->kind == NODE_INT) {
          fprintf(stderr, " int(%d):", item->int_val);
        } else if (item->kind == NODE_STR) {
          fprintf(stderr, " str(%s):", item->str_val);
        } else if (item->kind == NODE_LIST) {
          fprintf(stderr, " len(%d):", item->list->len);
        }
      }
      fprintf(stderr, "\n");
    }
  }

  fprintf(stderr, "  +---- dump list ----\n");
}

// --------------------------------

TokenKind TokenKind_from_str(char* str) {
  if (str_eq(str, "kw")) {
    return TOKEN_KW;
  } else if (str_eq(str, "sym")) {
    return TOKEN_SYM;
  } else if (str_eq(str, "int")) {
    return TOKEN_INT;
  } else if (str_eq(str, "str")) {
    return TOKEN_STR;
  } else if (str_eq(str, "ident")) {
    return TOKEN_IDENT;
  } else {
    must_not_happen("Invalid token kind string", __LINE__);
    exit(2);
  }
}

char* TokenKind_to_str(TokenKind kind) {
  if (kind == TOKEN_KW) {
    return "kw";
  } else if (kind == TOKEN_SYM) {
    return "sym";
  } else if (kind == TOKEN_INT) {
    return "int";
  } else if (kind == TOKEN_STR) {
    return "str";
  } else if (kind == TOKEN_IDENT) {
    return "ident";
  } else {
    must_not_happen("Invalid token kind", __LINE__);
    exit(2);
  }
}

int Token_is(Token* self, TokenKind kind, char* str) {
  if (
       self->kind == kind
    && str_eq(self->str, str)
  ) {
    return 1;
  } else {
    return 0;
  }
}

int Token_str_eq(Token* self, char* str) {
  if (str_eq(self->str, str)) {
    return 1;
  } else {
    return 0;
  }
}

// --------------------------------

Names* Names_new() {
  return (Names*) malloc(sizeof(Names));
}

void Names_add(Names* self, char* str) {
  self->names[self->len] = str;
  self->len++;
}

Names* Names_from_node_list(NodeList* list) {
  Names* names = Names_new();
  for (int i = 0; i < list->len; i++) {
    Names_add(names, list->items[i]->str_val);
  }
  return names;
}

int Names_index(Names* self, char* name) {
  for (int i = 0; i < self->len; i++) {
    if (str_eq(self->names[i], name)) {
      return i;
    }
  }
  return -1;
}

int Names_contains(Names* self, char* name) {
  int i = Names_index(self, name);
  if (i >= 0) {
    return 1;
  } else {
    return 0;
  }
}

void Names_dump(Names* self) {
  for (int i = 0; i < self->len; i++) {
    fprintf(stderr, "  name | (%d) (%s)\n", i, self->names[i]);
  }
}
