#ifndef __HTCompiler__H__
#define __HTCompiler__H__

#include "../utils/HTList.h"
#include "../utils/HTMem.h"
#include "../utils/HTString.h"

#include "HTVariable.h"
#include "HTExpression.h"
#include "HTStatement.h"


HTClassBegin
    HTList * statementList;
HTClassEnd(HTCompiler)


static HTCompilerRef activeCompiler = NULL;

HTCompilerRef HTCompilerCreate();
void HTCompilerSetCurrent(HTCompilerRef current);

HTCompilerRef HTCompilerGetCurrent();

void HTCompilerPrintDebugInfo(HTCompilerRef interpreter);
#endif

