#include "HTExecutor.h"

// Statement Execution
void HTExecutorExecAssignStatement(HTCompilerRef compiler, HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.assignStatement.identifier), identifier);
    HTVariableRef var = HTRuntimeEnvironmentGetVariable(rootEnv, identifier);
    if (var == NULL) {
        printf("不存在变量 <<%s>>.\n", HTPropGet(identifier, characters));
        return;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.assignStatement.expression), rootEnv);
    HTVaraibleCopyValue(exprVal, var);

    printf("Assign: %s\n", HTPropGet(HTPropGet(var, identifier), characters));
    HTVariablePrintDebugInfo(var);

    HTTypeRelease(exprVal);
}

void HTExecutorExecDeclareStatement(HTCompilerRef compiler, HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.declareStatement.variable), identifier);
    HTVariableRef var = HTVariableCreateWithTypeAndName(HTPropGet(HTPropGet(statement, u.declareStatement.variable), dataType), HTPropGet(identifier, characters));
    HTRuntimeEnvironmentDeclareVariable(rootEnv, var, 0);
    HTTypeRelease(var);

    if (HTPropGet(statement, u.declareStatement.expression) != NULL) {
        HTVariableRef result = HTExpressionEvaluate(HTPropGet(statement, u.declareStatement.expression), rootEnv);
        HTVaraibleCopyValue(result, var);
        HTTypeRelease(result);
    }
    printf("Declare: %s\n", HTPropGet(HTPropGet(var, identifier), characters));
    HTVariablePrintDebugInfo(var);
}

void HTExecutorExecIfStatement(HTCompilerRef compiler, HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef conditionResult = HTExpressionEvaluate(HTPropGet(statement, u.ifStatement.conditionExpression), rootEnv);
    if (HTPropGet(conditionResult, value.boolValue)) {
        HTRuntimeEnvironmentBeginNewEnv(rootEnv);
        HTListNodeRef statementNode = HTPropGet(HTPropGet(statement, u.ifStatement.statementList), head);
        while (statementNode) {
            HTStatementRef statementRef = HTPropGet(statementNode, ptr);
            HTExecuteStatement(compiler, statementRef, rootEnv);
            statementNode = HTPropGet(statementNode, next);
        }
        HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
    }
    HTTypeRelease(conditionResult);
}

void HTExecute(HTCompilerRef compiler) {
    HTRuntimeEnvironmentRef rootEnv = HTRuntimeEnvironmentCreate();
    HTListNodeRef statementNode = HTPropGet(HTPropGet(compiler, statementList), head);
    while (statementNode) {
        HTStatementRef statementRef = HTPropGet(statementNode, ptr);
        HTExecuteStatement(compiler, statementRef, rootEnv);
        statementNode = HTPropGet(statementNode, next);
    }
    HTTypeRelease(rootEnv);
}

void HTExecuteStatement(HTCompilerRef compiler, HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv) {
    if (statementRef == NULL) {
        return;
    }
    switch (HTPropGet(statementRef, type)) {
        case HTStatementTypeAssign:
            HTExecutorExecAssignStatement(compiler, statementRef, rootEnv);
            break;
        case HTStatementTypeDeclare:
            HTExecutorExecDeclareStatement(compiler, statementRef, rootEnv);
            break;
        case HTStatementTypeIf:
            HTExecutorExecIfStatement(compiler, statementRef, rootEnv);
            break;
        default:
            break;
    }
}