/* A Bison parser, made by Lrama 0.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mrcl_parser_lrama.y"

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


#line 96 "mrcl_parser_lrama.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TS_IDENT = 258,                /* TS_IDENT  */
    TS_INT = 259,                  /* TS_INT  */
    TS_STR = 260,                  /* TS_STR  */
    TS_SYM = 261,                  /* TS_SYM  */
    TS_SCOLON = 262,               /* TS_SCOLON  */
    TS_PAREN_L = 263,              /* TS_PAREN_L  */
    TS_PAREN_R = 264,              /* TS_PAREN_R  */
    TS_BIN_OP = 265,               /* TS_BIN_OP  */
    TS_PLUS = 266,                 /* TS_PLUS  */
    TS_MULT = 267,                 /* TS_MULT  */
    TS_KW_FUNC = 268,              /* TS_KW_FUNC  */
    TS_KW_VAR = 269,               /* TS_KW_VAR  */
    TS_KW_SET = 270,               /* TS_KW_SET  */
    TS_KW_CALL = 271,              /* TS_KW_CALL  */
    TS_KW_CALL_SET = 272,          /* TS_KW_CALL_SET  */
    TS_KW_RETURN = 273,            /* TS_KW_RETURN  */
    TS_KW_WHILE = 274,             /* TS_KW_WHILE  */
    TS_KW_CASE = 275,              /* TS_KW_CASE  */
    TS_KW_WHEN = 276,              /* TS_KW_WHEN  */
    TS_KW_CMT = 277,               /* TS_KW_CMT  */
    TS_KW_DEBUG = 278              /* TS_KW_DEBUG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "mrcl_parser_lrama.y"

  NodeList* union_list;
  NodeItem* union_node;
  char* union_str;

#line 173 "mrcl_parser_lrama.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse ();


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TS_IDENT = 3,                   /* TS_IDENT  */
  YYSYMBOL_TS_INT = 4,                     /* TS_INT  */
  YYSYMBOL_TS_STR = 5,                     /* TS_STR  */
  YYSYMBOL_TS_SYM = 6,                     /* TS_SYM  */
  YYSYMBOL_TS_SCOLON = 7,                  /* TS_SCOLON  */
  YYSYMBOL_TS_PAREN_L = 8,                 /* TS_PAREN_L  */
  YYSYMBOL_TS_PAREN_R = 9,                 /* TS_PAREN_R  */
  YYSYMBOL_TS_BIN_OP = 10,                 /* TS_BIN_OP  */
  YYSYMBOL_TS_PLUS = 11,                   /* TS_PLUS  */
  YYSYMBOL_TS_MULT = 12,                   /* TS_MULT  */
  YYSYMBOL_TS_KW_FUNC = 13,                /* TS_KW_FUNC  */
  YYSYMBOL_TS_KW_VAR = 14,                 /* TS_KW_VAR  */
  YYSYMBOL_TS_KW_SET = 15,                 /* TS_KW_SET  */
  YYSYMBOL_TS_KW_CALL = 16,                /* TS_KW_CALL  */
  YYSYMBOL_TS_KW_CALL_SET = 17,            /* TS_KW_CALL_SET  */
  YYSYMBOL_TS_KW_RETURN = 18,              /* TS_KW_RETURN  */
  YYSYMBOL_TS_KW_WHILE = 19,               /* TS_KW_WHILE  */
  YYSYMBOL_TS_KW_CASE = 20,                /* TS_KW_CASE  */
  YYSYMBOL_TS_KW_WHEN = 21,                /* TS_KW_WHEN  */
  YYSYMBOL_TS_KW_CMT = 22,                 /* TS_KW_CMT  */
  YYSYMBOL_TS_KW_DEBUG = 23,               /* TS_KW_DEBUG  */
  YYSYMBOL_YYACCEPT = 24,                  /* $accept  */
  YYSYMBOL_program = 25,                   /* program  */
  YYSYMBOL_top_stmts = 26,                 /* top_stmts  */
  YYSYMBOL_top_stmt = 27,                  /* top_stmt  */
  YYSYMBOL_func_def = 28,                  /* func_def  */
  YYSYMBOL_args = 29,                      /* args  */
  YYSYMBOL_arg = 30,                       /* arg  */
  YYSYMBOL_stmts = 31,                     /* stmts  */
  YYSYMBOL_stmt = 32,                      /* stmt  */
  YYSYMBOL_stmt_var = 33,                  /* stmt_var  */
  YYSYMBOL_stmt_set = 34,                  /* stmt_set  */
  YYSYMBOL_stmt_return = 35,               /* stmt_return  */
  YYSYMBOL_stmt_call = 36,                 /* stmt_call  */
  YYSYMBOL_stmt_call_set = 37,             /* stmt_call_set  */
  YYSYMBOL_stmt_while = 38,                /* stmt_while  */
  YYSYMBOL_stmt_case = 39,                 /* stmt_case  */
  YYSYMBOL_when_clauses = 40,              /* when_clauses  */
  YYSYMBOL_when_clause = 41,               /* when_clause  */
  YYSYMBOL_stmt_vm_comment = 42,           /* stmt_vm_comment  */
  YYSYMBOL_stmt_debug = 43,                /* stmt_debug  */
  YYSYMBOL_expr = 44                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    63,    67,    74,    82,    84,    97,   101,
     107,   114,   119,   127,   131,   138,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   156,   165,   176,   187,   197,
     208,   223,   234,   244,   250,   257,   266,   276,   285,   290,
     294,   303,   312,   321
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TS_IDENT", "TS_INT",
  "TS_STR", "TS_SYM", "TS_SCOLON", "TS_PAREN_L", "TS_PAREN_R", "TS_BIN_OP",
  "TS_PLUS", "TS_MULT", "TS_KW_FUNC", "TS_KW_VAR", "TS_KW_SET",
  "TS_KW_CALL", "TS_KW_CALL_SET", "TS_KW_RETURN", "TS_KW_WHILE",
  "TS_KW_CASE", "TS_KW_WHEN", "TS_KW_CMT", "TS_KW_DEBUG", "$accept",
  "program", "top_stmts", "top_stmt", "func_def", "args", "arg", "stmts",
  "stmt", "stmt_var", "stmt_set", "stmt_return", "stmt_call",
  "stmt_call_set", "stmt_while", "stmt_case", "when_clauses",
  "when_clause", "stmt_vm_comment", "stmt_debug", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    14,     6,    27,   -81,   -81,    21,   -81,   -81,    61,
     -81,   -81,     1,   -81,    61,    53,   -81,    16,    59,    63,
      75,    87,     5,   111,    73,   115,   116,    31,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   106,    94,
     117,   100,   -81,   -81,     5,    45,     5,   118,    73,   -81,
     113,   119,   -81,   -81,     5,   -81,     5,    61,   124,    15,
     -81,     5,     5,     5,    32,     5,   -81,   120,   123,   104,
     110,     9,   125,   -81,    86,    92,    98,   126,    70,   127,
     -81,   -81,   -81,   128,    61,    16,   130,   -81,   -81,    52,
      54,    16,   131,   -81,    69,   -81,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     6,     0,     1,     5,     8,
      11,    12,     0,     9,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    17,
      18,    16,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,    39,    38,     0,     0,     0,     0,    32,    33,
       0,     0,     7,    15,     0,    25,     0,     8,     0,     0,
      28,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
      37,    26,    27,     0,     8,     0,     0,    36,    29,     0,
       0,     0,     0,    31,     0,    30,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   134,   -81,   -56,   129,   -80,   -27,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    83,   -81,   -81,
     -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    12,    13,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    48,    49,    36,    37,
      45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      53,    71,    59,    -3,    64,    90,     7,    14,    42,    43,
      15,    94,    69,    44,    70,    14,     1,     6,    83,    74,
      75,    76,   -13,    78,    73,    61,    62,    63,    89,     9,
      18,    19,    20,    21,    22,    23,    24,    52,    25,    26,
       1,    77,    61,    62,    63,    18,    19,    20,    21,    22,
      23,    24,    60,    25,    26,    61,    62,    63,    14,    17,
      93,    92,    38,    53,    10,    11,    39,    53,    18,    19,
      20,    21,    22,    23,    24,    96,    25,    26,    40,    86,
      61,    62,    63,    18,    19,    20,    21,    22,    23,    24,
      41,    25,    26,   -42,    47,   -42,    61,    62,    63,   -40,
      56,   -40,    61,   -40,   -40,   -41,    58,   -41,    61,   -41,
     -41,    81,    54,    55,    61,    62,    63,    82,    67,    46,
      61,    62,    63,    50,    51,    57,    65,    72,    68,    79,
      80,    66,    85,    84,    87,    88,    91,     8,    95,     0,
       0,     0,     0,    16
};

static const yytype_int8 yycheck[] =
{
      27,    57,    44,     0,    46,    85,     0,     6,     3,     4,
       9,    91,    54,     8,    56,     6,    13,     3,     9,    61,
      62,    63,     6,    65,     9,    10,    11,    12,    84,     8,
      14,    15,    16,    17,    18,    19,    20,     6,    22,    23,
      13,     9,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,     7,    22,    23,    10,    11,    12,     6,     6,
       6,     9,     3,    90,     3,     4,     3,    94,    14,    15,
      16,    17,    18,    19,    20,     6,    22,    23,     3,     9,
      10,    11,    12,    14,    15,    16,    17,    18,    19,    20,
       3,    22,    23,     7,    21,     9,    10,    11,    12,     7,
       6,     9,    10,    11,    12,     7,     6,     9,    10,    11,
      12,     7,     6,     7,    10,    11,    12,     7,     5,     8,
      10,    11,    12,     8,     8,     8,     8,     3,     9,     9,
       7,    48,     6,     8,     7,     7,     6,     3,     7,    -1,
      -1,    -1,    -1,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    25,    26,    27,    28,     3,     0,    27,     8,
       3,     4,    29,    30,     6,     9,    30,     6,    14,    15,
      16,    17,    18,    19,    20,    22,    23,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    42,    43,     3,     3,
       3,     3,     3,     4,     8,    44,     8,    21,    40,    41,
       8,     8,     6,    32,     6,     7,     6,     8,     6,    44,
       7,    10,    11,    12,    44,     8,    41,     5,     9,    44,
      44,    29,     3,     9,    44,    44,    44,     9,    44,     9,
       7,     7,     7,     9,     8,     6,     9,     7,     7,    29,
      31,     6,     9,     6,    31,     7,     6
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    24,    25,    26,    26,    26,    27,    28,    29,    29,
      29,    30,    30,    31,    31,    31,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    33,    33,    34,    35,    36,
      37,    38,    39,    40,    40,    41,    42,    43,    44,    44,
      44,    44,    44,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     8,     0,     1,
       3,     1,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     5,     3,     6,
       8,     7,     2,     1,     2,     7,     5,     4,     1,     1,
       3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, p); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);

  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
switch (yykind)
    {
      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, p);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), p);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, p); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse ()
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */



#line 1466 "mrcl_parser_lrama.c"

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: top_stmts  */
#line 54 "mrcl_parser_lrama.y"
                    {
                        NodeList* ast = NodeList_new();
                        NodeList_add_str(ast, "top_stmts");
                        NodeList_add_all(ast, (yyvsp[0].union_list));

                        g_ast = ast;
                    }
#line 1685 "mrcl_parser_lrama.c"
    break;

  case 3: /* top_stmts: %empty  */
#line 63 "mrcl_parser_lrama.y"
                    {
                        NodeList* top_stmts = NodeList_new();
                        (yyval.union_list) = top_stmts;
                    }
#line 1694 "mrcl_parser_lrama.c"
    break;

  case 4: /* top_stmts: top_stmt  */
#line 68 "mrcl_parser_lrama.y"
                    {
                        NodeList* top_stmts = NodeList_new();
                        NodeList_add_list(top_stmts, (yyvsp[0].union_list));

                        (yyval.union_list) = top_stmts;
                    }
#line 1705 "mrcl_parser_lrama.c"
    break;

  case 5: /* top_stmts: top_stmts top_stmt  */
#line 75 "mrcl_parser_lrama.y"
                    {
                        NodeList* top_stmts = (yyvsp[-1].union_list);
                        NodeList_add_list(top_stmts, (yyvsp[0].union_list));

                        (yyval.union_list) = top_stmts;
                    }
#line 1716 "mrcl_parser_lrama.c"
    break;

  case 7: /* func_def: TS_KW_FUNC TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SYM stmts TS_SYM  */
#line 86 "mrcl_parser_lrama.y"
                                                                                                    {
                        NodeList* func_def = NodeList_new();
                        NodeList_add_str(func_def, "func");
                        NodeList_add_str(func_def, (yyvsp[-6].union_str));
                        NodeList_add_list(func_def, (yyvsp[-4].union_list));
                        NodeList_add_list(func_def, (yyvsp[-1].union_list));

                        (yyval.union_list) = func_def;
                    }
#line 1730 "mrcl_parser_lrama.c"
    break;

  case 8: /* args: %empty  */
#line 97 "mrcl_parser_lrama.y"
                    {
                        NodeList* args = NodeList_new();
                        (yyval.union_list) = args;
                    }
#line 1739 "mrcl_parser_lrama.c"
    break;

  case 9: /* args: arg  */
#line 102 "mrcl_parser_lrama.y"
                    {
                        NodeList* args = NodeList_new();
                        NodeList_add_node(args, (yyvsp[0].union_node));
                        (yyval.union_list) = args;
                    }
#line 1749 "mrcl_parser_lrama.c"
    break;

  case 10: /* args: args TS_SYM arg  */
#line 108 "mrcl_parser_lrama.y"
                    {
                        NodeList* args = (yyvsp[-2].union_list);
                        NodeList_add_node(args, (yyvsp[0].union_node));
                        (yyval.union_list) = args;
                    }
#line 1759 "mrcl_parser_lrama.c"
    break;

  case 11: /* arg: TS_IDENT  */
#line 115 "mrcl_parser_lrama.y"
                    {
                        NodeItem* arg = NodeItem_new_str((yyvsp[0].union_str));
                        (yyval.union_node) = arg;
                    }
#line 1768 "mrcl_parser_lrama.c"
    break;

  case 12: /* arg: TS_INT  */
#line 120 "mrcl_parser_lrama.y"
                    {
                        int n = s_to_i((yyvsp[0].union_str));
                        NodeItem* arg = NodeItem_new_int(n);
                        (yyval.union_node) = arg;
                    }
#line 1778 "mrcl_parser_lrama.c"
    break;

  case 13: /* stmts: %empty  */
#line 127 "mrcl_parser_lrama.y"
                    {
                        NodeList* stmts = NodeList_new();
                        (yyval.union_list) = stmts;
                    }
#line 1787 "mrcl_parser_lrama.c"
    break;

  case 14: /* stmts: stmt  */
#line 132 "mrcl_parser_lrama.y"
                    {
                        NodeList* stmts = NodeList_new();
                        NodeList_add_list(stmts, (yyvsp[0].union_list));

                        (yyval.union_list) = stmts;
                    }
#line 1798 "mrcl_parser_lrama.c"
    break;

  case 15: /* stmts: stmts stmt  */
#line 139 "mrcl_parser_lrama.y"
                    {
                        NodeList* stmts = (yyvsp[-1].union_list);
                        NodeList_add_list(stmts, (yyvsp[0].union_list));

                        (yyval.union_list) = stmts;
                    }
#line 1809 "mrcl_parser_lrama.c"
    break;

  case 25: /* stmt_var: TS_KW_VAR TS_IDENT TS_SCOLON  */
#line 158 "mrcl_parser_lrama.y"
                                                           {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "var");
                        NodeList_add_str(stmt, (yyvsp[-1].union_str));

                        (yyval.union_list) = stmt;
                    }
#line 1821 "mrcl_parser_lrama.c"
    break;

  case 26: /* stmt_var: TS_KW_VAR TS_IDENT TS_SYM expr TS_SCOLON  */
#line 167 "mrcl_parser_lrama.y"
                                                                       {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "var");
                        NodeList_add_str(stmt, (yyvsp[-3].union_str));
                        NodeList_add_node(stmt, (yyvsp[-1].union_node));

                        (yyval.union_list) = stmt;
                    }
#line 1834 "mrcl_parser_lrama.c"
    break;

  case 27: /* stmt_set: TS_KW_SET TS_IDENT TS_SYM expr TS_SCOLON  */
#line 178 "mrcl_parser_lrama.y"
                                                                       {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "set");
                        NodeList_add_str(stmt, (yyvsp[-3].union_str));
                        NodeList_add_node(stmt, (yyvsp[-1].union_node));

                        (yyval.union_list) = stmt;
                    }
#line 1847 "mrcl_parser_lrama.c"
    break;

  case 28: /* stmt_return: TS_KW_RETURN expr TS_SCOLON  */
#line 189 "mrcl_parser_lrama.y"
                                                          {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "return");
                        NodeList_add_node(stmt, (yyvsp[-1].union_node));

                        (yyval.union_list) = stmt;
                    }
#line 1859 "mrcl_parser_lrama.c"
    break;

  case 29: /* stmt_call: TS_KW_CALL TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SCOLON  */
#line 199 "mrcl_parser_lrama.y"
                                                                                       {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "call");
                        NodeList_add_str(stmt, (yyvsp[-4].union_str));
                        NodeList_add_all(stmt, (yyvsp[-2].union_list));

                        (yyval.union_list) = stmt;
                    }
#line 1872 "mrcl_parser_lrama.c"
    break;

  case 30: /* stmt_call_set: TS_KW_CALL_SET TS_IDENT TS_SYM TS_IDENT TS_PAREN_L args TS_PAREN_R TS_SCOLON  */
#line 210 "mrcl_parser_lrama.y"
                                                                                                           {
                        NodeList* funcall = NodeList_new();
                        NodeList_add_str(funcall, (yyvsp[-4].union_str));
                        NodeList_add_all(funcall, (yyvsp[-2].union_list));

                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "call_set");
                        NodeList_add_str(stmt, (yyvsp[-6].union_str));
                        NodeList_add_list(stmt, funcall);

                        (yyval.union_list) = stmt;
                    }
#line 1889 "mrcl_parser_lrama.c"
    break;

  case 31: /* stmt_while: TS_KW_WHILE TS_PAREN_L expr TS_PAREN_R TS_SYM stmts TS_SYM  */
#line 225 "mrcl_parser_lrama.y"
                                                                                            {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "while");
                        NodeList_add_node(stmt, (yyvsp[-4].union_node));
                        NodeList_add_list(stmt, (yyvsp[-1].union_list));

                        (yyval.union_list) = stmt;
                    }
#line 1902 "mrcl_parser_lrama.c"
    break;

  case 32: /* stmt_case: TS_KW_CASE when_clauses  */
#line 236 "mrcl_parser_lrama.y"
                                                              {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "case");
                        NodeList_add_all(stmt, (yyvsp[0].union_list));

                        (yyval.union_list) = stmt;
                    }
#line 1914 "mrcl_parser_lrama.c"
    break;

  case 33: /* when_clauses: when_clause  */
#line 245 "mrcl_parser_lrama.y"
                    {
                        NodeList* when_clauses = NodeList_new();
                        NodeList_add_list(when_clauses, (yyvsp[0].union_list));
                        (yyval.union_list) = when_clauses;
                    }
#line 1924 "mrcl_parser_lrama.c"
    break;

  case 34: /* when_clauses: when_clauses when_clause  */
#line 251 "mrcl_parser_lrama.y"
                    {
                        NodeList* when_clauses = (yyvsp[-1].union_list);
                        NodeList_add_list(when_clauses, (yyvsp[0].union_list));
                        (yyval.union_list) = when_clauses;
                    }
#line 1934 "mrcl_parser_lrama.c"
    break;

  case 35: /* when_clause: TS_KW_WHEN TS_PAREN_L expr TS_PAREN_R TS_SYM stmts TS_SYM  */
#line 259 "mrcl_parser_lrama.y"
                                                                                           {
                        NodeList* when_clause = NodeList_new();
                        NodeList_add_node(when_clause, (yyvsp[-4].union_node));
                        NodeList_add_all(when_clause, (yyvsp[-1].union_list));
                        (yyval.union_list) = when_clause;
                    }
#line 1945 "mrcl_parser_lrama.c"
    break;

  case 36: /* stmt_vm_comment: TS_KW_CMT TS_PAREN_L TS_STR TS_PAREN_R TS_SCOLON  */
#line 268 "mrcl_parser_lrama.y"
                                                                               {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "_cmt");
                        NodeList_add_str(stmt, (yyvsp[-2].union_str));

                        (yyval.union_list) = stmt;
                    }
#line 1957 "mrcl_parser_lrama.c"
    break;

  case 37: /* stmt_debug: TS_KW_DEBUG TS_PAREN_L TS_PAREN_R TS_SCOLON  */
#line 278 "mrcl_parser_lrama.y"
                                                                          {
                        NodeList* stmt = NodeList_new();
                        NodeList_add_str(stmt, "_debug");

                        (yyval.union_list) = stmt;
                    }
#line 1968 "mrcl_parser_lrama.c"
    break;

  case 38: /* expr: TS_INT  */
#line 286 "mrcl_parser_lrama.y"
                    {
                        int n = s_to_i((yyvsp[0].union_str));
                        (yyval.union_node) = NodeItem_new_int(n);
                    }
#line 1977 "mrcl_parser_lrama.c"
    break;

  case 39: /* expr: TS_IDENT  */
#line 291 "mrcl_parser_lrama.y"
                    {
                        (yyval.union_node) = NodeItem_new_str((yyvsp[0].union_str));
                    }
#line 1985 "mrcl_parser_lrama.c"
    break;

  case 40: /* expr: expr TS_PLUS expr  */
#line 295 "mrcl_parser_lrama.y"
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, "+");
                        NodeList_add_node(xs, (yyvsp[-2].union_node));
                        NodeList_add_node(xs, (yyvsp[0].union_node));

                        (yyval.union_node) = NodeItem_new_list(xs);
                    }
#line 1998 "mrcl_parser_lrama.c"
    break;

  case 41: /* expr: expr TS_MULT expr  */
#line 304 "mrcl_parser_lrama.y"
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, "*");
                        NodeList_add_node(xs, (yyvsp[-2].union_node));
                        NodeList_add_node(xs, (yyvsp[0].union_node));

                        (yyval.union_node) = NodeItem_new_list(xs);
                    }
#line 2011 "mrcl_parser_lrama.c"
    break;

  case 42: /* expr: expr TS_BIN_OP expr  */
#line 313 "mrcl_parser_lrama.y"
                    {
                        NodeList* xs = NodeList_new();
                        NodeList_add_str(xs, (yyvsp[-1].union_str)); // ==, !=
                        NodeList_add_node(xs, (yyvsp[-2].union_node));
                        NodeList_add_node(xs, (yyvsp[0].union_node));

                        (yyval.union_node) = NodeItem_new_list(xs);
                    }
#line 2024 "mrcl_parser_lrama.c"
    break;

  case 43: /* expr: TS_PAREN_L expr TS_PAREN_R  */
#line 323 "mrcl_parser_lrama.y"
                                                        {
                      (yyval.union_node) = (yyvsp[-1].union_node);
                    }
#line 2032 "mrcl_parser_lrama.c"
    break;


#line 2036 "mrcl_parser_lrama.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 327 "mrcl_parser_lrama.y"


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