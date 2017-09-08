#include "compiler/HTCompiler.h"
#include "executor/HTExecutor.h"
#include "analyzer/bison.h"
#include <stdio.h>

int main() {
    extern int yyparse(void);
    extern FILE *yyin;

    yyin = fopen("/Users/wangyang/Documents/Codes/OnGit/HtLang/AssignTest.ht", "r");
    HTCompilerRef compiler = HTCompilerCreate();
    HTCompilerSetCurrent(compiler);
    if (yyparse()) {
        fprintf(stderr, "Error! \n");
    }
    HTExecute(compiler);

    HTTypeRelease(compiler);
    printf("=========================================================\n");
    printf("Check Mem Leak >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    HTMemPrintAllBlocks();
}