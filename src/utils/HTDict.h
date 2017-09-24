//
// Created by wang yang on 2017/9/22.
//

#ifndef HTLANG_HTDICT_H
#define HTLANG_HTDICT_H

#include "HTTypeKit.h"
#include "HTList.h"
#include "HTString.h"

HTClassBegin
HTListRef buckets;
size_t bucketCount;
HTClassEnd(HTDict)

HTClassBegin
    HTStringRef key;
    HTTypeRef value;
HTClassEnd(HTDictPair)

HTDictRef HTDictCreateWithBucketCount(size_t bucketCount);
unsigned long HTDictHash(HTDictRef dict, const char * key);
void HTDictSet(HTDictRef dict, HTStringRef key, HTTypeRef value);
HTTypeRef HTDictGet(HTDictRef dict, HTStringRef key);
size_t HTDictSize(HTDictRef dict);
HTListRef HTDictMakeKeys(HTDictRef dict);
void HTDictRemove(HTDictRef dict, HTStringRef key);

HTDictPairRef HTDictPairCreateWithKeyAndValue(HTStringRef key, HTTypeRef value);

void HTDictPrintDebugInfo(HTDictRef dict);
#endif //HTLANG_HTDICT_H
