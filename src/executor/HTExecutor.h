#ifndef __HTExecutor_H__
#define __HTExecutor_H__

#include "../compiler/HTExpression.h"
#include "../compiler/HTCompiler.h"
#include "HTExpressionEval.h"

static HTRuntimeEnvironmentRef rootRuntimeEnvironment = NULL;
// Statement Execution
void HTExecutorExecAssignStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv);
void HTExecutorExecDeclareStatement(HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv);
void HTExecute(HTCompilerRef compiler);
void HTExecuteStatementList(HTListRef statementList, HTRuntimeEnvironmentRef rootEnv);
void HTExecuteStatement(HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv);
#endif
