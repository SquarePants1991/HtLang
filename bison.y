%{
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1
%}

%union {
    int     intValue;
    double  doubleValue;
}

%token <doubleValue> DoubleLiteral
%token Add Sub Mul Div CR

%type <doubleValue> expression term primaryExpression

%%

lineList
    : line
    | lineList line
    ;

line
    : expression CR
    {
        printf(">> %lf\n", $1);
    }
    ;

expression
    : term
    | expression Add term
    {
        $$ = $1 + $3
    }
    | expression Sub term
    {
        $$ = $1 - $3
    }
    ;

term
    : primaryExpression
    | term Mul primaryExpression
    {
        $$ = $1 * $3
    }
    | term Div primaryExpression
    {
        $$ = $1 / $3
    }
    ;

primaryExpression
    : DoubleLiteral
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

    yyin = stdin;
    if (yyparse()) {
        fprintf(stderr, "Error! \n");
        exit(1);
    }
}