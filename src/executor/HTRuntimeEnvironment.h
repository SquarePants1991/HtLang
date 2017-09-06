//
// Created by wang yang on 2017/9/6.
//

#ifndef HTLANG_HTRUNTIMEENVIRONMENT_H
#define HTLANG_HTRUNTIMEENVIRONMENT_H

#include "../compiler/HTCompiler.h"
#include "../utils/HTString.h"


HTClassBegin
    HTListRef variables;
    struct HTRuntimeEnvironment *prev;
    struct HTRuntimeEnvironment *next;
HTClassEnd(HTRuntimeEnvironment)

void HTRuntimeEnvironmentBeginNewEnv(HTRuntimeEnvironmentRef env);
void HTRuntimeEnvironmentEndCurrentEnv(HTRuntimeEnvironmentRef env);
HTVariableRef HTRuntimeEnvironmentGetVariable(HTRuntimeEnvironmentRef env, HTStringRef identifier);
void HTRuntimeEnvironmentDeclareVariable(HTRuntimeEnvironmentRef env, HTVariableRef variable, unsigned char isGlobalVar);
HTRuntimeEnvironmentRef HTRuntimeEnvironmentCurrentEnv(HTRuntimeEnvironmentRef env);

void HTRuntimeEnvironmentPrintDebugInfo(HTRuntimeEnvironmentRef env);

#endif //HTLANG_HTRUNTIMEENVIRONMENT_H
