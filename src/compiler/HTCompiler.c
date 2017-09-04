#include <utils/HTList.h>
#include "HTCompiler.h"

void HTCompilerAlloc(HTCompilerRef self) {
    HTListRef statementList = HTListCreate();
    HTListRef variableList = HTListCreate();

    HTPropAssignStrong(self, statementList, statementList);
    HTPropAssignStrong(self, variableList, variableList);

    HTTypeRelease(statementList);
    HTTypeRelease(variableList);
}

void HTCompilerDealloc(HTCompilerRef self) {
    HTPropAssignStrong(self, statementList, NULL);
    HTPropAssignStrong(self, variableList, NULL);
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

void HTCompilerAddVariable(HTVariableRef variable) {
    HTListAppend(HTPropGet(HTCompilerGetCurrent(), variableList), variable);
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

    node = compiler->impl->variableList->impl->head;
    printf("Has %d global vars\n", HTListSize(compiler->impl->variableList));
    while (node != NULL) {
        HTVariableRef variable = node->impl->ptr;
        HTVariablePrintDebugInfo (variable);
        node = node->impl->next;
    }
}