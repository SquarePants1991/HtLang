/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "../src/compiler/HTCompiler.h"
#include "../src/executor/HTExecutor.h"
#define YYDEBUG 1

#line 74 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.h".  */
#ifndef YY_YY_USERS_WANGYANG_DOCUMENTS_CODES_ONGIT_HTLANG_SRC_ANALYZER_BISON_H_INCLUDED
# define YY_YY_USERS_WANGYANG_DOCUMENTS_CODES_ONGIT_HTLANG_SRC_ANALYZER_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IntLiteral = 258,
    DoubleLiteral = 259,
    BoolLiteral = 260,
    IDENTIFIER = 261,
    Literal = 262,
    BinaryOperator = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    POWER = 269,
    EQ = 270,
    NEQ = 271,
    GT = 272,
    LT = 273,
    GE = 274,
    LE = 275,
    AND = 276,
    OR = 277,
    Statement = 278,
    List = 279,
    ASSIGN = 280,
    INT = 281,
    DOUBLE = 282,
    BOOL = 283,
    STRING = 284,
    ARRAY = 285,
    MAP = 286,
    SEMI = 287,
    COMMA = 288,
    COLON = 289,
    IF = 290,
    ELIF = 291,
    ELSE = 292,
    FOR = 293,
    FUNC = 294,
    RETURN = 295,
    WHILE = 296,
    BREAK = 297,
    CONTINUE = 298,
    LB = 299,
    RB = 300,
    LCB = 301,
    RCB = 302,
    LSB = 303,
    RSB = 304,
    DOT = 305,
    RANGE_UNCLOSE = 306,
    RANGE_CLOSE = 307,
    IN = 308,
    COMMENT_ONE_LINE = 309,
    NEGATIVE = 310,
    BRACE = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:355  */

    HTExpressionRef expressionValue;
    HTStringRef stringValue;
    int intValue;
    double  doubleValue;
    unsigned char boolValue;
    HTStatementRef statementValue;
    HTDataType dataTypeValue;
    HTListRef listValue;
    HTExpressionBinaryOperator binaryOperatorValue;
    HTVariableRef variableValue;
    HTDictPairRef dictPairValue;

#line 185 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_WANGYANG_DOCUMENTS_CODES_ONGIT_HTLANG_SRC_ANALYZER_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   722

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    63,    70,    78,    83,    87,    91,    95,
      99,   103,   107,   111,   115,   122,   130,   137,   147,   151,
     157,   166,   174,   182,   189,   200,   209,   219,   231,   238,
     244,   251,   258,   266,   272,   280,   287,   295,   296,   302,
     308,   314,   320,   326,   332,   338,   344,   350,   356,   362,
     368,   374,   380,   386,   392,   400,   401,   407,   415,   427,
     431,   436,   441,   446,   453,   460,   470,   481,   487,   491,
     495,   499,   503,   507
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IntLiteral", "DoubleLiteral",
  "BoolLiteral", "IDENTIFIER", "Literal", "BinaryOperator", "ADD", "SUB",
  "MUL", "DIV", "MOD", "POWER", "EQ", "NEQ", "GT", "LT", "GE", "LE", "AND",
  "OR", "Statement", "List", "ASSIGN", "INT", "DOUBLE", "BOOL", "STRING",
  "ARRAY", "MAP", "SEMI", "COMMA", "COLON", "IF", "ELIF", "ELSE", "FOR",
  "FUNC", "RETURN", "WHILE", "BREAK", "CONTINUE", "LB", "RB", "LCB", "RCB",
  "LSB", "RSB", "DOT", "RANGE_UNCLOSE", "RANGE_CLOSE", "IN",
  "COMMENT_ONE_LINE", "NEGATIVE", "BRACE", "$accept", "fragment",
  "statementList", "statement", "assignStatement", "declareStatement",
  "ifStatement", "pureIfStatement", "elifStatement", "elseStatement",
  "forStatement", "whileStatement", "funcDefStatement", "returnStatement",
  "breakStatement", "continueStatement", "parameterDefList",
  "parameterDef", "parameterList", "expression", "postfixExpression",
  "primaryExpression", "arrayLiteral", "pairList", "dictLiteral",
  "dataType", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     674,   -26,   -82,    13,   -82,   -82,   -82,   -82,   -82,   -82,
      13,    18,    30,    13,    13,     9,    11,    13,    13,    13,
      44,   674,   -82,   -82,   -82,    -4,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   167,   -21,   -82,   -82,   -82,    39,    13,
      34,   -11,   191,    -1,     5,   212,   236,   -82,   -82,   256,
     300,   -17,   -18,   456,   -82,   -82,    13,    12,   -82,   -82,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   -82,    13,    13,    13,    13,    54,
      10,   -28,   674,    13,    40,   -82,   674,   -82,    13,    55,
     -82,    13,   -82,   326,   674,    66,    66,    34,    34,    34,
      34,   159,   159,   159,   159,   159,   159,   280,   280,   477,
     477,   344,   370,    20,    13,   -82,   -82,   475,   388,   -19,
     -82,    68,   518,   456,    38,   456,   674,   544,   -82,   -82,
      13,   432,   -82,   674,   -12,   -82,    42,   -82,    13,   570,
     -82,   -20,   -82,   596,    40,   674,   -82,   456,   -82,   -82,
     -82,    35,   622,   674,   -82,   648,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    62,    59,     0,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     6,     7,     8,    18,     9,    10,    11,
      12,    13,    14,     0,    37,    55,    60,    61,     0,     0,
      54,    37,     0,     0,     0,     0,     0,    29,    30,     0,
       0,     0,     0,    35,     1,     4,     0,     0,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    63,     0,     0,
      67,     0,    64,     0,     0,    40,    41,    42,    43,    44,
      45,    47,    46,    48,    50,    49,    51,    52,    53,    38,
      39,     0,     0,     0,     0,    16,    57,     0,     0,     0,
      31,     0,     0,    65,     0,    36,     0,     0,    15,    56,
       0,     0,    21,     0,     0,    32,    33,    25,     0,     0,
      23,     0,    17,     0,     0,     0,    34,    66,    22,    58,
      24,     0,     0,     0,    26,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -80,     7,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -36,   -38,    37,
       0,   -82,   -82,   -82,   -82,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    58,    59,
      27,    28,    29,    30,    31,    32,   119,   120,    52,    33,
      41,    35,    36,    51,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    81,   117,   121,    77,    91,   122,     4,     5,     6,
       7,     8,     9,    91,   127,    91,    89,   116,    39,     1,
       2,    34,   144,     3,    43,   149,   134,    78,    55,    79,
      90,    92,    56,    57,   145,   114,    44,    78,   121,    79,
      40,    47,   115,    48,    54,    80,   139,    42,    65,    84,
      45,    46,    83,   143,    49,    50,    53,    17,    94,    18,
     113,    19,   124,   151,   130,   152,     4,     5,     6,     7,
       8,     9,   138,   155,   136,   146,    53,    62,    63,    64,
      65,   153,    34,   135,     0,     0,    34,     0,     0,     0,
       0,     0,   141,    93,    34,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,   109,   110,   111,   112,     0,    34,     0,     0,
     118,     0,    34,     0,    55,   123,    34,    34,   125,    55,
       0,     0,     0,    34,    55,     0,     0,     0,     0,    34,
       0,     0,     0,    34,     0,    34,    55,     0,     0,     0,
      55,   131,    34,    34,     0,    34,     0,     0,     0,    55,
       0,     0,    55,     0,     0,     0,     0,    53,    60,    61,
      62,    63,    64,    65,     0,   147,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    75,    76,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    82,     0,     0,
       0,     0,    75,    76,    85,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,    75,    76,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,    86,     0,     0,     0,     0,    75,    76,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    87,     0,     0,     0,     0,     0,    75,    76,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    75,    76,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,   126,     0,     0,     0,   128,    75,    76,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    75,    76,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,     0,    75,
      76,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     1,     2,    75,    76,     3,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     4,     5,     6,     7,     8,     9,    75,    76,     0,
      10,     0,     0,    11,    12,    13,    14,    15,    16,    17,
       0,    18,   132,    19,     1,     2,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
       1,     2,     0,    10,     3,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    18,   137,    19,     0,     0,     0,
       4,     5,     6,     7,     8,     9,     1,     2,     0,    10,
       3,     0,    11,    12,    13,    14,    15,    16,    17,     0,
      18,   140,    19,     0,     0,     0,     4,     5,     6,     7,
       8,     9,     1,     2,     0,    10,     3,     0,    11,    12,
      13,    14,    15,    16,    17,     0,    18,   148,    19,     0,
       0,     0,     4,     5,     6,     7,     8,     9,     1,     2,
       0,    10,     3,     0,    11,    12,    13,    14,    15,    16,
      17,     0,    18,   150,    19,     0,     0,     0,     4,     5,
       6,     7,     8,     9,     1,     2,     0,    10,     3,     0,
      11,    12,    13,    14,    15,    16,    17,     0,    18,   154,
      19,     0,     0,     0,     4,     5,     6,     7,     8,     9,
       1,     2,     0,    10,     3,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    18,   156,    19,     0,     0,     0,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    10,
       0,     0,    11,    12,    13,    14,    15,    16,    17,     0,
      18,     0,    19
};

static const yytype_int16 yycheck[] =
{
       0,    39,    82,    84,    25,    33,    86,    26,    27,    28,
      29,    30,    31,    33,    94,    33,    33,    45,    44,     6,
       7,    21,    34,    10,     6,    45,    45,    48,    21,    50,
      47,    49,    36,    37,    46,    25,     6,    48,   119,    50,
       3,    32,    32,    32,     0,     6,   126,    10,    14,    44,
      13,    14,    53,   133,    17,    18,    19,    44,    46,    46,
       6,    48,     7,   144,    44,   145,    26,    27,    28,    29,
      30,    31,    34,   153,     6,    33,    39,    11,    12,    13,
      14,    46,    82,   119,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,   130,    56,    94,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,    76,    77,    78,    -1,   117,    -1,    -1,
      83,    -1,   122,    -1,   117,    88,   126,   127,    91,   122,
      -1,    -1,    -1,   133,   127,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   143,    -1,   145,   139,    -1,    -1,    -1,
     143,   114,   152,   153,    -1,   155,    -1,    -1,    -1,   152,
      -1,    -1,   155,    -1,    -1,    -1,    -1,   130,     9,    10,
      11,    12,    13,    14,    -1,   138,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    51,    52,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    51,    52,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    45,    -1,    -1,    -1,    -1,    -1,    51,    52,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    51,    52,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    32,    51,    52,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    51,    52,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,     6,     7,    51,    52,    10,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    26,    27,    28,    29,    30,    31,    51,    52,    -1,
      35,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    46,    47,    48,     6,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
       6,     7,    -1,    35,    10,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,     6,     7,    -1,    35,
      10,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,     6,     7,    -1,    35,    10,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,     6,     7,
      -1,    35,    10,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,     6,     7,    -1,    35,    10,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
       6,     7,    -1,    35,    10,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    10,    26,    27,    28,    29,    30,    31,
      35,    38,    39,    40,    41,    42,    43,    44,    46,    48,
      58,    59,    60,    61,    62,    63,    64,    67,    68,    69,
      70,    71,    72,    76,    77,    78,    79,    81,    82,    44,
      76,    77,    76,     6,     6,    76,    76,    32,    32,    76,
      76,    80,    75,    76,     0,    60,    36,    37,    65,    66,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    32,    51,    52,    25,    48,    50,
       6,    75,    46,    53,    44,    32,    46,    45,    34,    33,
      47,    33,    49,    76,    46,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,     6,    25,    32,    45,    59,    76,    73,
      74,    82,    59,    76,     7,    76,    46,    59,    32,    49,
      44,    76,    47,    46,    45,    74,     6,    47,    34,    59,
      47,    75,    32,    59,    34,    46,    33,    76,    47,    45,
      47,    82,    59,    46,    47,    59,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    62,    62,    63,    63,
      63,    64,    65,    66,    67,    68,    69,    69,    70,    71,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    79,    80,    80,    81,    82,    82,
      82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     1,     2,
       2,     5,     5,     4,     7,     5,     8,    10,     3,     2,
       2,     1,     2,     2,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     4,     4,     6,     1,
       1,     1,     1,     3,     3,     3,     5,     3,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 57 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTPropAssignStrong(HTCompilerGetCurrent(), statementList, (yyvsp[0].listValue));
        HTTypeRelease((yyvsp[0].listValue));
    }
#line 1508 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 3:
#line 64 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, (yyvsp[0].statementValue));
        HTTypeRelease((yyvsp[0].statementValue));
        (yyval.listValue) = statementList;
    }
#line 1519 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 4:
#line 71 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListAppend((yyvsp[-1].listValue), (yyvsp[0].statementValue));
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1528 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 5:
#line 79 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreatePureExpression((yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1537 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 6:
#line 84 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1545 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 7:
#line 88 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1553 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 8:
#line 92 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1561 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 9:
#line 96 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1569 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 10:
#line 100 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1577 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 11:
#line 104 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1585 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 12:
#line 108 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1593 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 13:
#line 112 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1601 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 14:
#line 116 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1609 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 15:
#line 123 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateAssign((yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1619 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 16:
#line 131 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-2].dataTypeValue), (yyvsp[-1].stringValue)->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease((yyvsp[-1].stringValue));
        HTTypeRelease(variable);
    }
#line 1630 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 17:
#line 138 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-4].dataTypeValue), (yyvsp[-3].stringValue)->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, (yyvsp[-1].expressionValue));
        HTTypeRelease(variable);
        HTTypeRelease((yyvsp[-3].stringValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1642 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 18:
#line 148 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1650 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 19:
#line 152 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTStatementSetAsIfBranchStatement((yyvsp[-1].statementValue), (yyvsp[0].statementValue));
        (yyval.statementValue) = (yyvsp[-1].statementValue);
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1660 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 20:
#line 158 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTStatementSetAsIfBranchStatement((yyvsp[-1].statementValue), (yyvsp[0].statementValue));
        (yyval.statementValue) = (yyvsp[-1].statementValue);
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1670 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 21:
#line 167 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[-3].expressionValue), (yyvsp[-1].listValue), HTIfStatementTypeIf);
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1680 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 22:
#line 175 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[-3].expressionValue), (yyvsp[-1].listValue), HTIfStatementTypeElif);
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1690 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 23:
#line 183 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf(NULL, (yyvsp[-1].listValue), HTIfStatementTypeElse);
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1699 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 24:
#line 190 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-5].stringValue));
        (yyval.statementValue) = HTStatementCreateFor(identifier, (yyvsp[-3].expressionValue), (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-5].stringValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 1712 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 25:
#line 201 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateWhile((yyvsp[-3].expressionValue), (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1722 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 26:
#line 210 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-6].stringValue));
        (yyval.statementValue) = HTStatementCreateFuncDef(identifier, (yyvsp[-4].listValue), (yyvsp[-1].listValue), HTDataTypeVoid);
        HTTypeRelease((yyvsp[-6].stringValue));
        HTTypeRelease((yyvsp[-4].listValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
        printf("This is a function statement\n");
    }
#line 1736 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 27:
#line 220 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-8].stringValue));
        (yyval.statementValue) = HTStatementCreateFuncDef(identifier, (yyvsp[-6].listValue), (yyvsp[-1].listValue), (yyvsp[-3].dataTypeValue));
        HTTypeRelease((yyvsp[-8].stringValue));
        HTTypeRelease((yyvsp[-6].listValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 1749 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 28:
#line 232 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateReturn((yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1758 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 29:
#line 239 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateBreak();
    }
#line 1766 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 30:
#line 245 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateContinue();
    }
#line 1774 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 31:
#line 252 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef list = HTListCreate();
        HTListAppend(list, (yyvsp[0].variableValue));
        HTTypeRelease((yyvsp[0].variableValue));
        (yyval.listValue) = list;
    }
#line 1785 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 32:
#line 259 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
         HTListAppend((yyvsp[-1].listValue), (yyvsp[0].variableValue));
         HTTypeRelease((yyvsp[0].variableValue));
    }
#line 1794 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 33:
#line 267 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-1].dataTypeValue), (yyvsp[0].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[0].stringValue));
    }
#line 1804 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 34:
#line 273 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-2].dataTypeValue), (yyvsp[-1].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[-1].stringValue));
    }
#line 1814 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 35:
#line 281 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, (yyvsp[0].expressionValue));
        (yyval.listValue) = paramList;
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1825 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 36:
#line 288 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListAppend((yyvsp[-2].listValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        (yyval.listValue) = (yyvsp[-2].listValue);
    }
#line 1835 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 38:
#line 297 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorUncloseRangeArray, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1845 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 39:
#line 303 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorCloseRangeArray, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1855 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 40:
#line 309 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1865 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 41:
#line 315 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1875 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 42:
#line 321 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1885 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 43:
#line 327 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1895 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 44:
#line 333 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1905 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 45:
#line 339 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1915 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 46:
#line 345 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1925 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 47:
#line 351 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1935 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 48:
#line 357 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1945 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 49:
#line 363 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1955 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 50:
#line 369 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1965 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 51:
#line 375 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1975 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 52:
#line 381 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1985 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 53:
#line 387 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1995 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 54:
#line 393 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateUnaryOperation(HTExpressionUnaryOperatorNeg, (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 2004 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 56:
#line 402 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreatePostfixOperation(HTExpressionPostfixOperatorIndex, (yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 2014 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 57:
#line 408 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-3].stringValue));
        (yyval.expressionValue) = HTExpressionCreateFuncCall(identifier, (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-3].stringValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 2026 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 58:
#line 416 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-3].stringValue));
        (yyval.expressionValue) = HTExpressionCreateMemberFuncCall((yyvsp[-5].expressionValue), identifier, (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-5].expressionValue));
        HTTypeRelease((yyvsp[-3].stringValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 2039 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 59:
#line 428 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = (yyvsp[0].expressionValue);
    }
#line 2047 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 60:
#line 432 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateArray((yyvsp[0].listValue));
        HTTypeRelease((yyvsp[0].listValue));
    }
#line 2056 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 61:
#line 437 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateDict((yyvsp[0].listValue));
        HTTypeRelease((yyvsp[0].listValue));
    }
#line 2065 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 62:
#line 442 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateIdentifier((yyvsp[0].stringValue));
        HTTypeRelease((yyvsp[0].stringValue));
    }
#line 2074 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 63:
#line 447 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = (yyvsp[-1].expressionValue);
    }
#line 2082 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 64:
#line 454 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.listValue) = (yyvsp[-1].listValue);
    }
#line 2090 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 65:
#line 461 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, pair);
        (yyval.listValue) = paramList;
        HTTypeRelease(pair);
    }
#line 2104 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 66:
#line 471 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        HTListAppend((yyvsp[-4].listValue), pair);
        HTTypeRelease(pair);
        (yyval.listValue) = (yyvsp[-4].listValue);
    }
#line 2117 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 67:
#line 482 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.listValue) = (yyvsp[-1].listValue);
    }
#line 2125 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 68:
#line 488 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeInt;
    }
#line 2133 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 69:
#line 492 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeDouble;
    }
#line 2141 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 70:
#line 496 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeBool;
    }
#line 2149 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 71:
#line 500 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeString;
    }
#line 2157 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 72:
#line 504 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeArray;
    }
#line 2165 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 73:
#line 508 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeMap;
    }
#line 2173 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;


#line 2177 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 513 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1906  */


int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}
