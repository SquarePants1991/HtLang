#ifndef __HTCompiler__H__
#define __HTCompiler__H__

#include "HTVariable.h"
#include "HTExpression.h"
#include "HTStatement.h"
#include "../utils/HTList.h"
#include "../utils/HTMem.h"
#include "../utils/HTString.h"

HTClassBegin
    HTList * statementList;
    HTList * variableList;
HTClassEnd(HTCompiler)


static HTCompilerRef activeCompiler = NULL;

HTCompilerRef HTCompilerCreate();
void HTCompilerSetCurrent(HTCompilerRef current);

HTCompilerRef HTCompilerGetCurrent();

void HTCompilerAddStatement(HTStatementRef statement);
void HTCompilerAddVariable(HTVariableRef variable);
void HTCompilerCollectGlobalVaraibles(HTCompilerRef interpreter);

void HTCompilerPrintDebugInfo(HTCompilerRef interpreter);
#endif

