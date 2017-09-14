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
     GT = 271,
     LT = 272,
     GE = 273,
     LE = 274,
     AND = 275,
     OR = 276,
     Statement = 277,
     List = 278,
     ASSIGN = 279,
     INT = 280,
     DOUBLE = 281,
     BOOL = 282,
     STRING = 283,
     ARRAY = 284,
     SEMI = 285,
     COMMA = 286,
     COLON = 287,
     IF = 288,
     ELIF = 289,
     ELSE = 290,
     FOR = 291,
     FUNC = 292,
     RETURN = 293,
     WHILE = 294,
     BREAK = 295,
     CONTINUE = 296,
     LB = 297,
     RB = 298,
     LCB = 299,
     RCB = 300,
     LSB = 301,
     RSB = 302,
     RANGE_UNCLOSE = 303,
     RANGE_CLOSE = 304,
     IN = 305,
     COMMENT_ONE_LINE = 306,
     NEGATIVE = 307
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
#define GT 271
#define LT 272
#define GE 273
#define LE 274
#define AND 275
#define OR 276
#define Statement 277
#define List 278
#define ASSIGN 279
#define INT 280
#define DOUBLE 281
#define BOOL 282
#define STRING 283
#define ARRAY 284
#define SEMI 285
#define COMMA 286
#define COLON 287
#define IF 288
#define ELIF 289
#define ELSE 290
#define FOR 291
#define FUNC 292
#define RETURN 293
#define WHILE 294
#define BREAK 295
#define CONTINUE 296
#define LB 297
#define RB 298
#define LCB 299
#define RCB 300
#define LSB 301
#define RSB 302
#define RANGE_UNCLOSE 303
#define RANGE_CLOSE 304
#define IN 305
#define COMMENT_ONE_LINE 306
#define NEGATIVE 307




/* Copy the first part of user declarations.  */
#line 1 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"

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
#line 9 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
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
}
/* Line 193 of yacc.c.  */
#line 221 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 234 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c"

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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   555

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    36,    40,    46,    48,
      51,    54,    60,    66,    71,    79,    85,    94,   105,   109,
     112,   115,   117,   121,   125,   128,   132,   136,   140,   144,
     148,   152,   156,   160,   164,   168,   172,   176,   180,   185,
     187,   190,   193,   197,   199,   202,   204,   207,   209,   211,
     213,   217,   221,   223,   225,   227,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    56,    -1,    55,    56,    -1,
      69,    30,    -1,    57,    -1,    58,    -1,    59,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,     6,    24,    69,    30,    -1,    76,     6,    30,    -1,
      76,     6,    24,    69,    30,    -1,    60,    -1,    59,    61,
      -1,    59,    62,    -1,    33,    69,    44,    55,    45,    -1,
      34,    69,    44,    55,    45,    -1,    35,    44,    55,    45,
      -1,    36,     6,    50,    69,    44,    55,    45,    -1,    39,
      69,    44,    55,    45,    -1,    37,     6,    42,    70,    43,
      44,    55,    45,    -1,    37,     6,    42,    70,    43,    32,
      76,    44,    55,    45,    -1,    38,    69,    30,    -1,    40,
      30,    -1,    41,    30,    -1,    74,    -1,    69,    48,    69,
      -1,    69,    49,    69,    -1,    10,    69,    -1,    69,     9,
      69,    -1,    69,    10,    69,    -1,    69,    11,    69,    -1,
      69,    12,    69,    -1,    69,    13,    69,    -1,    69,    14,
      69,    -1,    69,    15,    69,    -1,    69,    16,    69,    -1,
      69,    18,    69,    -1,    69,    17,    69,    -1,    69,    19,
      69,    -1,    69,    20,    69,    -1,    69,    21,    69,    -1,
       6,    42,    72,    43,    -1,    71,    -1,    70,    71,    -1,
      76,     6,    -1,    76,     6,    31,    -1,    73,    -1,    72,
      73,    -1,    69,    -1,    69,    31,    -1,     7,    -1,    75,
      -1,     6,    -1,    42,    69,    43,    -1,    46,    72,    47,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    60,    67,    75,    80,    84,    88,    92,
      96,   100,   104,   108,   112,   119,   127,   134,   144,   148,
     154,   163,   171,   179,   186,   195,   204,   212,   222,   229,
     235,   241,   242,   248,   254,   261,   267,   273,   279,   285,
     291,   297,   303,   309,   315,   321,   327,   333,   339,   348,
     355,   363,   369,   377,   384,   392,   396,   402,   406,   411,
     415,   423,   429,   433,   437,   441,   445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IntLiteral", "DoubleLiteral",
  "BoolLiteral", "IDENTIFIER", "Literal", "BinaryOperator", "ADD", "SUB",
  "MUL", "DIV", "MOD", "POWER", "EQ", "GT", "LT", "GE", "LE", "AND", "OR",
  "Statement", "List", "ASSIGN", "INT", "DOUBLE", "BOOL", "STRING",
  "ARRAY", "SEMI", "COMMA", "COLON", "IF", "ELIF", "ELSE", "FOR", "FUNC",
  "RETURN", "WHILE", "BREAK", "CONTINUE", "LB", "RB", "LCB", "RCB", "LSB",
  "RSB", "RANGE_UNCLOSE", "RANGE_CLOSE", "IN", "COMMENT_ONE_LINE",
  "NEGATIVE", "$accept", "fragment", "statementList", "statement",
  "assignStatement", "declareStatement", "ifStatement", "pureIfStatement",
  "elifStatement", "elseStatement", "forStatement", "whileStatement",
  "funcDefStatement", "returnStatement", "breakStatement",
  "continueStatement", "expression", "parameterDefList", "parameterDef",
  "parameterList", "parameter", "primaryExpression", "arrayLiteral",
  "dataType", 0
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
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    59,
      59,    60,    61,    62,    63,    64,    65,    65,    66,    67,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     1,     2,
       2,     5,     5,     4,     7,     5,     8,    10,     3,     2,
       2,     1,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     1,
       2,     2,     3,     1,     2,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    59,    57,     0,    62,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     6,     7,     8,    18,     9,    10,    11,    12,    13,
      14,     0,    31,    58,     0,     0,     0,    59,    34,     0,
       0,     0,     0,     0,    29,    30,     0,    55,     0,    53,
       1,     4,     0,     0,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      60,    56,    61,    54,     0,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    44,    43,    45,    46,    47,    32,
      33,     0,    16,    15,    48,     0,     0,     0,    49,     0,
       0,     0,     0,     0,    21,     0,     0,    50,    51,    25,
       0,    23,    17,     0,     0,     0,    52,    22,    24,     0,
       0,     0,    26,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    22,    23,    24,    54,    55,
      25,    26,    27,    28,    29,    30,    31,   107,   108,    48,
      49,    32,    33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
     258,   -18,   -76,   247,   -76,   -76,   -76,   -76,   -76,   247,
      17,    19,   247,   247,    -4,    -3,   247,   247,     4,   258,
     -76,   -76,   -76,   -26,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   296,   -76,   -76,    22,   247,   247,   -12,    23,   318,
      -8,     3,   338,   360,   -76,   -76,   379,   420,     6,   -76,
     -76,   -76,   247,     7,   -76,   -76,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   -76,
     247,   247,    14,   443,    33,   258,   247,   293,   -76,   258,
     -76,   -76,   -76,   -76,   465,   258,    71,    71,    23,    23,
      23,    23,    96,    96,    96,    96,    96,   401,   401,   528,
     528,   247,   -76,   -76,   -76,    90,   484,    -7,   -76,    41,
     114,   258,   138,   506,   -76,   258,   -27,   -76,    39,   -76,
     162,   -76,   -76,   186,   293,   258,   -76,   -76,   -76,    29,
     210,   258,   -76,   234,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -44,   -19,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,    -2,   -76,   -30,    42,
     -45,   -76,   -76,   -75
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    38,   109,    83,    50,   124,    35,    39,    52,    53,
      42,    43,    37,     2,    46,    47,     3,   125,     4,     5,
       6,     7,     8,    40,    36,    41,    44,    45,    72,    83,
      36,   105,   109,    73,    47,   110,   116,    61,   101,    37,
       2,   112,    76,     3,   102,    77,    47,   118,    16,   129,
      84,    85,    17,    82,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   120,    99,   100,
     126,   123,    47,   131,   106,    16,   104,   117,    74,    17,
       0,   130,    58,    59,    60,    61,    51,   133,     0,     0,
       0,    51,     0,    51,     0,     0,     1,     2,     0,   113,
       3,    51,     0,     0,    51,    56,    57,    58,    59,    60,
      61,    51,     0,     0,    51,     4,     5,     6,     7,     8,
       1,     2,     0,     9,     3,     0,    10,    11,    12,    13,
      14,    15,    16,     0,     0,   114,    17,     0,     0,     4,
       5,     6,     7,     8,     1,     2,     0,     9,     3,     0,
      10,    11,    12,    13,    14,    15,    16,     0,     0,   119,
      17,     0,     0,     4,     5,     6,     7,     8,     1,     2,
       0,     9,     3,     0,    10,    11,    12,    13,    14,    15,
      16,     0,     0,   121,    17,     0,     0,     4,     5,     6,
       7,     8,     1,     2,     0,     9,     3,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,   127,    17,     0,
       0,     4,     5,     6,     7,     8,     1,     2,     0,     9,
       3,     0,    10,    11,    12,    13,    14,    15,    16,     0,
       0,   128,    17,     0,     0,     4,     5,     6,     7,     8,
       1,     2,     0,     9,     3,     0,    10,    11,    12,    13,
      14,    15,    16,    37,     2,   132,    17,     3,     0,     4,
       5,     6,     7,     8,     1,     2,     0,     9,     3,     0,
      10,    11,    12,    13,    14,    15,    16,     0,     0,   134,
      17,     0,     0,     4,     5,     6,     7,     8,     0,    16,
       0,     9,     0,    17,    10,    11,    12,    13,    14,    15,
      16,     0,     0,     0,    17,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     4,     5,
       6,     7,     8,     0,     0,     0,    69,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,     0,     0,     0,    70,    71,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,     0,    75,     0,     0,     0,    70,    71,    78,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,    70,    71,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,    79,     0,     0,     0,    70,    71,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    80,     0,     0,     0,     0,    70,    71,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,    70,    71,
       0,     0,     0,   103,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     0,
       0,    70,    71,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,     0,     0,   111,
       0,     0,     0,    70,    71,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   115,     0,
       0,     0,    70,    71,     0,     0,   122,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,     0,     0,     0,    70,    71
};

static const yytype_int16 yycheck[] =
{
      19,     3,    77,    48,     0,    32,    24,     9,    34,    35,
      12,    13,     6,     7,    16,    17,    10,    44,    25,    26,
      27,    28,    29,     6,    42,     6,    30,    30,     6,    74,
      42,    75,   107,    35,    36,    79,    43,    14,    24,     6,
       7,    85,    50,    10,    30,    42,    48,     6,    42,   124,
      52,    44,    46,    47,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   111,    70,    71,
      31,   115,    74,    44,    76,    42,    43,   107,    36,    46,
      -1,   125,    11,    12,    13,    14,   105,   131,    -1,    -1,
      -1,   110,    -1,   112,    -1,    -1,     6,     7,    -1,   101,
      10,   120,    -1,    -1,   123,     9,    10,    11,    12,    13,
      14,   130,    -1,    -1,   133,    25,    26,    27,    28,    29,
       6,     7,    -1,    33,    10,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    -1,    -1,    25,
      26,    27,    28,    29,     6,     7,    -1,    33,    10,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    25,    26,    27,    28,    29,     6,     7,
      -1,    33,    10,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    46,    -1,    -1,    25,    26,    27,
      28,    29,     6,     7,    -1,    33,    10,    -1,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    45,    46,    -1,
      -1,    25,    26,    27,    28,    29,     6,     7,    -1,    33,
      10,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    45,    46,    -1,    -1,    25,    26,    27,    28,    29,
       6,     7,    -1,    33,    10,    -1,    36,    37,    38,    39,
      40,    41,    42,     6,     7,    45,    46,    10,    -1,    25,
      26,    27,    28,    29,     6,     7,    -1,    33,    10,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    45,
      46,    -1,    -1,    25,    26,    27,    28,    29,    -1,    42,
      -1,    33,    -1,    46,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    46,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    48,    49,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    30,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    48,    49,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    30,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    48,    49,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    49,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    44,    -1,
      -1,    -1,    48,    49,    -1,    -1,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    10,    25,    26,    27,    28,    29,    33,
      36,    37,    38,    39,    40,    41,    42,    46,    54,    55,
      56,    57,    58,    59,    60,    63,    64,    65,    66,    67,
      68,    69,    74,    75,    76,    24,    42,     6,    69,    69,
       6,     6,    69,    69,    30,    30,    69,    69,    72,    73,
       0,    56,    34,    35,    61,    62,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    30,
      48,    49,     6,    69,    72,    44,    50,    42,    30,    44,
      43,    31,    47,    73,    69,    44,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    24,    30,    30,    43,    55,    69,    70,    71,    76,
      55,    44,    55,    69,    45,    44,    43,    71,     6,    45,
      55,    45,    30,    55,    32,    44,    31,    45,    45,    76,
      55,    44,    45,    55,    45
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
#line 54 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTPropAssignStrong(HTCompilerGetCurrent(), statementList, (yyvsp[(1) - (1)].listValue));
        HTTypeRelease((yyvsp[(1) - (1)].listValue));
    ;}
    break;

  case 3:
#line 61 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, (yyvsp[(1) - (1)].statementValue));
        HTTypeRelease((yyvsp[(1) - (1)].statementValue));
        (yyval.listValue) = statementList;
    ;}
    break;

  case 4:
#line 68 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTListAppend((yyvsp[(1) - (2)].listValue), (yyvsp[(2) - (2)].statementValue));
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 5:
#line 76 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreatePureExpression((yyvsp[(1) - (2)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (2)].expressionValue));
    ;}
    break;

  case 6:
#line 81 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 7:
#line 85 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 8:
#line 89 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 9:
#line 93 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 10:
#line 97 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 11:
#line 101 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 12:
#line 105 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 13:
#line 109 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 14:
#line 113 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 15:
#line 120 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateAssign((yyvsp[(1) - (4)].expressionValue), (yyvsp[(3) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (4)].expressionValue));
    ;}
    break;

  case 16:
#line 128 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (3)].dataTypeValue), (yyvsp[(2) - (3)].expressionValue)->impl->identifier->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease((yyvsp[(2) - (3)].expressionValue));
        HTTypeRelease(variable);
    ;}
    break;

  case 17:
#line 135 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (5)].dataTypeValue), (yyvsp[(2) - (5)].expressionValue)->impl->identifier->impl->characters);
        (yyval.statementValue) = HTStatementCreateDeclare(variable, (yyvsp[(4) - (5)].expressionValue));
        HTTypeRelease(variable);
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].expressionValue));
    ;}
    break;

  case 18:
#line 145 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = (yyvsp[(1) - (1)].statementValue);
    ;}
    break;

  case 19:
#line 149 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTStatementSetAsIfBranchStatement((yyvsp[(1) - (2)].statementValue), (yyvsp[(2) - (2)].statementValue));
        (yyval.statementValue) = (yyvsp[(1) - (2)].statementValue);
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 20:
#line 155 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTStatementSetAsIfBranchStatement((yyvsp[(1) - (2)].statementValue), (yyvsp[(2) - (2)].statementValue));
        (yyval.statementValue) = (yyvsp[(1) - (2)].statementValue);
        HTTypeRelease((yyvsp[(2) - (2)].statementValue));
    ;}
    break;

  case 21:
#line 164 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue), HTIfStatementTypeIf);
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 22:
#line 172 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue), HTIfStatementTypeElif);
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 23:
#line 180 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateIf(NULL, (yyvsp[(3) - (4)].listValue), HTIfStatementTypeElse);
        HTTypeRelease((yyvsp[(3) - (4)].listValue));
    ;}
    break;

  case 24:
#line 187 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateFor((yyvsp[(2) - (7)].expressionValue), (yyvsp[(4) - (7)].expressionValue), (yyvsp[(6) - (7)].listValue));
        HTTypeRelease((yyvsp[(2) - (7)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (7)].expressionValue));
        HTTypeRelease((yyvsp[(6) - (7)].listValue));
    ;}
    break;

  case 25:
#line 196 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateWhile((yyvsp[(2) - (5)].expressionValue), (yyvsp[(4) - (5)].listValue));
        HTTypeRelease((yyvsp[(2) - (5)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (5)].listValue));
    ;}
    break;

  case 26:
#line 205 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateFuncDef((yyvsp[(2) - (8)].expressionValue), (yyvsp[(4) - (8)].listValue), (yyvsp[(7) - (8)].listValue), HTDataTypeVoid);
        HTTypeRelease((yyvsp[(2) - (8)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (8)].listValue));
        HTTypeRelease((yyvsp[(7) - (8)].listValue));
        printf("This is a function statement\n");
    ;}
    break;

  case 27:
#line 213 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateFuncDef((yyvsp[(2) - (10)].expressionValue), (yyvsp[(4) - (10)].listValue), (yyvsp[(9) - (10)].listValue), (yyvsp[(7) - (10)].dataTypeValue));
        HTTypeRelease((yyvsp[(2) - (10)].expressionValue));
        HTTypeRelease((yyvsp[(4) - (10)].listValue));
        HTTypeRelease((yyvsp[(9) - (10)].listValue));
    ;}
    break;

  case 28:
#line 223 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateReturn((yyvsp[(2) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(2) - (3)].expressionValue));
    ;}
    break;

  case 29:
#line 230 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateBreak();
    ;}
    break;

  case 30:
#line 236 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.statementValue) = HTStatementCreateContinue();
    ;}
    break;

  case 32:
#line 243 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorUncloseRangeArray, (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 33:
#line 249 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorCloseRangeArray, (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 34:
#line 255 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTExpressionRef zeroExpr = HTExpressionCreateDoubleLiteral(0.0);
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorSub, zeroExpr, (yyvsp[(2) - (2)].expressionValue));
        HTTypeRelease(zeroExpr);
        HTTypeRelease((yyvsp[(2) - (2)].expressionValue));
    ;}
    break;

  case 35:
#line 262 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 36:
#line 268 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 37:
#line 274 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 38:
#line 280 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 39:
#line 286 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 40:
#line 292 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 41:
#line 298 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 42:
#line 304 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 43:
#line 310 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 44:
#line 316 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 45:
#line 322 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 46:
#line 328 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 47:
#line 334 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateBinaryOperation((yyvsp[(2) - (3)].binaryOperatorValue), (yyvsp[(1) - (3)].expressionValue), (yyvsp[(3) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (3)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (3)].expressionValue));
    ;}
    break;

  case 48:
#line 340 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateFuncCall((yyvsp[(1) - (4)].expressionValue), (yyvsp[(3) - (4)].listValue));
        HTTypeRelease((yyvsp[(1) - (4)].expressionValue));
        HTTypeRelease((yyvsp[(3) - (4)].listValue));
    ;}
    break;

  case 49:
#line 349 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTListRef list = HTListCreate();
        HTListAppend(list, (yyvsp[(1) - (1)].variableValue));
        HTTypeRelease((yyvsp[(1) - (1)].variableValue));
        (yyval.listValue) = list;
    ;}
    break;

  case 50:
#line 356 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
         HTListAppend((yyvsp[(1) - (2)].listValue), (yyvsp[(2) - (2)].variableValue));
         HTTypeRelease((yyvsp[(2) - (2)].variableValue));
    ;}
    break;

  case 51:
#line 364 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (2)].dataTypeValue), (yyvsp[(2) - (2)].expressionValue)->impl->identifier->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[(2) - (2)].expressionValue));
    ;}
    break;

  case 52:
#line 370 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName((yyvsp[(1) - (3)].dataTypeValue), (yyvsp[(2) - (3)].expressionValue)->impl->identifier->impl->characters);
        (yyval.variableValue) = variable;
        HTTypeRelease((yyvsp[(2) - (3)].expressionValue));
    ;}
    break;

  case 53:
#line 378 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, (yyvsp[(1) - (1)].expressionValue));
        (yyval.listValue) = paramList;
        HTTypeRelease((yyvsp[(1) - (1)].expressionValue));
    ;}
    break;

  case 54:
#line 385 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        HTListAppend((yyvsp[(1) - (2)].listValue), (yyvsp[(2) - (2)].expressionValue));
        HTTypeRelease((yyvsp[(2) - (2)].expressionValue));
        (yyval.listValue) = (yyvsp[(1) - (2)].listValue);
    ;}
    break;

  case 55:
#line 393 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(1) - (1)].expressionValue);
    ;}
    break;

  case 56:
#line 397 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(1) - (2)].expressionValue);
    ;}
    break;

  case 57:
#line 403 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(1) - (1)].expressionValue)
    ;}
    break;

  case 58:
#line 407 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = HTExpressionCreateArray((yyvsp[(1) - (1)].expressionValue));
        HTTypeRelease((yyvsp[(1) - (1)].expressionValue));
    ;}
    break;

  case 59:
#line 412 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(1) - (1)].expressionValue)
    ;}
    break;

  case 60:
#line 416 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(2) - (3)].expressionValue)
    ;}
    break;

  case 61:
#line 424 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.expressionValue) = (yyvsp[(2) - (3)].listValue);
    ;}
    break;

  case 62:
#line 430 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeInt
    ;}
    break;

  case 63:
#line 434 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeDouble
    ;}
    break;

  case 64:
#line 438 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeBool
    ;}
    break;

  case 65:
#line 442 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeString
    ;}
    break;

  case 66:
#line 446 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"
    {
        (yyval.dataTypeValue) = HTDataTypeArray
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2169 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.c"
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


#line 451 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y"


int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}
