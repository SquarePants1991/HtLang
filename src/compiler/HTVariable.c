#include "HTVariable.h"

void HTVariableAlloc(HTVariableRef self) {

}

void HTVariableDealloc(HTVariableRef self) {
    HTPropAssignStrong(self, identifier, NULL);
    HTPropAssignStrong(self, stringValue, NULL);
    HTPropAssignStrong(self, arrayValue, NULL);
}

HTStringRef HTVariableToString(HTVariableRef ref) {
    HTStringRef newString = NULL;
    switch (HTPropGet(ref, dataType)) {
        case HTDataTypeString:
            newString = HTStringCreateWithChars(HTPropGet(HTPropGet(ref, stringValue), characters));
            break;
        case HTDataTypeInt:
            newString = HTStringCreateFormat("%d", HTPropGet(ref, value.intValue));
            break;
        case HTDataTypeBool:
            newString = HTStringCreateFormat("%d", HTPropGet(ref, value.boolValue));
            break;
        case HTDataTypeDouble:
            newString = HTStringCreateFormat("%lf", HTPropGet(ref, value.doubleValue));
            break;
        case HTDataTypeArray: {
            HTListNodeRef node = HTPropGet(HTPropGet(ref, arrayValue), head);
            newString = HTStringCreateWithChars("[");
            HTStringRef commaStr = HTStringCreateWithChars(",");
            HTStringRef sbEndStr = HTStringCreateWithChars("]");
            while (node) {
                HTVariableRef variable = HTPropGet(node, ptr);
                HTStringRef addStr = HTVariableToString(variable);
                HTStringRef _newString = HTStringConcat(newString, addStr);
                HTTypeRelease(newString);
                HTTypeRelease(addStr);
                newString = _newString;

                if (HTPropGet(node, next)) {
                    HTStringRef _newString = HTStringConcat(newString, commaStr);
                    HTTypeRelease(newString);
                    newString = _newString;
                } else {
                    HTStringRef _newString = HTStringConcat(newString, sbEndStr);
                    HTTypeRelease(newString);
                    newString = _newString;
                }

                node = HTPropGet(node, next);
            }
            HTTypeRelease(commaStr);
            HTTypeRelease(sbEndStr);
            break;
        default:
            newString = HTStringCreateWithChars("");
            break;
        }
    }
    return newString;
}