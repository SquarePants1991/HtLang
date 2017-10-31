#ifndef __HTTypeKit_H_
#define __HTTypeKit_H_

#include "./HTType.h"

#define Stringify(str) #str

#define HTClassBegin \
typedef struct {\


#define HTClassEnd(className) \
} className##Impl;\
typedef struct {\
    int refCount;\
    className##Impl *impl;\
    DeallocHandler deallocHandler;\
    IsNULLHandler isNULLHandler;\
} className;\
typedef className * className##Ref;\
\
void className##Alloc(className *obj);\
void className##Dealloc(className *obj);\
static className * className##Create() {\
    className *instance = HTTypeCreateWithIdentifier(Stringify(className));\
    instance->impl = HTMemAllocWithIdentifier(sizeof(className##Impl), Stringify(className##Impl));\
    instance->deallocHandler = className##Dealloc;\
    className##Alloc(instance);\
    return instance;\
}

#define HTPropAssignStrong(dstRef, propertyName, value) \
do { \
if (dstRef == NULL) {\
    break;\
}\
if (dstRef->impl->propertyName) {\
    HTTypeRelease(dstRef->impl->propertyName);\
}\
dstRef->impl->propertyName = value;\
if (dstRef->impl->propertyName) { \
    HTTypeRetain(dstRef->impl->propertyName); \
}\
} while(0)

#define HTPropGet(srcRef, propertyName) \
srcRef->impl->propertyName


#define HTPropAssignWeak(dstRef, propertyName, value) \
dstRef->impl->propertyName = value;

#endif