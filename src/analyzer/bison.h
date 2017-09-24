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
/* Line 1529 of yacc.c.  */
#line 173 "/Users/yangwang/Documents/Projects/On Git/HtLang/src/analyzer/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

