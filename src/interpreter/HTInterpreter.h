#ifndef __HTInterpreter__H__
#define __HTInterpreter__H__

#include "HTVariable.h"
#include "HTExpression.h"
#include "HTStatement.h"
#include "../utils/HTList.h"
#include "../utils/HTMem.h"
#include "../utils/HTString.h"


struct _HTInterpreter {
    HTList * statementList;
    HTList * variableList;
};

typedef struct _HTInterpreter HTInterpreter;
typedef HTInterpreter * HTInterpreterRef;


static HTInterpreterRef activeInterpreter = NULL;

static HTInterpreterRef HTInterpreterCreate() {
    HTInterpreterRef ref = HTMemAlloc(sizeof(HTInterpreter));
    ref->statementList = HTListCreate();
    ref->variableList = HTListCreate();
    return ref;
}

static void HTInterpreterSetCurrent(HTInterpreterRef current) {
    activeInterpreter = current;
}

static HTInterpreterRef HTInterpreterGetCurrent() {
    return activeInterpreter;
}

static void HTInterpreterAddStatement(HTStatementRef statement) {
    HTListAppend(HTInterpreterGetCurrent()->statementList, statement);
}

static void HTInterpreterAddVariable(HTVariableRef variable) {
    HTListAppend(HTInterpreterGetCurrent()->variableList, variable);
}

static void HTInterpreterCollectGlobalVaraibles(HTInterpreterRef interpreter) {
    HTListRef node = interpreter->statementList->head;
    while (node != NULL) {
        HTStatementRef statement = node->dataPtr;

        if (statement->type == HTStatementTypeDeclare) {
            HTListAppend(interpreter->variableList, statement->u.declareStatement.variable);
        }

        node = node->next;
    }
}

static void HTInterpreterPrintDebugInfo(HTInterpreterRef interpreter) {
    HTListRef node = interpreter->statementList->head;
    printf("Has %d statement\n", HTListSize(interpreter->statementList));
    while (node != NULL) {
        HTStatementRef statement = node->dataPtr;
        HTStatementPrintDebugInfo(statement);
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

// Variable Related
static HTVariableRef HTInterpreterFindVariable(HTInterpreterRef interpreter, HTStringRef identifier) {
    HTListRef node = interpreter->variableList->head;
    while (node != NULL) {
        HTVariableRef variable = node->dataPtr;
        if (variable && HTStringEqual(identifier, variable->identifier)) {
            return variable;
        }
        node = node->next;
    }
    return NULL;
}

// Statement Execution
static void HTInterpreterExecAssignStatement(HTInterpreterRef interpreter, HTStatementRef statement) {
    HTStringRef identifier = statement->u.assignStatement.identifier->stringVal;
    HTVariableRef var = HTInterpreterFindVariable(interpreter, identifier);
    if (var == NULL) {
        printf("%s is not exist.\n", identifier->characters);
        return;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(statement->u.assignStatement.expression, interpreter->variableList, NULL);
    switch (exprVal->dataType) {
        case HTDataTypeInt:
            var->value.intValue = exprVal->value.intValue;
            break;
        case HTDataTypeDouble:
            var->value.doubleValue = exprVal->value.doubleValue;
            HTVariablePrintDebugInfo(var);
            break;
    }
    HTVariableFree(exprVal);
}

static void HTInterpreterExecDeclareStatement(HTInterpreterRef interpreter, HTStatementRef statement) {
    HTStringRef identifier = statement->u.declareStatement.variable->identifier;
    HTVariableRef var = HTVariableCreate(statement->u.declareStatement.variable->dataType, identifier->characters);
    HTInterpreterAddVariable(var);
}

static void HTInterpreterExec(HTInterpreterRef interpreter) {
    HTListRef statementNode = interpreter->statementList->head;
    while (statementNode) {
        HTStatementRef statementRef = statementNode->dataPtr;
        switch (statementRef->type) {
            case HTStatementTypeAssign:
                HTInterpreterExecAssignStatement(interpreter, statementRef);
                break;
            case HTStatementTypeDeclare:
                HTInterpreterExecDeclareStatement(interpreter, statementRef);
                break;
            default:
                break;
        }
        statementNode = statementNode->next;
    }
}
#endif

