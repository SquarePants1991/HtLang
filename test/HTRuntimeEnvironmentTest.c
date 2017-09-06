//
// Created by wang yang on 2017/9/6.
//

#include <compiler/HTVariable.h>
#include "executor/HTRuntimeEnvironment.h"

int main() {
    HTRuntimeEnvironmentRef rootEnv = HTRuntimeEnvironmentCreate();
    HTVariableRef globalIntVar = HTVariableCreateWithTypeAndName(HTDataTypeInt, "globalIntVar");
    HTRuntimeEnvironmentDeclareVariable(rootEnv, globalIntVar, 0);
    HTTypeRelease(globalIntVar);

    HTStringRef varId = HTStringCreateWithChars("globalIntVar");
    HTVariableRef globalIntVarGet = HTRuntimeEnvironmentGetVariable(rootEnv, varId);
    HTPropAssignWeak(globalIntVarGet, value.intValue, 300);


    HTVariableRef localIntVar = HTVariableCreateWithTypeAndName(HTDataTypeInt, "localIntVar");
    HTRuntimeEnvironmentBeginNewEnv(rootEnv);
    HTRuntimeEnvironmentDeclareVariable(rootEnv, localIntVar, 0);

    HTRuntimeEnvironmentPrintDebugInfo(rootEnv);

    HTStringRef localIntVarID = HTStringCreateWithChars("localIntVar");

    HTVariableRef localIntVarGet = HTRuntimeEnvironmentGetVariable(rootEnv, localIntVarID);
    globalIntVarGet = HTRuntimeEnvironmentGetVariable(rootEnv, varId);
    HTPropAssignWeak(globalIntVarGet, value.intValue, 300);
    HTPropAssignWeak(localIntVarGet, value.intValue, 100);

    printf("after assign new values ------------------------------------\n");
    HTRuntimeEnvironmentPrintDebugInfo(rootEnv);

    HTRuntimeEnvironmentEndCurrentEnv(rootEnv);
    HTTypeRelease(localIntVar);




    HTTypeRelease(localIntVarID);
    HTTypeRelease(varId);
    HTTypeRelease(rootEnv);
    HTMemPrintAllBlocks();

    return 0;
}