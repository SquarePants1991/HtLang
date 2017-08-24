%{

#include <stdio.h>
#include "bison.tab.h"

int yywrap(void) {
    return 1;
}

%}

%%
"+"     return Add;
"-"     return Sub;
"*"     return Mul;
"/"     return Div;
"\n"    return CR;

([1-9][0-9]*)|0|([1-9]+\.[0-9]+) {
    double doubleVal;
    sscanf(yytext, "%lf", &doubleVal);
    yylval.doubleValue = doubleVal;
    return DoubleLiteral;
}

. {
    fprintf(stderr, "lex parse error! \n");
    exit(1);
}

%%