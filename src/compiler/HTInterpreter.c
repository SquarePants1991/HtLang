#include "HTInterpreter.h"

HTInterpreterRef HTInterpreterCreate() {
    HTInterpreterRef ref = HTMemAlloc(sizeof(HTInterpreter));
    ref->statementList = HTListCreate();
    ref->variableList = HTListCreate();
    return ref;
}

void HTInterpreterSetCurrent(HTInterpreterRef current) {
    activeInterpreter = current;
}

HTInterpreterRef HTInterpreterGetCurrent() {
    return activeInterpreter;
}

void HTInterpreterAddStatement(HTStatementRef statement) {
    HTListAppend(HTInterpreterGetCurrent()->statementList, statement);
}

void HTInterpreterAddVariable(HTVariableRef variable) {
    HTListAppend(HTInterpreterGetCurrent()->variableList, variable);
}

void HTInterpreterCollectGlobalVaraibles(HTInterpreterRef interpreter) {
    HTListRef node = interpreter->statementList->head;
    while (node != NULL) {
        HTStatementRef statement = node->dataPtr;

        if (statement->type == HTStatementTypeDeclare) {
            HTListAppend(interpreter->variableList, statement->u.declareStatement.variable);
        }

        node = node->next;
    }
}

void HTInterpreterPrintDebugInfo(HTInterpreterRef interpreter) {
    HTListRef node = interpreter->statementList->head;
    printf("Has %d statement\n", HTListSize(interpreter->statementList));
    while (node != NULL) {
        HTStatementRef statement = node->dataPtr;
        if (statement) {
            HTStatementPrintDebugInfo(statement);
        }
        node = node->next;
    }

    node = interpreter->variableList->head;
    printf("Has %d global vars\n", HTListSize(interpreter->variableList));
    while (node != NULL) {
        HTVariableRef variable = node->dataPtr;
        HTVariablePrintDebugInfo (variable);
        node = node->next;
    }
}