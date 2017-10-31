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
    NIL = 287,
    SEMI = 288,
    COMMA = 289,
    COLON = 290,
    IF = 291,
    ELIF = 292,
    ELSE = 293,
    FOR = 294,
    FUNC = 295,
    RETURN = 296,
    WHILE = 297,
    BREAK = 298,
    CONTINUE = 299,
    LB = 300,
    RB = 301,
    LCB = 302,
    RCB = 303,
    LSB = 304,
    RSB = 305,
    DOT = 306,
    RANGE_UNCLOSE = 307,
    RANGE_CLOSE = 308,
    IN = 309,
    COMMENT_ONE_LINE = 310,
    NEGATIVE = 311,
    BRACE = 312
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

#line 186 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_WANGYANG_DOCUMENTS_CODES_ONGIT_HTLANG_SRC_ANALYZER_BISON_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:358  */

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   740

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    63,    70,    78,    83,    87,    91,    95,
      99,   103,   107,   111,   115,   122,   130,   137,   147,   151,
     157,   166,   174,   182,   189,   200,   209,   218,   230,   237,
     243,   250,   257,   265,   271,   279,   286,   294,   295,   301,
     307,   313,   319,   325,   331,   337,   343,   349,   355,   361,
     367,   373,   379,   385,   391,   399,   400,   406,   415,   423,
     432,   445,   449,   454,   459,   464,   471,   478,   488,   499,
     503,   510,   514,   518,   522,   526,   530,   534
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
  "ARRAY", "MAP", "NIL", "SEMI", "COMMA", "COLON", "IF", "ELIF", "ELSE",
  "FOR", "FUNC", "RETURN", "WHILE", "BREAK", "CONTINUE", "LB", "RB", "LCB",
  "RCB", "LSB", "RSB", "DOT", "RANGE_UNCLOSE", "RANGE_CLOSE", "IN",
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     691,   -35,   -85,    77,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,    77,     7,    10,    77,    77,     6,     8,    77,    14,
      77,    49,   691,   -85,   -85,   -85,    -1,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   170,   -18,   -85,   -85,   -85,    44,
      -2,    40,   -32,   195,     4,    15,   216,   241,   -85,   -85,
     261,   -85,   306,   -22,   -25,   466,   -85,   -85,    77,    18,
     -85,   -85,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,   -85,    77,    77,    77,
      77,    64,     9,   -85,   -23,   691,    77,   135,   -85,   691,
     -85,    77,    65,   -85,    77,   -85,   333,   691,    67,    67,
      40,    40,    40,    40,   184,   184,   184,   184,   184,   184,
     286,   286,   487,   487,   351,   378,    28,    77,   -85,   -85,
     485,   396,   393,   -85,    69,   529,   466,    41,   466,   691,
     556,   -85,   -85,    22,   441,   -85,   691,   -20,   -85,    48,
     -85,    77,   583,   -85,   -85,   -16,   -85,   610,   135,   691,
     -85,   466,   -85,   -85,   -85,    39,   637,   691,   -85,   664,
     -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    61,     0,    71,    72,    73,    74,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     6,     7,     8,    18,     9,    10,
      11,    12,    13,    14,     0,    37,    55,    62,    63,     0,
       0,    54,    37,     0,     0,     0,     0,     0,    29,    30,
       0,    70,     0,     0,     0,    35,     1,     4,     0,     0,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,    28,     0,
      65,     0,     0,    69,     0,    66,     0,     0,    40,    41,
      42,    43,    44,    45,    47,    46,    48,    50,    49,    51,
      52,    53,    38,    39,     0,     0,     0,     0,    16,    58,
       0,     0,     0,    31,     0,     0,    67,     0,    36,     0,
       0,    15,    56,     0,     0,    21,     0,     0,    32,    33,
      25,     0,     0,    23,    60,     0,    17,     0,     0,     0,
      34,    68,    22,    59,    24,     0,     0,     0,    26,     0,
      27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -83,    13,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -34,   -39,    37,
       0,   -85,   -85,   -85,   -85,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    22,    23,    24,    25,    26,    27,    60,    61,
      28,    29,    30,    31,    32,    33,   122,   123,    54,    34,
      42,    36,    37,    53,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    84,   120,   124,     1,     2,   125,    79,     3,    94,
      40,    94,    92,    44,   130,   148,    45,    80,    94,    81,
       1,     2,    35,   119,     3,    95,    93,   149,     1,     2,
     153,    80,     3,    81,   117,    57,    58,    59,   124,    48,
      41,    49,   118,    18,    83,    19,   142,    20,    43,    56,
      82,    46,    47,   147,    67,    50,    52,    55,    86,    18,
      87,    19,    51,    20,   155,    97,   156,    18,   144,    19,
     116,    20,   127,   133,   159,   139,   141,    55,    64,    65,
      66,    67,   150,     1,     2,    35,   157,     3,   138,    35,
       0,     0,     0,     0,   145,    96,     0,    35,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,   114,   115,     0,     0,
      35,     0,    18,   121,    19,    35,    20,     0,   126,    35,
      35,   128,     0,    57,     0,     0,    35,     0,    57,     0,
       0,     0,    35,    57,     0,     0,     0,    35,     0,    35,
       0,     0,     0,     0,   134,    57,    35,    35,     0,    35,
      57,     4,     5,     6,     7,     8,     9,    10,     0,    57,
      55,     0,    57,     0,     0,     0,     0,     0,   151,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    62,    63,    64,    65,    66,    67,     0,
       0,     0,     0,    76,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,    77,    78,     0,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,    85,     0,     0,     0,     0,    77,    78,    88,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,    77,    78,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,    89,     0,
       0,     0,     0,    77,    78,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    90,     0,     0,
       0,     0,     0,    77,    78,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    77,    78,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,   131,    77,    78,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    77,    78,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     4,
       5,     6,     7,     8,     9,    10,     0,     0,   132,     0,
      77,    78,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,     0,   136,     0,     0,     0,     0,    77,    78,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     1,     2,    77,    78,     3,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     4,     5,     6,     7,     8,     9,    10,    77,    78,
       0,    11,     0,     0,    12,    13,    14,    15,    16,    17,
      18,     0,    19,   135,    20,     1,     2,     0,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     1,     2,     0,    11,     3,     0,    12,    13,
      14,    15,    16,    17,    18,     0,    19,   140,    20,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     1,
       2,     0,    11,     3,     0,    12,    13,    14,    15,    16,
      17,    18,     0,    19,   143,    20,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     1,     2,     0,    11,
       3,     0,    12,    13,    14,    15,    16,    17,    18,     0,
      19,   152,    20,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     1,     2,     0,    11,     3,     0,    12,
      13,    14,    15,    16,    17,    18,     0,    19,   154,    20,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       1,     2,     0,    11,     3,     0,    12,    13,    14,    15,
      16,    17,    18,     0,    19,   158,    20,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     1,     2,     0,
      11,     3,     0,    12,    13,    14,    15,    16,    17,    18,
       0,    19,   160,    20,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    11,     0,     0,
      12,    13,    14,    15,    16,    17,    18,     0,    19,     0,
      20
};

static const yytype_int16 yycheck[] =
{
       0,    40,    85,    87,     6,     7,    89,    25,    10,    34,
      45,    34,    34,     6,    97,    35,     6,    49,    34,    51,
       6,     7,    22,    46,    10,    50,    48,    47,     6,     7,
      46,    49,    10,    51,    25,    22,    37,    38,   122,    33,
       3,    33,    33,    45,    46,    47,   129,    49,    11,     0,
       6,    14,    15,   136,    14,    18,    19,    20,    54,    45,
      45,    47,    48,    49,   148,    47,   149,    45,    46,    47,
       6,    49,     7,    45,   157,     6,    35,    40,    11,    12,
      13,    14,    34,     6,     7,    85,    47,    10,   122,    89,
      -1,    -1,    -1,    -1,   133,    58,    -1,    97,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    -1,    -1,
     120,    -1,    45,    86,    47,   125,    49,    -1,    91,   129,
     130,    94,    -1,   120,    -1,    -1,   136,    -1,   125,    -1,
      -1,    -1,   142,   130,    -1,    -1,    -1,   147,    -1,   149,
      -1,    -1,    -1,    -1,   117,   142,   156,   157,    -1,   159,
     147,    26,    27,    28,    29,    30,    31,    32,    -1,   156,
     133,    -1,   159,    -1,    -1,    -1,    -1,    -1,   141,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    52,    53,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    33,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    52,    53,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    46,    -1,    -1,
      -1,    -1,    -1,    52,    53,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    52,    53,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    33,    52,    53,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    52,    53,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    50,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,     6,     7,    52,    53,    10,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    26,    27,    28,    29,    30,    31,    32,    52,    53,
      -1,    36,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    -1,    47,    48,    49,     6,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,     6,     7,    -1,    36,    10,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    47,    48,    49,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,     6,
       7,    -1,    36,    10,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,     6,     7,    -1,    36,
      10,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    48,    49,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,     6,     7,    -1,    36,    10,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
       6,     7,    -1,    36,    10,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    47,    48,    49,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,     6,     7,    -1,
      36,    10,    -1,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    48,    49,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    47,    -1,
      49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    10,    26,    27,    28,    29,    30,    31,
      32,    36,    39,    40,    41,    42,    43,    44,    45,    47,
      49,    59,    60,    61,    62,    63,    64,    65,    68,    69,
      70,    71,    72,    73,    77,    78,    79,    80,    82,    83,
      45,    77,    78,    77,     6,     6,    77,    77,    33,    33,
      77,    48,    77,    81,    76,    77,     0,    61,    37,    38,
      66,    67,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    33,    52,    53,    25,
      49,    51,     6,    46,    76,    47,    54,    45,    33,    47,
      46,    35,    34,    48,    34,    50,    77,    47,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,     6,    25,    33,    46,
      60,    77,    74,    75,    83,    60,    77,     7,    77,    47,
      60,    33,    50,    45,    77,    48,    47,    46,    75,     6,
      48,    35,    60,    48,    46,    76,    33,    60,    35,    47,
      34,    77,    48,    46,    48,    83,    60,    47,    48,    60,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    64,    64,
      64,    65,    66,    67,    68,    69,    70,    70,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    80,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     1,     2,
       2,     5,     5,     4,     7,     5,     8,    10,     3,     2,
       2,     1,     2,     2,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     4,     3,     4,     6,
       5,     1,     1,     1,     1,     3,     3,     3,     5,     3,
       2,     1,     1,     1,     1,     1,     1,     1
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
#line 1516 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 3:
#line 64 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, (yyvsp[0].statementValue));
        HTTypeRelease((yyvsp[0].statementValue));
        (yyval.listValue) = statementList;
    }
#line 1527 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 4:
#line 71 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListAppend((yyvsp[-1].listValue), (yyvsp[0].statementValue));
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1536 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 5:
#line 79 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreatePureExpression((yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1545 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 6:
#line 84 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1553 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 7:
#line 88 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1561 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 8:
#line 92 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1569 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 9:
#line 96 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1577 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 10:
#line 100 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1585 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 11:
#line 104 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1593 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 12:
#line 108 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1601 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 13:
#line 112 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1609 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 14:
#line 116 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1617 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 15:
#line 123 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateAssign((yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1627 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 16:
#line 131 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-2].dataTypeValue), (yyvsp[-1].stringValue)->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease((yyvsp[-1].stringValue));
        HTTypeRelease(variable);
    }
#line 1638 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
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
#line 1650 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 18:
#line 148 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = (yyvsp[0].statementValue);
    }
#line 1658 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 19:
#line 152 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTStatementSetAsIfBranchStatement((yyvsp[-1].statementValue), (yyvsp[0].statementValue));
        (yyval.statementValue) = (yyvsp[-1].statementValue);
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1668 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 20:
#line 158 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTStatementSetAsIfBranchStatement((yyvsp[-1].statementValue), (yyvsp[0].statementValue));
        (yyval.statementValue) = (yyvsp[-1].statementValue);
        HTTypeRelease((yyvsp[0].statementValue));
    }
#line 1678 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 21:
#line 167 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[-3].expressionValue), (yyvsp[-1].listValue), HTIfStatementTypeIf);
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1688 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 22:
#line 175 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[-3].expressionValue), (yyvsp[-1].listValue), HTIfStatementTypeElif);
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1698 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 23:
#line 183 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateIf(NULL, (yyvsp[-1].listValue), HTIfStatementTypeElse);
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1707 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
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
#line 1720 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 25:
#line 201 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateWhile((yyvsp[-3].expressionValue), (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].listValue));
    }
#line 1730 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
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
    }
#line 1743 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 27:
#line 219 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-8].stringValue));
        (yyval.statementValue) = HTStatementCreateFuncDef(identifier, (yyvsp[-6].listValue), (yyvsp[-1].listValue), (yyvsp[-3].dataTypeValue));
        HTTypeRelease((yyvsp[-8].stringValue));
        HTTypeRelease((yyvsp[-6].listValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 1756 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 28:
#line 231 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateReturn((yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 1765 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 29:
#line 238 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateBreak();
    }
#line 1773 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 30:
#line 244 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.statementValue) = HTStatementCreateContinue();
    }
#line 1781 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 31:
#line 251 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef list = HTListCreate();
        HTListAppend(list, (yyvsp[0].variableValue));
        HTTypeRelease((yyvsp[0].variableValue));
        (yyval.listValue) = list;
    }
#line 1792 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 32:
#line 258 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
         HTListAppend((yyvsp[-1].listValue), (yyvsp[0].variableValue));
         HTTypeRelease((yyvsp[0].variableValue));
    }
#line 1801 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 33:
#line 266 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-1].dataTypeValue), (yyvsp[0].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[0].stringValue));
    }
#line 1811 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 34:
#line 272 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[-2].dataTypeValue), (yyvsp[-1].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[-1].stringValue));
    }
#line 1821 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 35:
#line 280 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, (yyvsp[0].expressionValue));
        (yyval.listValue) = paramList;
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1832 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 36:
#line 287 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListAppend((yyvsp[-2].listValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        (yyval.listValue) = (yyvsp[-2].listValue);
    }
#line 1842 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 38:
#line 296 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorUncloseRangeArray, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1852 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 39:
#line 302 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorCloseRangeArray, (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1862 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 40:
#line 308 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1872 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 41:
#line 314 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1882 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 42:
#line 320 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1892 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 43:
#line 326 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1902 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 44:
#line 332 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1912 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 45:
#line 338 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1922 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 46:
#line 344 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1932 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 47:
#line 350 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1942 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 48:
#line 356 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1952 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 49:
#line 362 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1962 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 50:
#line 368 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1972 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 51:
#line 374 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1982 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 52:
#line 380 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 1992 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 53:
#line 386 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[-1].binaryOperatorValue), (yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 2002 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 54:
#line 392 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateUnaryOperation(HTExpressionUnaryOperatorNeg, (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
    }
#line 2011 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 56:
#line 401 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreatePostfixOperation(HTExpressionPostfixOperatorIndex, (yyvsp[-3].expressionValue), (yyvsp[-1].expressionValue));
        HTTypeRelease((yyvsp[-3].expressionValue));
        HTTypeRelease((yyvsp[-1].expressionValue));
    }
#line 2021 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 57:
#line 407 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-2].stringValue));
        HTListRef parameterList = HTListCreate();
        (yyval.expressionValue) = HTExpressionCreateFuncCall(identifier, parameterList);
        HTTypeRelease((yyvsp[-2].stringValue));
        HTTypeRelease(parameterList);
        HTTypeRelease(identifier);
    }
#line 2034 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 58:
#line 416 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-3].stringValue));
        (yyval.expressionValue) = HTExpressionCreateFuncCall(identifier, (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-3].stringValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 2046 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 59:
#line 424 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-3].stringValue));
        (yyval.expressionValue) = HTExpressionCreateMemberFuncCall((yyvsp[-5].expressionValue), identifier, (yyvsp[-1].listValue));
        HTTypeRelease((yyvsp[-5].expressionValue));
        HTTypeRelease((yyvsp[-3].stringValue));
        HTTypeRelease((yyvsp[-1].listValue));
        HTTypeRelease(identifier);
    }
#line 2059 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 60:
#line 433 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[-2].stringValue));
        HTListRef parameterList = HTListCreate();
        (yyval.expressionValue) = HTExpressionCreateMemberFuncCall((yyvsp[-4].expressionValue), identifier, parameterList);
        HTTypeRelease((yyvsp[-4].expressionValue));
        HTTypeRelease((yyvsp[-2].stringValue));
        HTTypeRelease(parameterList);
        HTTypeRelease(identifier);
    }
#line 2073 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 61:
#line 446 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = (yyvsp[0].expressionValue);
    }
#line 2081 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 62:
#line 450 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateArray((yyvsp[0].listValue));
        HTTypeRelease((yyvsp[0].listValue));
    }
#line 2090 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 63:
#line 455 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateDict((yyvsp[0].listValue));
        HTTypeRelease((yyvsp[0].listValue));
    }
#line 2099 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 64:
#line 460 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = HTExpressionCreateIdentifier((yyvsp[0].stringValue));
        HTTypeRelease((yyvsp[0].stringValue));
    }
#line 2108 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 65:
#line 465 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.expressionValue) = (yyvsp[-1].expressionValue);
    }
#line 2116 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 66:
#line 472 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.listValue) = (yyvsp[-1].listValue);
    }
#line 2124 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 67:
#line 479 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, pair);
        (yyval.listValue) = paramList;
        HTTypeRelease(pair);
    }
#line 2138 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 68:
#line 489 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[-2].expressionValue), (yyvsp[0].expressionValue));
        HTTypeRelease((yyvsp[-2].expressionValue));
        HTTypeRelease((yyvsp[0].expressionValue));
        HTListAppend((yyvsp[-4].listValue), pair);
        HTTypeRelease(pair);
        (yyval.listValue) = (yyvsp[-4].listValue);
    }
#line 2151 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 69:
#line 500 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.listValue) = (yyvsp[-1].listValue);
    }
#line 2159 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 70:
#line 504 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        HTListRef paramList = HTListCreate();
        (yyval.listValue) = paramList;
    }
#line 2168 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 71:
#line 511 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeInt;
    }
#line 2176 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 72:
#line 515 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeDouble;
    }
#line 2184 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 73:
#line 519 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeBool;
    }
#line 2192 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 74:
#line 523 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeString;
    }
#line 2200 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 75:
#line 527 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeArray;
    }
#line 2208 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 76:
#line 531 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeMap;
    }
#line 2216 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;

  case 77:
#line 535 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1661  */
    {
        (yyval.dataTypeValue) = HTDataTypeNil;
    }
#line 2224 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
    break;


#line 2228 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c" /* yacc.c:1661  */
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
#line 540 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1906  */


int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}
