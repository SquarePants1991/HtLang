#include <compiler/HTStatement.h>
#include <compiler/HTExpression.h>
#include <utils/HTList.h>
#include "HTExecutor.h"
#include "HTLocalFunctionRegsiter.h"
#include "HTRuntimeEnvironment.h"

// Statement Execution
void HTExecutorExecPureExpressionStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.pureExpressionStatement.expression), rootEnv);
    HTTypeRelease(exprVal);
}

void HTExecutorExecAssignStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.assignStatement.identifier), identifier);
    HTVariableRef var = HTRuntimeEnvironmentGetVariable(rootEnv, identifier);
    if (var == NULL) {
        printf("不存在变量 <<%s>>.\n", HTPropGet(identifier, characters));
        return;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.assignStatement.expression), rootEnv);
    HTVaraibleCopyValue(exprVal, var);

    HTTypeRelease(exprVal);
}

void HTExecutorExecDeclareStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.declareStatement.variable), identifier);
    HTVariableRef var = HTVariableCreateWithTypeAndName(HTPropGet(HTPropGet(statement, u.declareStatement.variable), dataType), HTPropGet(identifier, characters));
    HTRuntimeEnvironmentDeclareVariable(rootEnv, var, 0);
    HTTypeRelease(var);

    if (HTPropGet(statement, u.declareStatement.expression) != NULL) {
        HTVariableRef result = HTExpressionEvaluate(HTPropGet(statement, u.declareStatement.expression), rootEnv);
        HTVaraibleCopyValue(result, var);
        HTTypeRelease(result);
    }
}

void HTExecutorExecIfStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef conditionResult = HTExpressionEvaluate(HTPropGet(statement, u.ifStatement.conditionExpression), rootEnv);
    if (HTPropGet(conditionResult, value.boolValue)) {
        HTRuntimeEnvironmentBeginNewEnv(rootEnv);
        HTExecuteStatementList(HTPropGet(statement, u.ifStatement.statementList), rootEnv);
        HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
    } else {
        HTListRef branchList = HTPropGet(statement, u.ifStatement.branchStatements);
        HTListNodeRef branchNode = HTPropGet(branchList, head);
        while (branchNode) {
            HTStatementRef branchStatement = HTPropGet(branchNode, ptr);
            if (HTPropGet(branchStatement, u.ifStatement.ifStatementType) == HTIfStatementTypeElif) {
                HTVariableRef elifConditionResult = HTExpressionEvaluate(HTPropGet(branchStatement, u.ifStatement.conditionExpression), rootEnv);
                unsigned char result = HTPropGet(elifConditionResult, value.boolValue);
                HTTypeRelease(elifConditionResult);
                if (result) {
                    HTRuntimeEnvironmentBeginNewEnv(rootEnv);
                    HTExecuteStatementList(HTPropGet(branchStatement, u.ifStatement.statementList), rootEnv);
                    HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
                    break;
                }
            } else if (HTPropGet(branchStatement, u.ifStatement.ifStatementType) == HTIfStatementTypeElse) {
                HTRuntimeEnvironmentBeginNewEnv(rootEnv);
                HTExecuteStatementList(HTPropGet(branchStatement, u.ifStatement.statementList), rootEnv);
                HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
                break;
            }
            branchNode = HTPropGet(branchNode, next);
        }
    }
    HTTypeRelease(conditionResult);
}

void HTExecutorExecFuncDefStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef funcName = HTPropGet(HTPropGet(statement, u.funcDefStatement.identifier), identifier);
    HTListRef parameterDefList = HTPropGet(statement, u.funcDefStatement.parameterDefList);
    HTListRef statementList = HTPropGet(statement, u.funcDefStatement.statementList);

    HTFunctionRef func = HTFunctionCreateCustom(funcName, parameterDefList, statementList, HTPropGet(statement, u.funcDefStatement.returnType));
    HTListAppend(HTPropGet(rootEnv, functions), func);
    HTTypeRelease(func);
}

void HTExecutorExecReturnStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef returnExpr = HTPropGet(statement, u.returnStatement.expression);
    HTVariableRef exprResult = HTExpressionEvaluate(returnExpr, rootEnv);
    HTRuntimeEnvironmentRef currentEnv = HTRuntimeEnvironmentCurrentEnv(rootEnv);
    HTPropAssignStrong(currentEnv, returnVariable, exprResult);
    HTTypeRelease(exprResult);
}

void HTExecute(HTCompilerRef compiler) {
    HTRuntimeEnvironmentRef rootEnv = HTRuntimeEnvironmentCreate();
    HTLocalFunctionRegisterRegister(rootEnv);
    HTExecuteStatementList(HTPropGet(compiler, statementList), rootEnv);
    HTTypeRelease(rootEnv);
}

void HTExecuteStatementList(HTListRef statementList, HTRuntimeEnvironmentRef rootEnv) {
    HTListNodeRef statementNode = HTPropGet(statementList, head);
    while (statementNode) {
        HTStatementRef statementRef = HTPropGet(statementNode, ptr);
        HTExecuteStatement(statementRef, rootEnv);
        statementNode = HTPropGet(statementNode, next);
    }
}

void HTExecuteStatement(HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv) {
    if (statementRef == NULL) {
        return;
    }
    switch (HTPropGet(statementRef, type)) {
        case HTStatementTypePureExpression:
            HTExecutorExecPureExpressionStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeAssign:
            HTExecutorExecAssignStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeDeclare:
            HTExecutorExecDeclareStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeIf:
            HTExecutorExecIfStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeFuncDef:
            HTExecutorExecFuncDefStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeReturn:
            HTExecutorExecReturnStatement(statementRef, rootEnv);
            break;
        default:
            break;
    }
}