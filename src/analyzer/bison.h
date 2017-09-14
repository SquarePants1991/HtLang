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
/* Line 1529 of yacc.c.  */
#line 166 "/Users/wangyang/Documents/Codes/OnGit/HtLang/src/analyzer/bison.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

