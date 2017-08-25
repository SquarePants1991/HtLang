%{

#include <stdio.h>
#include "../HTInterpreter.h"
#include "bison.h"

int yywrap(void) {
    return 1;
}

%}

%%
<INITIAL>"="                     return EQ;
<INITIAL>"int"                   return INT;
<INITIAL>"double"                return DOUBLE;
<INITIAL>"bool"                  return BOOL;

<INITIAL>"if"                    return IF;
<INITIAL>"for"                   return FOR;
<INITIAL>"func"                  return FUNC;

<INITIAL>"+"                     return ADD;
<INITIAL>"-"                     return SUB;
<INITIAL>"*"                     return MUL;
<INITIAL>"/"                     return DIV;
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



<INITIAL>[ \t\n\r]   ;

<INITIAL>([1-9][0-9]*)|0|([1-9]+\.[0-9]+) {
    double doubleVal;
    sscanf(yytext, "%lf", &doubleVal);
    yylval.expressionValue = HTExpressionCreateDouble(doubleVal);
    return ExpressionValue;
}

<INITIAL>[a-zA-Z][a-zA-Z0-9]*  {
    yylval.expressionValue = HTExpressionCreateDouble(2);
    return IDENTIFIER;
}

. {
    fprintf(stderr, "lex parse error! \n");
    exit(1);
}

%%