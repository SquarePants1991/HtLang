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
    HTListRef listValue;
    HTExpressionBinaryOperator binaryOperatorValue;
}

%token <intValue>               IntLiteral
%token <doubleValue>            DoubleLiteral
%token <boolValue>              BoolLiteral
%token <expressionValue>        IDENTIFIER
%token <expressionValue>        Literal
%token <binaryOperatorValue>    BinaryOperator ADD SUB MUL DIV MOD POWER EQ GT LT GE LE
%token <statementValue>         Statement
%token <listValue>              List

%token ASSIGN INT DOUBLE BOOL STRING SEMI COMMA COLON
%token IF FOR FUNC
%token LB RB LCB RCB
%token EQ GT LT GE LE RANGE_UNCLOSE RANGE_CLOSE IN
%token COMMENT_ONE_LINE

%type <dataTypeValue> dataType
%type <listValue> statementList
%type <statementValue>  statement assignStatement declareStatement ifStatement
%type <expressionValue> rangeExpression expression primaryExpression

%left EQ GT LT GE LE
%left ADD SUB
%left MUL DIV MOD
%right POWER

%%

fragment
    : statementList
    {
        HTPropAssignStrong(HTCompilerGetCurrent(), statementList, $1);
        HTTypeRelease($1);
    }

statementList
    : statement
    {
        printf("statement list begin.\n");
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, $1);
        HTTypeRelease($1);
        $$ = statementList;
    }
    | statementList statement
    {
        printf("statement list collect.\n");
        HTListAppend($1, $2);
        HTTypeRelease($2);
    }
    ;

statement
    : expression SEMI
    {
        printf("This is a pure expr\n");
    }
    | assignStatement
    {
        $$ = $1;
    }
    | declareStatement
    {
        $$ = $1;
    }
    | ifStatement
    | forStatement
    | funcDefStatement
    | funcCallStatement
    ;

assignStatement
    : IDENTIFIER ASSIGN expression SEMI
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
    | dataType IDENTIFIER ASSIGN expression SEMI
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
        $$ = HTStatementCreateIf($2, $4);
        HTTypeRelease($2);
        HTTypeRelease($4);
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
    : primaryExpression
    | expression ADD expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression SUB expression
        {
            $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
            HTTypeRelease($1);
            HTTypeRelease($3);
        }
    | expression MUL expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression DIV expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression MOD expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression POWER expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression EQ expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression GT expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression GE expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression LT expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression LE expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
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