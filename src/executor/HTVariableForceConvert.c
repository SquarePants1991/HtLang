//
// Created by wang yang on 2017/9/14.
//

#include <compiler/HTVariable.h>
#include "../compiler/HTVariable.h"

#include "HTVariableForceConvert.h"

HTVariableRef HTVariableConvertToDouble(HTVariableRef variable, unsigned char useOriginVariable) {
    HTVariableRef targetVariable = variable;
    if (!useOriginVariable) {
        targetVariable = HTVariableCreateWithTypeAndName(HTPropGet(variable, dataType), HTPropGet(variable, identifier));
    }

    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeBool:
            HTPropAssignWeak(targetVariable, value.doubleValue, (double)HTPropGet(variable, value.boolValue));
            return targetVariable;
        case HTDataTypeInt:
            HTPropAssignWeak(targetVariable, value.doubleValue, (double)HTPropGet(variable, value.intValue));
            return targetVariable;
        default:
            HTPropAssignWeak(targetVariable, value.doubleValue, (int)HTPropGet(variable, value.doubleValue));
            break;
    }

    HTPropAssignWeak(targetVariable, dataType, HTDataTypeDouble);
    return targetVariable;
}

HTVariableRef HTVariableConvertToInt(HTVariableRef variable, unsigned char useOriginVariable) {
    HTVariableRef targetVariable = variable;
    if (!useOriginVariable) {
        targetVariable = HTVariableCreateWithTypeAndName(HTPropGet(variable, dataType), HTPropGet(variable, identifier));
    }
    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeBool:
            HTPropAssignWeak(targetVariable, value.intValue, (int)HTPropGet(variable, value.boolValue));
            break;
        case HTDataTypeDouble:
            HTPropAssignWeak(targetVariable, value.intValue, (int)HTPropGet(variable, value.doubleValue));
            break;
        default:
            HTPropAssignWeak(targetVariable, value.intValue, (int)HTPropGet(variable, value.intValue));
            break;
    }
    HTPropAssignWeak(targetVariable, dataType, HTDataTypeInt);

    return targetVariable;
}

HTVariableRef HTVariableConvertToString(HTVariableRef variable, unsigned char useOriginVariable) {
    HTVariableRef targetVariable = variable;
    if (!useOriginVariable) {
        targetVariable = HTVariableCreateWithTypeAndName(HTPropGet(variable, dataType), HTPropGet(variable, identifier));
    }

    if (!HTVariableIsNull(variable)) {
        HTStringRef str = HTVariableToString(variable);
        HTPropAssignStrong(targetVariable, stringValue, str);
        HTTypeRelease(str);
    }

    HTPropAssignWeak(targetVariable, dataType, HTDataTypeString);
    return targetVariable;
}

HTVariableRef HTVariableConvertToBool(HTVariableRef variable, unsigned char useOriginVariable) {
    HTVariableRef targetVariable = variable;
    if (!useOriginVariable) {
        targetVariable = HTVariableCreateWithTypeAndName(HTDataTypeBool, HTPropGet(variable, identifier));
    }
    switch (HTPropGet(variable, dataType)) {
        case HTDataTypeInt:
            HTPropAssignWeak(targetVariable, value.boolValue, (unsigned char)HTPropGet(variable, value.intValue));
            break;
        case HTDataTypeDouble:
            HTPropAssignWeak(targetVariable, value.boolValue, (unsigned char)HTPropGet(variable, value.doubleValue));
            break;
        default:
            HTPropAssignWeak(targetVariable, value.boolValue, (int)HTPropGet(variable, value.boolValue));
            break;
    }
    HTPropAssignWeak(targetVariable, dataType, HTDataTypeBool);
    return targetVariable;
}
