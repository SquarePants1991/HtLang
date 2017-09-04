#include "utils/HTTypeKit.h"
#include <stdio.h>


HTClassBegin
    int value;
HTClassEnd(HTInt)

void HTIntAlloc(HTInt *this) {

}

void HTIntDealloc(HTInt *htInt) {
    printf("HTint is dealloc, Value is %d\n", htInt->impl->value);
}

int main() {
    HTInt *htInt = HTIntCreate();
    htInt->impl->value = 3;
    HTMemPrintAllBlocks();
    HTTypeRelease(htInt);
    HTMemPrintAllBlocks();
    return 0;
}