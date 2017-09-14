#ifndef __HTExecutor_H__
#define __HTExecutor_H__

#include "../compiler/HTExpression.h"
#include "../compiler/HTCompiler.h"

#include "HTExpressionEval.h"

typedef enum  {
    HTStatementExecuteFinishStateNone,
    HTStatementExecuteFinishStateReturn,
    HTStatementExecuteFinishStateBreak,
    HTStatementExecuteFinishStateContinue
} HTStatementExecuteFinishState;

static HTRuntimeEnvironmentRef rootRuntimeEnvironment = NULL;
void HTExecute(HTCompilerRef compiler);
HTStatementExecuteFinishState HTExecuteStatementList(HTListRef statementList, HTRuntimeEnvironmentRef rootEnv);
HTStatementExecuteFinishState HTExecuteStatement(HTStatementRef statementRef, HTRuntimeEnvironmentRef rootEnv);
#endif
