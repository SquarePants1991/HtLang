/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     RANGE_UNCLOSE = 305,
     RANGE_CLOSE = 306,
     IN = 307,
     COMMENT_ONE_LINE = 308,
     NEGATIVE = 309,
     BRACE = 310
   };
#endif
/* Tokens.  */
#define IntLiteral 258
#define DoubleLiteral 259
#define BoolLiteral 260
#define IDENTIFIER 261
#define Literal 262
#define BinaryOperator 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define POWER 269
#define EQ 270
#define NEQ 271
#define GT 272
#define LT 273
#define GE 274
#define LE 275
#define AND 276
#define OR 277
#define Statement 278
#define List 279
#define ASSIGN 280
#define INT 281
#define DOUBLE 282
#define BOOL 283
#define STRING 284
#define ARRAY 285
#define MAP 286
#define SEMI 287
#define COMMA 288
#define COLON 289
#define IF 290
#define ELIF 291
#define ELSE 292
#define FOR 293
#define FUNC 294
#define RETURN 295
#define WHILE 296
#define BREAK 297
#define CONTINUE 298
#define LB 299
#define RB 300
#define LCB 301
#define RCB 302
#define LSB 303
#define RSB 304
#define RANGE_UNCLOSE 305
#define RANGE_CLOSE 306
#define IN 307
#define COMMENT_ONE_LINE 308
#define NEGATIVE 309
#define BRACE 310




/* Copy the first part of user declarations.  */
#line 1 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"

#include <stdio.h>
#include <stdlib.h>
#include "../src/compiler/HTCompiler.h"
#include "../src/executor/HTExecutor.h"
#define YYDEBUG 1


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 9 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
{
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
}
/* Line 193 of yacc.c.  */
#line 228 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 241 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   708

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    36,    40,    46,    48,
      51,    54,    60,    66,    71,    79,    85,    94,   105,   109,
     112,   115,   117,   120,   123,   127,   129,   133,   135,   139,
     143,   147,   151,   155,   159,   163,   167,   171,   175,   179,
     183,   187,   191,   195,   199,   202,   207,   209,   214,   216,
     218,   220,   222,   226,   230,   234,   240,   244,   246,   248,
     250,   252,   254
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    59,    -1,    58,    59,    -1,
      75,    32,    -1,    60,    -1,    61,    -1,    62,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    76,    25,    75,    32,    -1,    81,     6,    32,    -1,
      81,     6,    25,    75,    32,    -1,    63,    -1,    62,    64,
      -1,    62,    65,    -1,    35,    75,    46,    58,    47,    -1,
      36,    75,    46,    58,    47,    -1,    37,    46,    58,    47,
      -1,    38,     6,    52,    75,    46,    58,    47,    -1,    41,
      75,    46,    58,    47,    -1,    39,     6,    44,    72,    45,
      46,    58,    47,    -1,    39,     6,    44,    72,    45,    34,
      81,    46,    58,    47,    -1,    40,    75,    32,    -1,    42,
      32,    -1,    43,    32,    -1,    73,    -1,    72,    73,    -1,
      81,     6,    -1,    81,     6,    33,    -1,    75,    -1,    74,
      33,    75,    -1,    76,    -1,    75,    50,    75,    -1,    75,
      51,    75,    -1,    75,     9,    75,    -1,    75,    10,    75,
      -1,    75,    11,    75,    -1,    75,    12,    75,    -1,    75,
      13,    75,    -1,    75,    14,    75,    -1,    75,    16,    75,
      -1,    75,    15,    75,    -1,    75,    17,    75,    -1,    75,
      19,    75,    -1,    75,    18,    75,    -1,    75,    20,    75,
      -1,    75,    21,    75,    -1,    75,    22,    75,    -1,    10,
      75,    -1,     6,    44,    74,    45,    -1,    77,    -1,    77,
      48,    75,    49,    -1,     7,    -1,    78,    -1,    80,    -1,
       6,    -1,    44,    75,    45,    -1,    48,    74,    49,    -1,
      75,    34,    75,    -1,    79,    33,     7,    34,    75,    -1,
      46,    79,    47,    -1,    26,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    63,    70,    78,    83,    87,    91,    95,
      99,   103,   107,   111,   115,   122,   130,   137,   147,   151,
     157,   166,   174,   182,   189,   200,   209,   219,   231,   238,
     244,   251,   258,   266,   272,   280,   287,   295,   296,   302,
     308,   314,   320,   326,   332,   338,   344,   350,   356,   362,
     368,   374,   380,   386,   392,   397,   408,   409,   418,   422,
     427,   432,   437,   444,   451,   461,   472,   478,   482,   486,
     490,   494,   498
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "LSB", "RSB", "RANGE_UNCLOSE", "RANGE_CLOSE", "IN", "COMMENT_ONE_LINE",
  "NEGATIVE", "BRACE", "$accept", "fragment", "statementList", "statement",
  "assignStatement", "declareStatement", "ifStatement", "pureIfStatement",
  "elifStatement", "elseStatement", "forStatement", "whileStatement",
  "funcDefStatement", "returnStatement", "breakStatement",
  "continueStatement", "parameterDefList", "parameterDef", "parameterList",
  "expression", "postfixExpression", "primaryExpression", "arrayLiteral",
  "pairList", "dictLiteral", "dataType", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    61,    61,    62,    62,
      62,    63,    64,    65,    66,    67,    68,    68,    69,    70,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    78,    79,    79,    80,    81,    81,    81,
      81,    81,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     1,     2,
       2,     5,     5,     4,     7,     5,     8,    10,     3,     2,
       2,     1,     2,     2,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     4,     1,     4,     1,     1,
       1,     1,     3,     3,     3,     5,     3,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    61,    58,     0,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     6,     7,     8,    18,     9,    10,    11,
      12,    13,    14,     0,    37,    56,    59,    60,     0,     0,
      54,    37,     0,     0,     0,     0,     0,    29,    30,     0,
       0,     0,     0,    35,     1,     4,     0,     0,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    62,     0,     0,    66,
       0,    63,     0,     0,    40,    41,    42,    43,    44,    45,
      47,    46,    48,    50,    49,    51,    52,    53,    38,    39,
       0,     0,     0,    16,    55,     0,     0,     0,    31,     0,
       0,    64,     0,    36,     0,     0,    15,    57,     0,    21,
       0,     0,    32,    33,    25,     0,     0,    23,    17,     0,
       0,     0,    34,    65,    22,    24,     0,     0,     0,    26,
       0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    58,    59,
      27,    28,    29,    30,    31,    32,   117,   118,    52,    33,
      41,    35,    36,    51,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     334,   -26,   -80,    -5,   -80,   -80,   -80,   -80,   -80,   -80,
      -5,    14,    17,    -5,    -5,    -7,    -3,    -5,    -5,    -5,
      40,   334,   -80,   -80,   -80,    20,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   374,    28,    -6,   -80,   -80,    39,    -5,
      48,   -80,   398,    19,    29,   418,   442,   -80,   -80,   461,
     504,   -17,   -27,   657,   -80,   -80,    -5,    26,   -80,   -80,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,   -80,    -5,    -5,    -5,    -5,    -8,
     -19,   334,    -5,     6,   -80,   334,   -80,    -5,    67,   -80,
      -5,   -80,   530,   334,    36,    36,    48,    48,    48,    48,
      55,    55,    55,    55,    55,    55,   154,   154,   676,   676,
     547,   573,    -5,   -80,   -80,   152,   590,   -18,   -80,    69,
     178,   657,    42,   657,   334,   204,   -80,   -80,   633,   -80,
     334,   -15,   -80,    44,   -80,    -5,   230,   -80,   -80,   256,
       6,   334,   -80,   657,   -80,   -80,    32,   282,   334,   -80,
     308,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -78,     7,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -38,    43,    41,
       0,   -80,   -80,   -80,   -80,   -79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,     1,     2,   115,   119,     3,    90,   120,     4,     5,
       6,     7,     8,     9,    90,   125,    88,   112,    39,   140,
      43,    34,    91,    44,   113,    47,   114,   131,    55,    48,
      89,   141,     4,     5,     6,     7,     8,     9,   119,    17,
      54,    18,    78,    19,    40,    79,   136,    62,    63,    64,
      65,    42,   139,    77,    45,    46,    56,    57,    49,    50,
      53,   146,    65,   147,    60,    61,    62,    63,    64,    65,
     150,    82,    93,    83,   122,   133,   135,   142,   148,   132,
      53,    34,    80,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,    92,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    34,   108,   109,   110,   111,
      34,     0,    55,   116,    34,    34,     0,    55,   121,     0,
      34,   123,    55,     0,     0,     0,    34,     0,     0,    34,
       0,    34,     0,    55,     0,     0,    55,    34,    34,     0,
      34,     0,     0,   128,    55,     0,     0,    55,     1,     2,
       0,     0,     3,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,   143,     0,     4,     5,
       6,     7,     8,     9,     1,     2,     0,    10,     3,     0,
      11,    12,    13,    14,    15,    16,    17,     0,    18,   129,
      19,     0,     0,     0,     4,     5,     6,     7,     8,     9,
       1,     2,     0,    10,     3,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    18,   134,    19,     0,     0,     0,
       4,     5,     6,     7,     8,     9,     1,     2,     0,    10,
       3,     0,    11,    12,    13,    14,    15,    16,    17,     0,
      18,   137,    19,     0,     0,     0,     4,     5,     6,     7,
       8,     9,     1,     2,     0,    10,     3,     0,    11,    12,
      13,    14,    15,    16,    17,     0,    18,   144,    19,     0,
       0,     0,     4,     5,     6,     7,     8,     9,     1,     2,
       0,    10,     3,     0,    11,    12,    13,    14,    15,    16,
      17,     0,    18,   145,    19,     0,     0,     0,     4,     5,
       6,     7,     8,     9,     1,     2,     0,    10,     3,     0,
      11,    12,    13,    14,    15,    16,    17,     0,    18,   149,
      19,     0,     0,     0,     4,     5,     6,     7,     8,     9,
       1,     2,     0,    10,     3,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    18,   151,    19,     0,     0,     0,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    10,
       0,     0,    11,    12,    13,    14,    15,    16,    17,     0,
      18,     0,    19,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,    75,    76,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,    81,     0,     0,     0,    75,    76,
      84,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,    75,    76,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    85,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,    75,    76,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    75,    76,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,   124,     0,     0,   126,
      75,    76,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    75,    76,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
      75,    76,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,    75,    76,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
       0,     6,     7,    81,    83,    10,    33,    85,    26,    27,
      28,    29,    30,    31,    33,    93,    33,    25,    44,    34,
       6,    21,    49,     6,    32,    32,    45,    45,    21,    32,
      47,    46,    26,    27,    28,    29,    30,    31,   117,    44,
       0,    46,    48,    48,     3,     6,   124,    11,    12,    13,
      14,    10,   130,    25,    13,    14,    36,    37,    17,    18,
      19,   140,    14,   141,     9,    10,    11,    12,    13,    14,
     148,    52,    46,    44,     7,     6,    34,    33,    46,   117,
      39,    81,    39,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   115,    75,    76,    77,    78,
     120,    -1,   115,    82,   124,   125,    -1,   120,    87,    -1,
     130,    90,   125,    -1,    -1,    -1,   136,    -1,    -1,   139,
      -1,   141,    -1,   136,    -1,    -1,   139,   147,   148,    -1,
     150,    -1,    -1,   112,   147,    -1,    -1,   150,     6,     7,
      -1,    -1,    10,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,   135,    -1,    26,    27,
      28,    29,    30,    31,     6,     7,    -1,    35,    10,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
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
      46,    -1,    48,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    50,    51,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    50,    51,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    50,    51,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    50,    51,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    32,
      50,    51,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    50,    51,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    51,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    50,    51,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    10,    26,    27,    28,    29,    30,    31,
      35,    38,    39,    40,    41,    42,    43,    44,    46,    48,
      57,    58,    59,    60,    61,    62,    63,    66,    67,    68,
      69,    70,    71,    75,    76,    77,    78,    80,    81,    44,
      75,    76,    75,     6,     6,    75,    75,    32,    32,    75,
      75,    79,    74,    75,     0,    59,    36,    37,    64,    65,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    32,    50,    51,    25,    48,     6,
      74,    46,    52,    44,    32,    46,    45,    34,    33,    47,
      33,    49,    75,    46,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    25,    32,    45,    58,    75,    72,    73,    81,
      58,    75,     7,    75,    46,    58,    32,    49,    75,    47,
      46,    45,    73,     6,    47,    34,    58,    47,    32,    58,
      34,    46,    33,    75,    47,    47,    81,    58,    46,    47,
      58,    47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 57 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTPropAssignStrong(HTCompilerGetCurrent(), statementList, (yyvsp[(1) - (1)].listValue));
        HTTypeRelease((yyvsp[(1) - (1)].listValue));
    ;}
    break;

  case 3:
#line 64 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, (yyvsp[(1) - (1)].statementValue));
        HTTypeRelease((yyvsp[(1) - (1)].statementValue));
        (yyval.listValue) = statementList;
    ;}
    break;

  case 4:
#line 71 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTListAppend((yyvsp[(1) - (2)].listValue), (yyvsp[(2) - (2)].statementValue));
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 5:
#line 79 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreatePureExpression((yyvsp[(1) - (2)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (2)].expressionValue));
    ;}
    break;

  case 6:
#line 84 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 7:
#line 88 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 8:
#line 92 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 9:
#line 96 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 10:
#line 100 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 11:
#line 104 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 12:
#line 108 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 13:
#line 112 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 14:
#line 116 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 15:
#line 123 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateAssign((yyvsp[(1) - (4)].expressionValue), (yyvsp[(3) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (4)].expressionValue));
    ;}
    break;

  case 16:
#line 131 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (3)].dataTypeValue), (yyvsp[(2) - (3)].stringValue)->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease((yyvsp[(2) - (3)].stringValue));
        HTTypeRelease(variable);
    ;}
    break;

  case 17:
#line 138 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (5)].dataTypeValue), (yyvsp[(2) - (5)].stringValue)->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, (yyvsp[(4) - (5)].expressionValue));
        HTTypeRelease(variable);
        HTTypeRelease((yyvsp[(2) - (5)].stringValue));
        HTTypeRelease((yyvsp[(4) - (5)].expressionValue));
    ;}
    break;

  case 18:
#line 148 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 19:
#line 152 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTStatementSetAsIfBranchStatement((yyvsp[(1) - (2)].statementValue), (yyvsp[(2) - (2)].statementValue));
        (yyval.statementValue) = (yyvsp[(1) - (2)].statementValue);
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 20:
#line 158 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTStatementSetAsIfBranchStatement((yyvsp[(1) - (2)].statementValue), (yyvsp[(2) - (2)].statementValue));
        (yyval.statementValue) = (yyvsp[(1) - (2)].statementValue);
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 21:
#line 167 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue), HTIfStatementTypeIf);
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 22:
#line 175 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue), HTIfStatementTypeElif);
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 23:
#line 183 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf(NULL, (yyvsp[(3) - (4)].listValue), HTIfStatementTypeElse);
        HTTypeRelease((yyvsp[(3) - (4)].listValue));
    ;}
    break;

  case 24:
#line 190 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[(2) - (7)].stringValue));
        (yyval.statementValue) = HTStatementCreateFor(identifier, (yyvsp[(4) - (7)].expressionValue), (yyvsp[(6) - (7)].listValue));
        HTTypeRelease((yyvsp[(2) - (7)].stringValue));
        HTTypeRelease((yyvsp[(4) - (7)].expressionValue));
        HTTypeRelease((yyvsp[(6) - (7)].listValue));
        HTTypeRelease(identifier);
    ;}
    break;

  case 25:
#line 201 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateWhile((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue));
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 26:
#line 210 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[(2) - (8)].stringValue));
        (yyval.statementValue) = HTStatementCreateFuncDef(identifier, (yyvsp[(4) - (8)].listValue), (yyvsp[(7) - (8)].listValue), HTDataTypeVoid);
        HTTypeRelease((yyvsp[(2) - (8)].stringValue));
        HTTypeRelease((yyvsp[(4) - (8)].listValue));
        HTTypeRelease((yyvsp[(7) - (8)].listValue));
        HTTypeRelease(identifier);
        printf("This is a function statement\n");
    ;}
    break;

  case 27:
#line 220 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[(2) - (10)].stringValue));
        (yyval.statementValue) = HTStatementCreateFuncDef(identifier, (yyvsp[(4) - (10)].listValue), (yyvsp[(9) - (10)].listValue), (yyvsp[(7) - (10)].dataTypeValue));
        HTTypeRelease((yyvsp[(2) - (10)].stringValue));
        HTTypeRelease((yyvsp[(4) - (10)].listValue));
        HTTypeRelease((yyvsp[(9) - (10)].listValue));
        HTTypeRelease(identifier);
    ;}
    break;

  case 28:
#line 232 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateReturn((yyvsp[(2) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(2) - (3)].expressionValue));
    ;}
    break;

  case 29:
#line 239 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateBreak();
    ;}
    break;

  case 30:
#line 245 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateContinue();
    ;}
    break;

  case 31:
#line 252 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTListRef list = HTListCreate();
        HTListAppend(list, (yyvsp[(1) - (1)].variableValue));
        HTTypeRelease((yyvsp[(1) - (1)].variableValue));
        (yyval.listValue) = list;
    ;}
    break;

  case 32:
#line 259 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
         HTListAppend((yyvsp[(1) - (2)].listValue), (yyvsp[(2) - (2)].variableValue));
         HTTypeRelease((yyvsp[(2) - (2)].variableValue));
    ;}
    break;

  case 33:
#line 267 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (2)].dataTypeValue), (yyvsp[(2) - (2)].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[(2) - (2)].stringValue));
    ;}
    break;

  case 34:
#line 273 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (3)].dataTypeValue), (yyvsp[(2) - (3)].stringValue)->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[(2) - (3)].stringValue));
    ;}
    break;

  case 35:
#line 281 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, (yyvsp[(1) - (1)].expressionValue));
        (yyval.listValue) = paramList;
        HTTypeRelease((yyvsp[(1) - (1)].expressionValue));
    ;}
    break;

  case 36:
#line 288 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTListAppend((yyvsp[(1) - (3)].listValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
        (yyval.listValue) = (yyvsp[(1) - (3)].listValue);
    ;}
    break;

  case 38:
#line 297 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorUncloseRangeArray, (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 39:
#line 303 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorCloseRangeArray, (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 40:
#line 309 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 41:
#line 315 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 42:
#line 321 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 43:
#line 327 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 44:
#line 333 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 45:
#line 339 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 46:
#line 345 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 47:
#line 351 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 48:
#line 357 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 49:
#line 363 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 50:
#line 369 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 51:
#line 375 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 52:
#line 381 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 53:
#line 387 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 54:
#line 393 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateUnaryOperation(HTExpressionUnaryOperatorNeg, (yyvsp[(2) - (2)].expressionValue));
        HTTypeRelease((yyvsp[(2) - (2)].expressionValue));
    ;}
    break;

  case 55:
#line 398 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier((yyvsp[(1) - (4)].stringValue));
        (yyval.expressionValue) = HTExpressionCreateFuncCall(identifier, (yyvsp[(3) - (4)].listValue));
        HTTypeRelease((yyvsp[(1) - (4)].stringValue));
        HTTypeRelease((yyvsp[(3) - (4)].listValue));
        HTTypeRelease(identifier);
    ;}
    break;

  case 57:
#line 410 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreatePostfixOperation(HTExpressionPostfixOperatorIndex, (yyvsp[(1) - (4)].expressionValue), (yyvsp[(3) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (4)].expressionValue));
    ;}
    break;

  case 58:
#line 419 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(1) - (1)].expressionValue);
    ;}
    break;

  case 59:
#line 423 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateArray((yyvsp[(1) - (1)].listValue));
        HTTypeRelease((yyvsp[(1) - (1)].listValue));
    ;}
    break;

  case 60:
#line 428 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateDict((yyvsp[(1) - (1)].listValue));
        HTTypeRelease((yyvsp[(1) - (1)].listValue));
    ;}
    break;

  case 61:
#line 433 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateIdentifier((yyvsp[(1) - (1)].stringValue));
        HTTypeRelease((yyvsp[(1) - (1)].stringValue));
    ;}
    break;

  case 62:
#line 438 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(2) - (3)].expressionValue);
    ;}
    break;

  case 63:
#line 445 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.listValue) = (yyvsp[(2) - (3)].listValue);
    ;}
    break;

  case 64:
#line 452 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, pair);
        (yyval.listValue) = paramList;
        HTTypeRelease(pair);
    ;}
    break;

  case 65:
#line 462 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue((yyvsp[(3) - (5)].expressionValue), (yyvsp[(5) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(5) - (5)].expressionValue));
        HTListAppend((yyvsp[(1) - (5)].listValue), pair);
        HTTypeRelease(pair);
        (yyval.listValue) = (yyvsp[(1) - (5)].listValue);
    ;}
    break;

  case 66:
#line 473 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.listValue) = (yyvsp[(2) - (3)].listValue);
    ;}
    break;

  case 67:
#line 479 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeInt
    ;}
    break;

  case 68:
#line 483 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeDouble
    ;}
    break;

  case 69:
#line 487 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeBool
    ;}
    break;

  case 70:
#line 491 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeString
    ;}
    break;

  case 71:
#line 495 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeArray
    ;}
    break;

  case 72:
#line 499 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeMap
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2277 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 504 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.y"


int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}
