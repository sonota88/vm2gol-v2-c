#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/utils.h"
#include "lib/types.h"
#include "lib/json.h"

#define INPUT_SIZE (1024 * 20)
#define NUM_TOKENS 1024

Token g_tokens[NUM_TOKENS];
int g_num_tokens;
int g_pos = 0;
static int g_is_debug = 0;

NodeItem* parse_expr();
NodeList* parse_stmts();

// --------------------------------

static void not_yet_impl(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

static void parse_error(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

// --------------------------------

void puts_fn(char* s) {
  if (g_is_debug) {
    puts_e(s);
  }
}

int get_line_size(char* text, int pos) {
  int i = find_index(text, '\n', pos);
  if (0 <= i) {
    return i - pos + 1;
  } else {
    return strlen(text) - pos;
  }
}

void chomp(char* str) {
  int i = 0;

  for (;; i++) {
    if (str[i] == '\0') {
      break;
    }
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
  }
}

void read_tokens(char* input) {
  int src_len;
  int pos = 0;
  int line_size;
  char line[256];
  char kind_str[8];
  char str[64];
  int ti = 0;
  int sep_i;

  src_len = strlen(input);

  while (pos < src_len) {
    line_size = get_line_size(input, pos);
    substring(line, input, pos, pos + line_size);

    chomp(line);

    sep_i = find_index(line, ':', 0);
    substring(kind_str, line, 0, sep_i);
    substring(str, line, sep_i + 1, line_size);

    g_tokens[ti].kind = TokenKind_from_str(kind_str);
    strcpy(g_tokens[ti].str, str);

    ti++;
    if (NUM_TOKENS <= ti) {
      _err_exit("Over NUM_TOKENS", __FILE__, __LINE__);
    }

    pos += line_size;
  }

  g_num_tokens = ti;
}

int is_end() {
  if (g_num_tokens <= g_pos) {
    return 1;
  } else {
    return 0;
  }
}

Token* peek(int offset) {
  return g_tokens + g_pos + offset;
}

void assert_value(TokenKind kind, char* str) {
  Token* t = peek(0);

  if (t->kind != kind) {
    fprintf(stderr, "Assertion failed:\n");
    fprintf(stderr, "  expected kind: (%s) \n", TokenKind_to_str(kind));
    fprintf(stderr, "  actual: (%s) (%s) \n",
            TokenKind_to_str(t->kind), t->str);
    parse_error("Unexpected kind", __LINE__);
  }

  if (Token_str_eq(t, str)) {
    // OK
  } else {
    fprintf(stderr, "Assertion failed:\n");
    fprintf(stderr, "  expected str: (%s) \n", str);
    fprintf(stderr, "  actual: (%s) (%s) \n",
            TokenKind_to_str(t->kind), t->str);
    parse_error("Unexpected str", __LINE__);
  }
}

void consume_kw(char* str) {
  assert_value(TOKEN_KW, str);
  g_pos++;
}

void consume_sym(char* str) {
  assert_value(TOKEN_SYM, str);
  g_pos++;
}

// --------------------------------

NodeItem* parse_arg() {
  Token* t;
  NodeItem* arg;

  puts_fn("-->> parse_arg");

  t = peek(0);

  if (t->kind == TOKEN_INT) {
    g_pos++;
    arg = NodeItem_new_int(s_to_i(t->str));
    return arg;

  } else if (t->kind == TOKEN_IDENT) {
    g_pos++;
    arg = NodeItem_new_str(t->str);
    return arg;

  } else {
    not_yet_impl("parse_arg", __LINE__);
    exit(2);
  }
}

NodeItem* parse_args_first() {
  Token* t;

  puts_fn("-->> parse_args_first");

  t = peek(0);

  if (Token_is(t, TOKEN_SYM, ")")) {
    return NULL;
  }

  return parse_arg();
}

NodeItem* parse_args_rest() {
  Token* t;

  puts_fn("-->> parse_args_rest");

  t = peek(0);

  if (Token_is(t, TOKEN_SYM, ")")) {
    return NULL;
  }

  consume_sym(",");

  return parse_arg();
}

NodeList* parse_args() {
  NodeList* args;
  NodeItem* first_arg;
  NodeItem* rest_arg;

  puts_fn("-->> parse_args");

  args = NodeList_new();

  first_arg = parse_args_first();
  if (first_arg == NULL) {
    return args;
  }
  NodeList_add_item(args, first_arg);

  while (1) {
    rest_arg = parse_args_rest();
    if (rest_arg == NULL) {
      break;
    }
    NodeList_add_item(args, rest_arg);
  }

  return args;
}

NodeList* parse_func() {
  NodeList* list;
  Token* t;
  char fn_name[64];
  NodeList* args;
  NodeList* stmts;

  puts_fn("-->> parse_func");

  consume_kw("func");

  t = peek(0);
  g_pos++;
  strcpy(fn_name, t->str);

  // fprintf(stderr, "  fn_name (%s)\n", fn_name);

  consume_sym("(");
  args = parse_args();
  consume_sym(")");

  consume_sym("{");
  stmts = parse_stmts();
  consume_sym("}");

  list = NodeList_new();
  NodeList_add_str_item(list, "func");
  NodeList_add_str_item(list, fn_name);
  NodeList_add_list_item(list, args);
  NodeList_add_list_item(list, stmts);

  return list;
}

NodeList* parse_var_declare() {
  NodeList* list;
  char var_name[64];
  Token* t;

  puts_fn("-->> parse_var_declare");

  t = peek(0);
  g_pos++;
  strcpy(var_name, t->str);

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "var");
  NodeList_add_str_item(list, var_name);
  return list;
}

NodeList* parse_var_init() {
  NodeList* list;
  char var_name[64];
  Token* t;
  NodeItem* expr;

  puts_fn("-->> parse_var_init");

  t = peek(0);
  g_pos++;
  strcpy(var_name, t->str);

  consume_sym("=");

  expr = parse_expr();

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "var");
  NodeList_add_str_item(list, var_name);
  NodeList_add_item(list, expr);
  return list;
}

NodeList* parse_var() {
  Token* t;

  consume_kw("var");

  t = peek(1);

  if (Token_str_eq(t, ";")) {
    return parse_var_declare();
  } else if (Token_str_eq(t, "=")) {
    return parse_var_init();
  } else {
    parse_error("Unexpected token", __LINE__);
    exit(2);
  }
}

NodeItem* parse_expr_right(NodeItem* expr_l) {
  Token* t;
  NodeList* expr_els;
  NodeItem* expr_r;

  t = peek(0);

  if (
      Token_is(t, TOKEN_SYM, ";") ||
      Token_is(t, TOKEN_SYM, ")")
  ) {
    return expr_l;
  }

  if (Token_is(t, TOKEN_SYM, "+")) {
    consume_sym("+");
    expr_r = parse_expr();
    expr_els = NodeList_new();
    NodeList_add_str_item(expr_els, "+");
    NodeList_add_item(expr_els, expr_l);
    NodeList_add_item(expr_els, expr_r);

  } else if (Token_is(t, TOKEN_SYM, "*")) {
    consume_sym("*");
    expr_r = parse_expr();
    expr_els = NodeList_new();
    NodeList_add_str_item(expr_els, "*");
    NodeList_add_item(expr_els, expr_l);
    NodeList_add_item(expr_els, expr_r);

  } else if (Token_is(t, TOKEN_SYM, "==")) {
    consume_sym("==");
    expr_r = parse_expr();
    expr_els = NodeList_new();
    NodeList_add_str_item(expr_els, "eq");
    NodeList_add_item(expr_els, expr_l);
    NodeList_add_item(expr_els, expr_r);

  } else if (Token_is(t, TOKEN_SYM, "!=")) {
    consume_sym("!=");
    expr_r = parse_expr();
    expr_els = NodeList_new();
    NodeList_add_str_item(expr_els, "neq");
    NodeList_add_item(expr_els, expr_l);
    NodeList_add_item(expr_els, expr_r);

  } else {
    not_yet_impl("Unsupported operator", __LINE__);
  }

  return NodeItem_new_list(expr_els);
}

NodeItem* parse_expr() {
  Token* tl;
  NodeItem* expr_l;
  int n;

  puts_fn("-->> parse_expr");

  tl = peek(0);

  if (Token_is(tl, TOKEN_SYM, "(")) {
    consume_sym("(");
    expr_l = parse_expr();
    consume_sym(")");

    return parse_expr_right(expr_l);
  }

  if (tl->kind == TOKEN_INT) {
    g_pos++;
    n = s_to_i(tl->str);

    expr_l = NodeItem_new_int(n);

    return parse_expr_right(expr_l);

  } else if (tl->kind == TOKEN_IDENT) {
    g_pos++;

    expr_l = NodeItem_new_str(tl->str);

    return parse_expr_right(expr_l);

  } else {

    puts_e(TokenKind_to_str(tl->kind));
    parse_error("Unexpected token kind", __LINE__);
    exit(2);
  }
}

NodeList* parse_set() {
  char var_name[64];
  Token* t;
  NodeItem* expr;
  NodeList* list;

  puts_fn("-->> parse_set");

  consume_kw("set");

  t = peek(0);
  g_pos++;
  strcpy(var_name, t->str);

  consume_sym("=");

  expr = parse_expr();

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "set");
  NodeList_add_str_item(list, var_name);
  NodeList_add_item(list, expr);
  return list;
}

NodeList* parse_funcall() {
  NodeList* list;
  Token* t;
  char* fn_name;
  NodeList* args;

  puts_fn("-->> parse_funcall");

  list = NodeList_new();

  t = peek(0);
  g_pos++;
  fn_name = t->str;

  consume_sym("(");
  args = parse_args();
  consume_sym(")");

  NodeList_add_str_item(list, fn_name);
  NodeList_add_all(list, args);
  return list;
}

NodeList* parse_call() {
  NodeList* list;
  NodeList* funcall;

  puts_fn("-->> parse_call");

  consume_kw("call");

  funcall = parse_funcall();

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "call");
  NodeList_add_all(list, funcall);
  return list;
}

NodeList* parse_call_set() {
  NodeList* list;
  Token* t;
  char var_name[64];
  NodeList* funcall;

  consume_kw("call_set");

  t = peek(0);
  g_pos++;
  strcpy(var_name, t->str);

  consume_sym("=");

  funcall = parse_funcall();

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "call_set");
  NodeList_add_str_item(list, var_name);
  NodeList_add_list_item(list, funcall);
  return list;
}

NodeList* parse_return() {
  NodeList* list;
  NodeItem* expr;

  consume_kw("return");

  expr = parse_expr();

  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "return");
  NodeList_add_item(list, expr);
  return list;
}

NodeList* parse_while() {
  NodeList* list;
  NodeItem* expr;
  NodeList* stmts;

  consume_kw("while");

  consume_sym("(");
  expr = parse_expr();
  consume_sym(")");

  consume_sym("{");
  stmts = parse_stmts();
  consume_sym("}");

  list = NodeList_new();
  NodeList_add_str_item(list, "while");
  NodeList_add_item(list, expr);
  NodeList_add_list_item(list, stmts);
  return list;
}

NodeList* parse_when_clause() {
  NodeList* list;
  Token* t;
  NodeItem* expr;
  NodeList* stmts;

  t = peek(0);
  if (Token_is(t, TOKEN_SYM, "}")) {
    return NULL;
  }

  consume_sym("(");
  expr = parse_expr();
  consume_sym(")");

  consume_sym("{");
  stmts = parse_stmts();
  consume_sym("}");

  list = NodeList_new();
  NodeList_add_item(list, expr);
  NodeList_add_all(list, stmts);
  return list;
}

NodeList* parse_case() {
  NodeList* list;
  NodeList* when_clauses;
  NodeList* when_clause;

  consume_kw("case");

  consume_sym("{");

  when_clauses = NodeList_new();

  while (1) {
    when_clause = parse_when_clause();
    if (when_clause == NULL) {
      break;
    }

    NodeList_add_list_item(when_clauses, when_clause);
  }

  consume_sym("}");

  list = NodeList_new();
  NodeList_add_str_item(list, "case");
  NodeList_add_all(list, when_clauses);
  return list;
}

NodeList* parse_vm_comment() {
  NodeList* list;
  char* comment;
  Token* t;

  consume_kw("_cmt");
  consume_sym("(");

  t = peek(0);
  g_pos++;
  comment = t->str;

  consume_sym(")");
  consume_sym(";");

  list = NodeList_new();
  NodeList_add_str_item(list, "_cmt");
  NodeList_add_str_item(list, comment);
  return list;
}

NodeList* parse_stmt() {
  Token* t = peek(0);

  if (Token_is(t, TOKEN_SYM, "}")) {
    return NULL;
  }

  if (Token_str_eq(t, "func")) {
    return parse_func();
  } else if (Token_str_eq(t, "var")) {
    return parse_var();
  } else if (Token_str_eq(t, "set")) {
    return parse_set();
  } else if (Token_str_eq(t, "call")) {
    return parse_call();
  } else if (Token_str_eq(t, "call_set")) {
    return parse_call_set();
  } else if (Token_str_eq(t, "return")) {
    return parse_return();
  } else if (Token_str_eq(t, "while")) {
    return parse_while();
  } else if (Token_str_eq(t, "case")) {
    return parse_case();
  } else if (Token_str_eq(t, "_cmt")) {
    return parse_vm_comment();
  } else {
    not_yet_impl("parse_stmt", __LINE__);
    exit(1);
  }
}

NodeList* parse_stmts() {
  NodeList* stmts = NodeList_new();

  puts_fn("-->> parse_stmts");

  while (1) {
    if (is_end()) {
      break;
    }

    NodeList* stmt = parse_stmt();
    if (stmt == NULL) {
      break;
    }

    NodeItem* list_wrapper = NodeItem_new(NODE_LIST);
    list_wrapper->list = stmt;
    NodeList_add_item(stmts, list_wrapper);
  }

  return stmts;
}

NodeItem* parse_top_stmts() {
  NodeItem* root_item = NodeItem_new(NODE_LIST);
  NodeList* stmts = NodeList_new();

  NodeList_add_str_item(stmts, "stmts");

  {
    NodeList* main_fn;

    main_fn = NodeList_new();

    NodeList_add_str_item(main_fn, "func");
    NodeList_add_str_item(main_fn, "main");

    NodeList_add_list_item(main_fn, NodeList_empty());
    NodeList_add_list_item(main_fn, NodeList_empty());

    NodeList_add_list_item(stmts, main_fn);
  }

  NodeItem_set_list(root_item, stmts);

  return root_item;
}

NodeItem* parse() {
  NodeItem* list_wrapper;
  NodeList* list;
  NodeList* stmts;

  stmts = parse_stmts();

  list = NodeList_new();
  NodeList_add_str_item(list, "stmts");
  for (int i = 0; i < stmts->len; i++) {
    NodeList_add_item(list, NodeList_get(stmts, i));
  }

  list_wrapper = NodeItem_new(NODE_LIST);
  list_wrapper->list = list;
  return list_wrapper;
}

void print_node_item(NodeItem* item, int lv);

void print_indent_space(int lv) {
  for (int i = 0; i < lv; i++) {
    printf("  ");
  }
}

int main(void) {
  char input[INPUT_SIZE];
  NodeItem* tree;
  Token t;

  read_stdin_all(input);

  read_tokens(input);

  if (0) {
    for (int i = 0; i < g_num_tokens; i++) {
      t = g_tokens[i];
      fprintf(
        stderr,
        "  kind(%s) str<%s>\n",
        TokenKind_to_str(t.kind),
        t.str
      );
    }
  }

  tree = parse();

  print_as_json(tree->list);

  return 0;
}
