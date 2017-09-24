#include "HTVariable.h"

void HTVariableAlloc(HTVariableRef self) {

}

void HTVariableDealloc(HTVariableRef self) {
    HTPropAssignStrong(self, identifier, NULL);
    HTPropAssignStrong(self, stringValue, NULL);
    HTPropAssignStrong(self, arrayValue, NULL);
    HTPropAssignStrong(self, dictValue, NULL);
}

HTVariableRef HTVariableCreateWithTypeAndName(HTDataType dataType, const char *name) {
    HTVariableRef variable = HTVariableCreate();
    HTStringRef identifierStr = HTStringCreateWithChars(name);
    HTListRef arrayValue = HTListCreate();
    HTDictRef dictValue = HTDictCreateWithBucketCount(100);
    HTPropAssignWeak(variable, dataType, dataType);
    HTPropAssignStrong(variable, identifier, identifierStr);
    HTPropAssignWeak(variable, value.boolValue, 0);
    HTPropAssignWeak(variable, value.intValue, 0);
    HTPropAssignWeak(variable, value.doubleValue, 0);
    HTPropAssignStrong(variable, stringValue, NULL);
    HTPropAssignStrong(variable, arrayValue, arrayValue);
    HTPropAssignStrong(variable, dictValue, dictValue);
    HTTypeRelease(arrayValue);
    HTTypeRelease(identifierStr);
    HTTypeRelease(dictValue);
    return variable;
}

void HTVaraibleCopyValue(HTVariableRef source, HTVariableRef dst) {
    HTPropAssignWeak(dst, dataType, HTPropGet(source, dataType));
    if (HTPropGet(dst, dataType) == HTDataTypeString) {
        HTPropAssignStrong(dst, stringValue, HTPropGet(source, stringValue));
    } else if (HTPropGet(dst, dataType) == HTDataTypeArray) {
        HTPropAssignStrong(dst, arrayValue, HTPropGet(source, arrayValue));
    } else if (HTPropGet(dst, dataType) == HTDataTypeMap) {
        HTPropAssignStrong(dst, dictValue, HTPropGet(source, dictValue));
    }
    else {
        HTPropAssignWeak(dst, value, HTPropGet(source, value));
    }
}

void HTVariablePrintDebugInfo(HTVariableRef ref) {
    if (ref) {
        switch (ref->impl->dataType) {
            case HTDataTypeInt:
                printf("Int: %s, value: %d\n", ref->impl->identifier->impl->characters, ref->impl->value.intValue);
                break;
            case HTDataTypeDouble:
                printf("Double: %s, value: %lf\n", ref->impl->identifier->impl->characters, ref->impl->value.doubleValue);
                break;
            case HTDataTypeBool:
                printf("Bool: %s, value: %d\n", ref->impl->identifier->impl->characters, ref->impl->value.boolValue);
                break;
            case HTDataTypeString:
                printf("String: %s, value: %s\n", ref->impl->identifier->impl->characters, ref->impl->stringValue == NULL ? "": ref->impl->stringValue->impl->characters);
                break;}
    }
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