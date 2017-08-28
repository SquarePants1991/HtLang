#include "HTExecutor.h"
#include <stdio.h>
#include <compiler/HTVariable.h>
#include <compiler/HTStatement.h>
#include <utils/HTString.h>

// Variable Related
HTVariableRef HTInterpreterFindVariable(HTInterpreterRef interpreter, HTStringRef identifier) {
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
void HTInterpreterExecAssignStatement(HTInterpreterRef interpreter, HTStatementRef statement) {
    HTStringRef identifier = statement->u.assignStatement.identifier->u.identifier;
    HTVariableRef var = HTInterpreterFindVariable(interpreter, identifier);
    if (var == NULL) {
        printf("%s is not exist.\n", identifier->characters);
        return;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(statement->u.assignStatement.expression, interpreter->variableList, NULL);
    var->dataType = exprVal->dataType;
    var->value = exprVal->value;

    printf("Assign: %s\n", var->identifier->characters);
    HTVariablePrintDebugInfo(var);

    HTVariableFree(exprVal);
}

void HTInterpreterExecDeclareStatement(HTInterpreterRef interpreter, HTStatementRef statement) {
    HTStringRef identifier = statement->u.declareStatement.variable->identifier;
    HTVariableRef var = HTVariableCreate(statement->u.declareStatement.variable->dataType, identifier->characters);
    HTInterpreterAddVariable(var);

    if (statement->u.declareStatement.expression != NULL) {
        HTVariableRef result = HTExpressionEvaluate(statement->u.declareStatement.expression, interpreter->variableList, NULL);
        var->dataType = result->dataType;
        var->value = result->value;
        HTVariableFree(result);
    }
    printf("Declare: %s\n", var->identifier->characters);
    HTVariablePrintDebugInfo(var);
}

void HTExecute(HTInterpreterRef interpreter) {
    HTListRef statementNode = interpreter->statementList->head;
    while (statementNode) {
        HTStatementRef statementRef = statementNode->dataPtr;
        if (statementRef == NULL) {
            break;
        }
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