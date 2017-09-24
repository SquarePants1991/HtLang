//
// Created by wang yang on 2017/9/22.
//

#include "HTDict.h"
#include "HTString.h"
#include "HTList.h"
#include <limits.h>

void HTDictAlloc(HTDictRef self) {

}

void HTDictDealloc(HTDictRef self) {
    HTPropAssignStrong(self, buckets, NULL);
}

HTDictRef HTDictCreateWithBucketCount(size_t bucketCount) {
    HTDictRef dict = HTDictCreate();
    HTListRef buckets = HTListCreate();
    for (int i = 0; i < bucketCount; ++i) {
        HTListRef list = HTListCreate();
        HTListAppend(buckets, list);
        HTTypeRelease(list);
    }
    HTPropAssignStrong(dict, buckets, buckets);
    HTPropAssignWeak(dict, bucketCount, bucketCount);
    HTTypeRelease(buckets);
    return dict;
}

unsigned long HTDictHash(HTDictRef dict, const char * key) {
    unsigned long hashval = 0;
    int i = 0;

    /* Convert our string to an integer */
    while( hashval < ULONG_MAX && i < strlen( key ) ) {
        hashval = hashval << 8;
        hashval += key[ i ];
        i++;
    }

    return hashval % HTListSize(HTPropGet(dict, buckets));
}

void HTDictSet(HTDictRef dict, HTStringRef key, HTTypeRef value) {
    char * keyChars = HTPropGet(key, characters);
    unsigned long hashVal = HTDictHash(dict, keyChars);
    HTListRef bucket = HTListAt(HTPropGet(dict, buckets), hashVal);
    HTListNodeRef bucketNode = HTPropGet(bucket, head);
    HTDictPairRef newPair = HTDictPairCreateWithKeyAndValue(key, value);
    unsigned char isExist = 0;
    while (bucketNode) {
        HTDictPairRef pair = HTPropGet(bucketNode, ptr);
        if (HTStringEqual(key, HTPropGet(pair, key))) {
            isExist = 1;
            HTPropAssignStrong(pair, value, value);
        }
        bucketNode = HTPropGet(bucketNode, next);
    }
    if (isExist == 0) {
        HTListAppend(bucket, newPair);
    }
    HTTypeRelease(newPair);
}

HTTypeRef HTDictGet(HTDictRef dict, HTStringRef key) {
    char * keyChars = HTPropGet(key, characters);
    unsigned long hashVal = HTDictHash(dict, keyChars);
    HTListRef bucket = HTListAt(HTPropGet(dict, buckets), hashVal);
    HTListNodeRef bucketNode = HTPropGet(bucket, head);
    while (bucketNode) {
        HTDictPairRef pair = HTPropGet(bucketNode, ptr);
        if (HTStringEqual(key, HTPropGet(pair, key))) {
            return HTPropGet(pair, value);
        }
        bucketNode = HTPropGet(bucketNode, next);
    }
    return NULL;
}

void HTDictRemove(HTDictRef dict, HTStringRef key) {
    char * keyChars = HTPropGet(key, characters);
    unsigned long hashVal = HTDictHash(dict, keyChars);
    HTListRef bucket = HTListAt(HTPropGet(dict, buckets), hashVal);
    HTListNodeRef bucketNode = HTPropGet(bucket, head);
    int removeIndex = 0;
    while (bucketNode) {
        HTDictPairRef pair = HTPropGet(bucketNode, ptr);
        if (HTStringEqual(key, HTPropGet(pair, key))) {
            // TODO:这里偷懒，其实可以直接对node进行断链操作
            HTListRemove(bucket, removeIndex);
            break;
        }
        bucketNode = HTPropGet(bucketNode, next);
        removeIndex++;
    }
}

size_t HTDictSize(HTDictRef dict) {
    HTListRef list = HTPropGet(dict, buckets);
    HTListNodeRef bucketsNode = HTPropGet(list, head);
    size_t sumSize = 0;
    while (bucketsNode) {
        HTListRef bucketList = HTPropGet(bucketsNode, ptr);
        sumSize += HTListSize(bucketList);
        bucketsNode = HTPropGet(bucketsNode, next);
    }
    return sumSize;
}

HTListRef HTDictMakeKeys(HTDictRef dict) {
    HTListRef keys = HTListCreate();

    HTListRef list = HTPropGet(dict, buckets);
    HTListNodeRef bucketsNode = HTPropGet(list, head);
    size_t sumSize = 0;
    while (bucketsNode) {
        HTListRef bucketList = HTPropGet(bucketsNode, ptr);
        HTListNodeRef bucketNode = HTPropGet(bucketList, head);
        while (bucketNode) {
            HTDictPairRef pair = HTPropGet(bucketNode, ptr);
            HTListAppend(keys, HTPropGet(pair, key));
            bucketNode = HTPropGet(bucketNode, next);
        }
        bucketsNode = HTPropGet(bucketsNode, next);
    }

    return keys;
}

void HTDictPairAlloc(HTDictPairRef self) {

}

void HTDictPairDealloc(HTDictPairRef self) {
    HTPropAssignStrong(self, key, NULL);
    HTPropAssignStrong(self, value, NULL);
}

HTDictPairRef HTDictPairCreateWithKeyAndValue(HTStringRef key, HTTypeRef value) {
    HTDictPairRef pair = HTDictPairCreate();
    HTPropAssignStrong(pair, key, key);
    HTPropAssignStrong(pair, value, value);
    return pair;
}

void HTDictPrintDebugInfo(HTDictRef dict) {
    HTListRef list = HTPropGet(dict, buckets);
    HTListNodeRef bucketsNode = HTPropGet(list, head);
    while (bucketsNode) {
        HTListRef bucketList = HTPropGet(bucketsNode, ptr);
        HTListNodeRef bucketNode = HTPropGet(bucketList, head);
        while (bucketNode) {
            HTDictPairRef pair = HTPropGet(bucketNode, ptr);
            HTStringRef keyStr = HTPropGet(pair, key);
            printf("key => %s,", HTPropGet(keyStr, characters));
            bucketNode = HTPropGet(bucketNode, next);
        }
        bucketsNode = HTPropGet(bucketsNode, next);
    }
}