#include "utils/HTString.h"

#include <stdio.h>
#include <utils/HTString.h>

void printHTString(HTStringRef str) {
    printf("HTString: > ");
    printf("%s\n", str->impl->characters);
}

int main() {
    HTStringRef str1 = HTStringCreateWithChars("Hello");
    HTStringRef str2 = HTStringCreateWithChars("World");
    HTStringRef str3 = HTStringConcat(str1, str2);
    printHTString(str1);
    printHTString(str2);
    printHTString(str3);
    HTMemPrintAllBlocks();

    HTTypeRelease(str1);
    HTTypeRelease(str2);

    HTTypeRelease(str3);
    HTMemPrintAllBlocks();
    return 0;
}