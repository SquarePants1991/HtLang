#ifndef __HTVariable_H_
#define __HTVariable_H_

#include <utils/HTString.h>
#include "../utils/HTString.h"
#include "../utils/HTMem.h"

typedef enum {
    HTDataTypeInt,
    HTDataTypeDouble,
    HTDataTypeBool,
	HTDataTypeString
} HTDataType;

typedef struct {
	HTDataType dataType;
	HTStringRef identifier;
	union {
		int intValue;
		double doubleValue;
		unsigned char boolValue;
		HTStringRef stringValue;
	} value;
} HTVariable;

typedef HTVariable * HTVariableRef;

static HTVariableRef HTVariableCreate(HTDataType dataType, const char *name) {
	HTVariableRef variable = HTMemAlloc(sizeof(HTVariable));
	variable->dataType = dataType;
	variable->identifier = HTStringCreate(name);
	variable->value.boolValue = 0;
	variable->value.doubleValue = 0;
	variable->value.intValue = 0;
	variable->value.stringValue = NULL;
	return variable;
}

static void HTVariableFree(HTVariableRef ref) {
	HTMemFree(ref->identifier);
	HTMemFree(ref);
}

static void HTVariablePrintDebugInfo(HTVariableRef ref) {
    if (ref) {
        switch (ref->dataType) {
            case HTDataTypeInt:
                printf("Int: %s, value: %d\n", ref->identifier->characters, ref->value.intValue);
                break;
            case HTDataTypeDouble:
                printf("Double: %s, value: %lf\n", ref->identifier->characters, ref->value.doubleValue);
                break;
            case HTDataTypeBool:
                printf("Bool: %s, value: %d\n", ref->identifier->characters, ref->value.boolValue);
                break;
            case HTDataTypeString:
                printf("String: %s, value: %s\n", ref->identifier->characters, ref->value.stringValue == NULL ? "": ref->value.stringValue->characters);
                break;}
    }
}

#endif