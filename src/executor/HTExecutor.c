#include "HTExecutor.h"
#include <stdio.h>
#include <compiler/HTVariable.h>
#include <compiler/HTStatement.h>
#include <utils/HTString.h>
#include <compiler/HTExpression.h>
#include <utils/HTList.h>

// Variable Related
HTVariableRef HTExecutorFindVariable(HTCompilerRef compiler, HTStringRef identifier) {
    HTListNodeRef node = HTPropGet(HTPropGet(compiler, variableList), head);
    while (node != NULL) {
        HTVariableRef variable = HTPropGet(node, ptr);
        if (variable && HTStringEqual(identifier, HTPropGet(variable, identifier))) {
            return variable;
        }
        node = HTPropGet(node, next);
    }
    return NULL;
}

// Statement Execution
void HTExecutorExecAssignStatement(HTCompilerRef compiler, HTStatementRef statement) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.assignStatement.identifier), identifier);
    HTVariableRef var = HTExecutorFindVariable(compiler, identifier);
    if (var == NULL) {
        printf("不存在变量 <<%s>>.\n", HTPropGet(identifier, characters));
        return;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.assignStatement.expression), HTPropGet(compiler, variableList), NULL);
    HTVaraibleCopyValue(exprVal, var);

    printf("Assign: %s\n", HTPropGet(HTPropGet(var, identifier), characters));
    HTVariablePrintDebugInfo(var);

    HTTypeRelease(exprVal);
}

void HTExecutorExecDeclareStatement(HTCompilerRef compiler, HTStatementRef statement) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.declareStatement.variable), identifier);
    HTVariableRef var = HTVariableCreateWithTypeAndName(HTPropGet(HTPropGet(statement, u.declareStatement.variable), dataType), HTPropGet(identifier, characters));
    HTCompilerAddVariable(var);
    HTTypeRelease(var);

    if (HTPropGet(statement, u.declareStatement.expression) != NULL) {
        HTVariableRef result = HTExpressionEvaluate(HTPropGet(statement, u.declareStatement.expression), HTPropGet(compiler, variableList), NULL);
        HTVaraibleCopyValue(result, var);
        HTTypeRelease(result);
    }
    printf("Declare: %s\n", HTPropGet(HTPropGet(var, identifier), characters));
    HTVariablePrintDebugInfo(var);
}

void HTExecute(HTCompilerRef compiler) {
    HTListNodeRef statementNode = HTPropGet(HTPropGet(compiler, statementList), head);
    while (statementNode) {
        HTStatementRef statementRef = HTPropGet(statementNode, ptr);
        if (statementRef == NULL) {
            break;
        }
        switch (HTPropGet(statementRef, type)) {
            case HTStatementTypeAssign:
                HTExecutorExecAssignStatement(compiler, statementRef);
                break;
            case HTStatementTypeDeclare:
                HTExecutorExecDeclareStatement(compiler, statementRef);
                break;
            default:
                break;
        }
        statementNode = HTPropGet(statementNode, next);
    }
}