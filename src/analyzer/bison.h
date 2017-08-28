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
     SEMI = 268,
     COMMA = 269,
     COLON = 270,
     IF = 271,
     FOR = 272,
     FUNC = 273,
     ADD = 274,
     SUB = 275,
     MUL = 276,
     DIV = 277,
     MOD = 278,
     POWER = 279,
     LB = 280,
     RB = 281,
     LCB = 282,
     RCB = 283,
     GT = 284,
     LT = 285,
     GE = 286,
     LE = 287,
     RANGE_UNCLOSE = 288,
     RANGE_CLOSE = 289,
     IN = 290,
     COMMENT_ONE_LINE = 291
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
#define SEMI 268
#define COMMA 269
#define COLON 270
#define IF 271
#define FOR 272
#define FUNC 273
#define ADD 274
#define SUB 275
#define MUL 276
#define DIV 277
#define MOD 278
#define POWER 279
#define LB 280
#define RB 281
#define LCB 282
#define RCB 283
#define GT 284
#define LT 285
#define GE 286
#define LE 287
#define RANGE_UNCLOSE 288
#define RANGE_CLOSE 289
#define IN 290
#define COMMENT_ONE_LINE 291




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
#line 131 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

