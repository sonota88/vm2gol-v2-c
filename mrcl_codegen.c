#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/utils.h"
#include "lib/types.h"
#include "lib/json.h"

#define INPUT_SIZE (1024 * 20)
#define HEAD_SIZE 1024

static int g_label_id = 0;
static int g_is_debug = 0;

void gen_vm_comment(char* comment);
void gen_set(  Names* fn_arg_names, Names* lvar_names, NodeList* rest );
void gen_stmts(Names* fn_arg_names, Names* lvar_names, NodeList* stmts);
void _gen_expr_binary( Names* fn_arg_names, Names* lvar_names, NodeItem* expr );
void gen_expr( Names* fn_arg_names, Names* lvar_names, NodeItem* expr );

// --------------------------------

static void not_yet_impl(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

static void gen_error(char* msg, int ln) {
  _err_exit(msg, __FILE__, ln);
}

static void puts_fn(char* str) {
  if (g_is_debug) {
    puts_e(str);
  }
}

// --------------------------------

int get_label_id() {
  g_label_id++;
  return g_label_id;
}

int to_fn_arg_disp(Names* names, char* name) {
  int i = Names_index(names, name);
  if (i < 0) {
    Names_dump(names);
    fprintf(stderr, "name (%s)\n", name);
    gen_error("to_fn_arg_disp", __LINE__);
  }
  return i + 2;
}

int to_lvar_disp(Names* names, char* name) {
  int i = Names_index(names, name);
  if (i < 0) {
    Names_dump(names);
    fprintf(stderr, "name (%s)\n", name);
    gen_error("to_lvar_disp", __LINE__);
  }
  return -(i + 1);
}

int is_number(char* str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if ( '0' <= str[i] && str[i] <= '9' ) {
      ;
    } else {
      return 0;
    }
  }
  return 1;
}

void asm_prologue() {
  printf("  push bp\n");
  printf("  cp sp bp\n");
}

void asm_epilogue() {
  printf("  cp bp sp\n");
  printf("  pop bp\n");
}

// --------------------------------

void gen_expr_add() {
  printf("  pop reg_b\n");
  printf("  pop reg_a\n");
  printf("  add_ab\n");
}

void gen_expr_mult() {
  printf("  pop reg_b\n");
  printf("  pop reg_a\n");
  printf("  mult_ab\n");
}

void gen_expr_eq() {
  int label_id;
  char then_label[16];
  char end_label[16];

  label_id = get_label_id();

  sprintf(then_label, "then_%d", label_id);
  sprintf(end_label, "end_eq_%d", label_id);

  printf("  pop reg_b\n");
  printf("  pop reg_a\n");

  printf("  compare\n");
  printf("  jump_eq %s\n", then_label);

  printf("  cp 0 reg_a\n");
  printf("  jump %s\n", end_label);

  printf("label %s\n", then_label);
  printf("  cp 1 reg_a\n");
  printf("label %s\n", end_label);
}

void gen_expr_neq() {
  int label_id;
  char then_label[16];
  char end_label[16];

  label_id = get_label_id();

  sprintf(then_label, "then_%d", label_id);
  sprintf(end_label, "end_neq_%d", label_id);

  printf("  pop reg_b\n");
  printf("  pop reg_a\n");

  printf("  compare\n");
  printf("  jump_eq %s\n", then_label);

  printf("  cp 1 reg_a\n");
  printf("  jump %s\n", end_label);

  printf("label %s\n", then_label);
  printf("  cp 0 reg_a\n");
  printf("label %s\n", end_label);
}

void _gen_expr_binary(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeItem* expr
) {
  NodeItem* operator;
  NodeList* args;
  NodeItem* term_l;
  NodeItem* term_r;

  puts_fn("-->> _gen_expr_binary");

  operator = NodeList_head(expr->list);
  args     = NodeList_rest(expr->list);

  term_l = NodeList_get(args, 0);
  term_r = NodeList_get(args, 1);

  gen_expr(fn_arg_names, lvar_names, term_l);
  printf("  push reg_a\n");
  gen_expr(fn_arg_names, lvar_names, term_r);
  printf("  push reg_a\n");

  if (NodeItem_str_eq(operator, "+")) {
    gen_expr_add();
  } else if (NodeItem_str_eq(operator, "*")) {
    gen_expr_mult();
  } else if (NodeItem_str_eq(operator, "==")) {
    gen_expr_eq();
  } else if (NodeItem_str_eq(operator, "neq")) {
    gen_expr_neq();
  } else {
    not_yet_impl("_gen_expr_binary", __LINE__);
  }
}

void gen_expr(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeItem* val
) {
  char push_arg[16];
  int disp;

  puts_fn("-->> gen_expr");

  if (val->kind == NODE_INT) {
    printf("  cp %d reg_a\n", val->int_val);
  } else if (val->kind == NODE_STR) {

    if (Names_contains(fn_arg_names, val->str_val)) {
      disp = to_fn_arg_disp(fn_arg_names, val->str_val);
      printf("  cp [bp:%d] reg_a\n", disp);

    } else if (Names_contains(lvar_names, val->str_val)) {
      disp = to_lvar_disp(lvar_names, val->str_val);
      printf("  cp [bp:%d] reg_a\n", disp);

    } else {
      not_yet_impl("gen_expr", __LINE__);
    }

  } else if (val->kind == NODE_LIST) {
    _gen_expr_binary(fn_arg_names, lvar_names, val);
    strcpy(push_arg, "reg_a");
  } else {
    not_yet_impl("gen_expr", __LINE__);
  }
}

void gen_call(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt_rest
) {
  char* fn_name;
  NodeList* fn_args;
  char vm_comment[256];
  NodeItem* fn_arg;

  fn_name = NodeList_head(stmt_rest)->str_val;
  fn_args = NodeList_rest(stmt_rest);

  // NodeList_dump(fn_args);
  for (int i = NodeList_len(fn_args) - 1; i >= 0; i--) {
    fn_arg = NodeList_get(fn_args, i);
    gen_expr(fn_arg_names, lvar_names, fn_arg);
    printf("  push reg_a\n");
  }

  sprintf(vm_comment, "call  %s", fn_name);
  gen_vm_comment(vm_comment);
  printf("  call %s\n", fn_name);

  printf("  add_sp %d\n", NodeList_len(fn_args));
}

void gen_call_set(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt_rest
) {
  char lvar_name[64];
  NodeList* funcall;
  int disp;
  
  strcpy(lvar_name, NodeList_head(stmt_rest)->str_val);
  funcall = NodeList_get(stmt_rest, 1)->list ;

  gen_call(fn_arg_names, lvar_names, funcall);

  disp = to_lvar_disp(lvar_names, lvar_name);
  printf("  cp reg_a [bp:%d]\n", disp);
}

void gen_set(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* rest
) {
  NodeItem* dest = NodeList_get(rest, 0);
  NodeItem* expr = NodeList_get(rest, 1);
  char dest_str[64];
  int disp;

  // NodeList_dump(rest);

  puts_fn("-->> gen_set");
  // NodeItem_dump(expr);

  // Names_dump(lvar_names);

  gen_expr(fn_arg_names, lvar_names, expr);

  strcpy(dest_str, dest->str_val);

  if (Names_contains(lvar_names, dest_str)) {
    disp = to_lvar_disp(lvar_names, dest_str);
    printf("  cp reg_a [bp:%d]\n", disp);
  } else {
    not_yet_impl("gen_set", __LINE__);
  }
}

void gen_return(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt_rest
) {
  NodeItem* retval = NodeList_head(stmt_rest);

  gen_expr(fn_arg_names, lvar_names, retval);
}

void gen_vm_comment(
  char* comment
) {
  char temp[256];
  int i;
  for (i = 0; i < strlen(comment); i++) {
    if (comment[i] == ' ') {
      temp[i] = '~';
    } else {
      temp[i] = comment[i];
    }
  }
  temp[i] = '\0';
  printf("  _cmt %s\n", temp);
}

void gen_while(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt_rest
) {
  NodeItem* cond_expr;
  NodeList* body;
  int label_id;

  puts_fn("-->> gen_while");

  cond_expr = NodeList_head(stmt_rest);
  body = NodeList_get(stmt_rest, 1)->list;

  label_id = get_label_id();

  printf("\n");

  printf("label while_%d\n", label_id);

  gen_expr(fn_arg_names, lvar_names, cond_expr);
  printf("  cp 0 reg_b\n");
  printf("  compare\n");

  printf("  jump_eq end_while_%d\n", label_id);

  gen_stmts(fn_arg_names, lvar_names, body);

  printf("  jump while_%d\n", label_id);

  printf("label end_while_%d\n", label_id);
  printf("\n");
}

void gen_case(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* when_clauses
) {
  int label_id;
  int when_idx = -1;
  NodeList* when_clause;
  NodeItem* cond;
  NodeList* rest;
  char cond_json[512];

  label_id = get_label_id();

  printf("\n");
  printf("  # -->> case_%d\n", label_id);

  for (int i = 0; i < NodeList_len(when_clauses); i++) {
    when_clause = NodeList_get(when_clauses, i)->list;
    when_idx++;

    cond = NodeList_head(when_clause);
    rest = NodeList_rest(when_clause);

    to_json_line(cond_json, cond);
    printf("  # when_%d_%d: %s\n",
           label_id, when_idx, cond_json
           );

    printf("  # -->> expr\n");
    gen_expr(fn_arg_names, lvar_names, cond);
    printf("  # <<-- expr\n");
    printf("  cp 0 reg_b\n");

    printf("  compare\n");
    printf("  jump_eq end_when_%d_%d\n", label_id, when_idx);

    gen_stmts(fn_arg_names, lvar_names, rest);      

    printf("  jump end_case_%d\n", label_id);

    // 偽の場合ここにジャンプ
    printf("label end_when_%d_%d\n", label_id, when_idx);
  }

  printf("label end_case_%d\n", label_id);
  printf("  # <<-- case_%d\n", label_id);
  printf("\n");
}

void gen_stmt(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt
) {
  NodeItem* stmt_head = NodeList_head(stmt);
  NodeList* stmt_rest = NodeList_rest(stmt);

  if (g_is_debug) {
    fprintf(stderr, "-->> gen_stmt (%s)\n", stmt_head->str_val);
  }

  if (str_eq(stmt_head->str_val, "set")) {
    gen_set(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "call")) {
    gen_call(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "call_set")) {
    gen_call_set(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "return")) {
    gen_return(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "while")) {
    gen_while(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "case")) {
    gen_case(fn_arg_names, lvar_names, stmt_rest);
  } else if (str_eq(stmt_head->str_val, "_cmt")) {
    gen_vm_comment(NodeList_head(stmt_rest)->str_val);
  } else {
    not_yet_impl("gen_stmt", __LINE__);
  }
}

void gen_stmts(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmts
) {
  NodeList* stmt;

  puts_fn("-->> gen_stmts");

  for (int i = 0; i < NodeList_len(stmts); i++) {
    stmt = NodeList_get(stmts, i)->list;
    gen_stmt(fn_arg_names, lvar_names, stmt);
  }
}

void gen_var(
  Names* fn_arg_names,
  Names* lvar_names,
  NodeList* stmt_rest
) {
  printf("  sub_sp 1\n");

  if (NodeList_len(stmt_rest) == 2) {
    gen_set(fn_arg_names, lvar_names, stmt_rest);
  }
}

void gen_func_def(NodeList* rest) {
  char* fn_name;
  Names* fn_arg_names;
  NodeList* body;
  Names* lvar_names;
  NodeList* stmt;
  NodeList* stmt_rest;
  NodeItem* var_name;

  puts_fn("-->> gen_func_def");

  fn_name = NodeList_get(rest, 0)->str_val;
  fn_arg_names = Names_from_node_list(NodeList_get(rest, 1)->list);
  body = NodeList_get(rest, 2)->list;

  if (g_is_debug) {
    fprintf(stderr, "fn_name (%s)", fn_name);
  }

  printf("\n");
  printf("label %s\n", fn_name);
  asm_prologue();

  printf("\n");
  printf("  # 関数の処理本体\n");

  lvar_names = Names_new();

  for (int i = 0; i < NodeList_len(body); i++) {
    stmt = NodeList_get(body, i)->list;

    stmt_rest = NodeList_rest(stmt);

    if (
      str_eq(
        NodeList_head(stmt)->str_val,
        "var"
      )
    ) {
      var_name = NodeList_head(stmt_rest);
      Names_add(lvar_names, var_name->str_val);
      gen_var(fn_arg_names, lvar_names, stmt_rest);
    } else {
      gen_stmt(fn_arg_names, lvar_names, stmt);
    }
  }

  printf("\n");
  asm_epilogue();
  printf("  ret\n");
}

void gen_top_stmts(NodeList* list) {
  NodeItem* item;
  NodeItem* stmt_head;
  NodeList* stmt_rest;

  for (int i = 0; i < NodeList_len(list); i++) {
    item = NodeList_get(list, i);

    stmt_head = NodeList_head(item->list);
    stmt_rest = NodeList_rest(item->list);

    if (str_eq(stmt_head->str_val, "func")) {
      gen_func_def(stmt_rest);
    } else {
      not_yet_impl("gen_top_stmts", __LINE__);
    }
  }
}

void gen_builtin_set_vram() {
  printf("\n");
  printf("label set_vram\n");
  asm_prologue();

  printf("  set_vram [bp:2] [bp:3]\n"); // vram_addr value

  asm_epilogue();
  printf("  ret\n");
}

void gen_builtin_get_vram() {
  printf("\n");
  printf("label get_vram\n");
  asm_prologue();

  printf("  get_vram [bp:2] reg_a\n"); // vram_addr dest

  asm_epilogue();
  printf("  ret\n");
}

int main(void) {
  char input[INPUT_SIZE];

  read_stdin_all(input, INPUT_SIZE);

  NodeList* tree = parse_json(input);

  printf("  call main\n");
  printf("  exit\n");

  NodeList* top_stmts = NodeList_rest(tree);
  gen_top_stmts(top_stmts);

  printf("#>builtins\n");
  gen_builtin_set_vram();
  gen_builtin_get_vram();
  printf("#<builtins\n");

  return 0;
}
