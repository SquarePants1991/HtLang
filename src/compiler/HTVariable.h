#ifndef __HTVariable_H_
#define __HTVariable_H_

#include "../utils/HTString.h"
#include "../utils/HTMem.h"
#include "../utils/HTDict.h"

#include <stdio.h>

#define HTDataTypeValueMask 0x00001
#define HTDataTypeRefMask 0x00010
#define HTDataTypeValueOffset 1
#define HTDataTypeRefOffset 2

typedef enum {
    HTDataTypeVoid = 0 << HTDataTypeRefOffset | HTDataTypeRefMask,
    HTDataTypeInt = 2 << HTDataTypeValueOffset  | HTDataTypeValueMask,
    HTDataTypeDouble = 3 << HTDataTypeValueOffset  | HTDataTypeValueMask,
    HTDataTypeBool = 4 << HTDataTypeValueOffset  | HTDataTypeValueMask,
	HTDataTypeString = 1 << HTDataTypeRefOffset  | HTDataTypeRefMask,
	HTDataTypeArray = 2 << HTDataTypeRefOffset  | HTDataTypeRefMask,
    HTDataTypeMap = 3 << HTDataTypeRefOffset  | HTDataTypeRefMask,
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
void HTVariableSetNull(HTVariableRef variable);


typedef HTVariable * HTVariableRef;


HTVariableRef HTVariableCreateWithTypeAndName(HTDataType dataType, const char *name);
void HTVaraibleCopyValue(HTVariableRef source, HTVariableRef dst);
HTStringRef HTVariableToString(HTVariableRef ref);

void HTVariablePrintDebugInfo(HTVariableRef ref);

#endif