#include "compiler/HTCompiler.h"

int main() {
    HTCompilerRef compiler = HTCompilerCreate();
    HTCompilerSetCurrent(compiler);
    HTMemPrintAllBlocks();

    HTTypeRelease(compiler);
    HTMemPrintAllBlocks();
}