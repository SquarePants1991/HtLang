%{

#include <stdio.h>
#include "../src/compiler/HTCompiler.h"
#include "bison.h"

int yywrap(void) {
    return 1;
}

%}

%start STRING_LITERAL COMMENT

%%
<INITIAL>"="                     return ASSIGN;
<INITIAL>"int"                   return INT;
<INITIAL>"double"                return DOUBLE;
<INITIAL>"bool"                  return BOOL;
<INITIAL>"string"                return STRING;

<INITIAL>"if"                    return IF;
<INITIAL>"for"                   return FOR;
<INITIAL>"func"                  return FUNC;

<INITIAL>"*"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorMul; return MUL; }
<INITIAL>"/"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorDiv; return DIV; }
<INITIAL>"+"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorAdd; return ADD; }
<INITIAL>"-"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorSub; return SUB; }
<INITIAL>"%"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorMod; return MOD; }
<INITIAL>"**"                    { yylval.binaryOperatorValue = HTExpressionBinaryOperatorPower; return POWER; }
<INITIAL>"("                     return LB;
<INITIAL>")"                     return RB;
<INITIAL>"{"                     return LCB;
<INITIAL>"}"                     return RCB;
<INITIAL>";"                     return SEMI;
<INITIAL>","                     return COMMA;
<INITIAL>":"                     return COLON;

<INITIAL>"=="                    { yylval.binaryOperatorValue = HTExpressionBinaryOperatorLogicEqual; return EQ; }
<INITIAL>">"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorLogicGreater; return GT; }
<INITIAL>">="                    { yylval.binaryOperatorValue = HTExpressionBinaryOperatorLogicGreaterEqual; return GE; }
<INITIAL>"<"                     { yylval.binaryOperatorValue = HTExpressionBinaryOperatorLogicLess; return LT; }
<INITIAL>"<="                    { yylval.binaryOperatorValue = HTExpressionBinaryOperatorLogicLessEqual; return LE; }
<INITIAL>"..<"                   return RANGE_UNCLOSE;
<INITIAL>"..."                   return RANGE_CLOSE;
<INITIAL>"in"                    return IN;

<INITIAL>"true" {
   yylval.expressionValue = HTExpressionCreateBoolLiteral(1);
   return Literal;
}

<INITIAL>"false" {
   yylval.expressionValue = HTExpressionCreateBoolLiteral(0);
   return Literal;
}

<INITIAL>"\""                    {
    HTExpressionBeginStringLiteral();
    BEGIN STRING_LITERAL;
}

<INITIAL>"#"                    {
    BEGIN COMMENT;
}

<STRING_LITERAL>"\""             {
    yylval.expressionValue = HTExpressionEndStringLiteral();
    BEGIN INITIAL;
    return Literal;
}

<STRING_LITERAL>.   {
    HTExpressionAddStringLiteral(yytext);
}

<COMMENT>"\n"       BEGIN INITIAL;
<COMMENT>.  ;



<INITIAL>[ \t\n\r]   ;

<INITIAL>([1-9]+\.[0-9]+) {
    double doubleVal;
    sscanf(yytext, "%lf", &doubleVal);
    yylval.expressionValue = HTExpressionCreateDoubleLiteral(doubleVal);
    return Literal;
}

<INITIAL>([1-9][0-9]*)|0 {
    int intVal;
    sscanf(yytext, "%d", &intVal);
    yylval.expressionValue = HTExpressionCreateIntLiteral(intVal);
    return Literal;
}


<INITIAL>[a-zA-Z][a-zA-Z0-9]*  {
    HTStringRef str = HTStringCreateWithChars(yytext);
    yylval.expressionValue = HTExpressionCreateIdentifier(str);
    HTTypeRelease(str);
    return IDENTIFIER;
}

. {
    fprintf(stderr, "lex parse error! \n");
    exit(1);
}

%%