//
// Created by wang yang on 2017/9/7.
//

#ifndef HTLANG_HTFUNCTION_H
#define HTLANG_HTFUNCTION_H

#include "utils/HTString.h"
#include "utils/HTTypeKit.h"
#include "HTVariable.h"

typedef void (*HTFunctionBody)(HTListRef parameters, HTVariableRef returnVal);

typedef enum {
    HTFunctionTypeLocal,
    HTFunctionTypeCustom
} HTFunctionType;

typedef struct {
    HTFunctionBody functionBody;
} HTFunctionLocal;

typedef struct {
    HTListRef parameterDefList;
    HTListRef statementList;
} HTFunctionCustom;

HTClassBegin
    HTFunctionType functionType;
    HTStringRef identifier;
    HTDataType returnType;
    union {
        HTFunctionLocal localFunction;
        HTFunctionCustom customFunction;
    } u;
HTClassEnd(HTFunction)

HTFunctionRef HTFunctionCreateWithIdentifierAndBody(HTStringRef identifier, HTFunctionBody funcBody, HTDataType returnType);
HTFunctionRef HTFunctionCreateCustom(HTStringRef identifier, HTListRef parameterDefList, HTListRef statementList, HTDataType returnType);

#endif //HTLANG_HTFUNCTION_H
