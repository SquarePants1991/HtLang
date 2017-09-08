//
// Created by wang yang on 2017/9/7.
//

#include "HTFunction.h"

void HTFunctionAlloc(HTFunctionRef self) {

}

void HTFunctionDealloc(HTFunctionRef self) {
    HTPropAssignStrong(self, identifier, NULL);
    switch (HTPropGet(self, functionType)) {
        case HTFunctionTypeLocal:
            HTPropAssignWeak(self, u.localFunction.functionBody, NULL);
            break;
        case HTFunctionTypeCustom:
            HTPropAssignStrong(self, u.customFunction.parameterDefList, NULL);
            HTPropAssignStrong(self, u.customFunction.statementList, NULL);
            break;
    }

}

HTFunctionRef HTFunctionCreateWithIdentifierAndBody(HTStringRef identifier, HTFunctionBody funcBody, HTDataType returnType) {
    HTFunctionRef func = HTFunctionCreate();
    HTPropAssignWeak(func, returnType, returnType);
    HTPropAssignWeak(func, functionType, HTFunctionTypeLocal);
    HTPropAssignStrong(func, identifier, identifier);
    HTPropAssignWeak(func, u.localFunction.functionBody, funcBody);
    return func;
}

HTFunctionRef HTFunctionCreateCustom(HTStringRef identifier, HTListRef parameterDefList, HTListRef statementList, HTDataType returnType) {
    HTFunctionRef func = HTFunctionCreate();
    HTPropAssignWeak(func, returnType, returnType);
    HTPropAssignWeak(func, functionType, HTFunctionTypeCustom);
    HTPropAssignStrong(func, identifier, identifier);
    HTPropAssignStrong(func, u.customFunction.parameterDefList, parameterDefList);
    HTPropAssignStrong(func, u.customFunction.statementList, statementList);
    return func;
}