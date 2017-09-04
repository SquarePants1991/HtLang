#include "HTVariable.h"

void HTVariableAlloc(HTVariableRef self) {

}

void HTVariableDealloc(HTVariableRef self) {
    HTPropAssignStrong(self, identifier, NULL);
    HTPropAssignStrong(self, stringValue, NULL);
}