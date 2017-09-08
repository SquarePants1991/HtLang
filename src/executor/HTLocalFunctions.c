//
// Created by wang yang on 2017/9/7.
//

#ifndef __HTLocalFunctions_H__
#define __HTLocalFunctions_H__

#include <compiler/HTVariable.h>
#include <utils/HTList.h>
#include "../compiler/HTVariable.h"
#include "../utils/HTString.h"
#include "../utils/HTList.h"

#include <math.h>
#include <utils/HTString.h>


static void HTPrint(HTListRef parameters, HTVariableRef returnVal) {
    HTListNodeRef node = HTPropGet(parameters, head);
    while (node) {
        HTVariableRef variable = HTPropGet(node, ptr);
        HTStringRef desc = HTVariableToString(variable);
        printf("%s", HTPropGet(desc, characters));
        HTTypeRelease(desc);
        node = HTPropGet(node, next);
    }
}

static void HTPrintln(HTListRef parameters, HTVariableRef returnVal) {
    HTListNodeRef node = HTPropGet(parameters, head);
    while (node) {
        HTVariableRef variable = HTPropGet(node, ptr);
        HTStringRef desc = HTVariableToString(variable);
        printf("%s\n", HTPropGet(desc, characters));
        HTTypeRelease(desc);
        node = HTPropGet(node, next);
    }
}

static void HTSin(HTListRef parameters, HTVariableRef returnVal) {
    HTListNodeRef node = HTPropGet(parameters, head);
    if (node) {
        HTVariableRef var = HTPropGet(node, ptr);
        HTPropAssignWeak(returnVal, dataType, HTDataTypeDouble);
        HTPropAssignWeak(returnVal, value.doubleValue, sin(HTPropGet(var, value.doubleValue)));
    }
}

#endif