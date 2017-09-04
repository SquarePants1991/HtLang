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
<INITIAL>"="                     return EQ;
<INITIAL>"int"                   return INT;
<INITIAL>"double"                return DOUBLE;
<INITIAL>"bool"                  return BOOL;
<INITIAL>"string"                return STRING;

<INITIAL>"if"                    return IF;
<INITIAL>"for"                   return FOR;
<INITIAL>"func"                  return FUNC;

<INITIAL>"+"                     return ADD;
<INITIAL>"-"                     return SUB;
<INITIAL>"*"                     return MUL;
<INITIAL>"/"                     return DIV;
<INITIAL>"%"                     return MOD;
<INITIAL>"**"                    return POWER;
<INITIAL>"("                     return LB;
<INITIAL>")"                     return RB;
<INITIAL>"{"                     return LCB;
<INITIAL>"}"                     return RCB;
<INITIAL>";"                     return SEMI;
<INITIAL>","                     return COMMA;
<INITIAL>":"                     return COLON;

<INITIAL>">"                     return GT;
<INITIAL>">="                    return GE;
<INITIAL>"<"                     return LT;
<INITIAL>"<="                    return LE;
<INITIAL>"..<"                   return RANGE_UNCLOSE;
<INITIAL>"..."                   return RANGE_CLOSE;
<INITIAL>"in"                    return IN;

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