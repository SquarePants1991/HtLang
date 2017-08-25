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
     ExpressionValue = 262,
     EQ = 263,
     INT = 264,
     DOUBLE = 265,
     BOOL = 266,
     SEMI = 267,
     COMMA = 268,
     COLON = 269,
     IF = 270,
     FOR = 271,
     FUNC = 272,
     ADD = 273,
     SUB = 274,
     MUL = 275,
     DIV = 276,
     LB = 277,
     RB = 278,
     LCB = 279,
     RCB = 280,
     GT = 281,
     LT = 282,
     GE = 283,
     LE = 284,
     RANGE_UNCLOSE = 285,
     RANGE_CLOSE = 286,
     IN = 287,
     COMMENT_ONE_LINE = 288
   };
#endif
/* Tokens.  */
#define IntLiteral 258
#define DoubleLiteral 259
#define BoolLiteral 260
#define IDENTIFIER 261
#define ExpressionValue 262
#define EQ 263
#define INT 264
#define DOUBLE 265
#define BOOL 266
#define SEMI 267
#define COMMA 268
#define COLON 269
#define IF 270
#define FOR 271
#define FUNC 272
#define ADD 273
#define SUB 274
#define MUL 275
#define DIV 276
#define LB 277
#define RB 278
#define LCB 279
#define RCB 280
#define GT 281
#define LT 282
#define GE 283
#define LE 284
#define RANGE_UNCLOSE 285
#define RANGE_CLOSE 286
#define IN 287
#define COMMENT_ONE_LINE 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 8 "./bison.y"
{
    HTExpression expressionValue;
    int intValue;
    double  doubleValue;
    unsigned char boolValue;
}
/* Line 1529 of yacc.c.  */
#line 122 "./src/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

