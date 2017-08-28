#ifndef __HTInterpreter__H__
#define __HTInterpreter__H__

#include "HTVariable.h"
#include "HTExpression.h"
#include "HTStatement.h"
#include "../utils/HTList.h"
#include "../utils/HTMem.h"
#include "../utils/HTString.h"


struct _HTInterpreter {
    HTList * statementList;
    HTList * variableList;
};

typedef struct _HTInterpreter HTInterpreter;
typedef HTInterpreter * HTInterpreterRef;


static HTInterpreterRef activeInterpreter = NULL;

HTInterpreterRef HTInterpreterCreate();
void HTInterpreterSetCurrent(HTInterpreterRef current);

HTInterpreterRef HTInterpreterGetCurrent();

void HTInterpreterAddStatement(HTStatementRef statement);
void HTInterpreterAddVariable(HTVariableRef variable);
void HTInterpreterCollectGlobalVaraibles(HTInterpreterRef interpreter);

void HTInterpreterPrintDebugInfo(HTInterpreterRef interpreter);
#endif

