#include "utils/HTList.h"
#include <stdio.h>

HTClassBegin
    float x;
    float y;
HTClassEnd(HTVector)

void HTVectorAlloc(HTVectorRef self) {

}

void HTVectorDealloc(HTVectorRef self) {

}

int main() {
    HTListRef list = HTListCreate();
    HTVectorRef vector1 = HTVectorCreate();
    HTPropAssignWeak(vector1, x, 10);
    HTPropAssignWeak(vector1, y, 20);

    HTListAppend(list, vector1);
    HTTypeRelease(vector1);
    printf("After Append1.List Len is %d \n", HTListSize(list));

    HTVectorRef vector2 = HTVectorCreate();
    HTPropAssignWeak(vector2, x, 10);
    HTPropAssignWeak(vector2, y, 20);
    HTListAppend(list, vector2);
    HTTypeRelease(vector2);
    printf("After Append2.List Len is %d \n", HTListSize(list));

    HTListRemove(list, 0);
    printf("After Remove.List Len is %d \n", HTListSize(list));

    HTListClear(list);
    printf("After Clear.List Len is %d \n", HTListSize(list));

    HTTypeRelease(list);
    HTMemPrintAllBlocks();
}