//
// Created by wang yang on 2017/9/7.
//

#include "HTLocalFunctionRegsiter.h"
#include "HTLocalFunctions.c"

void HTLocalFunctionRegisterRegister(HTRuntimeEnvironmentRef rootEnv) {
    HTLocalFunctionRegisterRegisterFunc(rootEnv, "print", HTPrint);
    HTLocalFunctionRegisterRegisterFunc(rootEnv, "println", HTPrintln);
    HTLocalFunctionRegisterRegisterFunc(rootEnv, "sin", HTSin);
}

void HTLocalFunctionRegisterRegisterFunc(HTRuntimeEnvironmentRef rootEnv, const char * identifier, HTFunctionBody funcBody) {
    HTStringRef identifierStr = HTStringCreateWithChars(identifier);
    HTFunctionRef func = HTFunctionCreateWithIdentifierAndBody(identifierStr, funcBody, HTDataTypeVoid);
    HTListAppend(HTPropGet(rootEnv, functions), func);

    HTTypeRelease(identifierStr);
    HTTypeRelease(func);
}