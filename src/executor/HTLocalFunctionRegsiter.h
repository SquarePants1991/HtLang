//
// Created by wang yang on 2017/9/7.
//

#ifndef HTLANG_HTLOCALFUNCTIONREGSITER_H
#define HTLANG_HTLOCALFUNCTIONREGSITER_H

#include "../compiler/HTFunction.h"

#include "HTRuntimeEnvironment.h"

void HTLocalFunctionRegisterRegister(HTRuntimeEnvironmentRef rootEnv);
void HTLocalFunctionRegisterRegisterFunc(HTRuntimeEnvironmentRef rootEnv, const char * identifier, HTFunctionBody funcBody);

#endif //HTLANG_HTLOCALFUNCTIONREGSITER_H
