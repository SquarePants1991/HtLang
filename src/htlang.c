#include "compiler/HTCompiler.h"
#include "executor/HTExecutor.h"
#include "analyzer/bison.h"
#include <stdio.h>

int main(int argc, char ** argv) {
    extern int yyparse(void);
    extern FILE *yyin;

    unsigned char enableLeakCheck = 0;
    if (argc == 1) {
        yyin = fopen("/Users/wangyang/Documents/Codes/OnGit/HtLang/AssignTest.ht", "r");
    } else if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else if (argc == 3) {
        sscanf(argv[2], "%d", enableLeakCheck);
    }

    HTCompilerRef compiler = HTCompilerCreate();
    HTCompilerSetCurrent(compiler);
    if (yyparse()) {
        fprintf(stderr, "Error! \n");
    }
    HTExecute(compiler);

    HTTypeRelease(compiler);

    if (enableLeakCheck) {
        printf("=========================================================\n");
        printf("Check Mem Leak >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        HTMemPrintAllBlocks();
    }
}