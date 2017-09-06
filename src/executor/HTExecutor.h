#ifndef __HTExecutor_H__
#define __HTExecutor_H__

#include "../compiler/HTExpression.h"
#include "../compiler/HTCompiler.h"
#include "HTExpressionEval.h"

static HTRuntimeEnvironmentRef rootRuntimeEnvironment = NULL;
// Statement Execution
void HTExecutorExecAssignStatement(HTCompilerRef compiler, HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv);
void HTExecutorExecDeclareStatement(HTCompilerRef compiler, HTStatementRef statement, HTRuntimeEnvironmentRef rootEnv);
void HTExecute(HTCompilerRef compiler);
void HTExecuteStatement(HTCompilerRef compiler, HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv);
#endif
