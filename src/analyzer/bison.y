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
    HTDictPairRef dictPairValue;
}

%token <intValue>               IntLiteral
%token <doubleValue>            DoubleLiteral
%token <boolValue>              BoolLiteral
%token <stringValue>            IDENTIFIER
%token <expressionValue>        Literal
%token <binaryOperatorValue>    BinaryOperator ADD SUB MUL DIV MOD POWER EQ NEQ GT LT GE LE AND OR
%token <statementValue>         Statement
%token <listValue>              List

%token ASSIGN INT DOUBLE BOOL STRING ARRAY MAP SEMI COMMA COLON
%token IF ELIF ELSE FOR FUNC RETURN WHILE BREAK CONTINUE
%token LB RB LCB RCB LSB RSB
%token RANGE_UNCLOSE RANGE_CLOSE IN
%token COMMENT_ONE_LINE

%type <dataTypeValue> dataType
%type <listValue> statementList parameterList parameterDefList pairList arrayLiteral dictLiteral
%type <statementValue>  statement assignStatement declareStatement ifStatement pureIfStatement elifStatement elseStatement funcDefStatement returnStatement forStatement whileStatement breakStatement continueStatement
%type <expressionValue> expression postfixExpression primaryExpression
%type <variableValue> parameterDef

%left COLON
%left RANGE_UNCLOSE RANGE_CLOSE
%left AND OR
%left EQ GT LT GE LE NEQ
%left ADD SUB
%left MUL DIV MOD
%right POWER NEGATIVE
%left BRACE

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
    {
        $$ = $1;
    }
    | whileStatement
    {
        $$ = $1;
    }
    | funcDefStatement
    {
        $$ = $1;
    }
    | returnStatement
    {
        $$ = $1;
    }
    | breakStatement
    {
        $$ = $1;
    }
    | continueStatement
    {
        $$ = $1;
    }
    ;

assignStatement
    : postfixExpression ASSIGN expression SEMI
    {
        $$ = HTStatementCreateAssign($1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }

declareStatement
    : dataType IDENTIFIER SEMI
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->characters);
        $$ = HTStatementCreateDeclare(variable, NULL);
        HTTypeRelease($2);
        HTTypeRelease(variable);
    }
    | dataType IDENTIFIER ASSIGN expression SEMI
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->characters);
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
        HTExpressionRef identifier = HTExpressionCreateIdentifier($2);
        $$ = HTStatementCreateFor(identifier, $4, $6);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($6);
        HTTypeRelease(identifier);
    }

whileStatement
    : WHILE expression LCB statementList RCB
    {
        $$ = HTStatementCreateWhile($2, $4);
        HTTypeRelease($2);
        HTTypeRelease($4);
    }
    ;

funcDefStatement
    : FUNC IDENTIFIER LB parameterDefList RB LCB statementList RCB
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier($2);
        $$ = HTStatementCreateFuncDef(identifier, $4, $7, HTDataTypeVoid);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($7);
        HTTypeRelease(identifier);
        printf("This is a function statement\n");
    }
    | FUNC IDENTIFIER LB parameterDefList RB COLON dataType LCB statementList RCB
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier($2);
        $$ = HTStatementCreateFuncDef(identifier, $4, $9, $7);
        HTTypeRelease($2);
        HTTypeRelease($4);
        HTTypeRelease($9);
        HTTypeRelease(identifier);
    }
    ;

returnStatement
    : RETURN expression SEMI
    {
        $$ = HTStatementCreateReturn($2);
        HTTypeRelease($2);
    }

breakStatement
    : BREAK SEMI
    {
        $$ = HTStatementCreateBreak();
    }

continueStatement
    : CONTINUE SEMI
    {
        $$ = HTStatementCreateContinue();
    }


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
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->characters);
        $$ = variable;
        HTTypeRelease($2);
    }
    | dataType IDENTIFIER COMMA
    {
        HTVariableRef variable = HTVariableCreateWithTypeAndName($1, $2->impl->characters);
        $$ = variable;
        HTTypeRelease($2);
    }

parameterList
    : expression
    {
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, $1);
        $$ = paramList;
        HTTypeRelease($1);
    }
    | parameterList COMMA expression
    {
        HTListAppend($1, $3);
        HTTypeRelease($3);
        $$ = $1;
    }

expression
    : postfixExpression
    | expression RANGE_UNCLOSE expression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorUncloseRangeArray, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    | expression RANGE_CLOSE expression
    {
        $$ = HTExpressionCreateBinaryOperation(HTExpressionBinaryOperatorCloseRangeArray, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
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
    | expression NEQ expression
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
    | SUB expression %prec NEGATIVE
    {
        $$ = HTExpressionCreateUnaryOperation(HTExpressionUnaryOperatorNeg, $2);
        HTTypeRelease($2);
    }
    | IDENTIFIER LB parameterList RB
    {
        HTExpressionRef identifier = HTExpressionCreateIdentifier($1);
        $$ = HTExpressionCreateFuncCall(identifier, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
        HTTypeRelease(identifier);
    }
    ;

postfixExpression
    : primaryExpression
    | primaryExpression LSB expression RSB
    {
        $$ = HTExpressionCreatePostfixOperation(HTExpressionPostfixOperatorIndex, $1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
    }
    ;

primaryExpression
    : Literal
    {
        $$ = $1;
    }
    | arrayLiteral
    {
        $$ = HTExpressionCreateArray($1);
        HTTypeRelease($1);
    }
    | dictLiteral
    {
        $$ = HTExpressionCreateDict($1);
        HTTypeRelease($1);
    }
    | IDENTIFIER
    {
        $$ = HTExpressionCreateIdentifier($1);
        HTTypeRelease($1);
    }
    | LB expression RB
    {
        $$ = $2;
    }
    ;

arrayLiteral
    : LSB parameterList RSB
    {
        $$ = $2;
    }


pairList
    : expression COLON expression
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue($1, $3);
        HTTypeRelease($1);
        HTTypeRelease($3);
        HTListRef paramList = HTListCreate();
        HTListAppend(paramList, pair);
        $$ = paramList;
        HTTypeRelease(pair);
    }
    | pairList COMMA Literal COLON expression
    {
        HTDictPairRef pair = HTDictPairCreateWithKeyAndValue($3, $5);
        HTTypeRelease($3);
        HTTypeRelease($5);
        HTListAppend($1, pair);
        HTTypeRelease(pair);
        $$ = $1;
    }

dictLiteral
    : LCB pairList RCB
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
    | MAP
    {
        $$ = HTDataTypeMap
    }
    ;

%%

int yyerror(char const * str) {
    extern char * yytext;
    fprintf(stderr, "parse error near %s \n", yytext);
    return 0;
}