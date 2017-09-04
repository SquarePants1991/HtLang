#ifndef __HTExecutor_H__
#define __HTExecutor_H__

#include <compiler/HTExpression.h>
#include "compiler/HTCompiler.h"
#include "HTExpressionEval.h"

// Variable Related
HTVariableRef HTExecutorFindVariable(HTCompilerRef compiler, HTStringRef identifier);
// Statement Execution
void HTExecutorExecAssignStatement(HTCompilerRef compiler, HTStatementRef statement);
void HTExecutorExecDeclareStatement(HTCompilerRef compiler, HTStatementRef statement);
void HTExecute(HTCompilerRef compiler);

#endif
