#ifndef __HTType_H_
#define __HTType_H_

#include "HTMem.h"

typedef void (*DeallocHandler)(void * instance);
typedef unsigned char (*IsNULLHandler)(void * instance);

typedef struct {
    int refCount;
    void *data;
    DeallocHandler deallocHandler;
    IsNULLHandler isNULLHandler;
} HTType;

typedef HTType * HTTypeRef;

HTTypeRef HTTypeCreate();
HTTypeRef HTTypeCreateWithIdentifier(const char* identifier);
void HTTypeRetain(HTTypeRef ref);
void HTTypeRelease(HTTypeRef ref);

#endif