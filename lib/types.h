#pragma once

typedef enum {
  TOKEN_KW,
  TOKEN_SYM,
  TOKEN_INT,
  TOKEN_STR,
  TOKEN_IDENT
} TokenKind;

typedef struct {
  TokenKind kind;
  char str[64];
} Token;

TokenKind TokenKind_from_str(char* str);
char* TokenKind_to_str(TokenKind kind);
int Token_is(Token* self, TokenKind kind, char* str);
int Token_str_eq(Token* self, char* str);

// --------------------------------

#define NODE_ITEM__STR_VAL_SIZE_MAX 48

typedef enum {
  NODE_INT,
  NODE_STR,
  NODE_LIST
} NodeKind;

char* NodeKind_to_s(NodeKind kind);

typedef struct NodeItem_tag {
  NodeKind kind;
  int int_val;
  char str_val[NODE_ITEM__STR_VAL_SIZE_MAX];
  struct NodeList_tag* list;
} NodeItem;

typedef struct NodeList_tag {
  int len;
  struct NodeItem_tag* items[64];
} NodeList;

NodeItem* NodeItem_new(NodeKind kind);
NodeItem* NodeItem_new_int(int n);
NodeItem* NodeItem_new_str(char* str);
NodeItem* NodeItem_new_list(NodeList* list);

void NodeItem_kind_to_str(NodeItem* self, char* dest);
void NodeItem_set_int_val(NodeItem* self, int n);
void NodeItem_set_str_val(NodeItem* self, char* str);
void NodeItem_set_list(NodeItem* self, NodeList* list);

int NodeItem_str_eq(NodeItem* self, char* str);

void NodeItem_dump(NodeItem* self);

// --------------------------------

NodeList* NodeList_new();
NodeList* NodeList_empty();
int NodeList_len(NodeList* self);
void NodeList_add_item(NodeList* self, NodeItem* item);
void NodeList_add_all(NodeList* self, NodeList* list);
void NodeList_add_int(NodeList* self, int n);
void NodeList_add_str(NodeList* self, char* str);
void NodeList_add_list(NodeList* self, NodeList* list);

NodeItem* NodeList_head(NodeList* self);
NodeList* NodeList_rest(NodeList* self);
NodeItem* NodeList_get(NodeList* self, int index);

void NodeList_dump(NodeList* self);

// --------------------------------

typedef struct {
  char* names[8];
  int len;
} Names;

Names* Names_new();
void Names_add(Names* self, char* str);
Names* Names_from_node_list(NodeList* list);
int Names_index(Names* self, char* name);
int Names_contains(Names* self, char* name);
void Names_dump(Names* self);
