#include "HTType.h"

HTTypeRef HTTypeCreate() {
    HTTypeRef typeRef = HTMemAlloc(sizeof(HTType));
    typeRef->refCount = 1;
    typeRef->deallocHandler = NULL;
    typeRef->isNULLHandler = NULL;
    return typeRef;
}

HTTypeRef HTTypeCreateWithIdentifier(const char* identifier) {
    HTTypeRef typeRef = HTMemAllocWithIdentifier(sizeof(HTType), identifier);
    typeRef->refCount = 1;
    typeRef->deallocHandler = NULL;
    typeRef->isNULLHandler = NULL;
    return typeRef;
}

void HTTypeRetain(HTTypeRef ref) {
    ref->refCount++;
}

void HTTypeRelease(HTTypeRef ref) {
    ref->refCount--;
    if (ref->refCount < 0) {

    }
    if (ref->refCount <= 0) {
        if (ref->deallocHandler) {
            ref->deallocHandler(ref);
        }
        if (ref->data) {
            HTMemFree(ref->data);
        }
        HTMemFree(ref);
    }
}