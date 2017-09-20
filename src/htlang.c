#include "compiler/HTCompiler.h"
#include "executor/HTExecutor.h"
#include "analyzer/bison.h"
#include <stdio.h>
#include "htlang_ctrl.h"

HTUnitTestLevel CTRL_UnitTestLevel = HTUnitTestLevelVerbose;

int main(int argc, char ** argv) {
    extern int yyparse(void);
    extern FILE *yyin;

    unsigned char enableLeakCheck = 0;
    unsigned char errorOnly = 0;

    if (argc >= 1) {
        yyin = fopen("/Users/wangyang/Documents/Codes/OnGit/HtLang/AssignTest.ht", "r");
    }
    if (argc >= 2) {
        yyin = fopen(argv[1], "r");
    }
    if (argc >= 3) {
        sscanf(argv[2], "%c", &enableLeakCheck);
        enableLeakCheck = enableLeakCheck - '0';
    }
    if (argc >= 4) {
        sscanf(argv[3], "%c", &errorOnly);
        errorOnly = errorOnly - '0';
        if (errorOnly) {
            CTRL_UnitTestLevel = HTUnitTestLevelError;
        }
    }

    HTCompilerRef compiler = HTCompilerCreate();
    HTCompilerSetCurrent(compiler);
    if (yyparse()) {
        fprintf(stderr, "Error! \n");
    }
    HTExecute(compiler);

    HTTypeRelease(compiler);

    if (enableLeakCheck) {
        size_t memBlocksLeft = HTMemCurrentBlockCount();
        if (memBlocksLeft > 0) {
            printf("检测到内存泄漏\n");
            HTMemPrintAllBlocks();
        }
    }
}