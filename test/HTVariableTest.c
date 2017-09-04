#include "compiler/HTVariable.h"

int main() {
    HTVariableRef svar = HTVariableCreateWithTypeAndName(HTDataTypeString, "StrVar");
    HTVariableRef ivar = HTVariableCreateWithTypeAndName(HTDataTypeInt, "IntVar");
    HTVariableRef bvar = HTVariableCreateWithTypeAndName(HTDataTypeBool, "BoolVar");
    HTVariableRef dvar = HTVariableCreateWithTypeAndName(HTDataTypeDouble, "DoubleVar");
    HTMemPrintAllBlocks();

    HTTypeRelease(svar);
    HTTypeRelease(ivar);
    HTTypeRelease(bvar);
    HTTypeRelease(dvar);
    HTMemPrintAllBlocks();
    return 0;
}