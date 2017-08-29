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
     Statement = 263,
     EQ = 264,
     INT = 265,
     DOUBLE = 266,
     BOOL = 267,
     STRING = 268,
     SEMI = 269,
     COMMA = 270,
     COLON = 271,
     IF = 272,
     FOR = 273,
     FUNC = 274,
     ADD = 275,
     SUB = 276,
     MUL = 277,
     DIV = 278,
     MOD = 279,
     POWER = 280,
     LB = 281,
     RB = 282,
     LCB = 283,
     RCB = 284,
     GT = 285,
     LT = 286,
     GE = 287,
     LE = 288,
     RANGE_UNCLOSE = 289,
     RANGE_CLOSE = 290,
     IN = 291,
     COMMENT_ONE_LINE = 292
   };
#endif
/* Tokens.  */
#define IntLiteral 258
#define DoubleLiteral 259
#define BoolLiteral 260
#define IDENTIFIER 261
#define Literal 262
#define Statement 263
#define EQ 264
#define INT 265
#define DOUBLE 266
#define BOOL 267
#define STRING 268
#define SEMI 269
#define COMMA 270
#define COLON 271
#define IF 272
#define FOR 273
#define FUNC 274
#define ADD 275
#define SUB 276
#define MUL 277
#define DIV 278
#define MOD 279
#define POWER 280
#define LB 281
#define RB 282
#define LCB 283
#define RCB 284
#define GT 285
#define LT 286
#define GE 287
#define LE 288
#define RANGE_UNCLOSE 289
#define RANGE_CLOSE 290
#define IN 291
#define COMMENT_ONE_LINE 292




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
}
/* Line 1529 of yacc.c.  */
#line 133 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

