%{
// Prologue

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

NodeList* g_ast;

// int yylex(YYSTYPE *yylval, YYLTYPE *loc);
// void yyerror(YYLTYPE *yylloc, const char *msg);

%}

%union {
  NodeList* union_list;
  NodeItem* union_node;
  char* union_str;
}

// terminal symbols
%token<union_str> TS_IDENT TS_INT TS_STR
%token<union_str> TS_SYM TS_SCOLON TS_PAREN_L TS_PAREN_R
%token<union_str> TS_BIN_OP
%token<union_str> TS_PLUS TS_MULT
%token<union_str> TS_KW_FUNC
%token<union_str> TS_KW_VAR TS_KW_SET TS_KW_CALL TS_KW_CALL_SET TS_KW_RETURN TS_KW_WHILE TS_KW_CASE TS_KW_WHEN
%token<union_str> TS_KW_CMT TS_KW_DEBUG

// non-terminal symbols
%type<union_list> program top_stmts top_stmt func_def args stmts
%type<union_list> stmt stmt_var stmt_set stmt_return stmt_call stmt_call_set
%type<union_list> stmt_while stmt_case when_clauses when_clause
%type<union_list> stmt_vm_comment stmt_debug
%type<union_node> expr arg

// assoc / prec
%left TS_PLUS TS_MULT

%%

program         : top_stmts
                    {
                        NodeList* ast = NodeList_new();
                        NodeList_add_str(ast, "top_stmts");
                        NodeList_add_all(ast, $1);

                        g_ast = ast;
                    }

top_stmts       :
                    {
                        NodeList* top_stmts = NodeList_new();
                        $$ = top_stmts;
                    }
                | top_stmt
                    {
                        NodeList* top_stmts = NodeList_new();
                        NodeList_add_list(top_stmts, $1);

                        $$ = top_stmts;
                    }
                | top_stmts top_stmt
                    {
                        NodeList* top_stmts = $1;
                        NodeList_add_list(top_stmts, $2);

                        $$ = top_stmts;
                    }

top_stmt        : func_def

func_def        : TS_KW_FUNC TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SYM stmts TS_SYM
                // func      ident    (          args )          {      stmts }
                    {
                        NodeList* func_def = NodeList_new();
                        NodeList_add_str(func_def, "func");
                        NodeList_add_str(func_def, $2);
                        NodeList_add_list(func_def, $4);
                        NodeList_add_list(func_def, $7);

                        $$ = func_def;
                    }

args            :
                    {
                        NodeList* args = NodeList_new();
                        $$ = args;
                    }
                | arg
                    {
                        NodeList* args = NodeList_new();
                        NodeList_add_node(args, $1);
                        $$ = args;
                    }
                | args TS_SYM arg
                    {
                        NodeList* args = $1;
                        NodeList_add_node(args, $3);
                        $$ = args;
                    }

arg             : TS_IDENT
                    {
                        NodeItem* arg = NodeItem_new_str($1);
                        $$ = arg;
                    }
                | TS_INT
                    {
                        int n = s_to_i($1);
                        NodeItem* arg = NodeItem_new_int(n);
                        $$ = arg;
                    }

stmts           :
                    {
                        NodeList* stmts = NodeList_new();
                        $$ = stmts;
                    }
                | stmt
                    {
                        NodeList* stmts = NodeList_new();
                        NodeList_add_list(stmts, $1);

                        $$ = stmts;
                    }
                | stmts stmt
                    {
                        NodeList* stmts = $1;
                        NodeList_add_list(stmts, $2);

                        $$ = stmts;
                    }

stmt            : stmt_return
                | stmt_var
                | stmt_set
                | stmt_call
                | stmt_call_set
                | stmt_while
                | stmt_case
                | stmt_vm_comment
                | stmt_debug

stmt_var        : TS_KW_VAR TS_IDENT TS_SCOLON
                // var      a        ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "var");
                        NodeList_add_str(stmt, $2);

                        $$ = stmt;
                    }
                | TS_KW_VAR TS_IDENT TS_SYM expr TS_SCOLON
                // var      a        =      1    ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "var");
                        NodeList_add_str(stmt, $2);
                        NodeList_add_node(stmt, $4);

                        $$ = stmt;
                    }

stmt_set        : TS_KW_SET TS_IDENT TS_SYM expr TS_SCOLON
                // set      a        =      1    ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "set");
                        NodeList_add_str(stmt, $2);
                        NodeList_add_node(stmt, $4);

                        $$ = stmt;
                    }

stmt_return     : TS_KW_RETURN expr TS_SCOLON
                // return      expr ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "return");
                        NodeList_add_node(stmt, $2);

                        $$ = stmt;
                    }

stmt_call       : TS_KW_CALL TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SCOLON
                // call      IDENT    (          args )          ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "call");
                        NodeList_add_str(stmt, $2);
                        NodeList_add_all(stmt, $4);

                        $$ = stmt;
                    }

stmt_call_set   : TS_KW_CALL_SET TS_IDENT TS_SYM TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SCOLON
                // call_set      a        =      f        (          args )          ;
                    {
                        NodeList* funcall = NodeList_new();
                        NodeList_add_str(funcall, $4);
                        NodeList_add_all(funcall, $6);

                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "call_set");
                        NodeList_add_str(stmt, $2);
                        NodeList_add_list(stmt, funcall);

                        $$ = stmt;
                    }

stmt_while      : TS_KW_WHILE TS_PAREN_L expr TS_PAREN_R TS_SYM stmts TS_SYM
                // while      (          expr )          {      stmts }
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "while");
                        NodeList_add_node(stmt, $3);
                        NodeList_add_list(stmt, $6);

                        $$ = stmt;
                    }

stmt_case       : TS_KW_CASE when_clauses
                // case      when_clauses
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "case");
                        NodeList_add_all(stmt, $2);

                        $$ = stmt;
                    }

when_clauses    : when_clause
                    {
                        NodeList* when_clauses = NodeList_new();
                        NodeList_add_list(when_clauses, $1);
                        $$ = when_clauses;
                    }
                | when_clauses when_clause
                    {
                        NodeList* when_clauses = $1;
                        NodeList_add_list(when_clauses, $2);
                        $$ = when_clauses;
                    }

when_clause     : TS_KW_WHEN TS_PAREN_L expr TS_PAREN_R TS_SYM stmts TS_SYM
                // when      (          expr )          {      stmts }
                    {
                        NodeList* when_clause = NodeList_new();
                        NodeList_add_node(when_clause, $3);
                        NodeList_add_all(when_clause, $6);
                        $$ = when_clause;
                    }

stmt_vm_comment : TS_KW_CMT TS_PAREN_L TS_STR TS_PAREN_R TS_SCOLON
                // _cmt     (          "fdsa" )          ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "_cmt");
                        NodeList_add_str(stmt, $3);

                        $$ = stmt;
                    }

stmt_debug      : TS_KW_DEBUG TS_PAREN_L TS_PAREN_R TS_SCOLON
                // _debug     (          )          ;
                    {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "_debug");

                        $$ = stmt;
                    }

expr            : TS_INT
                    {
                        int n = s_to_i($1);
                        $$ = NodeItem_new_int(n);
                    }
                | TS_IDENT
                    {
                        $$ = NodeItem_new_str($1);
                    }
                | expr TS_PLUS expr
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, "+");
                        NodeList_add_node(xs, $1);
                        NodeList_add_node(xs, $3);

                        $$ = NodeItem_new_list(xs);
                    }
                | expr TS_MULT expr
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, "*");
                        NodeList_add_node(xs, $1);
                        NodeList_add_node(xs, $3);

                        $$ = NodeItem_new_list(xs);
                    }
                | expr TS_BIN_OP expr
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, $2); // ==, !=
                        NodeList_add_node(xs, $1);
                        NodeList_add_node(xs, $3);

                        $$ = NodeItem_new_list(xs);
                    }
                | TS_PAREN_L expr TS_PAREN_R
                // (         expr )
                    {
                      $$ = $2;
                    }

%%

// Epilogue

int get_line_size(char* text, int pos) {
  int i = find_index(text, '\n', pos);
  if (0 <= i) {
    return i - pos + 1;
  } else {
    return strlen(text) - pos;
  }
}

void read_tokens(char* input) {
  int src_size;
  int pos = 0;
  int line_size;
  char line[256];
  int ti = 0;
  NodeList* token;

  src_size = strlen(input);

  while (pos < src_size) {
    line_size = get_line_size(input, pos);
    substring(line, input, pos, pos + line_size);

    token = parse_json(line);

    g_tokens[ti].lineno = NodeList_get(token, 0)->int_val;
    g_tokens[ti].kind = TokenKind_from_str(NodeList_get(token, 1)->str_val);
    strcpy(g_tokens[ti].str, NodeList_get(token, 2)->str_val);

    ti++;
    if (NUM_TOKENS <= ti) {
      _err_exit("too many tokens", __FILE__, __LINE__);
    }

    pos += line_size;
  }

  g_num_tokens = ti;
}

int token_to_symbol(Token* t) {
  char* str = t->str;

  switch (t->kind) {
  case TOKEN_KW:
    if (str_eq(str, "func")) {
      return TS_KW_FUNC;
    } else if (str_eq(str, "var")) {
      return TS_KW_VAR;
    } else if (str_eq(str, "set")) {
      return TS_KW_SET;
    } else if (str_eq(str, "call")) {
      return TS_KW_CALL;
    } else if (str_eq(str, "call_set")) {
      return TS_KW_CALL_SET;
    } else if (str_eq(str, "return")) {
      return TS_KW_RETURN;
    } else if (str_eq(str, "while")) {
      return TS_KW_WHILE;
    } else if (str_eq(str, "case")) {
      return TS_KW_CASE;
    } else if (str_eq(str, "when")) {
      return TS_KW_WHEN;
    } else if (str_eq(str, "_cmt")) {
      return TS_KW_CMT;
    } else if (str_eq(str, "_debug")) {
      return TS_KW_DEBUG;
    } else {
      fprintf(stderr, "unsupported keyword\n");
      exit(1);
    }
  case TOKEN_IDENT:
    return TS_IDENT;
  case TOKEN_SYM:
    if (str_eq(str, ";")) {
      return TS_SCOLON;
    } else if (str_eq(str, "(")) {
      return TS_PAREN_L;
    } else if (str_eq(str, ")")) {
      return TS_PAREN_R;
    } else if (str_eq(str, "+")) {
      return TS_PLUS;
    } else if (str_eq(str, "*")) {
      return TS_MULT;
    } else if (str_eq(str, "==")) {
      return TS_BIN_OP;
    } else if (str_eq(str, "!=")) {
      return TS_BIN_OP;
    } else {
      return TS_SYM; // 手抜き
    }
  case TOKEN_INT:
    return TS_INT;
  case TOKEN_STR:
    return TS_STR;
  default:
    fprintf(stderr, "unsupported token kind\n");
    exit(1);
  }
}

int yylex(YYSTYPE *yylval, YYLTYPE *loc) {
  Token* t;

  // fprintf(stderr, "yylex: g_pos (%d)  ", g_pos);

  if (g_num_tokens <= g_pos) {
    // fprintf(stderr, "end of tokens\n");
    return 0;
  }

  t = g_tokens + g_pos;
  // fprintf(stderr, "yylex: %s (%s)\n", TokenKind_to_str(t->kind), t->str);

  g_pos++;

  // 値は yylval にセットする
  yylval->union_str = t->str;

  // 返り値は記号
  return token_to_symbol(t);
}

void yyerror(YYLTYPE *yylloc, const char *msg) {
  fprintf(stderr, "yyerror\n");
  exit(1);
}

int main() {
  char input[INPUT_SIZE];

  read_stdin_all(input, INPUT_SIZE);
  read_tokens(input);

  // fprintf(stderr, "-->> yyparse\n");
  yyparse();

  print_as_json(g_ast, 1);

  return 0;
}
