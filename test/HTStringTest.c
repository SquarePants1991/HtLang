#include "utils/HTString.h"

#include <stdio.h>
#include <utils/HTString.h>

void printHTString(HTStringRef str) {
    printf("HTString: > ");
    printf("%s\n", str->characters);
}

int main() {
    HTStringRef str1 = HTStringCreate("Hello");
    HTStringRef str2 = HTStringCreate("World");
    HTStringRef str3 = HTStringConcat(str1, str2);
    printHTString(str1);
    printHTString(str2);
    printHTString(str3);
    return 0;
}