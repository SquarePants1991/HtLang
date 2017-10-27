//
// Created by wang yang on 2017/9/22.
//

#include <utils/HTString.h>
#include "utils/HTDict.h"

void batchTest() {
    size_t dataCount = 100;
    HTDictRef dict = HTDictCreateWithBucketCount(1000);
    for (int i = 0; i < dataCount; ++i) {
        HTStringRef key = HTStringCreateFormat("%d", i);
        HTStringRef val = HTStringCreateFormat("val-%d", i);
        HTDictSet(dict, key, val);
        HTTypeRelease(key);
        HTTypeRelease(val);
        printf("Gen Progress %d ...\n", i);
    }
    printf("Large Dict Size: %d\n", HTDictSize(dict));
    printf("Begin Check ...\n");
    for (int j = 0; j < dataCount; ++j) {
        HTStringRef key = HTStringCreateFormat("%d", j);
        HTStringRef val = HTStringCreateFormat("val-%d", j);
        HTStringRef valCmp = HTDictGet(dict, key);
        if (!HTStringEqual(valCmp, val)) {
            printf("Check Failed At %d ...\n", j);
            break;
        }
        HTTypeRelease(key);
        HTTypeRelease(val);
    }

    printf("Before Clear.Dict Len is %d \n", HTDictSize(dict));
    HTDictClear(dict);
    printf("After Clear.Dict Len is %d \n", HTDictSize(dict));

    HTTypeRelease(dict);
}

int main() {
//    HTDictRef dict = HTDictCreateWithBucketCount(100);
//
//    HTStringRef key1 = HTStringCreateWithChars("a");
//    HTStringRef key2 = HTStringCreateWithChars("b");
//    HTStringRef val1 = HTStringCreateWithChars("hello");
//    HTStringRef val2 = HTStringCreateWithChars("world");
//    HTStringRef val3 = HTStringCreateWithChars("hello2");
//
//    HTDictSet(dict, key1, val1);
//    HTDictSet(dict, key2, val2);
//
//    HTStringRef hello = HTDictGet(dict, key1);
//    HTStringRef world = HTDictGet(dict, key2);
//    printf("%s\n", HTPropGet(hello, characters));
//    printf("%s\n", HTPropGet(world, characters));
//
//    HTDictRemove(dict, key1);
//    hello = HTDictGet(dict, key1);
//    if (!hello) {
//        printf("Hello is Removed\n");
//    }
//    printf("Left count: %d\n", HTDictSize(dict));
//
//    HTListRef keys = HTDictMakeKeys(dict);
//    for (int i = 0; i < HTListSize(keys); ++i) {
//        HTStringRef key = HTListAt(keys, i);
//        printf("key=> %s\n", HTPropGet(key, characters));
//    }
//    HTTypeRelease(keys);
//
//    HTDictSet(dict, key1, val3);
//    hello = HTDictGet(dict, key1);
//    world = HTDictGet(dict, key2);
//    printf("%s\n", HTPropGet(hello, characters));
//    printf("%s\n", HTPropGet(world, characters));
//
//    HTTypeRelease(key1);
//    HTTypeRelease(key2);
//    HTTypeRelease(val1);
//    HTTypeRelease(val2);
//    HTTypeRelease(val3);
//
//    HTTypeRelease(dict);

    batchTest();

    HTMemPrintAllBlocks();
}