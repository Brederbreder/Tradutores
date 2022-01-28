/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "src/syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../lib/structures.h"

    extern int lines;
    extern int columns;
    extern int errors;
    int errors_sem = 0;
    int errors_sin = 0;

    extern int yylex();
    extern int yyparse();
    extern int yylex_destroy();
    extern void yyerror(const char* message);
    extern void ScopeChange(int op);
    extern FILE* yyin;

    extern Symbol Table[1000];
    extern TreeNode* Nodes[1000];
    extern TreeNode* Tree;

    int scope;
    int scope_position;
    int params;
    int param;
    int param_errors;
    int arg_return;
    int args;
    int main_error;
    int call_scope;
    int scope_id;
    int type_return;

    int stack[1000];
    char tac_table[10000];
    char tac_code[10000];

    int reg;
    int str;
    int loop;
    int if_start;
    int ifs;

    char reg_num[6];
    char str_num[6];
    char loop_num[6];
    char for_loop1[6];
    char for_loop2[6];
    char for_loop3[6];
    char for_loop4[6];
    char if_loop[6];
    char else_loop[6];
    char end_loop1[6];
    char end_loop2[6];
    char end_loop3[6];
    char end_loop4[6];
    char list_loop1[6];
    char list_loop2[6];
    char list_loop3[6];
    char list_loop4[6];
    char finish_loop[6];
    char tac[1000];
    char cur_ret[100];
    char int_list[1000];
    char float_list[1000];

#line 140 "src/syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_LIST = 5,                       /* LIST  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_NIL_RW = 11,                    /* NIL_RW  */
  YYSYMBOL_REL_OP = 12,                    /* REL_OP  */
  YYSYMBOL_ASSIGN_OP = 13,                 /* ASSIGN_OP  */
  YYSYMBOL_LIST_CONSTRUC = 14,             /* LIST_CONSTRUC  */
  YYSYMBOL_FOR_RW = 15,                    /* FOR_RW  */
  YYSYMBOL_IF_RW = 16,                     /* IF_RW  */
  YYSYMBOL_RETURN_RW = 17,                 /* RETURN_RW  */
  YYSYMBOL_18_ = 18,                       /* ';'  */
  YYSYMBOL_19_ = 19,                       /* '{'  */
  YYSYMBOL_20_ = 20,                       /* '}'  */
  YYSYMBOL_21_ = 21,                       /* '('  */
  YYSYMBOL_22_ = 22,                       /* ')'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_ELSE_RW = 24,                   /* ELSE_RW  */
  YYSYMBOL_LIST_BIN_OP = 25,               /* LIST_BIN_OP  */
  YYSYMBOL_LIST_UN_OP = 26,                /* LIST_UN_OP  */
  YYSYMBOL_ADD_OP = 27,                    /* ADD_OP  */
  YYSYMBOL_MUL_OP = 28,                    /* MUL_OP  */
  YYSYMBOL_LOG_OP = 29,                    /* LOG_OP  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_start = 31,                     /* start  */
  YYSYMBOL_prog = 32,                      /* prog  */
  YYSYMBOL_prog_block = 33,                /* prog_block  */
  YYSYMBOL_decl = 34,                      /* decl  */
  YYSYMBOL_funct_decl = 35,                /* funct_decl  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_38_3 = 38,                      /* $@3  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_funct = 40,                     /* funct  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_block = 43,                     /* block  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_45_5 = 45,                      /* $@5  */
  YYSYMBOL_ass_op = 46,                    /* ass_op  */
  YYSYMBOL_expression = 47,                /* expression  */
  YYSYMBOL_operation = 48,                 /* operation  */
  YYSYMBOL_log_op = 49,                    /* log_op  */
  YYSYMBOL_rel_op = 50,                    /* rel_op  */
  YYSYMBOL_list_op = 51,                   /* list_op  */
  YYSYMBOL_add_op = 52,                    /* add_op  */
  YYSYMBOL_mul_op = 53,                    /* mul_op  */
  YYSYMBOL_op_un = 54,                     /* op_un  */
  YYSYMBOL_write = 55,                     /* write  */
  YYSYMBOL_read = 56,                      /* read  */
  YYSYMBOL_flow_control = 57,              /* flow_control  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_if_else_statement = 59,         /* if_else_statement  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_for_statement = 61,             /* for_statement  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_return_statement = 65,          /* return_statement  */
  YYSYMBOL_value = 66,                     /* value  */
  YYSYMBOL_function_call = 67,             /* function_call  */
  YYSYMBOL_68_11 = 68,                     /* $@11  */
  YYSYMBOL_id = 69,                        /* id  */
  YYSYMBOL_function_params = 70            /* function_params  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2084

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

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
      21,    22,     2,     2,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,    20,     2,     2,     2,     2,
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
      15,    16,    17,    24,    25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   135,   135,   141,   147,   153,   157,   164,   180,   209,
     211,   209,   259,   261,   259,   310,   325,   343,   350,   358,
     363,   371,   381,   385,   395,   402,   406,   410,   410,   417,
     424,   565,   569,   573,   580,   599,   688,   695,   974,   981,
    1075,  1122,  1129,  1217,  1237,  1244,  1332,  1339,  1438,  1445,
    1485,  1500,  1500,  1509,  1513,  1520,  1530,  1530,  1586,  1597,
    1603,  1586,  1629,  1645,  1649,  1653,  1657,  1661,  1665,  1669,
    1683,  1683,  1720,  1738,  1760,  1776
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "LIST",
  "TYPE", "READ", "WRITE", "STRING", "ID", "NIL_RW", "REL_OP", "ASSIGN_OP",
  "LIST_CONSTRUC", "FOR_RW", "IF_RW", "RETURN_RW", "';'", "'{'", "'}'",
  "'('", "')'", "','", "ELSE_RW", "LIST_BIN_OP", "LIST_UN_OP", "ADD_OP",
  "MUL_OP", "LOG_OP", "$accept", "start", "prog", "prog_block", "decl",
  "funct_decl", "$@1", "$@2", "$@3", "$@4", "funct", "params", "param",
  "block", "statement", "$@5", "ass_op", "expression", "operation",
  "log_op", "rel_op", "list_op", "add_op", "mul_op", "op_un", "write",
  "read", "flow_control", "$@6", "if_else_statement", "$@7",
  "for_statement", "$@8", "$@9", "$@10", "return_statement", "value",
  "function_call", "$@11", "id", "function_params", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    59,   123,
     125,    40,    41,    44,   273,   274,   275,   276,   277,   278
};
#endif

#define YYPACT_NINF (-174)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    31,    44,    52,    95,   115,   146,    53,   106,    -8,
    -174,   161,     8,    -6,   165,   128,   116,   181,    68,    34,
      48,   122,   138,   134,   128,   121,   579,   147,   220,   153,
    1343,  1343,  1745,  1757,   113,   162,   180,  1765,   552,  1777,
     184,    82,  1368,  1471,  1505,  1505,   868,   893,   918,   168,
     211,   215,   -11,    17,    54,  2055,  1785,  1797,   222,   242,
     943,   196,   968,   249,  1805,  1817,  1538,   993,   264,   262,
     293,  1471,    28,   295,   267,  1825,  1343,   199,  1837,  1845,
     194,  1018,  1043,  1068,  1093,    82,    82,    82,    82,  1505,
    1505,   281,  1118,  1143,    82,   208,   299,   306,   311,   312,
    1857,  1480,   325,   331,  1168,  1865,    84,   133,   201,   298,
    1877,  1885,  1471,   327,   338,   339,   233,   243,  1484,  1193,
     336,  1897,  1480,    82,  1389,   301,   341,   280,   343,  1410,
     295,  1431,   344,  1218,  1452,  1431,  1243,   425,  1905,  1917,
    1926,  1547,  1935,  1471,  1509,  1509,    11,   102,   229,   250,
    1944,  1953,  1962,  1971,  1980,  1268,   352,  1293,  1559,  1571,
    1583,  1520,  1595,  1471,  1518,  1518,   247,     5,    65,   590,
    1607,  1619,  1631,  1643,  1655,   300,  1368,   350,   351,   618,
     354,   643,   364,   359,   491,   361,  1989,  1998,  1471,  1471,
    1471,  1471,  1509,  1509,   529,   363,  1667,  1679,  1480,  1480,
    1480,  1480,  1518,  1518,   295,  1343,   668,   693,   365,   718,
     743,  1471,  2007,  1480,  2016,   307,   355,   393,   404,  2025,
    2034,  1691,  1480,  1703,   137,   173,   203,   286,  1715,  1727,
     370,  1318,  1471,   368,   303,   308,  1484,   768,   369,  2043,
    1739,    82,  1389,   341,   793,   374,  1410,   295,  1389,   372,
     818,  1452,  1389,   843
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,   392,     0,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,   382,   -23,   -24,   231,   -49,  -123,    41,   398,
     386,   292,   346,   275,    46,  -174,  -174,  -122,  -120,   216,
     178,  -115,   183,   182,   176,   -98,   149,   210,  -173,   -25,
    -154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    46,     6,    15,    25,    16,    30,
       7,    19,    20,    47,    48,    76,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    92,
     131,    62,   123,   128,   135,    63,    64,    65,   101,   154,
     117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   178,   179,     5,   180,    66,    66,   -34,    67,   181,
      14,   213,    17,   -15,    -9,   -16,    75,   199,    85,    75,
      75,   222,    66,    82,   102,     1,   182,   -36,   -36,    86,
     -12,   -70,   -70,   -34,   -36,   -36,     8,   -70,   -70,   -70,
     188,     9,    66,    82,    10,    98,   -36,    81,   103,   -70,
     100,    66,    -2,   104,   -70,   -70,   -10,    24,     1,   234,
      75,    75,    75,    75,    75,    75,   -38,    81,   235,    75,
     -18,   -18,   -38,    22,    12,   177,   174,   -38,    23,    66,
      82,   132,    74,   -38,    77,    32,    33,   -38,   -38,   151,
      78,    37,   137,    39,   -38,    -4,    86,   174,    75,    66,
     127,    -4,   -35,    43,    81,   183,    66,   133,    44,    45,
      66,   136,    99,   -35,   189,    -5,    13,   151,    68,   178,
     179,    -5,   180,    69,   -36,   178,   179,   181,   180,   178,
     179,   -36,   180,   181,    18,   113,   111,   181,    21,   174,
     174,    26,   116,    29,   182,   -37,    -6,   171,    27,   199,
     182,   -37,    -6,   120,   182,   230,   -19,   -19,   151,   -35,
     -35,    -3,   -37,   125,   126,    -7,   -35,    -3,   171,   -20,
     -20,    -7,    31,   174,   174,   174,   174,   174,   174,   103,
      66,    -8,   231,    70,   185,   -37,    83,    -8,   174,   151,
     186,   151,   152,   177,   -14,   -37,   -37,   174,   249,   177,
     -14,    71,   -37,   177,   195,    73,    66,    82,   -11,   151,
     196,   171,    91,   -40,   -11,   -40,    75,    66,   244,   -40,
     152,   105,   183,    66,   250,   -40,   -40,    66,   253,    84,
     -40,    81,   -40,   -31,   151,   151,   151,   151,   151,   220,
     -32,   -38,   -17,   -17,   171,   171,   171,   171,   171,   229,
     172,   -38,   233,   153,   116,   -75,   -75,   151,   -38,   171,
     -33,   152,   -41,   116,   190,   121,   122,    93,   171,   -34,
     -34,   172,   -41,   238,    96,   191,   198,   192,   151,   -41,
     155,   153,   243,   -55,   -55,   -62,   -55,   -55,   -55,   -55,
     -55,   -55,   152,   152,   152,   -55,   -55,   -55,   -39,   -55,
     -55,   -55,   112,    97,   129,   156,   -55,   -55,   -39,   -39,
     -39,   173,   152,   172,   172,   -39,   -39,   157,   150,   189,
      79,   204,   153,   -74,   -74,   239,   122,   -39,   -73,   -35,
     240,   122,   173,   114,   115,   148,   -35,   152,   152,   152,
     152,   152,   152,   118,    94,   -30,   150,   172,   172,   172,
     172,   172,   172,   153,   153,   153,   -50,   -49,   124,   -59,
     152,   130,   172,   148,   110,   -73,   134,   -37,   206,   207,
     208,   172,   211,   153,   173,   173,   170,   -37,   107,   108,
     109,   152,   210,   214,   -37,   223,   232,   150,   236,   149,
     -30,   242,   247,   168,   251,    11,   209,   170,   153,   153,
     153,   153,   153,   153,   148,   -40,    28,   205,   173,   173,
     173,   173,   173,   173,   168,   -40,   -39,   149,   150,   241,
     187,   153,   -40,   173,   248,   245,   -39,   252,     0,   147,
       0,     0,   173,   -39,     0,   148,     0,   -73,   150,   -73,
     197,   146,   153,   -73,     0,     0,    72,   169,     0,     0,
     -73,     0,   -73,   -73,   -73,   148,     0,   147,   149,     0,
       0,     0,     0,   150,   150,   150,   150,   219,   169,   146,
       0,   106,     0,   170,   170,   170,   170,   228,     0,     0,
     148,   216,   217,   218,     0,     0,   150,   167,   170,   149,
     168,   225,   226,   227,   -70,   -70,     0,   170,   147,   166,
     -70,   -70,   -70,   148,     0,   168,     0,   150,   167,   149,
     146,     0,   -70,   212,   168,     0,     0,   -70,   -70,     0,
     166,     0,     0,     0,   148,     0,     0,     0,     0,   147,
       0,     0,   -70,   -70,   149,   149,   149,   149,   -70,   -70,
     -70,   146,     0,     0,   169,   169,   169,   169,     0,   147,
     -70,   221,     0,     0,     0,   -70,   -70,   149,     0,   169,
       0,   146,     0,     0,   -73,   -73,   -73,     0,   169,     0,
     -73,     0,     0,    72,   215,     0,     0,   -73,   149,   -73,
     -73,   -73,   -13,   -13,   224,   -13,   -13,   -13,   -13,   -13,
     -13,     0,     0,     0,   -13,   -13,   -13,   147,   -13,   167,
     -13,     0,   -41,     0,   200,   -13,   -13,     0,   167,   146,
       0,   166,   -41,   -41,     0,   201,     0,   202,   147,   -41,
     166,   -29,   -29,     0,   -29,   -29,   -29,   -29,   -29,   -29,
     146,     0,     0,   -29,   -29,   -29,     0,   -29,   -29,   -29,
       0,     0,   -29,     0,   -29,   -29,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,   -53,
     -53,     0,   -53,   -53,   -53,     0,     0,   -53,     0,   -53,
     -53,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,   -26,
       0,     0,   -26,     0,   -26,   -26,   -25,   -25,     0,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,   -25,
     -25,     0,   -25,   -25,   -25,     0,     0,   -25,     0,   -25,
     -25,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,   -52,
       0,     0,   -52,     0,   -52,   -52,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,   -54,
     -54,     0,   -54,   -54,   -54,     0,     0,   -54,     0,   -54,
     -54,   -28,   -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,
       0,     0,     0,   -28,   -28,   -28,     0,   -28,   -28,   -28,
       0,     0,   -28,     0,   -28,   -28,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,   -55,
     -55,     0,   -55,   -55,   -55,     0,     0,   246,     0,   -55,
     -55,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,   -57,
       0,     0,   -57,     0,   -57,   -57,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,   -61,   -61,
     -61,     0,   -61,   -61,   -61,     0,     0,   -61,     0,   -61,
     -61,   -24,   -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,
       0,     0,     0,   -24,   -24,   -24,     0,   -24,   -24,   -24,
       0,     0,     0,     0,   -24,   -24,    32,    33,     0,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    40,   -51,
      41,     0,    42,    80,    43,     0,     0,     0,     0,    44,
      45,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,
       0,     0,     0,   -22,   -22,   -22,     0,   -22,   -22,   -22,
       0,     0,     0,     0,   -22,   -22,   -29,   -29,     0,   -29,
     -29,   -29,   -29,   -29,   -29,     0,     0,     0,   -29,   -29,
     -29,     0,   -29,   -29,   -29,     0,     0,     0,     0,   -29,
     -29,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,
       0,     0,     0,   -53,   -53,   -53,     0,   -53,   -53,   -53,
       0,     0,     0,     0,   -53,   -53,    32,    33,     0,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    40,   -51,
      41,     0,    42,    95,    43,     0,     0,     0,     0,    44,
      45,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,   -23,   -23,     0,   -23,   -23,   -23,
       0,     0,     0,     0,   -23,   -23,   -21,   -21,     0,   -21,
     -21,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,   -21,
     -21,     0,   -21,   -21,   -21,     0,     0,     0,     0,   -21,
     -21,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,   -26,
       0,     0,     0,     0,   -26,   -26,   -25,   -25,     0,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,   -25,
     -25,     0,   -25,   -25,   -25,     0,     0,     0,     0,   -25,
     -25,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,   -52,
       0,     0,     0,     0,   -52,   -52,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,   -54,
     -54,     0,   -54,   -54,   -54,     0,     0,     0,     0,   -54,
     -54,    32,    33,     0,    34,    35,    36,    37,    38,    39,
       0,     0,     0,    40,   -51,    41,     0,    42,   119,    43,
       0,     0,     0,     0,    44,    45,   -28,   -28,     0,   -28,
     -28,   -28,   -28,   -28,   -28,     0,     0,     0,   -28,   -28,
     -28,     0,   -28,   -28,   -28,     0,     0,     0,     0,   -28,
     -28,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,   -57,
       0,     0,     0,     0,   -57,   -57,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,   -61,   -61,
     -61,     0,   -61,   -61,   -61,     0,     0,     0,     0,   -61,
     -61,    -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,    -7,
       0,     0,     0,    -7,    -7,    -7,     0,    -7,    -7,    -7,
       0,     0,     0,     0,    -7,    -7,    -8,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,    -8,
      -8,     0,    -8,    -8,    -8,     0,     0,     0,     0,    -8,
      -8,    32,    33,     0,    34,    35,    36,    37,    38,    39,
       0,     0,     0,    40,   -51,    41,     0,    42,   237,    43,
       0,     0,     0,     0,    44,    45,    32,    33,     0,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    40,   -51,
      41,     0,    42,     0,    43,     0,     0,     0,     0,    44,
      45,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,   -27,
       0,     0,     0,   -27,   -27,   -27,     0,   -27,     0,   -27,
       0,     0,    32,    33,   -27,   -27,    35,    36,    37,    38,
      39,     0,     0,     0,   175,   -51,    41,     0,   176,     0,
      43,     0,     0,   -56,   -56,    44,    45,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
       0,   -56,     0,     0,    32,    33,   -56,   -56,    35,    36,
      37,    38,    39,     0,     0,     0,    40,   -51,    41,     0,
      42,     0,    43,     0,     0,   -60,   -60,    44,    45,   -60,
     -60,   -60,   -60,   -60,     0,     0,     0,   -60,   -60,   -60,
       0,   -60,     0,   -60,   138,   139,     0,     0,   -60,   -60,
     140,   141,   142,   158,   159,     0,     0,   -58,   -58,   160,
     161,   162,   143,   -58,   -58,   -58,     0,   144,   145,     0,
       0,   163,     0,     0,     0,   -58,   164,   165,    32,    33,
     -58,   -58,   138,   139,    37,   137,    39,     0,   140,   141,
     142,   158,   159,     0,     0,     0,    43,   160,   161,   162,
     143,    44,   -73,     0,   -73,   144,     0,     0,     0,   163,
       0,   194,   -73,   -73,   164,   -73,     0,   -73,   -73,   -73,
     -63,    94,   -63,     0,     0,     0,   -63,     0,     0,   -73,
       0,   -73,     0,   -63,     0,   -63,   -63,   -63,   184,   -73,
       0,   -66,   -73,   -66,   -73,   -73,   -73,     0,     0,     0,
       0,   -66,   -66,   -67,   -66,   -67,   -66,   -66,   -66,     0,
       0,     0,     0,   -67,   -67,   -69,   -67,   -69,   -67,   -67,
     -67,     0,     0,     0,     0,   -69,   -69,   -68,   -69,   -68,
     -69,   -69,   -69,     0,     0,     0,     0,   -68,   -68,   -44,
     -68,   -44,   -68,   -68,   -68,     0,     0,     0,     0,   -44,
     -44,   -46,   -44,   -46,   -44,   203,   -44,     0,     0,     0,
       0,   -46,   -46,   -48,   -46,   -48,   -46,   -46,   -46,     0,
       0,     0,     0,   -48,   -48,   -64,   -48,   -64,   -48,   -48,
     -48,     0,     0,     0,     0,   -64,   -64,   -63,   -64,   -63,
     -64,   -64,   -64,     0,     0,     0,     0,   -63,   -63,   -47,
     -63,   -47,   -63,   -63,   -63,     0,     0,     0,     0,   -47,
     -47,   -43,   -47,   -43,   -47,   -47,   -47,     0,     0,     0,
       0,   -43,   -43,   -72,   -43,   -72,   -43,   203,   -43,     0,
       0,     0,     0,   -72,   -72,   -65,   -72,   -65,   -72,   -72,
     -72,     0,     0,     0,     0,   -65,   -65,   -42,   -65,   -42,
     -65,   -65,   -65,     0,     0,     0,     0,   -42,   -42,   -45,
     -42,   -45,   -42,   203,   -42,     0,     0,     0,     0,   -45,
     -45,   -71,   -45,   -71,   -45,   -45,   -45,   -66,     0,   -66,
       0,   -71,   -71,   -66,   -71,     0,   -71,   -71,   -71,   -67,
     -66,   -67,   -66,   -66,   -66,   -67,     0,   -69,     0,   -69,
       0,     0,   -67,   -69,   -67,   -67,   -67,     0,     0,   -68,
     -69,   -68,   -69,   -69,   -69,   -68,     0,   -44,     0,   -44,
       0,     0,   -68,   -44,   -68,   -68,   -68,     0,     0,   -46,
     -44,   -46,   -44,    90,   -44,   -46,     0,   -48,     0,   -48,
       0,     0,   -46,   -48,   -46,   -46,   -46,     0,     0,   -64,
     -48,   -64,   -48,   -48,   -48,   -64,     0,   -63,     0,   -63,
       0,     0,   -64,   -63,   -64,   -64,   -64,     0,     0,   -47,
     -63,   -47,   -63,   -63,   -63,   -47,     0,   -43,     0,   -43,
       0,     0,   -47,   -43,   -47,   -47,   -47,     0,     0,   -72,
     -43,   -72,   -43,    90,   -43,   -72,     0,   -65,     0,   -65,
       0,     0,   -72,   -65,   -72,   -72,   -72,     0,     0,   -42,
     -65,   -42,   -65,   -65,   -65,   -42,     0,   -45,     0,   -45,
       0,     0,   -42,   -45,   -42,    90,   -42,     0,     0,   -71,
     -45,   -71,   -45,   -45,   -45,   -71,     0,   -66,     0,   -66,
       0,     0,   -71,     0,   -71,   -71,   -71,   -66,     0,   -67,
     -66,   -67,   -66,   -66,   -66,     0,     0,     0,   -69,   -67,
     -69,     0,   -67,     0,   -67,   -67,   -67,   -68,   -69,   -68,
       0,   -69,     0,   -69,   -69,   -69,   -44,   -68,   -44,     0,
     -68,     0,   -68,   -68,   -68,   -46,   -44,   -46,     0,   -44,
       0,   -44,   193,   -44,   -48,   -46,   -48,     0,   -46,     0,
     -46,   -46,   -46,   -64,   -48,   -64,     0,   -48,     0,   -48,
     -48,   -48,   -63,   -64,   -63,     0,   -64,     0,   -64,   -64,
     -64,   -47,   -63,   -47,     0,   -63,     0,   -63,   -63,   -63,
     -43,   -47,   -43,     0,   -47,     0,   -47,   -47,   -47,   -72,
     -43,   -72,     0,   -43,     0,   -43,   193,   -43,   -65,   -72,
     -65,     0,   -72,     0,   -72,   -72,   -72,   -42,   -65,   -42,
       0,   -65,     0,   -65,   -65,   -65,   -45,   -42,   -45,     0,
     -42,     0,   -42,   193,   -42,   -71,   -45,   -71,     0,   -45,
       0,   -45,   -45,   -45,     0,   -71,     0,   -41,   -71,    87,
     -71,   -71,   -71,   -41,     0,     0,     0,     0,     0,     0,
      88,     0,    89,     0,   -41
};

static const yytype_int16 yycheck[] =
{
       0,   124,   124,     3,   124,    30,    31,    18,    31,   124,
      18,   184,    18,    21,     6,    21,    41,    12,    29,    44,
      45,   194,    47,    47,    73,     6,   124,    22,    23,    12,
      22,     3,     4,    22,    29,    18,     5,     9,    10,    11,
      29,    10,    67,    67,     0,    70,    29,    47,    73,    21,
      22,    76,     0,    76,    26,    27,    22,    23,     6,   213,
      85,    86,    87,    88,    89,    90,    12,    67,   222,    94,
      22,    23,    18,     5,    21,   124,   101,    12,    10,   104,
     104,   130,    41,    29,    43,     3,     4,    22,    23,    43,
      44,     9,    10,    11,    29,     0,    12,   122,   123,   124,
     124,     6,    18,    21,   104,   130,   131,   131,    26,    27,
     135,   135,    71,    29,    12,     0,    10,    71,     5,   242,
     242,     6,   242,    10,    22,   248,   248,   242,   248,   252,
     252,    29,   252,   248,     6,    94,    90,   252,    22,   164,
     165,    19,   101,    22,   242,    12,     0,   101,    10,    12,
     248,    18,     6,   112,   252,   204,    22,    23,   112,    22,
      23,     0,    29,   122,   123,     0,    29,     6,   122,    22,
      23,     6,    19,   198,   199,   200,   201,   202,   203,   204,
     205,     0,   205,    21,   143,    12,    18,     6,   213,   143,
     144,   145,    43,   242,     0,    22,    23,   222,   247,   248,
       6,    21,    29,   252,   163,    21,   231,   231,     0,   163,
     164,   165,    16,    12,     6,    12,   241,   242,   242,    18,
      71,    22,   247,   248,   248,    22,    23,   252,   252,    18,
      29,   231,    29,    18,   188,   189,   190,   191,   192,   193,
      18,    12,    22,    23,   198,   199,   200,   201,   202,   203,
     101,    22,   211,    43,   213,    22,    23,   211,    29,   213,
      18,   112,    12,   222,    14,    22,    23,    18,   222,    22,
      23,   122,    22,   232,    10,    25,    29,    27,   232,    29,
      18,    71,   241,     3,     4,    18,     6,     7,     8,     9,
      10,    11,   143,   144,   145,    15,    16,    17,    12,    19,
      20,    21,    21,    10,    24,    10,    26,    27,    22,    23,
      12,   101,   163,   164,   165,    29,    18,    18,    43,    12,
      45,    21,   112,    22,    23,    22,    23,    29,    22,    22,
      22,    23,   122,    22,    22,    43,    29,   188,   189,   190,
     191,   192,   193,    18,    13,    18,    71,   198,   199,   200,
     201,   202,   203,   143,   144,   145,    18,    18,    22,    18,
     211,    18,   213,    71,    89,    13,    22,    12,    18,    18,
      16,   222,    13,   163,   164,   165,   101,    22,    86,    87,
      88,   232,    18,    22,    29,    22,    21,   112,    18,    43,
      22,    22,    18,   101,    22,     3,   180,   122,   188,   189,
     190,   191,   192,   193,   112,    12,    24,   176,   198,   199,
     200,   201,   202,   203,   122,    22,    12,    71,   143,   236,
     145,   211,    29,   213,   246,   243,    22,   251,    -1,    43,
      -1,    -1,   222,    29,    -1,   143,    -1,    12,   163,    14,
     165,    43,   232,    18,    -1,    -1,    21,   101,    -1,    -1,
      25,    -1,    27,    28,    29,   163,    -1,    71,   112,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,   192,   122,    71,
      -1,    85,    -1,   198,   199,   200,   201,   202,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,   211,   101,   213,   143,
     198,   199,   200,   201,     3,     4,    -1,   222,   112,   101,
       9,    10,    11,   211,    -1,   213,    -1,   232,   122,   163,
     112,    -1,    21,    22,   222,    -1,    -1,    26,    27,    -1,
     122,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,   143,
      -1,    -1,     3,     4,   188,   189,   190,   191,     9,    10,
      11,   143,    -1,    -1,   198,   199,   200,   201,    -1,   163,
      21,    22,    -1,    -1,    -1,    26,    27,   211,    -1,   213,
      -1,   163,    -1,    -1,    12,    13,    14,    -1,   222,    -1,
      18,    -1,    -1,    21,   188,    -1,    -1,    25,   232,    27,
      28,    29,     3,     4,   198,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,   211,    19,   213,
      21,    -1,    12,    -1,    14,    26,    27,    -1,   222,   211,
      -1,   213,    22,    23,    -1,    25,    -1,    27,   232,    29,
     222,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
     232,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,    21,
      -1,    -1,     3,     4,    26,    27,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,
      21,    -1,    -1,     3,     4,    26,    27,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      -1,    21,    -1,    -1,     3,     4,    26,    27,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    -1,    21,    -1,    -1,     3,     4,    26,    27,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    -1,    21,     3,     4,    -1,    -1,    26,    27,
       9,    10,    11,     3,     4,    -1,    -1,     3,     4,     9,
      10,    11,    21,     9,    10,    11,    -1,    26,    27,    -1,
      -1,    21,    -1,    -1,    -1,    21,    26,    27,     3,     4,
      26,    27,     3,     4,     9,    10,    11,    -1,     9,    10,
      11,     3,     4,    -1,    -1,    -1,    21,     9,    10,    11,
      21,    26,    12,    -1,    14,    26,    -1,    -1,    -1,    21,
      -1,    21,    22,    23,    26,    25,    -1,    27,    28,    29,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    12,
      -1,    14,    -1,    25,    -1,    27,    28,    29,    21,    22,
      -1,    12,    25,    14,    27,    28,    29,    -1,    -1,    -1,
      -1,    22,    23,    12,    25,    14,    27,    28,    29,    -1,
      -1,    -1,    -1,    22,    23,    12,    25,    14,    27,    28,
      29,    -1,    -1,    -1,    -1,    22,    23,    12,    25,    14,
      27,    28,    29,    -1,    -1,    -1,    -1,    22,    23,    12,
      25,    14,    27,    28,    29,    -1,    -1,    -1,    -1,    22,
      23,    12,    25,    14,    27,    28,    29,    -1,    -1,    -1,
      -1,    22,    23,    12,    25,    14,    27,    28,    29,    -1,
      -1,    -1,    -1,    22,    23,    12,    25,    14,    27,    28,
      29,    -1,    -1,    -1,    -1,    22,    23,    12,    25,    14,
      27,    28,    29,    -1,    -1,    -1,    -1,    22,    23,    12,
      25,    14,    27,    28,    29,    -1,    -1,    -1,    -1,    22,
      23,    12,    25,    14,    27,    28,    29,    -1,    -1,    -1,
      -1,    22,    23,    12,    25,    14,    27,    28,    29,    -1,
      -1,    -1,    -1,    22,    23,    12,    25,    14,    27,    28,
      29,    -1,    -1,    -1,    -1,    22,    23,    12,    25,    14,
      27,    28,    29,    -1,    -1,    -1,    -1,    22,    23,    12,
      25,    14,    27,    28,    29,    -1,    -1,    -1,    -1,    22,
      23,    12,    25,    14,    27,    28,    29,    12,    -1,    14,
      -1,    22,    23,    18,    25,    -1,    27,    28,    29,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    18,    27,    28,    29,    -1,    -1,    12,
      25,    14,    27,    28,    29,    18,    -1,    12,    -1,    14,
      -1,    -1,    25,    -1,    27,    28,    29,    22,    -1,    12,
      25,    14,    27,    28,    29,    -1,    -1,    -1,    12,    22,
      14,    -1,    25,    -1,    27,    28,    29,    12,    22,    14,
      -1,    25,    -1,    27,    28,    29,    12,    22,    14,    -1,
      25,    -1,    27,    28,    29,    12,    22,    14,    -1,    25,
      -1,    27,    28,    29,    12,    22,    14,    -1,    25,    -1,
      27,    28,    29,    12,    22,    14,    -1,    25,    -1,    27,
      28,    29,    12,    22,    14,    -1,    25,    -1,    27,    28,
      29,    12,    22,    14,    -1,    25,    -1,    27,    28,    29,
      12,    22,    14,    -1,    25,    -1,    27,    28,    29,    12,
      22,    14,    -1,    25,    -1,    27,    28,    29,    12,    22,
      14,    -1,    25,    -1,    27,    28,    29,    12,    22,    14,
      -1,    25,    -1,    27,    28,    29,    12,    22,    14,    -1,
      25,    -1,    27,    28,    29,    12,    22,    14,    -1,    25,
      -1,    27,    28,    29,    -1,    22,    -1,    12,    25,    14,
      27,    28,    29,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    31,    32,    33,    34,    35,    40,     5,    10,
       0,    33,    21,    10,    18,    36,    38,    18,     6,    41,
      42,    22,     5,    10,    23,    37,    19,    10,    42,    22,
      39,    19,     3,     4,     6,     7,     8,     9,    10,    11,
      15,    17,    19,    21,    26,    27,    34,    43,    44,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    61,    65,    66,    67,    69,    43,     5,    10,
      21,    21,    21,    21,    48,    69,    45,    48,    54,    53,
      20,    34,    44,    18,    18,    29,    12,    14,    25,    27,
      28,    16,    59,    18,    13,    20,    10,    10,    69,    48,
      22,    68,    46,    69,    43,    22,    50,    51,    51,    51,
      53,    54,    21,    48,    22,    22,    48,    70,    18,    20,
      48,    22,    23,    62,    22,    48,    48,    44,    63,    24,
      18,    60,    46,    44,    22,    64,    44,    10,     3,     4,
       9,    10,    11,    21,    26,    27,    49,    50,    51,    52,
      53,    54,    66,    67,    69,    18,    10,    18,     3,     4,
       9,    10,    11,    21,    26,    27,    49,    50,    51,    52,
      53,    54,    66,    67,    69,    15,    19,    46,    47,    57,
      58,    61,    65,    69,    21,    48,    54,    53,    29,    12,
      14,    25,    27,    28,    21,    48,    54,    53,    29,    12,
      14,    25,    27,    28,    21,    45,    18,    18,    16,    59,
      18,    13,    22,    68,    22,    50,    51,    51,    51,    53,
      54,    22,    68,    22,    50,    51,    51,    51,    53,    54,
      46,    43,    21,    48,    70,    70,    18,    20,    48,    22,
      22,    62,    22,    48,    44,    63,    24,    18,    60,    46,
      44,    22,    64,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    36,
      37,    35,    38,    39,    35,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    43,    44,    44,    45,    44,    44,
      46,    47,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    58,    57,    57,    57,    59,    60,    59,    62,    63,
      64,    61,    65,    66,    66,    66,    66,    66,    66,    66,
      68,    67,    67,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     4,     0,
       0,     9,     0,     0,     8,     2,     3,     3,     1,     2,
       3,     2,     1,     2,     1,     2,     2,     0,     4,     1,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     2,     1,     3,     1,     2,     1,     4,
       4,     0,     2,     1,     2,     5,     0,     8,     0,     0,
       0,    12,     2,     1,     1,     3,     1,     1,     1,     1,
       0,     5,     3,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: prog  */
#line 135 "src/syntax.y"
         {
        Tree = (yyval.node);
    }
#line 1983 "src/syntax.tab.c"
    break;

  case 3: /* prog: prog prog_block  */
#line 141 "src/syntax.y"
                    {
        (yyval.node) = NewNode("prog", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-1].node);
        (yyval.node)->t2 = (yyvsp[0].node);
    }
#line 1993 "src/syntax.tab.c"
    break;

  case 4: /* prog: prog_block  */
#line 147 "src/syntax.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2001 "src/syntax.tab.c"
    break;

  case 5: /* prog_block: decl  */
#line 153 "src/syntax.y"
         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2009 "src/syntax.tab.c"
    break;

  case 6: /* prog_block: funct_decl  */
#line 157 "src/syntax.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2017 "src/syntax.tab.c"
    break;

  case 7: /* decl: TYPE ID ';'  */
#line 164 "src/syntax.y"
               {
        strcat(tac_table, (yyvsp[-2].token).id);
        strcat(tac_table, " ");
        strcat(tac_table, (yyvsp[-1].token).id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "\n");
        if(SearchTable(Table, (yyvsp[-1].token).id, 0, 1, stack, scope_position)){
            printf("Semantic error, variable %s is already declared. Error position, Line = %d, Column = %d\n", (yyvsp[-1].token).id, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
        NewSymbol(Table, (yyvsp[-1].token).id, (yyvsp[-2].token).id, "variable", (yyvsp[-1].token).line, (yyvsp[-1].token).column, stack[scope_position], 0, reg);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-2].token).id, " variable "), (yyvsp[-1].token).id), CheckType(Table, (yyvsp[-1].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2037 "src/syntax.tab.c"
    break;

  case 8: /* decl: TYPE LIST ID ';'  */
#line 180 "src/syntax.y"
                      {
        strcat(tac_table, (yyvsp[-3].token).id);
        strcat(tac_table, " ");
        strcat(tac_table, (yyvsp[-1].token).id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "[100] = ");
        if(!strcmp((yyvsp[-3].token).id, "int")){
            strcat(tac_table, int_list);
        } else {
            strcat(tac_table, float_list);
        }
        strcat(tac_table, "\nint ");
        strcat(tac_table, (yyvsp[-1].token).id);
        strcat(tac_table, "_");
        sprintf(reg_num, "s%d", stack[scope_position]);
        strcat(tac_table, reg_num);
        strcat(tac_table, "_size = 0\n");
        if(SearchTable(Table, (yyvsp[-1].token).id, 0, 1, stack, scope_position)){
            printf("Semantic error, variable %s is already declared. Error position, Line = %d, Column = %d\n", (yyvsp[-1].token).id, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
        NewSymbol(Table, (yyvsp[-1].token).id, strcat((yyvsp[-3].token).id, " list"), "variable", (yyvsp[-1].token).line, (yyvsp[-1].token).column, stack[scope_position], 0, reg);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-3].token).id, " "), (yyvsp[-1].token).id), CheckType(Table, (yyvsp[-1].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2068 "src/syntax.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 209 "src/syntax.y"
              {
        ScopeChange(1);
    }
#line 2076 "src/syntax.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 211 "src/syntax.y"
             {
        UpdateParams(Table, params);
        params = 0;
    }
#line 2085 "src/syntax.tab.c"
    break;

  case 11: /* funct_decl: funct '(' $@1 params $@2 ')' '{' block '}'  */
#line 214 "src/syntax.y"
                        {
        (yyval.node) = NewNode("function", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-8].node);
        (yyval.node)->t2 = (yyvsp[-5].node);
        (yyval.node)->t3 = (yyvsp[-1].node);
        if((yyval.node)->t3->ret){
            if((yyval.node)->t1->type == 1){
                if((yyval.node)->t3->type == 1){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else if((yyval.node)->t3->type == 2){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t3->type, (yyvsp[-7].token).line, (yyvsp[-7].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 2){
                if((yyval.node)->t3->type == 1){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else if((yyval.node)->t3->type == 2){
                    (yyval.node)->type = (yyval.node)->t3->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t3->type, (yyvsp[-7].token).line, (yyvsp[-7].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 4){
                if((yyval.node)->t3->type == 3){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else if((yyval.node)->t3->type == 4){
                    (yyval.node)->type = (yyval.node)->t3->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", (yyval.node)->t1->type, (yyval.node)->t3->type, (yyvsp[-7].token).line, (yyvsp[-7].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 3){
                if((yyval.node)->t3->type == 3){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", (yyval.node)->t1->type, (yyval.node)->t3->type, (yyvsp[-7].token).line, (yyvsp[-7].token).column);
                    errors_sem++;
                }
            }
        }   
        ScopeChange(0);
    }
#line 2134 "src/syntax.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 259 "src/syntax.y"
                {
        UpdateParams(Table, params);
    }
#line 2142 "src/syntax.tab.c"
    break;

  case 13: /* $@4: %empty  */
#line 261 "src/syntax.y"
              {
        ScopeChange(1);
    }
#line 2150 "src/syntax.tab.c"
    break;

  case 14: /* funct_decl: funct '(' $@3 ')' '{' $@4 block '}'  */
#line 263 "src/syntax.y"
                {
        (yyval.node) = NewNode("function", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-7].node);
        (yyval.node)->t2 = (yyvsp[-1].node);
        if((yyval.node)->t2->ret == 2){
            if((yyval.node)->t1->type == 1){
                if((yyval.node)->t2->type == 1){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-6].token).line, (yyvsp[-6].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 2){
                if((yyval.node)->t2->type == 1){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else if((yyval.node)->t2->type == 2){
                    (yyval.node)->type = (yyval.node)->t2->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-6].token).line, (yyvsp[-6].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 4){
                if((yyval.node)->t2->type == 3){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else if((yyval.node)->t2->type == 4){
                    (yyval.node)->type = (yyval.node)->t2->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-6].token).line, (yyvsp[-6].token).column);
                    errors_sem++;
                }
            } else if((yyval.node)->t1->type == 3){
                if((yyval.node)->t2->type == 3){
                    (yyval.node)->type = (yyval.node)->t1->type;
                } else {
                    printf("Semantic error, function type = %d and return type = %d. Error position, Line = %d, Columns = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-6].token).line, (yyvsp[-6].token).column);
                    errors_sem++;
                }
            }
        } else {
            strcat(tac_code, "return\n");
        }
        ScopeChange(0);
    }
#line 2198 "src/syntax.tab.c"
    break;

  case 15: /* funct: TYPE ID  */
#line 310 "src/syntax.y"
            {
        strcat(tac_code, "_");
        strcat(tac_code, (yyvsp[0].token).id);
        strcat(tac_code, ":\n");
        if(!strcmp((yyvsp[0].token).id, "main")){
            main_error = 0;
        }
        if(SearchTable(Table, (yyvsp[0].token).id, 1, 0, stack, scope_position)){
            printf("Semantic error, function %s is already declared. Error position, Line = %d, Column = %d\n", (yyvsp[0].token).id, (yyvsp[0].token).line, (yyvsp[0].token).column);
            errors_sem++;
        }
        NewSymbol(Table, (yyvsp[0].token).id, (yyvsp[-1].token).id, "function", (yyvsp[0].token).line, (yyvsp[0].token).column, stack[scope_position], -1, -1);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-1].token).id, " function "), (yyvsp[0].token).id), CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2217 "src/syntax.tab.c"
    break;

  case 16: /* funct: TYPE LIST ID  */
#line 325 "src/syntax.y"
                   {
        strcat(tac_code, "_");
        strcat(tac_code, (yyvsp[0].token).id);
        strcat(tac_code, ":\n");
        if(!strcmp((yyvsp[0].token).id, "main")){
            main_error = 0;
        }
        if(SearchTable(Table, (yyvsp[0].token).id, 1, 0, stack, scope_position)){
            printf("Semantic error, function %s is already declared. Error position, Line = %d, Column = %d\n", (yyvsp[0].token).id, (yyvsp[0].token).line, (yyvsp[0].token).column);
            errors_sem++;
        }
        NewSymbol(Table, (yyvsp[0].token).id, strcat((yyvsp[-2].token).id, " list"), "function", (yyvsp[0].token).line, (yyvsp[0].token).column, scope, -1, -1);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-2].token).id, " function "), (yyvsp[0].token).id), CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2236 "src/syntax.tab.c"
    break;

  case 17: /* params: params ',' param  */
#line 343 "src/syntax.y"
                     {
        (yyval.node) = NewNode("params", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        params++;
    }
#line 2247 "src/syntax.tab.c"
    break;

  case 18: /* params: param  */
#line 350 "src/syntax.y"
            {
        (yyval.node) = (yyvsp[0].node);
        params++;
    }
#line 2256 "src/syntax.tab.c"
    break;

  case 19: /* param: TYPE ID  */
#line 358 "src/syntax.y"
            {
        NewSymbol(Table, (yyvsp[0].token).id, (yyvsp[-1].token).id, "param", (yyvsp[0].token).line, (yyvsp[0].token).column, stack[scope_position], params + 1, reg);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-1].token).id, " variable "), (yyvsp[0].token).id), CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2265 "src/syntax.tab.c"
    break;

  case 20: /* param: TYPE LIST ID  */
#line 363 "src/syntax.y"
                   {
        NewSymbol(Table, (yyvsp[0].token).id, strcat((yyvsp[-2].token).id, " list"), "list param", (yyvsp[0].token).line, (yyvsp[0].token).column, stack[scope_position], params + 1, reg);
        (yyval.node) = NewNode(strcat(strcat((yyvsp[-2].token).id, " "), (yyvsp[0].token).id), CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, " ");
    }
#line 2274 "src/syntax.tab.c"
    break;

  case 21: /* block: block statement  */
#line 371 "src/syntax.y"
                    {
        (yyval.node) = NewNode("block", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-1].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        if((yyval.node)->t1->ret || (yyval.node)->t2->ret){
            (yyval.node)->ret = 1;
        }
        (yyval.node)->type = (yyval.node)->t2->type;
    }
#line 2288 "src/syntax.tab.c"
    break;

  case 22: /* block: statement  */
#line 381 "src/syntax.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2296 "src/syntax.tab.c"
    break;

  case 23: /* block: block decl  */
#line 385 "src/syntax.y"
                 {
        (yyval.node) = NewNode("block", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-1].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        if((yyval.node)->t1->ret || (yyval.node)->t2->ret){
            (yyval.node)->ret = 1;
        }
        (yyval.node)->type = (yyval.node)->t2->type;
    }
#line 2310 "src/syntax.tab.c"
    break;

  case 24: /* block: decl  */
#line 395 "src/syntax.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2318 "src/syntax.tab.c"
    break;

  case 25: /* statement: expression ';'  */
#line 402 "src/syntax.y"
                   {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2326 "src/syntax.tab.c"
    break;

  case 26: /* statement: ass_op ';'  */
#line 406 "src/syntax.y"
                 {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2334 "src/syntax.tab.c"
    break;

  case 27: /* $@5: %empty  */
#line 410 "src/syntax.y"
          {
        ScopeChange(1);
    }
#line 2342 "src/syntax.tab.c"
    break;

  case 28: /* statement: '{' $@5 block '}'  */
#line 412 "src/syntax.y"
                {
        (yyval.node) = (yyvsp[-1].node);
        ScopeChange(0);
    }
#line 2351 "src/syntax.tab.c"
    break;

  case 29: /* statement: flow_control  */
#line 417 "src/syntax.y"
                   {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2359 "src/syntax.tab.c"
    break;

  case 30: /* ass_op: id ASSIGN_OP operation  */
#line 424 "src/syntax.y"
                           {
        (yyval.node) = NewNode("assign operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        if((yyval.node)->t1->type == 1){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\nmov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", $800\n");
            } else {
                printf("Semantic error, type assignment error assigning %d to %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t2->type, (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n mov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", $800\n");
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
            } else {
                printf("Semantic error, type assingment error assigning %d to %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t2->type, (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            }
        } else if((yyval.node)->t1->type == 3){
            if((yyval.node)->t2->type == 3){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\n");
                strcat(tac_code, "mov $603, $500[$600]\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else if((yyval.node)->t2->type == 4){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmove $600, 0\nmov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "fltoint $603, $603\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else {
                printf("Semantic error, type assingment error assigning %d to %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t2->type, (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            }
        } else if((yyval.node)->t1->type == 4){
            if((yyval.node)->t2->type == 3){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\n");
                strcat(tac_code, "mov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "inttofl $603, $603\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else if((yyval.node)->t2->type == 4){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "$mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $603, $500[$600]\n");
                strcat(tac_code, "mov $400[$600], $603\n");
                strcat(tac_code, "sub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbnrz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\nmov ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size, $601\n");
            } else {
                printf("Semantic Error, type assignment error assigning %d to %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t2->type, (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        }
    }
#line 2501 "src/syntax.tab.c"
    break;

  case 31: /* expression: operation  */
#line 565 "src/syntax.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2509 "src/syntax.tab.c"
    break;

  case 32: /* expression: write  */
#line 569 "src/syntax.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2517 "src/syntax.tab.c"
    break;

  case 33: /* expression: read  */
#line 573 "src/syntax.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2525 "src/syntax.tab.c"
    break;

  case 34: /* operation: log_op  */
#line 580 "src/syntax.y"
           {
        (yyval.node) = NewNode("Operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[0].node);
        (yyval.node)->type = (yyval.node)->t1->type;
        strcpy((yyval.node)->tac_code, (yyval.node)->t1->tac_code);
        strcpy((yyval.node)->value, (yyval.node)->t1->value);
        if(if_start){
            strcat(tac_code, "brz ");
            strcat(tac_code, if_loop);
            strcat(tac_code, ", ");
            strcat(tac_code, (yyval.node)->t1->tac_code);
            strcat(tac_code, "\n");
            if_start = 0;
        }
    }
#line 2545 "src/syntax.tab.c"
    break;

  case 35: /* log_op: log_op LOG_OP rel_op  */
#line 599 "src/syntax.y"
                         {
        (yyval.node) = NewNode("logic operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        if((yyval.node)->t1->type == 1){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = 1;
                if(!strcmp((yyvsp[-1].token).id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcat(tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error on logic operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                strcat(tac_code, "fltoint $801, $801\n");
                if(!strcmp((yyvsp[-1].token).id, "&&")){
                    strcat(tac_code, "and ");
                } else {
                    strcat(tac_code, "or ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error on logic operation with type %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else{
            printf("Semantic error, type error on logic operation with type %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
    }
#line 2638 "src/syntax.tab.c"
    break;

  case 36: /* log_op: rel_op  */
#line 688 "src/syntax.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2646 "src/syntax.tab.c"
    break;

  case 37: /* rel_op: rel_op REL_OP list_op  */
#line 695 "src/syntax.y"
                          {
        (yyval.node) = NewNode("relative operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        if((yyval.node)->t1->type == 1){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = 1;
                if(!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "!=") || !strcmp((yyvsp[-1].token).id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", $800, 1\n");
                if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "!=") || !strcmp((yyvsp[-1].token).id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "!=") || !strcmp((yyvsp[-1].token).id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = 1;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nfltoint $800, $800\n");
                strcat(tac_code, "fltoint $801, $801\n");
                if(!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "seq ");
                } else if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "<")){
                    strcat(tac_code, "slt ");
                } else {
                    strcat(tac_code, "sleq ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                if(!strcmp((yyvsp[-1].token).id, ">=") || !strcmp((yyvsp[-1].token).id, "!=") || !strcmp((yyvsp[-1].token).id, ">")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 3 && (!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id, "!="))){
            if((yyval.node)->t2->type == 3){
                (yyval.node)->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\nmov $602, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\n");
                strcat(tac_code, "sub $603, $601, %602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $500[$600]\n");
                strcat(tac_code, "mov $701, $400[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nbrz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\n brnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 4) {
                (yyval.node)->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\nmov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\nmov $602, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\n");
                strcat(tac_code, "sub $603, $601, %602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $500[$600]\n");
                strcat(tac_code, "fltoint $700, $700\n");
                strcat(tac_code, "mov $701, $400[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nbrz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add $600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 4 && (!strcmp((yyvsp[-1].token).id, "==") || !strcmp((yyvsp[-1].token).id,"!="))){
            if((yyval.node)->t2->type == 3 || (yyval.node)->t2->type == 4){
                (yyval.node)->type = 1;
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, "mov $400, &");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $500, &");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\nmov $600, 0\n");
                strcat(tac_code, "mov $601, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "_size\n");
                strcat(tac_code, "mov $602, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "_size\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 0\nsub $603, $601, $602\n");
                sprintf(list_loop1, "Jump%d", loop);
                loop++;
                strcat(tac_code, "brnz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", $603\nmov ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", 1\n");
                sprintf(loop_num, "Jump%d", loop);
                loop++;
                strcat(tac_code, loop_num);
                strcat(tac_code, ":\nmov $700, $400[$600]\n");
                strcat(tac_code, "fltoint $700, $700\n");
                strcat(tac_code, "mov $701, $500[$600]\nseq ");
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $701, $700\nrbz ");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ", ");
                strcat(tac_code, reg_num);
                strcat(tac_code, "\nsub $602, $601, $600\n");
                strcat(tac_code, "add &600, $600, 1\nbrnz ");
                strcat(tac_code, loop_num);
                strcat(tac_code, ", $602\n");
                strcat(tac_code, list_loop1);
                strcat(tac_code, ":\n");
                if(!strcmp((yyvsp[-1].token).id, "!=")){
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, "\n");
                }
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            } 
        } else {
                printf("Semantic error, type error in relational operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
    }
#line 2929 "src/syntax.tab.c"
    break;

  case 38: /* rel_op: list_op  */
#line 974 "src/syntax.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2937 "src/syntax.tab.c"
    break;

  case 39: /* list_op: add_op LIST_BIN_OP list_op  */
#line 981 "src/syntax.y"
                               {
        (yyval.node) = NewNode("list function", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        if(!strcmp((yyvsp[-1].token).id, ">>")){
            strcat(tac_code, "mov $500, &");
            strcat(tac_code, (yyval.node)->t2->tac_code);
            strcat(tac_code, "\n");
            strcat(tac_code, "mov $600, 0\n");
            strcat(tac_code, "mov $601, ");
            strcat(tac_code, (yyval.node)->t2->tac_code);
            strcat(tac_code, "_size\n");
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            strcat(tac_code, loop_num);
            strcat(tac_code, ":\n");
            strcat(tac_code, "mov $603, $500[$600]\n");
            strcat(tac_code, "param $603\n");
            strcat(tac_code, "call _");
            strcat(tac_code, (yyval.node)->t1->value);
            strcat(tac_code, ", 1\n");
            strcat(tac_code, "pop $605\n");
            strcat(tac_code, "mov $500[600], $605\n");
            strcat(tac_code, "add $600, $600, 1\n");
            strcat(tac_code, "sub $602, $601, $600\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $602\n//");
        } else {
            strcat(tac_code, "mov $500, &");
            strcat(tac_code, (yyval.node)->t2->tac_code);
            strcat(tac_code, "\nmov $600, 0\n");
            strcat(tac_code, "mov $601, ");
            strcat(tac_code, (yyval.node)->t2->tac_code);
            strcat(tac_code, "_size\n");
            sprintf(list_loop1, "Jump%d", loop);
            loop++;
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            sprintf(list_loop2, "Jump%d", loop);
            loop++;
            sprintf(list_loop3, "Jump%d", loop);
            loop++;
            sprintf(list_loop4, "Jump%d", loop);
            loop++;
            strcat(tac_code, list_loop1);
            strcat(tac_code, ":\nmov $603, $500[$600]\n");
            strcat(tac_code, "param $603\n");
            strcat(tac_code, "call _");
            strcat(tac_code, (yyval.node)->t1->value);
            strcat(tac_code, ", 1\n");
            strcat(tac_code, "pop $605\nbrnz ");
            strcat(tac_code, list_loop2);
            strcat(tac_code, ", $605\n");
            strcat(tac_code, "add $600, $600, 1\n");
            strcat(tac_code, list_loop3);
            strcat(tac_code, ":\nsub $602, $601, $600\nbrnz ");
            strcat(tac_code, list_loop1);
            strcat(tac_code, ", $602\njump ");
            strcat(tac_code, list_loop4);
            strcat(tac_code, "\n");
            strcat(tac_code, list_loop2);
            strcat(tac_code, ":\nmov $610, $600\n");
            strcat(tac_code, "add $611, $610, 1\n");
            strcat(tac_code, loop_num);
            strcat(tac_code, "\nmov $613, $600[$611]\n");
            strcat(tac_code, "mov $500[$610], $613\n");
            strcat(tac_code, "add $610, $610, 1\n");
            strcat(tac_code, "add $611, $611, 1\n");
            strcat(tac_code, "sub $612, $601, $610\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $612\n");
            strcat(tac_code, "sub $601, $601, 1\nsub ");
            strcat(tac_code, (yyval.node)->t2->tac_code);
            strcat(tac_code, "_size, 1\njump ");
            strcat(tac_code, list_loop3);
            strcat(tac_code, "\n");
            strcat(tac_code, list_loop4);
            strcat(tac_code, ":\n");
        }
        
        if((yyval.node)->t1->type == 1 || (yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 3 || (yyval.node)->t2->type == 4){
                (yyval.node)->type = (yyval.node)->t2->type;
            } else {
                printf("Semantic error, error type with type %d with list function with %d type. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, error type with type %d with list function with %d type. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
        strcpy((yyval.node)->tac_code, (yyval.node)->t2->tac_code);
    }
#line 3035 "src/syntax.tab.c"
    break;

  case 40: /* list_op: add_op LIST_CONSTRUC list_op  */
#line 1075 "src/syntax.y"
                                   {
        (yyval.node) = NewNode("list operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        sprintf(loop_num, "Jump%d", loop);
        loop++;
        sprintf(list_loop1, "Jump%d", loop);
        loop++;
        strcat(tac_code, "mov $500, &");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, "\nmov $601, ");
        strcat(tac_code, (yyval.node)->t2->tac_code);
        strcat(tac_code, "_size\nbrz ");
        strcat(tac_code, list_loop1);
        strcat(tac_code, ", $601\nsub $602, $601, 1\n");
        strcat(tac_code, loop_num);
        strcat(tac_code, ":\nmov $604, $500[$602]\n");
        strcat(tac_code, "mov $500[$601], $604");
        strcat(tac_code, "sub $602, $602, 1\n");
        strcat(tac_code, "sub $601, $601, 1\nbrnz ");
        strcat(tac_code, loop_num);
        strcat(tac_code, ", $601\n");
        strcat(tac_code, list_loop1);
        strcat(tac_code, ":\nmov $500[0], ");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, "\nadd ");
        strcat(tac_code, (yyval.node)->t2->tac_code);
        strcat(tac_code, "_size, ");
        strcat(tac_code, (yyval.node)->t2->tac_code);
        strcat(tac_code, "_size, 1\n");
        strcpy((yyval.node)->tac_code, (yyval.node)->t2->tac_code);

        if((yyval.node)->t1->type == 1 || (yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 3 || (yyval.node)->t2->type == 4){
                (yyval.node)->type = (yyval.node)->t2->type;
            } else {
                printf("Semantic error, error type with type %d with list constructor with %d type. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, error type with type %d with list constructor with %d type. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }

    }
#line 3086 "src/syntax.tab.c"
    break;

  case 41: /* list_op: add_op  */
#line 1122 "src/syntax.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3094 "src/syntax.tab.c"
    break;

  case 42: /* add_op: add_op ADD_OP mul_op  */
#line 1129 "src/syntax.y"
                         {
        (yyval.node) = NewNode("additive operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        if((yyval.node)->t1->type == 1){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t1->type;
                if(!strcmp((yyvsp[-1].token).id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else{
                printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, ", $800\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp((yyvsp[-1].token).id, "+")){
                    strcat(tac_code, "add ");
                } else {
                    strcat(tac_code, "sub ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $801, $800\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, type error in additive operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
        }
    }
#line 3186 "src/syntax.tab.c"
    break;

  case 43: /* add_op: ADD_OP mul_op  */
#line 1217 "src/syntax.y"
                    {
        (yyval.node) = NewNode("neg", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[0].node);
        sprintf(reg_num, "$%d", reg);
        strcat(tac_code, "minus ");
        strcat(tac_code, reg_num);
        strcat(tac_code, ", ");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, "\n");
        strcpy((yyval.node)->tac_code, reg_num);
        reg++;

        if((yyval.node)->t1->type > 2){
            printf("Semantic error, type error in negative operation with type %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        } else {
            (yyval.node)->type = (yyval.node)->t1->type;
        }
    }
#line 3210 "src/syntax.tab.c"
    break;

  case 44: /* add_op: mul_op  */
#line 1237 "src/syntax.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3218 "src/syntax.tab.c"
    break;

  case 45: /* mul_op: mul_op MUL_OP op_un  */
#line 1244 "src/syntax.y"
                        {
        (yyval.node) = NewNode("multiplicative operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);

        if((yyval.node)->t1->type == 1){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t1->type;
                if(!strcmp((yyvsp[-1].token).id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, ", ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else if((yyval.node)->t1->type == 2){
            if((yyval.node)->t2->type == 1){
                (yyval.node)->type = (yyval.node)->t1->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\ninttofl $800, $800\n");
                if(!strcmp((yyvsp[-1].token).id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else if((yyval.node)->t2->type == 2){
                (yyval.node)->type = (yyval.node)->t2->type;
                strcat(tac_code, "mov $800, ");
                strcat(tac_code, (yyval.node)->t1->tac_code);
                strcat(tac_code, "\nmov $801, ");
                strcat(tac_code, (yyval.node)->t2->tac_code);
                strcat(tac_code, "\n");
                if(!strcmp((yyvsp[-1].token).id, "*")){
                    strcat(tac_code, "mul ");
                } else {
                    strcat(tac_code, "div ");
                }
                sprintf(reg_num, "$%d", reg);
                strcat(tac_code, reg_num);
                strcat(tac_code, ", $800, $801\n");
                strcpy((yyval.node)->tac_code, reg_num);
                reg++;
            } else {
                printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                errors_sem++;
            }
        } else {
            printf("Semantic error, type error in multiplicative operation with types %d and %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyval.node)->t2->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
    }
#line 3310 "src/syntax.tab.c"
    break;

  case 46: /* mul_op: op_un  */
#line 1332 "src/syntax.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3318 "src/syntax.tab.c"
    break;

  case 47: /* op_un: LIST_UN_OP op_un  */
#line 1339 "src/syntax.y"
                     {
        (yyval.node) = NewNode("unary operation", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[0].node);
        sprintf(reg_num, "$%d", reg);
        strcpy((yyval.node)->tac_code, reg_num);
        reg++;
        if((yyval.node)->t1->type != 0){
            if(!strcmp((yyvsp[-1].token).id, "!")){
                if((yyval.node)->t1->type < 3){
                    (yyval.node)->type = 1;
                    strcat(tac_code, "not ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                } else {
                    (yyval.node)->type = (yyval.node)->t1->type;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "\nmov $600, 0\n");
                    strcat(tac_code, "mov $605, 1\n");
                    strcat(tac_code, "mov $601, ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, "brz ");
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ", ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ":\nmov $603, $500[$605]\n");
                    strcat(tac_code, "mov $500[$600], $603\n");
                    strcat(tac_code, "add $600, $600, 1\n");
                    strcat(tac_code, "add $605, $605, 1\n");
                    strcat(tac_code, "sub $602, $601, $600\nbrnz ");
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ", $602\nsub ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size, ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size, 1\n");
                    strcpy((yyval.node)->tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ":\n");
                }
            } else {
                if((yyval.node)->t1->type < 3){
                    printf("Semantic error, type error on unary operator with type %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
                    errors_sem++;
                } else if(!strcmp((yyvsp[-1].token).id, "%")){
                    (yyval.node)->type = (yyval.node)->t1->type;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "\nmov $600, 0\n");
                    strcat(tac_code, "mov $605, 1\n");
                    strcat(tac_code, "mov $601, ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, "brz ");
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ", ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size\n");
                    sprintf(loop_num, "Jump%d", loop);
                    loop++;
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ":\nmov $603, $500[$605]\n");
                    strcat(tac_code, "mov $500[$600], $603\n");
                    strcat(tac_code, "add $600, $600, 1\n");
                    strcat(tac_code, "add $605, $605, 1\n");
                    strcat(tac_code, "sub $602, $601, $600\nbrnz ");
                    strcat(tac_code, loop_num);
                    strcat(tac_code, ", $602\nsub ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size, ");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "_size, 1\n");
                    strcpy((yyval.node)->tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, list_loop1);
                    strcat(tac_code, ":\n");
                } else {
                    (yyval.node)->type = (yyval.node)->t1->type - 2;
                    strcat(tac_code, "mov $500, &");
                    strcat(tac_code, (yyval.node)->t1->tac_code);
                    strcat(tac_code, "\nmov ");
                    strcat(tac_code, reg_num);
                    strcat(tac_code, ", $500[0]\n");
                }
            }
        } else {
            printf("Semantic error, type error on unary operator with type %d. Error position, Line = %d, Column = %d\n", (yyval.node)->t1->type, (yyvsp[-1].token).line, (yyvsp[-1].token).column);
            errors_sem++;
        }
    }
#line 3421 "src/syntax.tab.c"
    break;

  case 48: /* op_un: value  */
#line 1438 "src/syntax.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3429 "src/syntax.tab.c"
    break;

  case 49: /* write: WRITE '(' operation ')'  */
#line 1445 "src/syntax.y"
                            {
        (yyval.node) = NewNode("write", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-1].node);
        if((yyval.node)->t1->type == 0){
            sprintf(loop_num, "Jump%d", loop);
            loop++;
            sprintf(reg_num, "$%d", reg);
            reg++;
            strcat(tac_code, "mov $1000, ");
            sprintf(tac_code, "%ld", strlen((yyval.node)->t1->value)-2);
            strcat(tac_code, str_num);
            strcat(tac_code, "\nmov $999, 0\n");
            strcat(tac_code, loop_num);
            strcat(tac_code, ":\nmov ");
            strcat(tac_code, reg_num);
            strcat(tac_code, ", &");
            strcat(tac_code, (yyval.node)->t1->tac_code);
            strcat(tac_code, "\nmov ");
            strcat(tac_code, reg_num);
            strcat(tac_code, ", ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "[$999]\nprint ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "\nsub $1000, $1000, 1\n");
            strcat(tac_code, "add $999, $999, 1\nbrnz ");
            strcat(tac_code, loop_num);
            strcat(tac_code, ", $1000\n");
        } else {
            strcat(tac_code, "print ");
            strcat(tac_code, (yyval.node)->t1->tac_code);
            strcat(tac_code, "\n");
        }
        if(!strcmp((yyvsp[-3].token).id, "writeln")){
            strcat(tac_code, "print '\\n' \n");
        }
    }
#line 3470 "src/syntax.tab.c"
    break;

  case 50: /* read: READ '(' id ')'  */
#line 1485 "src/syntax.y"
                    {
        (yyval.node) = NewNode("read", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-1].node);
        strcat(tac_code, "scanf $665\n");
        if((yyval.node)->t1->type == 1){
            strcat(tac_code, "fltoint $665, $665\n");
        }
        strcat(tac_code, "mov ");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, ", $665\n");
    }
#line 3486 "src/syntax.tab.c"
    break;

  case 51: /* $@6: %empty  */
#line 1500 "src/syntax.y"
    {
        sprintf(if_loop, "Jump%d", loop);
        if_start = 1;
        loop++;
        ifs++;
    }
#line 3497 "src/syntax.tab.c"
    break;

  case 52: /* flow_control: $@6 if_else_statement  */
#line 1505 "src/syntax.y"
                        {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3505 "src/syntax.tab.c"
    break;

  case 53: /* flow_control: for_statement  */
#line 1509 "src/syntax.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3513 "src/syntax.tab.c"
    break;

  case 54: /* flow_control: return_statement ';'  */
#line 1513 "src/syntax.y"
                           {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3521 "src/syntax.tab.c"
    break;

  case 55: /* if_else_statement: IF_RW '(' operation ')' statement  */
#line 1520 "src/syntax.y"
                                                    {
        (yyval.node) = NewNode("if", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        (yyval.node)->type = (yyval.node)->t2->type;
        strcat(tac_code, if_loop);
        strcat(tac_code, ":\n");
        ifs++;
    }
#line 3535 "src/syntax.tab.c"
    break;

  case 56: /* $@7: %empty  */
#line 1530 "src/syntax.y"
                                                {
        if(ifs == 0){
            sprintf(end_loop1, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop1);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
            loop++;
        } else if(ifs == 1) {
            sprintf(end_loop2, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop2);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, "\n");
            loop++;
        } else if(ifs == 2) {
            sprintf(end_loop3, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop3);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
            loop++;
        } else {
            sprintf(end_loop4, "Jump%d", loop);
            strcat(tac_code, "jump ");
            strcat(tac_code, end_loop4);
            strcat(tac_code, "\n");
            strcat(tac_code, if_loop);
            strcat(tac_code, ":\n");
        }
    }
#line 3574 "src/syntax.tab.c"
    break;

  case 57: /* if_else_statement: IF_RW '(' operation ')' statement ELSE_RW $@7 statement  */
#line 1563 "src/syntax.y"
                {
        (yyval.node) = NewNode("if else", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-5].node);
        (yyval.node)->t2 = (yyvsp[-3].node);
        (yyval.node)->t3 = (yyvsp[0].node);
        (yyval.node)->type = (yyval.node)->t3->type;
        if(ifs == 0){
            strcat(tac_code, end_loop1);
        } else if(ifs == 1) {
            strcat(tac_code, end_loop2);
        } else if(ifs == 2) {
            strcat(tac_code, end_loop3);
        } else if(ifs == 3) {
            strcat(tac_code, end_loop4);
        }
        strcat(tac_code, ":\n");
        ifs--;
    }
#line 3597 "src/syntax.tab.c"
    break;

  case 58: /* $@8: %empty  */
#line 1586 "src/syntax.y"
                          {
        sprintf(for_loop1, "Jump%d", loop);
        loop++;
        sprintf(for_loop2, "Jump%d", loop);
        loop++;
        sprintf(for_loop3, "Jump%d", loop);
        loop++;
        sprintf(for_loop4, "Jump%d", loop);
        loop++;
        strcat(tac_code, for_loop1);
        strcat(tac_code, ":\n");
    }
#line 3614 "src/syntax.tab.c"
    break;

  case 59: /* $@9: %empty  */
#line 1597 "src/syntax.y"
                {
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop2);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop4);
        strcat(tac_code, ":\n");
    }
#line 3626 "src/syntax.tab.c"
    break;

  case 60: /* $@10: %empty  */
#line 1603 "src/syntax.y"
                     {
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop1);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop3);
        strcat(tac_code, ":\n");
    }
#line 3638 "src/syntax.tab.c"
    break;

  case 61: /* for_statement: FOR_RW '(' ass_op ';' $@8 operation $@9 ';' ass_op ')' $@10 statement  */
#line 1609 "src/syntax.y"
                {
        (yyval.node) = NewNode("for", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-9].node);
        (yyval.node)->t2 = (yyvsp[-6].node);
        (yyval.node)->t3 = (yyvsp[-3].node);
        (yyval.node)->t4 = (yyvsp[0].node);
        (yyval.node)->type = (yyval.node)->t4->type;
        strcat(tac_code, "jump ");
        strcat(tac_code, for_loop4);
        strcat(tac_code, "\n");
        strcat(tac_code, for_loop2);
        strcat(tac_code, ":\nbrnz ");
        strcat(tac_code, for_loop3);
        strcat(tac_code, ", ");
        strcat(tac_code, (yyval.node)->t2->tac_code);
        strcat(tac_code, "\n");
    }
#line 3660 "src/syntax.tab.c"
    break;

  case 62: /* return_statement: RETURN_RW operation  */
#line 1629 "src/syntax.y"
                        {
        (yyval.node) = NewNode("return", 0, 1, " ");
        (yyval.node)->t1 = (yyvsp[0].node);
        (yyval.node)->type = (yyval.node)->t1->type;
        strcat(tac_code, "return ");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, "\n");
        if((yyval.node)->t1->type > 2){
            strcpy(cur_ret, (yyval.node)->t1->tac_code);
            type_return = (yyval.node)->t1->type;
        }
    }
#line 3677 "src/syntax.tab.c"
    break;

  case 63: /* value: id  */
#line 1645 "src/syntax.y"
       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3685 "src/syntax.tab.c"
    break;

  case 64: /* value: function_call  */
#line 1649 "src/syntax.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3693 "src/syntax.tab.c"
    break;

  case 65: /* value: '(' operation ')'  */
#line 1653 "src/syntax.y"
                        {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3701 "src/syntax.tab.c"
    break;

  case 66: /* value: INT  */
#line 1657 "src/syntax.y"
          {
        (yyval.node) = NewNode((yyvsp[0].token).id, 1, 0, (yyvsp[0].token).id);
    }
#line 3709 "src/syntax.tab.c"
    break;

  case 67: /* value: FLOAT  */
#line 1661 "src/syntax.y"
            {
        (yyval.node) = NewNode((yyvsp[0].token).id, 1, 0, (yyvsp[0].token).id);
    }
#line 3717 "src/syntax.tab.c"
    break;

  case 68: /* value: NIL_RW  */
#line 1665 "src/syntax.y"
             {
        (yyval.node) = NewNode("nil", 3, 0, (yyvsp[0].token).id);
    }
#line 3725 "src/syntax.tab.c"
    break;

  case 69: /* value: STRING  */
#line 1669 "src/syntax.y"
             {
        strcat(tac_table, "char ");
        sprintf(str_num, "_s%d", str);
        strcat(tac_table, str_num);
        strcat(tac_table, "[] = ");
        strcat(tac_table, (yyvsp[0].token).id);
        strcat(tac_table, "\n");
        str++;
        (yyval.node) = NewNode((yyvsp[0].token).id, 0, 0, str_num);
    }
#line 3740 "src/syntax.tab.c"
    break;

  case 70: /* $@11: %empty  */
#line 1683 "src/syntax.y"
           {
        call_scope = SearchTable(Table, (yyvsp[-1].token).id, 1, 1, stack, scope_position);
    }
#line 3748 "src/syntax.tab.c"
    break;

  case 71: /* function_call: ID '(' $@11 function_params ')'  */
#line 1685 "src/syntax.y"
                          {
        if(!call_scope){
            printf("Semantic error, function %s not declared. Error position, Line = %d, Column = %d\n", (yyvsp[-4].token).id, (yyvsp[-4].token).line, (yyvsp[-4].token).column);
            errors_sem++;
        } else if(CheckParams(Table, (yyvsp[-4].token).id, -1) != args){
            printf("Semantic error, function %s with wrong number of arguments. Error position, Line = %d, Column = %d\n", (yyvsp[-4].token).id, (yyvsp[-4].token).line, (yyvsp[-4].token).column);
            errors_sem++;
        } else if(param_errors){
            printf("Semantic error, function %s with wrong types of arguments. Error position, Line = %d, Column = %d\n", (yyvsp[-4].token).id, (yyvsp[-4].token).line, (yyvsp[-4].token).column);
            param_errors = 0;
            errors_sem++;
        }
        (yyval.node) = NewNode("function call", CheckType(Table, (yyvsp[-4].token).id, stack[scope_position], 0), 0, " ");
        (yyval.node)->t2 = (yyvsp[-1].node);

        strcat(tac_code, "call _");
        strcat(tac_code, (yyvsp[-4].token).id);
        strcat(tac_code, ", ");
        sprintf(str_num, "%d", args);
        strcat(tac_code, str_num);
        strcat(tac_code, "\n");
        
        if(type_return > 2){
            strcpy((yyval.node)->tac_code, cur_ret);
        } else {
            sprintf(reg_num, "$%d", reg);
            reg++;
            strcat(tac_code, "pop ");
            strcat(tac_code, reg_num);
            strcat(tac_code, "\n");
            strcat(tac_code, reg_num);
        }
        args = 0;
    }
#line 3787 "src/syntax.tab.c"
    break;

  case 72: /* function_call: ID '(' ')'  */
#line 1720 "src/syntax.y"
                 {
        if(!SearchTable(Table, (yyvsp[-2].token).id, 1, 1, stack, scope_position)){
            printf("Semantic error, function %s not declared. Error position, Line = %d, Column = %d\n", (yyvsp[-2].token).id, (yyvsp[-2].token).line, (yyvsp[-2].token).column);
            errors_sem++;
        } else if(CheckParams(Table, (yyvsp[-2].token).id, -1) != args){
            printf("Semantic error, function %s with wrong number of arguments. Error position, Line = %d, Column = %d\n", (yyvsp[-2].token).id, (yyvsp[-2].token).line, (yyvsp[-2].token).column);
            errors_sem++;
        }
        args = 0;
        (yyval.node) = NewNode("function call", CheckType(Table, (yyvsp[-2].token).id, stack[scope_position], 0), 0, " ");
        strcat(tac_code, "call _");
        strcat(tac_code, (yyvsp[-2].token).id);
        strcat(tac_code, ", 0\n");
    }
#line 3806 "src/syntax.tab.c"
    break;

  case 73: /* id: ID  */
#line 1738 "src/syntax.y"
       {
        if(!SearchTable(Table, (yyvsp[0].token).id, 0, 0, stack, scope_position)){
            printf("Semantic error, variable %s not declared. Error position, Line = %d, Column = %d\n", (yyvsp[0].token).id, (yyvsp[0].token).line, (yyvsp[0].token).column);
            errors_sem++;
        }
        param = CheckParams(Table, (yyvsp[0].token).id, stack[scope_position]);
        sprintf(reg_num, "#%d", param - 1);
        scope_id = CheckScope(Table, (yyvsp[0].token).id, stack[scope_position]);
        sprintf(str_num, "_s%d", scope_id);
        strcpy(tac, (yyvsp[0].token).id);
        strcat(tac, str_num);
        if(param){
            (yyval.node) = NewNode((yyvsp[0].token).id, CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, reg_num);
        } else {
            (yyval.node) = NewNode((yyvsp[0].token).id, CheckType(Table, (yyvsp[0].token).id, stack[scope_position], 1), 0, tac);
        }
        
    }
#line 3829 "src/syntax.tab.c"
    break;

  case 74: /* function_params: function_params ',' operation  */
#line 1760 "src/syntax.y"
                                  {
        (yyval.node) = NewNode("params", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[-2].node);
        (yyval.node)->t2 = (yyvsp[0].node);
        args++;
        strcat(tac_code, "param ");
        strcat(tac_code, (yyval.node)->t2->tac_code);
        strcat(tac_code, "\n");

        if((yyval.node)->t2->type < 3 && CheckParamsType(Table, args, call_scope - 1) > 2){
            param_errors = 1;
        } else if((yyval.node)->t2->type > 2 && CheckParamsType(Table, args, call_scope - 1) < 3){
            param_errors = 1;
        }
    }
#line 3849 "src/syntax.tab.c"
    break;

  case 75: /* function_params: operation  */
#line 1776 "src/syntax.y"
                {
        args++;
        (yyval.node) = NewNode("params", 0, 0, " ");
        (yyval.node)->t1 = (yyvsp[0].node);
        strcat(tac_code, "param ");
        strcat(tac_code, (yyval.node)->t1->tac_code);
        strcat(tac_code, "\n");

        if((yyval.node)->t1->type < 3 && CheckParamsType(Table, args, call_scope - 1) > 2){
            param_errors = 1;
        } else if((yyval.node)->t1->type > 2 && CheckParamsType(Table, args, call_scope - 1) < 3){
            param_errors = 1;
        }
    }
#line 3868 "src/syntax.tab.c"
    break;


#line 3872 "src/syntax.tab.c"

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
          = {yyssp, yytoken};
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
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 1792 "src/syntax.y"


extern void ScopeChange(int op){
    if(op){
        scope++;
        scope_position++;
        stack[scope_position] = scope;
    } else {
        stack[scope_position] = 0;
        scope_position--;
    }
}

void yyerror(const char* message){
    printf("\nSyntax error %s. Error position, Line = %d, Column = %d\n", message, lines, columns);
    errors_sin++;
}

int main(int argc, char** argv){
    ++argv, --argc;

    if(argc > 0){
        yyin = fopen(argv[0], "r");
    }else{
        yyin = stdin;
    }
    yyparse();
    if(main_error){
        printf("Semantic error, main function not found\n");
        errors_sem++;
    }
    printf("Analysis ended with %d semantic errors, %d syntax errors and %d lexical errors.\n", errors_sem, errors_sin, errors);
    if(!errors_sin){
        PrintTree(Tree, 0);
    }

    PrintTable(Table);
    DestroyTree();

    strcat(tac_code, "\nmain:\ncall _main, 0");

    if(errors_sem + errors_sin == 0){
        CreateTac(argv[0], tac_table, tac_code);
    }

    fclose(yyin);
    yylex_destroy();
    return 0;
}
