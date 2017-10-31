/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 9 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.y" /* yacc.c:1915  */

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

#line 126 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_USERS_WANGYANG_DOCUMENTS_CODES_ONGIT_HTLANG_SRC_ANALYZER_BISON_H_INCLUDED  */
