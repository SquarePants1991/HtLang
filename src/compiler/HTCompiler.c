#include "HTCompiler.h"

void HTCompilerAlloc(HTCompilerRef self) {
    HTListRef statementList = HTListCreate();

    HTPropAssignStrong(self, statementList, statementList);

    HTTypeRelease(statementList);
}

void HTCompilerDealloc(HTCompilerRef self) {
    HTPropAssignStrong(self, statementList, NULL);
}

void HTCompilerSetCurrent(HTCompilerRef current) {
    activeCompiler = current;
}

HTCompilerRef HTCompilerGetCurrent() {
    return activeCompiler;
}

void HTCompilerAddStatement(HTStatementRef statement) {
    HTListAppend(HTPropGet(HTCompilerGetCurrent(), statementList), statement);
}

void HTCompilerPrintDebugInfo(HTCompilerRef compiler) {
    HTListNodeRef node = HTPropGet(compiler, statementList)->impl->head;
    printf("Has %d statement\n", HTListSize(compiler->impl->statementList));
    while (node != NULL) {
        HTStatementRef statement = node->impl->ptr;
        if (statement) {
            HTStatementPrintDebugInfo(statement);
        }
        node = node->impl->next;
    }
}