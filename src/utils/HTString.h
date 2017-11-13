#ifndef __HTString_H_
#define __HTString_H_

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include "HTMem.h"
#include "HTList.h"
#include "HTTypeKit.h"


HTClassBegin
    char * characters;
    size_t length;
HTClassEnd(HTString)

typedef HTString* HTStringRef;

static HTStringRef HTStringCreateWithChars(const char *chars) {
    HTStringRef stringRef = HTStringCreate();
    int strSize = 0;
    char * chBeginPtr = (char *)chars;
    while (*chBeginPtr != 0) {
        chBeginPtr++;
        strSize++;
    }
    stringRef->impl->characters = (char *)HTMemAllocWithIdentifier(strSize * sizeof(char) + 1, "chars");
    memcpy(stringRef->impl->characters, chars, strSize);
    stringRef->impl->characters[strSize * sizeof(char)] = 0;
    stringRef->impl->length = strSize;
    return stringRef;
}

static HTStringRef HTStringCreateFormat(const char *format, ...) {
    int len, ret;
    char* buf;
    buf = (char *)malloc(1024);
    va_list ap;
    va_start(ap, format);

    // We should use vsprintf instead of sprintf
    len = vsprintf(buf, format, ap);

    HTStringRef strRef = HTStringCreateWithChars(buf);
    va_end(ap);
    return strRef;
}

static HTStringRef HTStringConcat(HTStringRef left, HTStringRef right) {
    size_t totalSize = left->impl->length + right->impl->length;
    HTStringRef stringRef = HTStringCreate();
    stringRef->impl->characters = (char *)HTMemAllocWithIdentifier(totalSize + 1, "chars");
    memcpy(stringRef->impl->characters, left->impl->characters, left->impl->length);
    memcpy(stringRef->impl->characters + left->impl->length, right->impl->characters, right->impl->length);
    stringRef->impl->length = totalSize;
    stringRef->impl->characters[totalSize] = 0;
    return stringRef;
}

static unsigned char HTStringEqual(HTStringRef left, HTStringRef right) {
    if (left != NULL && right != NULL) {
        if (left->impl->length == right->impl->length) {
            if (strcmp(left->impl->characters, right->impl->characters) == 0) {
                return 1;
            }
        }
    } else if (left == NULL && right == NULL) {
        return (unsigned char) (left == right);
    }
    return 0;
}

#endif