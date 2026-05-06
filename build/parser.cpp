/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"

#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

#include "ast.hpp"

int yylex();
void yyerror(const char *message);
extern int yylineno;

#define MC_SET_LOC(node, at) \
    do { (node)->loc = mc::SourceLocation{(at).first_line, (at).first_column}; } while (0)

namespace mc {
std::unique_ptr<Program> g_parsed_program;
std::vector<std::string> g_parse_errors;
}

#line 93 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FN = 3,                         /* FN  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_DO = 8,                         /* DO  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_INT_KW = 10,                    /* INT_KW  */
  YYSYMBOL_ARROW = 11,                     /* ARROW  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_INTEGER = 18,                   /* INTEGER  */
  YYSYMBOL_IDENT = 19,                     /* IDENT  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* '{'  */
  YYSYMBOL_24_ = 24,                       /* '}'  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '?'  */
  YYSYMBOL_28_ = 28,                       /* ':'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_function_list = 39,             /* function_list  */
  YYSYMBOL_function = 40,                  /* function  */
  YYSYMBOL_type = 41,                      /* type  */
  YYSYMBOL_param_list_opt = 42,            /* param_list_opt  */
  YYSYMBOL_param_list = 43,                /* param_list  */
  YYSYMBOL_block = 44,                     /* block  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_var_decl = 47,                  /* var_decl  */
  YYSYMBOL_for_init_opt = 48,              /* for_init_opt  */
  YYSYMBOL_for_init = 49,                  /* for_init  */
  YYSYMBOL_expression_opt = 50,            /* expression_opt  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_assignment = 52,                /* assignment  */
  YYSYMBOL_ternary = 53,                   /* ternary  */
  YYSYMBOL_logical_or = 54,                /* logical_or  */
  YYSYMBOL_logical_and = 55,               /* logical_and  */
  YYSYMBOL_equality = 56,                  /* equality  */
  YYSYMBOL_relational = 57,                /* relational  */
  YYSYMBOL_additive = 58,                  /* additive  */
  YYSYMBOL_multiplicative = 59,            /* multiplicative  */
  YYSYMBOL_unary = 60,                     /* unary  */
  YYSYMBOL_primary = 61,                   /* primary  */
  YYSYMBOL_argument_list_opt = 62,         /* argument_list_opt  */
  YYSYMBOL_argument_list = 63              /* argument_list  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,    36,     2,     2,     2,    35,     2,     2,
      20,    21,    33,    31,    22,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    25,
      29,    26,    30,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    92,    97,   105,   114,   126,   130,   131,
     135,   141,   150,   160,   161,   169,   170,   175,   180,   185,
     190,   195,   200,   204,   211,   221,   222,   226,   227,   231,
     232,   236,   240,   247,   251,   256,   260,   265,   269,   274,
     278,   283,   288,   292,   297,   302,   307,   312,   316,   321,
     326,   330,   335,   340,   345,   349,   354,   359,   363,   368,
     375,   384,   388,   389,   393,   398
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
  "\"end of file\"", "error", "\"invalid token\"", "FN", "RETURN", "IF",
  "ELSE", "FOR", "DO", "WHILE", "INT_KW", "ARROW", "EQ", "NE", "LE", "GE",
  "AND", "OR", "INTEGER", "IDENT", "'('", "')'", "','", "'{'", "'}'",
  "';'", "'='", "'?'", "':'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "$accept", "program", "function_list", "function", "type",
  "param_list_opt", "param_list", "block", "statement_list", "statement",
  "var_decl", "for_init_opt", "for_init", "expression_opt", "expression",
  "assignment", "ternary", "logical_or", "logical_and", "equality",
  "relational", "additive", "multiplicative", "unary", "primary",
  "argument_list_opt", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,    -2,   -49,    28,     5,   -49,    17,    18,   -49,   -49,
      25,    40,    40,    52,    55,    58,    56,   -49,    70,    40,
      62,    40,    71,   -49,   -49,    62,   -49,    36,   -49,    43,
      72,    73,    62,   -49,    11,    43,   -49,    46,    46,    75,
     -49,   -49,    66,    74,   -49,   -49,   -11,    79,    35,     4,
      26,    54,   -49,   -49,    76,    43,     3,    88,    43,    43,
      77,    80,   -49,   -49,    78,   -49,   -49,    46,    43,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,   -49,    82,   -49,    81,   -49,   -49,    85,   -49,    86,
      87,   -49,   -49,    43,    79,    83,    35,     4,     4,    26,
      26,    26,    26,    54,    54,   -49,   -49,   -49,    62,    43,
      43,   -49,    43,   -49,    46,   102,    89,   -49,    91,   -49,
     -49,    62,    43,    90,   -49,    92,   -49,    62,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     7,     0,     2,     3,     0,     0,     1,     4,
       0,     8,     8,     0,     0,     9,     0,    10,     0,     0,
       0,     0,     0,    13,     5,     0,    11,     0,     6,     0,
       0,     0,     0,    58,    59,     0,    12,     0,     0,     0,
      22,    14,     0,     0,    31,    33,    35,    37,    39,    42,
      47,    50,    54,    57,     0,     0,    25,     0,    62,     0,
       0,    59,    55,    56,    23,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    27,     0,    26,    28,     0,    64,     0,
      63,    32,    61,     0,    36,     0,    38,    40,    41,    44,
      46,    43,    45,    48,    49,    51,    52,    53,     0,    29,
       0,    60,     0,    24,     0,    19,     0,    30,     0,    65,
      34,     0,    29,     0,    18,     0,    21,     0,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   106,    -7,   104,   -49,   -25,   -49,   -49,
      61,   -49,   -49,    -4,   -26,    60,     6,   -49,    57,    53,
      -1,   -48,    -3,   -27,   -49,   -49,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    14,    15,    24,    27,    41,
      42,    84,    85,   116,   117,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    89,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    43,    40,    54,    13,    13,    67,    57,     1,    60,
      62,    63,    22,     2,    25,     2,    68,     7,    72,    73,
      39,    33,    34,    35,    99,   100,   101,   102,     8,    82,
      86,    58,    88,    74,    75,    37,    10,    59,    11,    38,
      29,    30,    95,    31,    32,    12,     2,    70,    71,    39,
       2,   105,   106,   107,    33,    34,    35,    76,    77,    23,
      36,    33,    34,    35,    33,    61,    35,   113,    37,    97,
      98,    17,    38,   103,   104,    37,    18,    20,    37,    38,
      19,    21,    38,   115,   118,    23,   119,    78,    79,    80,
      26,    65,    55,    56,    64,    69,   124,    87,    92,    66,
      58,    81,   128,   108,    93,   110,   109,   111,   121,   112,
       9,   114,   123,   127,   122,   126,    16,    83,   125,    91,
     120,     0,    96,     0,    94
};

static const yytype_int8 yycheck[] =
{
      25,    27,    27,    29,    11,    12,    17,    32,     3,    35,
      37,    38,    19,    10,    21,    10,    27,    19,    14,    15,
      27,    18,    19,    20,    72,    73,    74,    75,     0,    55,
      56,    20,    58,    29,    30,    32,    19,    26,    20,    36,
       4,     5,    68,     7,     8,    20,    10,    12,    13,    56,
      10,    78,    79,    80,    18,    19,    20,    31,    32,    23,
      24,    18,    19,    20,    18,    19,    20,    93,    32,    70,
      71,    19,    36,    76,    77,    32,    21,    21,    32,    36,
      22,    11,    36,   108,   110,    23,   112,    33,    34,    35,
      19,    25,    20,    20,    19,    16,   121,     9,    21,    25,
      20,    25,   127,    21,    26,    20,    25,    21,     6,    22,
       4,    28,    21,    21,    25,    25,    12,    56,   122,    59,
     114,    -1,    69,    -1,    67
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    10,    38,    39,    40,    41,    19,     0,    40,
      19,    20,    20,    41,    42,    43,    42,    19,    21,    22,
      21,    11,    41,    23,    44,    41,    19,    45,    44,     4,
       5,     7,     8,    18,    19,    20,    24,    32,    36,    41,
      44,    46,    47,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    51,    20,    20,    44,    20,    26,
      51,    19,    60,    60,    19,    25,    25,    17,    27,    16,
      12,    13,    14,    15,    29,    30,    31,    32,    33,    34,
      35,    25,    51,    47,    48,    49,    51,     9,    51,    62,
      63,    52,    21,    26,    55,    51,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    21,    25,
      20,    21,    22,    51,    28,    44,    50,    51,    51,    51,
      53,     6,    25,    21,    44,    50,    25,    21,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    42,
      43,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    57,    57,    57,    57,    57,    58,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     1,     0,     1,
       2,     4,     3,     0,     2,     2,     2,     3,     7,     5,
       9,     7,     1,     2,     4,     0,     1,     1,     1,     0,
       1,     1,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     1,     1,     1,
       4,     3,     0,     1,     1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value, Location); \
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
  YY_USE (yykind);
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
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
  switch (yykind)
    {
    case YYSYMBOL_IDENT: /* IDENT  */
#line 65 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { std::free(((*yyvaluep).str)); }
#line 1320 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_program: /* program  */
#line 70 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).program); }
#line 1326 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_function_list: /* function_list  */
#line 74 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).funcs); }
#line 1332 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_function: /* function  */
#line 69 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).func); }
#line 1338 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_param_list_opt: /* param_list_opt  */
#line 72 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).params); }
#line 1344 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_param_list: /* param_list  */
#line 72 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).params); }
#line 1350 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_block: /* block  */
#line 68 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).block); }
#line 1356 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_statement_list: /* statement_list  */
#line 73 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).stmts); }
#line 1362 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 67 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1368 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_var_decl: /* var_decl  */
#line 67 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1374 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_for_init_opt: /* for_init_opt  */
#line 67 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1380 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_for_init: /* for_init  */
#line 67 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).stmt); }
#line 1386 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_expression_opt: /* expression_opt  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1392 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1398 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_assignment: /* assignment  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1404 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_ternary: /* ternary  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1410 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_logical_or: /* logical_or  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1416 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_logical_and: /* logical_and  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1422 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_equality: /* equality  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1428 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_relational: /* relational  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1434 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_additive: /* additive  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1440 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_multiplicative: /* multiplicative  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1446 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_unary: /* unary  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1452 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_primary: /* primary  */
#line 66 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).expr); }
#line 1458 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_argument_list_opt: /* argument_list_opt  */
#line 71 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).exprs); }
#line 1464 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

    case YYSYMBOL_argument_list: /* argument_list  */
#line 71 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { delete ((*yyvaluep).exprs); }
#line 1470 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
  case 2: /* program: function_list  */
#line 82 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          auto *program = new mc::Program();
          program->functions = std::move(*(yyvsp[0].funcs));
          delete (yyvsp[0].funcs);
          mc::g_parsed_program.reset(program);
          (yyval.program) = nullptr;
      }
#line 1774 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 3: /* function_list: function  */
#line 93 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.funcs) = new mc::FunctionList();
          (yyval.funcs)->push_back(std::unique_ptr<mc::FunctionDecl>((yyvsp[0].func)));
      }
#line 1783 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 4: /* function_list: function_list function  */
#line 98 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyvsp[-1].funcs)->push_back(std::unique_ptr<mc::FunctionDecl>((yyvsp[0].func)));
          (yyval.funcs) = (yyvsp[-1].funcs);
      }
#line 1792 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 5: /* function: type IDENT '(' param_list_opt ')' block  */
#line 106 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[-4].str));
          std::free((yyvsp[-4].str));
          auto params = std::move(*(yyvsp[-2].params));
          delete (yyvsp[-2].params);
          (yyval.func) = new mc::FunctionDecl(static_cast<mc::TypeKind>((yyvsp[-5].type_kind)), name, std::move(params), std::unique_ptr<mc::BlockStmt>((yyvsp[0].block)));
          MC_SET_LOC((yyval.func), (yylsp[-5]));
      }
#line 1805 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 6: /* function: FN IDENT '(' param_list_opt ')' ARROW type block  */
#line 115 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[-6].str));
          std::free((yyvsp[-6].str));
          auto params = std::move(*(yyvsp[-4].params));
          delete (yyvsp[-4].params);
          (yyval.func) = new mc::FunctionDecl(static_cast<mc::TypeKind>((yyvsp[-1].type_kind)), name, std::move(params), std::unique_ptr<mc::BlockStmt>((yyvsp[0].block)));
          MC_SET_LOC((yyval.func), (yylsp[-7]));
      }
#line 1818 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 7: /* type: INT_KW  */
#line 126 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
             { (yyval.type_kind) = static_cast<int>(mc::TypeKind::Int); }
#line 1824 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 8: /* param_list_opt: %empty  */
#line 130 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.params) = new mc::ParamList(); }
#line 1830 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 9: /* param_list_opt: param_list  */
#line 131 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.params) = (yyvsp[0].params); }
#line 1836 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 10: /* param_list: type IDENT  */
#line 136 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.params) = new mc::ParamList();
          (yyval.params)->push_back({static_cast<mc::TypeKind>((yyvsp[-1].type_kind)), std::string((yyvsp[0].str))});
          std::free((yyvsp[0].str));
      }
#line 1846 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 11: /* param_list: param_list ',' type IDENT  */
#line 142 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyvsp[-3].params)->push_back({static_cast<mc::TypeKind>((yyvsp[-1].type_kind)), std::string((yyvsp[0].str))});
          std::free((yyvsp[0].str));
          (yyval.params) = (yyvsp[-3].params);
      }
#line 1856 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 12: /* block: '{' statement_list '}'  */
#line 151 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.block) = new mc::BlockStmt();
          MC_SET_LOC((yyval.block), (yylsp[-2]));
          (yyval.block)->statements = std::move(*(yyvsp[-1].stmts));
          delete (yyvsp[-1].stmts);
      }
#line 1867 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 13: /* statement_list: %empty  */
#line 160 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.stmts) = new mc::StmtList(); }
#line 1873 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 14: /* statement_list: statement_list statement  */
#line 162 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyvsp[-1].stmts)->push_back(std::unique_ptr<mc::Stmt>((yyvsp[0].stmt)));
          (yyval.stmts) = (yyvsp[-1].stmts);
      }
#line 1882 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 15: /* statement: var_decl ';'  */
#line 169 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                   { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1888 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 16: /* statement: expression ';'  */
#line 171 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::ExprStmt(std::unique_ptr<mc::Expr>((yyvsp[-1].expr)));
          MC_SET_LOC((yyval.stmt), (yylsp[-1]));
      }
#line 1897 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 17: /* statement: RETURN expression ';'  */
#line 176 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::ReturnStmt(std::unique_ptr<mc::Expr>((yyvsp[-1].expr)));
          MC_SET_LOC((yyval.stmt), (yylsp[-2]));
      }
#line 1906 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 18: /* statement: IF '(' expression ')' block ELSE block  */
#line 181 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::IfStmt(std::unique_ptr<mc::Expr>((yyvsp[-4].expr)), std::unique_ptr<mc::BlockStmt>((yyvsp[-2].block)), std::unique_ptr<mc::BlockStmt>((yyvsp[0].block)));
          MC_SET_LOC((yyval.stmt), (yylsp[-6]));
      }
#line 1915 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 19: /* statement: IF '(' expression ')' block  */
#line 186 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::IfStmt(std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::BlockStmt>((yyvsp[0].block)), nullptr);
          MC_SET_LOC((yyval.stmt), (yylsp[-4]));
      }
#line 1924 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 20: /* statement: FOR '(' for_init_opt ';' expression_opt ';' expression_opt ')' block  */
#line 191 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::ForStmt(std::unique_ptr<mc::Stmt>((yyvsp[-6].stmt)), std::unique_ptr<mc::Expr>((yyvsp[-4].expr)), std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::BlockStmt>((yyvsp[0].block)));
          MC_SET_LOC((yyval.stmt), (yylsp[-8]));
      }
#line 1933 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 21: /* statement: DO block WHILE '(' expression ')' ';'  */
#line 196 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.stmt) = new mc::DoWhileStmt(std::unique_ptr<mc::BlockStmt>((yyvsp[-5].block)), std::unique_ptr<mc::Expr>((yyvsp[-2].expr)));
          MC_SET_LOC((yyval.stmt), (yylsp[-6]));
      }
#line 1942 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 22: /* statement: block  */
#line 200 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { (yyval.stmt) = (yyvsp[0].block); }
#line 1948 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 23: /* var_decl: type IDENT  */
#line 205 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[0].str));
          std::free((yyvsp[0].str));
          (yyval.stmt) = new mc::VarDeclStmt(static_cast<mc::TypeKind>((yyvsp[-1].type_kind)), name, nullptr);
          MC_SET_LOC((yyval.stmt), (yylsp[-1]));
      }
#line 1959 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 24: /* var_decl: type IDENT '=' expression  */
#line 212 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[-2].str));
          std::free((yyvsp[-2].str));
          (yyval.stmt) = new mc::VarDeclStmt(static_cast<mc::TypeKind>((yyvsp[-3].type_kind)), name, std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.stmt), (yylsp[-3]));
      }
#line 1970 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 25: /* for_init_opt: %empty  */
#line 221 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.stmt) = nullptr; }
#line 1976 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 26: /* for_init_opt: for_init  */
#line 222 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
               { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1982 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 27: /* for_init: var_decl  */
#line 226 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
               { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1988 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 28: /* for_init: expression  */
#line 227 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.stmt) = new mc::ExprStmt(std::unique_ptr<mc::Expr>((yyvsp[0].expr))); }
#line 1994 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 29: /* expression_opt: %empty  */
#line 231 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.expr) = nullptr; }
#line 2000 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 30: /* expression_opt: expression  */
#line 232 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2006 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 31: /* expression: assignment  */
#line 236 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2012 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 32: /* assignment: IDENT '=' assignment  */
#line 241 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[-2].str));
          std::free((yyvsp[-2].str));
          (yyval.expr) = new mc::AssignExpr(name, std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2023 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 33: /* assignment: ternary  */
#line 247 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
              { (yyval.expr) = (yyvsp[0].expr); }
#line 2029 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 34: /* ternary: logical_or '?' expression ':' ternary  */
#line 252 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::TernaryExpr(std::unique_ptr<mc::Expr>((yyvsp[-4].expr)), std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-4]));
      }
#line 2038 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 35: /* ternary: logical_or  */
#line 256 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2044 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 36: /* logical_or: logical_or OR logical_and  */
#line 261 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Or, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2053 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 37: /* logical_or: logical_and  */
#line 265 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 2059 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 38: /* logical_and: logical_and AND equality  */
#line 270 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::And, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2068 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 39: /* logical_and: equality  */
#line 274 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 2074 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 40: /* equality: equality EQ relational  */
#line 279 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Eq, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2083 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 41: /* equality: equality NE relational  */
#line 284 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Ne, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2092 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 42: /* equality: relational  */
#line 288 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 2098 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 43: /* relational: relational '<' additive  */
#line 293 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Lt, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2107 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 44: /* relational: relational LE additive  */
#line 298 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Le, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2116 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 45: /* relational: relational '>' additive  */
#line 303 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Gt, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2125 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 46: /* relational: relational GE additive  */
#line 308 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Ge, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2134 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 47: /* relational: additive  */
#line 312 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 2140 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 48: /* additive: additive '+' multiplicative  */
#line 317 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Add, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2149 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 49: /* additive: additive '-' multiplicative  */
#line 322 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Sub, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2158 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 50: /* additive: multiplicative  */
#line 326 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2164 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 51: /* multiplicative: multiplicative '*' unary  */
#line 331 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Mul, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2173 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 52: /* multiplicative: multiplicative '/' unary  */
#line 336 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Div, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2182 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 53: /* multiplicative: multiplicative '%' unary  */
#line 341 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::BinaryExpr(mc::BinaryOp::Mod, std::unique_ptr<mc::Expr>((yyvsp[-2].expr)), std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-2]));
      }
#line 2191 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 54: /* multiplicative: unary  */
#line 345 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 2197 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 55: /* unary: '-' unary  */
#line 350 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::UnaryExpr(mc::UnaryOp::Neg, std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-1]));
      }
#line 2206 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 56: /* unary: '!' unary  */
#line 355 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::UnaryExpr(mc::UnaryOp::Not, std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          MC_SET_LOC((yyval.expr), (yylsp[-1]));
      }
#line 2215 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 57: /* unary: primary  */
#line 359 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
              { (yyval.expr) = (yyvsp[0].expr); }
#line 2221 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 58: /* primary: INTEGER  */
#line 364 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.expr) = new mc::IntLiteral((yyvsp[0].int_value));
          MC_SET_LOC((yyval.expr), (yylsp[0]));
      }
#line 2230 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 59: /* primary: IDENT  */
#line 369 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[0].str));
          std::free((yyvsp[0].str));
          (yyval.expr) = new mc::VarExpr(name);
          MC_SET_LOC((yyval.expr), (yylsp[0]));
      }
#line 2241 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 60: /* primary: IDENT '(' argument_list_opt ')'  */
#line 376 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          std::string name((yyvsp[-3].str));
          std::free((yyvsp[-3].str));
          auto args = std::move(*(yyvsp[-1].exprs));
          delete (yyvsp[-1].exprs);
          (yyval.expr) = new mc::CallExpr(name, std::move(args));
          MC_SET_LOC((yyval.expr), (yylsp[-3]));
      }
#line 2254 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 61: /* primary: '(' expression ')'  */
#line 384 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 2260 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 62: /* argument_list_opt: %empty  */
#line 388 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                  { (yyval.exprs) = new mc::ExprList(); }
#line 2266 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 63: /* argument_list_opt: argument_list  */
#line 389 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
                    { (yyval.exprs) = (yyvsp[0].exprs); }
#line 2272 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 64: /* argument_list: expression  */
#line 394 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyval.exprs) = new mc::ExprList();
          (yyval.exprs)->push_back(std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
      }
#line 2281 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;

  case 65: /* argument_list: argument_list ',' expression  */
#line 399 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"
      {
          (yyvsp[-2].exprs)->push_back(std::unique_ptr<mc::Expr>((yyvsp[0].expr)));
          (yyval.exprs) = (yyvsp[-2].exprs);
      }
#line 2290 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"
    break;


#line 2294 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/build/parser.cpp"

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
        yyerror (yymsgp);
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
  yyerror (YY_("memory exhausted"));
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

#line 405 "/mnt/c/Users/cergo9991/Downloads/mini-compiler-variant-5-main/mini-compiler-variant-5-main/src/parser.y"


void yyerror(const char *message) {
    mc::g_parse_errors.push_back("line " + std::to_string(yylloc.first_line) +
                                 ", column " + std::to_string(yylloc.first_column) +
                                 ": " + message);
}
