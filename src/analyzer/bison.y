%{
#include <stdio.h>
#include <stdlib.h>
#include "../src/compiler/HTCompiler.h"
#include "../src/executor/HTExecutor.h"
#define YYDEBUG 1
%}

%union {
    HTExpressionRef expressionValue;
    HTStringRef stringValue;
    int intValue;
    double  doubleValue;
    unsigned char boolValue;
    HTStatementRef statementValue;
    HTDataType dataTypeValue;
}

%token <intValue>           IntLiteral
%token <doubleValue>        DoubleLiteral
%token <boolValue>          BoolLiteral
%token <expressionValue>    IDENTIFIER
%token <expressionValue>    Literal
%token <statementValue>     Statement

%token EQ INT DOUBLE BOOL STRING SEMI COMMA COLON
%token IF FOR FUNC
%token ADD SUB MUL DIV MOD POWER LB RB LCB RCB
%token GT LT GE LE RANGE_UNCLOSE RANGE_CLOSE IN
%token COMMENT_ONE_LINE

%type <dataTypeValue> dataType
%type <statementValue>  assignStatement declareStatement
%type <expressionValue> rangeExpression expression term primaryExpression

%%

fragment
    : statementList

statementList
    : statement
    | statementList statement
    ;

statement
    : expression SEMI
    {
        printf("This is a pure expr\n");
    }
    | assignStatement
    {
        HTCompilerAddStatement($1);
        HTTypeRelease($1);
    }
    | declareStatement
    {
        HTCompilerAddStatement($1);
        HTTypeRelease($1);
    }
    | ifStatement
    | forStatement
    | funcDefStatement
    | funcCallStatement
    ;

assignStatement
    : IDENTIFIER EQ expression SEMI
    {
        printf("This is a assign statement\n");
        $$ = HTStatementCreateAssign($1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }

declareStatement
    : dataType IDENTIFIER SEMI
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->identifier->impl->characters);
        $$ = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease($2);
        HTTypeRelease(variable);
    }
    | dataType IDENTIFIER EQ expression SEMI
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->identifier->impl->characters);
        $$ = HTStatementCreateDeclare(variable, $4);
        HTTypeRelease(variable);
        HTTypeRelease($2);
        HTTypeRelease($4);
    }

ifStatement
    : IF expression LCB statementList RCB
    {
        printf("This is a if statement\n");
    }

forStatement
    : FOR IDENTIFIER IN rangeExpression LCB statementList RCB
    {
        printf("This is a for statement\n");
    }

funcDefStatement
    : FUNC IDENTIFIER LB parameterList RB LCB statementList RCB
    {
        printf("This is a function statement\n");
    }
    | FUNC IDENTIFIER LB parameterDefList RB COLON dataType LCB statementList RCB
    {
        printf("This is a function with return statement\n");
    }

funcCallStatement
    : IDENTIFIER LB parameterList RB SEMI
    {
        printf("This is a function call statement\n");
    }

parameterDefList
    : parameterDef
    | parameterDefList parameterDef

parameterDef
    : INT IDENTIFIER
    | INT IDENTIFIER COMMA

parameterList
    : parameter
    | parameterList parameter

parameter
    : IDENTIFIER
    | IDENTIFIER COMMA

rangeExpression
    : expression RANGE_UNCLOSE expression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression RANGE_CLOSE expression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }

expression
    : term
    | expression ADD term
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorAdd, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression SUB term
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorSub, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    ;

term
    : primaryExpression
    | term POWER primaryExpression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorPower, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | term MUL primaryExpression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorMul, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | term DIV primaryExpression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorDiv, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | term MOD primaryExpression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorMod, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    ;

primaryExpression
    : Literal
    {
        $$ = $1
    }
    | IDENTIFIER
    {
        $$ = $1
    }
    | LB expression RB
    {
        $$ = $2
    }
    ;

dataType
    : INT
    {
        $$ = HTDataTypeInt
    }
    | DOUBLE
    {
        $$ = HTDataTypeDouble
    }
    | BOOL
    {
        $$ = HTDataTypeBool
    }
    | STRING
    {
        $$ = HTDataTypeString
    }
    ;

%%

int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}