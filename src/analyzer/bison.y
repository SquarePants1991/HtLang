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
    HTVariableRef variableValue;
}

%token <intValue>               IntLiteral
%token <doubleValue>            DoubleLiteral
%token <boolValue>              BoolLiteral
%token <expressionValue>        IDENTIFIER
%token <expressionValue>        Literal
%token <binaryOperatorValue>    BinaryOperator ADD SUB MUL DIV MOD POWER EQ GT LT GE LE AND OR
%token <statementValue>         Statement
%token <listValue>              List

%token ASSIGN INT DOUBLE BOOL STRING ARRAY SEMI COMMA COLON
%token IF ELIF ELSE FOR FUNC RETURN
%token LB RB LCB RCB LSB RSB
%token RANGE_UNCLOSE RANGE_CLOSE IN
%token COMMENT_ONE_LINE

%type <dataTypeValue> dataType
%type <listValue> statementList parameterList parameterDefList
%type <statementValue>  statement assignStatement declareStatement ifStatement pureIfStatement elifStatement elseStatement funcDefStatement returnStatement
%type <expressionValue> parameter rangeExpression expression primaryExpression arrayLiteral
%type <variableValue> parameterDef

%left AND OR
%left EQ GT LT GE LE
%left ADD SUB
%left MUL DIV MOD
%right POWER NEGATIVE

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
        HTListRef statementList = HTListCreate();
        HTListAppend(statementList, $1);
        HTTypeRelease($1);
        $$ = statementList;
    }
    | statementList statement
    {
        HTListAppend($1, $2);
        HTTypeRelease($2);
    }
    ;

statement
    : expression SEMI
    {
        $$ = HTStatementCreatePureExpression($1);
        HTTypeRelease($1);
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
    {
        $$ = $1;
    }
    | forStatement
    | funcDefStatement
    {
        $$ = $1;
    }
    | returnStatement
    {
        $$ = $1;
    }
    ;

assignStatement
    : IDENTIFIER ASSIGN expression SEMI
    {
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
    : pureIfStatement
    {
        $$ = $1;
    }
    | ifStatement elifStatement
    {
        HTStatementSetAsIfBranchStatement($1, $2);
        $$ = $1;
        HTTypeRelease($2);
    }
    | ifStatement elseStatement
    {
        HTStatementSetAsIfBranchStatement($1, $2);
        $$ = $1;
        HTTypeRelease($2);
    }
    ;

pureIfStatement
    : IF expression LCB statementList RCB
    {
        $$ = HTStatementCreateIf($2, $4, HTIfStatementTypeIf);
        HTTypeRelease($2);
        HTTypeRelease($4);
    }

elifStatement
    : ELIF expression LCB statementList RCB
    {
        $$ = HTStatementCreateIf($2, $4, HTIfStatementTypeElif);
        HTTypeRelease($2);
        HTTypeRelease($4);
    }

elseStatement
    : ELSE LCB statementList RCB
    {
        $$ = HTStatementCreateIf(NULL, $3, HTIfStatementTypeElse);
        HTTypeRelease($3);
    }

forStatement
    : FOR IDENTIFIER IN expression LCB statementList RCB
    {
        $$ = HTStatementCreateFor($2, $4, $6);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($5);
    }

funcDefStatement
    : FUNC IDENTIFIER LB parameterDefList RB LCB statementList RCB
    {
        $$ = HTStatementCreateFuncDef($2, $4, $7, HTDataTypeVoid);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($7);
        printf("This is a function statement\n");
    }
    | FUNC IDENTIFIER LB parameterDefList RB COLON dataType LCB statementList RCB
    {
        $$ = HTStatementCreateFuncDef($2, $4, $9, $7);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($9);
    }
    ;

returnStatement
    : RETURN expression SEMI
    {
        $$ = HTStatementCreateReturn($2);
        HTTypeRelease($2);
    }

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
    | SUB expression %prec NEGATIVE
    {
        HTExpressionRef zeroExpr = HTExpressionCreateDoubleLiteral(0.0);
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorSub, zeroExpr, $2);
        HTTypeRelease(zeroExpr);
        HTTypeRelease($2);
    }
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
    | expression AND expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression OR expression
    {
        $$ = HTExpressionCreateBinaryOperation($2, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | IDENTIFIER LB parameterList RB
    {
        $$ = HTExpressionCreateFuncCall($1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    ;

parameterDefList
    : parameterDef
    {
        HTListRef list = HTListCreate();
        HTListAppend(list, $1);
        HTTypeRelease($1);
        $$ = list;
    }
    | parameterDefList parameterDef
    {
         HTListAppend($1, $2);
         HTTypeRelease($2);
    }
    ;

parameterDef
    : dataType IDENTIFIER
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->identifier->impl->characters);
        $$ = variable;
        HTTypeRelease($2);
    }
    | dataType IDENTIFIER COMMA
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->identifier->impl->characters);
        $$ = variable;
        HTTypeRelease($2);
    }

parameterList
    : parameter
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, $1);
        $$ = paramList;
        HTTypeRelease($1);
    }
    | parameterList parameter
    {
        HTListAppend($1, $2);
        HTTypeRelease($2);
        $$ = $1;
    }

parameter
    : expression
    {
        $$ = $1;
    }
    | expression COMMA
    {
        $$ = $1;
    }

primaryExpression
    : Literal
    {
        $$ = $1
    }
    | arrayLiteral
    {
        $$ = HTExpressionCreateArray($1);
        HTTypeRelease($1);
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


arrayLiteral
    : LSB parameterList RSB
    {
        $$ = $2;
    }

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
    | ARRAY
    {
        $$ = HTDataTypeArray
    }
    ;

%%

int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}