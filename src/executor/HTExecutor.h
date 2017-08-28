#ifndef __HTExecutor_H__
#define __HTExecutor_H__

#include <compiler/HTExpression.h>
#include "../compiler/HTInterpreter.h"
#include "HTExpressionEval.h"

// Variable Related
HTVariableRef HTInterpreterFindVariable(HTInterpreterRef interpreter, HTStringRef identifier);
// Statement Execution
void HTInterpreterExecAssignStatement(HTInterpreterRef interpreter, HTStatementRef statement);
void HTInterpreterExecDeclareStatement(HTInterpreterRef interpreter, HTStatementRef statement);
void HTExecute(HTInterpreterRef interpreter);

#endif
