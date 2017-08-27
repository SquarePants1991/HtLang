%{
#include <stdio.h>
#include <stdlib.h>
#include "../src/interpreter/HTInterpreter.h"
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

%token EQ INT DOUBLE BOOL SEMI COMMA COLON
%token IF FOR FUNC
%token ADD SUB MUL DIV LB RB LCB RCB
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
        HTInterpreterAddStatement($1);
    }
    | declareStatement
    {
        HTInterpreterAddStatement($1);
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
    }

declareStatement
    : dataType IDENTIFIER SEMI
    {
        printf("This is a declare statement\n");
        HTVariableRef variable = HTVariableCreate($1, $2->stringVal->characters);
        $$ = HTStatementCreateDeclare(variable, NULL);
    }
    | dataType IDENTIFIER EQ expression SEMI
    {
        printf("This is a declare statement\n");
        HTVariableRef variable = HTVariableCreate($1, $2->stringVal->characters);
        $$ = HTStatementCreateDeclare(variable, $4);
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
        $$ = HTExpressionAdd($1, $3)
    }
    | expression RANGE_CLOSE expression
    {
        $$ = HTExpressionAdd($1, $3)
    }

expression
    : term
    | expression ADD term
    {
        $$ = HTExpressionAdd($1, $3)
    }
    | expression SUB term
    {
        $$ = HTExpressionSub($1, $3)
    }
    ;

term
    : primaryExpression
    | term MUL primaryExpression
    {
        $$ = HTExpressionMul($1, $3)
    }
    | term DIV primaryExpression
    {
        $$ = HTExpressionDiv($1, $3)
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
        $$ =   HTDataTypeInt
    }
    | DOUBLE
    {
        $$ = HTDataTypeDouble
    }
    | BOOL
    {
        $$ = HTDataTypeBool
    }
    ;

%%

int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}

int main() {
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = fopen("./AssignTest.ht", "r");
    HTInterpreterRef interpreter = HTInterpreterCreate();
    HTInterpreterSetCurrent(interpreter);
    if (yyparse()) {
        fprintf(stderr, "Error! \n");
    }
    HTInterpreterPrintDebugInfo(interpreter);
    printf("Begin execution...\n");
    HTInterpreterExec(interpreter);
}