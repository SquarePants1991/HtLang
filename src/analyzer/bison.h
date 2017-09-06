/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     Statement = 275,
     List = 276,
     ASSIGN = 277,
     INT = 278,
     DOUBLE = 279,
     BOOL = 280,
     STRING = 281,
     SEMI = 282,
     COMMA = 283,
     COLON = 284,
     IF = 285,
     FOR = 286,
     FUNC = 287,
     LB = 288,
     RB = 289,
     LCB = 290,
     RCB = 291,
     RANGE_UNCLOSE = 292,
     RANGE_CLOSE = 293,
     IN = 294,
     COMMENT_ONE_LINE = 295
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
#define Statement 275
#define List 276
#define ASSIGN 277
#define INT 278
#define DOUBLE 279
#define BOOL 280
#define STRING 281
#define SEMI 282
#define COMMA 283
#define COLON 284
#define IF 285
#define FOR 286
#define FUNC 287
#define LB 288
#define RB 289
#define LCB 290
#define RCB 291
#define RANGE_UNCLOSE 292
#define RANGE_CLOSE 293
#define IN 294
#define COMMENT_ONE_LINE 295




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
}
/* Line 1529 of yacc.c.  */
#line 141 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

