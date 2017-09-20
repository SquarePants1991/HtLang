#ifndef __HTMem_H_
#define __HTMem_H_

#include <stdlib.h>

void * HTMemAlloc(size_t memSize);
void * HTMemAllocWithIdentifier(size_t memSize, const char *identifier);
void HTMemFree(void *ptr);
void HTMemPrintDebugInfo(void *ptr);
void HTMemPrintMemBlockDebugInfo(void *block);
size_t HTMemCurrentBlockCount();
void HTMemPrintAllBlocks();
#endif