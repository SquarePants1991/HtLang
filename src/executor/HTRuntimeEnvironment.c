//
// Created by wang yang on 2017/9/6.
//

#include <utils/HTList.h>
#include "HTRuntimeEnvironment.h"
#include "../compiler/HTFunction.h"

void HTRuntimeEnvironmentAlloc(HTRuntimeEnvironmentRef self) {
    HTListRef variableList = HTListCreate();
    HTListRef functionList = HTListCreate();
    HTPropAssignStrong(self, variables, variableList);
    HTPropAssignStrong(self, functions, functionList);
    HTPropAssignWeak(self, next, NULL);
    HTPropAssignWeak(self, prev, NULL);

    HTTypeRelease(variableList);
    HTTypeRelease(functionList);
}

void HTRuntimeEnvironmentDealloc(HTRuntimeEnvironmentRef self) {
    HTPropAssignStrong(self, variables, NULL);
    HTPropAssignStrong(self, functions, NULL);
    HTPropAssignStrong(self, returnVariable, NULL);
    HTPropAssignStrong(self, next, NULL);
    HTPropAssignStrong(self, prev, NULL);
}

void HTRuntimeEnvironmentBeginNewEnv(HTRuntimeEnvironmentRef env) {
    HTRuntimeEnvironmentRef newEnv = HTRuntimeEnvironmentCreate();
    HTRuntimeEnvironmentRef currentEnv = HTRuntimeEnvironmentCurrentEnv(env);
    HTPropAssignStrong(currentEnv, next, newEnv);
    HTPropAssignStrong(newEnv, prev, currentEnv);
    HTTypeRelease(newEnv);
}

void HTRuntimeEnvironmentEndCurrentEnv(HTRuntimeEnvironmentRef env) {
    HTRuntimeEnvironmentRef currentEnv = HTRuntimeEnvironmentCurrentEnv(env);
    HTRuntimeEnvironmentRef prevEnv = HTPropGet(currentEnv, prev);
    if (prevEnv) {
        HTPropAssignStrong(prevEnv, next, NULL);
    } else {
        // 无需释放顶级运行时环境，这种情况只会在你多调用了HTRuntimeEnvironmentEndCurrentEnv时会发生。
    }
}

HTVariableRef HTRuntimeEnvironmentGetVariable(HTRuntimeEnvironmentRef env, HTStringRef identifier) {
    HTRuntimeEnvironmentRef currentSearchEnv = HTRuntimeEnvironmentCurrentEnv(env);
    while(currentSearchEnv) {

        HTListNodeRef node = HTPropGet(HTPropGet(currentSearchEnv, variables), head);
        while (node != NULL) {
            HTVariableRef variable = HTPropGet(node, ptr);
            if (variable && HTStringEqual(identifier, HTPropGet(variable, identifier))) {
                return variable;
            }
            node = HTPropGet(node, next);
        }

        currentSearchEnv = HTPropGet(currentSearchEnv, prev);
    }
    return NULL;
}

HTFunctionRef HTRuntimeEnvironmentGetFunction(HTRuntimeEnvironmentRef env, HTStringRef identifier) {
    HTRuntimeEnvironmentRef currentSearchEnv = HTRuntimeEnvironmentCurrentEnv(env);
    while(currentSearchEnv) {

        HTListNodeRef node = HTPropGet(HTPropGet(currentSearchEnv, functions), head);
        while (node != NULL) {
            HTFunctionRef func = HTPropGet(node, ptr);
            if (func && HTStringEqual(identifier, HTPropGet(func, identifier))) {
                return func;
            }
            node = HTPropGet(node, next);
        }

        currentSearchEnv = HTPropGet(currentSearchEnv, prev);
    }
    return NULL;
}

void HTRuntimeEnvironmentDeclareVariable(HTRuntimeEnvironmentRef env, HTVariableRef variable, unsigned char isGlobalVar) {
    HTRuntimeEnvironmentRef currentOperationEnv = env;
    if (isGlobalVar == 0) {
        currentOperationEnv = HTRuntimeEnvironmentCurrentEnv(env);
    }
    HTListAppend(HTPropGet(currentOperationEnv, variables), variable);
}

void HTRuntimeEnvironmentDeclareVariables(HTRuntimeEnvironmentRef env, HTListRef variables, unsigned char isGlobalVar) {
    HTListNodeRef node = HTPropGet(variables, head);
    while (node) {
        HTRuntimeEnvironmentDeclareVariable(env, HTPropGet(node, ptr), isGlobalVar);
        node = HTPropGet(node, next);
    }
}

HTRuntimeEnvironmentRef HTRuntimeEnvironmentCurrentEnv(HTRuntimeEnvironmentRef env) {
    HTRuntimeEnvironmentRef currentSearchEnv = env;
    while(HTPropGet(currentSearchEnv, next)) {
        currentSearchEnv = HTPropGet(currentSearchEnv, next);
    }
    return currentSearchEnv;
}

void HTRuntimeEnvironmentPrintDebugInfo(HTRuntimeEnvironmentRef env) {
    HTRuntimeEnvironmentRef currentSearchEnv = env;
    int index = 0;
    while(currentSearchEnv) {
        printf("-------------- Begin Env #%d -----------------\n", index);
        HTListNodeRef node = HTPropGet(HTPropGet(currentSearchEnv, variables), head);
        while (node != NULL) {
            HTVariableRef variable = HTPropGet(node, ptr);

            HTVariablePrintDebugInfo(variable);

            node = HTPropGet(node, next);
        }
        printf("-------------- End Env #%d -----------------\n", index);
        currentSearchEnv = HTPropGet(currentSearchEnv, next);
        index++;
    }
}