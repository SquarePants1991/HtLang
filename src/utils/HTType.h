#ifndef __HTType_H_
#define __HTType_H_

#include "HTMem.h"

typedef void (*DeallocHandler)(void * instance);

typedef struct {
    int refCount;
    void *data;
    DeallocHandler deallocHandler;
} HTType;

typedef HTType * HTTypeRef;

HTTypeRef HTTypeCreate();
HTTypeRef HTTypeCreateWithIdentifier(const char* identifier);
void HTTypeRetain(HTTypeRef ref);
void HTTypeRelease(HTTypeRef ref);

#endif