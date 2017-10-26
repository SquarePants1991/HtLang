//
// Created by wang yang on 2017/9/6.
//

#ifndef HTLANG_HTRUNTIMEENVIRONMENT_H
#define HTLANG_HTRUNTIMEENVIRONMENT_H

#include "../compiler/HTFunction.h"
#include "../compiler/HTCompiler.h"
#include "../utils/HTString.h"

HTClassBegin
    HTListRef variables;
    HTListRef functions;
    HTVariableRef returnVariable;       // 用来存放return statement的返回值
    HTDictRef functionStack;            // 函数栈，顶级环境独有，保存当前函数参数。
    struct HTRuntimeEnvironment *prev;
    struct HTRuntimeEnvironment *next;
HTClassEnd(HTRuntimeEnvironment)

void HTRuntimeEnvironmentBeginNewEnv(HTRuntimeEnvironmentRef env);
void HTRuntimeEnvironmentEndCurrentEnv(HTRuntimeEnvironmentRef env);
HTVariableRef HTRuntimeEnvironmentGetVariable(HTRuntimeEnvironmentRef env, HTStringRef identifier);
HTFunctionRef HTRuntimeEnvironmentGetFunction(HTRuntimeEnvironmentRef env, HTStringRef identifier);
void HTRuntimeEnvironmentDeclareVariable(HTRuntimeEnvironmentRef env, HTVariableRef variable, unsigned char isGlobalVar);
void HTRuntimeEnvironmentDeclareVariables(HTRuntimeEnvironmentRef env, HTListRef variables, unsigned char isGlobalVar);
HTRuntimeEnvironmentRef HTRuntimeEnvironmentCurrentEnv(HTRuntimeEnvironmentRef env);

void HTRuntimeEnvironmentPrintDebugInfo(HTRuntimeEnvironmentRef env);

#endif //HTLANG_HTRUNTIMEENVIRONMENT_H
