#include "../compiler/HTStatement.h"

#include "HTExecutor.h"
#include "HTLocalFunctionRegsiter.h"

// Statement Execution
HTStatementExecuteFinishState HTExecutorExecPureExpressionStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.pureExpressionStatement.expression), rootEnv);
    HTTypeRelease(exprVal);
    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecutorExecAssignStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.assignStatement.identifier), identifier);
    HTVariableRef var = HTRuntimeEnvironmentGetVariable(rootEnv, identifier);
    if (var == NULL) {
        printf("不存在变量 <<%s>>.\n", HTPropGet(identifier, characters));
        return HTStatementExecuteFinishStateNone;
    }
    HTVariableRef exprVal = HTExpressionEvaluate(HTPropGet(statement, u.assignStatement.expression), rootEnv);
    HTVaraibleCopyValue(exprVal, var);

    HTTypeRelease(exprVal);

    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecutorExecDeclareStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifier = HTPropGet(HTPropGet(statement, u.declareStatement.variable), identifier);
    HTVariableRef var = HTVariableCreateWithTypeAndName(HTPropGet(HTPropGet(statement, u.declareStatement.variable), dataType), HTPropGet(identifier, characters));
    HTRuntimeEnvironmentDeclareVariable(rootEnv, var, 0);
    HTTypeRelease(var);

    if (HTPropGet(statement, u.declareStatement.expression) != NULL) {
        HTVariableRef result = HTExpressionEvaluate(HTPropGet(statement, u.declareStatement.expression), rootEnv);
        HTVaraibleCopyValue(result, var);
        HTTypeRelease(result);
    }

    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecutorExecIfStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStatementExecuteFinishState finishState = HTStatementExecuteFinishStateNone;
    HTVariableRef conditionResult = HTExpressionEvaluate(HTPropGet(statement, u.ifStatement.conditionExpression), rootEnv);
    if (HTPropGet(conditionResult, value.boolValue)) {
        HTRuntimeEnvironmentBeginNewEnv(rootEnv);
        finishState = HTExecuteStatementList(HTPropGet(statement, u.ifStatement.statementList), rootEnv);
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
                    finishState = HTExecuteStatementList(HTPropGet(branchStatement, u.ifStatement.statementList), rootEnv);
                    HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
                    break;
                }
            } else if (HTPropGet(branchStatement, u.ifStatement.ifStatementType) == HTIfStatementTypeElse) {
                HTRuntimeEnvironmentBeginNewEnv(rootEnv);
                finishState = HTExecuteStatementList(HTPropGet(branchStatement, u.ifStatement.statementList), rootEnv);
                HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
                break;
            }
            branchNode = HTPropGet(branchNode, next);
        }
    }
    HTTypeRelease(conditionResult);
    return finishState;
}

HTStatementExecuteFinishState HTExecutorExecFuncDefStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef funcName = HTPropGet(HTPropGet(statement, u.funcDefStatement.identifier), identifier);
    HTListRef parameterDefList = HTPropGet(statement, u.funcDefStatement.parameterDefList);
    HTListRef statementList = HTPropGet(statement, u.funcDefStatement.statementList);

    HTFunctionRef func = HTFunctionCreateCustom(funcName, parameterDefList, statementList, HTPropGet(statement, u.funcDefStatement.returnType));
    HTListAppend(HTPropGet(rootEnv, functions), func);
    HTTypeRelease(func);

    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecutorExecReturnStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef returnExpr = HTPropGet(statement, u.returnStatement.expression);
    HTVariableRef exprResult = HTExpressionEvaluate(returnExpr, rootEnv);
    HTRuntimeEnvironmentRef currentEnv = HTRuntimeEnvironmentCurrentEnv(rootEnv);
    HTPropAssignStrong(currentEnv, returnVariable, exprResult);
    HTTypeRelease(exprResult);

    return HTStatementExecuteFinishStateReturn;
}

HTStatementExecuteFinishState HTExecutorExecForStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTStringRef identifierName = HTPropGet(HTPropGet(statement, u.forStatement.identifierExpression), identifier);
    HTVariableRef arrayExprResult = HTExpressionEvaluate(HTPropGet(statement, u.forStatement.arrayExpression), rootEnv);
    HTListRef statementList = HTPropGet(statement, u.forStatement.statementList);
    if (arrayExprResult && HTPropGet(arrayExprResult, dataType) == HTDataTypeArray) {
        HTListRef arr = HTPropGet(arrayExprResult, arrayValue);
        HTListNodeRef node = HTPropGet(arr, head);
        while (node) {
            HTVariableRef var = HTPropGet(node, ptr);
            HTPropAssignStrong(var, identifier, identifierName);

            HTRuntimeEnvironmentBeginNewEnv(rootEnv);
            HTRuntimeEnvironmentDeclareVariable(rootEnv, var, 0);
            HTStatementExecuteFinishState finishState = HTExecuteStatementList(statementList, rootEnv);
            HTRuntimeEnvironmentEndCurrentEnv(rootEnv);

            node = HTPropGet(node, next);

            if (finishState == HTStatementExecuteFinishStateReturn ||
                finishState == HTStatementExecuteFinishStateBreak ) {
                break;
            } else if (finishState == HTStatementExecuteFinishStateContinue) {
                continue;
            }
        }
    } else {
        // throw loop in none array type error
    }

    HTTypeRelease(arrayExprResult);

    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecutorExecWhileStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv) {
    HTExpressionRef conditionExpr = HTPropGet(statement, u.whileStatement.conditionExpression);
    HTListRef statementList = HTPropGet(statement, u.whileStatement.statementList);
    while (1) {
        HTVariableRef arrayExprResult = HTExpressionEvaluate(conditionExpr, rootEnv);
        if (arrayExprResult && HTPropGet(arrayExprResult, dataType) == HTDataTypeBool) {
            HTTypeRelease(arrayExprResult);
            if (HTPropGet(arrayExprResult, value.boolValue)) {
                HTRuntimeEnvironmentBeginNewEnv(rootEnv);
                HTStatementExecuteFinishState finishState = HTExecuteStatementList(statementList, rootEnv);
                HTRuntimeEnvironmentEndCurrentEnv(rootEnv);

                if (finishState == HTStatementExecuteFinishStateReturn ||
                    finishState == HTStatementExecuteFinishStateBreak ) {
                    break;
                } else if (finishState == HTStatementExecuteFinishStateContinue) {
                    continue;
                }
            } else {
                break;
            }
        } else {
            // throw while condition must be bool value error
            break;
        }
    }

    return HTStatementExecuteFinishStateNone;
}

void HTExecute(HTCompilerRef compiler) {
    HTRuntimeEnvironmentRef rootEnv = HTRuntimeEnvironmentCreate();
    HTLocalFunctionRegisterRegister(rootEnv);
    HTExecuteStatementList(HTPropGet(compiler, statementList), rootEnv);
    HTTypeRelease(rootEnv);
}

HTStatementExecuteFinishState HTExecuteStatementList(HTListRef statementList, HTRuntimeEnvironmentRef rootEnv) {
    HTListNodeRef statementNode = HTPropGet(statementList, head);
    while (statementNode) {
        HTStatementRef statementRef = HTPropGet(statementNode, ptr);
        HTStatementExecuteFinishState finishState = HTExecuteStatement(statementRef, rootEnv);
        statementNode = HTPropGet(statementNode, next);
        if (finishState == HTStatementExecuteFinishStateReturn ||
                finishState == HTStatementExecuteFinishStateBreak ||
                finishState == HTStatementExecuteFinishStateContinue ) {
            return finishState;
        }
    }
    return HTStatementExecuteFinishStateNone;
}

HTStatementExecuteFinishState HTExecuteStatement(HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv) {
    if (statementRef == NULL) {
        return HTStatementExecuteFinishStateNone;
    }
    HTStatementExecuteFinishState finishState = HTStatementExecuteFinishStateNone;
    switch (HTPropGet(statementRef, type)) {
        case HTStatementTypePureExpression:
            finishState = HTExecutorExecPureExpressionStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeAssign:
            finishState = HTExecutorExecAssignStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeDeclare:
            finishState = HTExecutorExecDeclareStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeIf:
            finishState = HTExecutorExecIfStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeFuncDef:
            finishState = HTExecutorExecFuncDefStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeReturn:
            finishState = HTExecutorExecReturnStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeFor:
            finishState = HTExecutorExecForStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeWhile:
            finishState = HTExecutorExecWhileStatement(statementRef, rootEnv);
            break;
        case HTStatementTypeBreak:
            finishState = HTStatementExecuteFinishStateBreak;
            break;
        case HTStatementTypeContinue:
            finishState = HTStatementExecuteFinishStateContinue;
            break;
        default:
            break;
    }
    return finishState;
}