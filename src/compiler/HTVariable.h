#ifndef __HTVariable_H_
#define __HTVariable_H_

#include "../utils/HTString.h"
#include "../utils/HTMem.h"
#include <stdio.h>

typedef enum {
    HTDataTypeVoid,
    HTDataTypeInt,
    HTDataTypeDouble,
    HTDataTypeBool,
	HTDataTypeString,
	HTDataTypeArray
} HTDataType;

HTClassBegin
	HTDataType dataType;
	HTStringRef identifier;
	union {
		int intValue;
		double doubleValue;
		unsigned char boolValue;
	} value;
	HTStringRef stringValue;
	HTListRef arrayValue;
HTClassEnd(HTVariable)


typedef HTVariable * HTVariableRef;


static HTVariableRef HTVariableCreateWithTypeAndName(HTDataType dataType, const char *name) {
	HTVariableRef variable = HTVariableCreate();
	HTStringRef identifierStr = HTStringCreateWithChars(name);
	HTListRef arrayValue = HTListCreate();
	HTPropAssignWeak(variable, dataType, dataType);
	HTPropAssignStrong(variable, identifier, identifierStr);
	HTPropAssignWeak(variable, value.boolValue, 0);
	HTPropAssignWeak(variable, value.intValue, 0);
	HTPropAssignWeak(variable, value.doubleValue, 0);
	HTPropAssignStrong(variable, stringValue, NULL);
	HTPropAssignStrong(variable, arrayValue, arrayValue);
	HTTypeRelease(arrayValue);
	HTTypeRelease(identifierStr);
	return variable;
}

static void HTVaraibleCopyValue(HTVariableRef source, HTVariableRef dst) {
	HTPropAssignWeak(dst, dataType, HTPropGet(source, dataType));
	if (HTPropGet(dst, dataType) == HTDataTypeString) {
		HTPropAssignStrong(dst, stringValue, HTPropGet(source, stringValue));
	} else if (HTPropGet(dst, dataType) == HTDataTypeArray) {
		HTPropAssignStrong(dst, arrayValue, HTPropGet(source, arrayValue));
	}
	else {
		HTPropAssignWeak(dst, value, HTPropGet(source, value));
	}
}

static void HTVariablePrintDebugInfo(HTVariableRef ref) {
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

HTStringRef HTVariableToString(HTVariableRef ref);

#endif