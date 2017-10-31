#ifndef __HTVariable_H_
#define __HTVariable_H_

#include "../utils/HTString.h"
#include "../utils/HTMem.h"
#include "../utils/HTDict.h"

#include <stdio.h>

typedef enum {
    HTDataTypeVoid,
    HTDataTypeInt,
    HTDataTypeDouble,
    HTDataTypeBool,
	HTDataTypeString,
	HTDataTypeArray,
    HTDataTypeMap,
	HTDataTypeNil
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
    HTDictRef dictValue;
HTClassEnd(HTVariable)

unsigned char HTVariableIsNull(HTVariableRef variable);

typedef HTVariable * HTVariableRef;


HTVariableRef HTVariableCreateWithTypeAndName(HTDataType dataType, const char *name);
void HTVaraibleCopyValue(HTVariableRef source, HTVariableRef dst);
HTStringRef HTVariableToString(HTVariableRef ref);

void HTVariablePrintDebugInfo(HTVariableRef ref);

#endif