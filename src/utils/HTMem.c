#include "HTMem.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int memTotalSize;
    int identifierSize;
    char * identifier;
    void * data;
} HTMem;

typedef struct _HTMemList{
    HTMem *block;
    struct _HTMemList *next;
    struct _HTMemList *prev;
} HTMemList;

static HTMemList * memList = NULL;

void * HTMemAlloc(size_t memSize) {
    return HTMemAllocWithIdentifier(memSize, "Default");
}

void * HTMemAllocWithIdentifier(size_t memSize, const char *identifier) {
    int idLen = strlen(identifier);
    int totalLen = sizeof(HTMem) + idLen + memSize;
    HTMem *memBlock = (HTMem *)malloc(totalLen);
    memset(memBlock, 0x00, totalLen);
    memBlock->memTotalSize = totalLen;
    memBlock->identifierSize = idLen;
    memBlock->identifier = (void *)memBlock + sizeof(HTMem) + memSize;
    memBlock->data = (void *)memBlock + sizeof(HTMem);
    memcpy((void *)memBlock + sizeof(HTMem) + memSize, identifier, idLen);
    memset((void *)memBlock + sizeof(HTMem), 0x00, memSize);
    void *dataEntryPtr = (void *)memBlock + sizeof(HTMem);

    HTMemList *newNode = (HTMemList *)malloc(sizeof(HTMemList));
    newNode->block = memBlock;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (memList == NULL) {
        memList = newNode;
    } else {
        HTMemList *node = memList;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = newNode;
        newNode->prev = node;
    }

    return dataEntryPtr;
}

void HTMemFree(void *ptr) {
    void *memBlockPtr = ptr - sizeof(HTMem);
    if (memList) {
        HTMemList *node = memList;
        while (node) {
            if (node->block == memBlockPtr) {
                HTMemList *prevNode = node->prev;
                HTMemList *nextNode = node->next;
                if (prevNode) {
                    prevNode->next = nextNode;
                } else {
                    memList = nextNode;
                }
                if (nextNode) {
                    nextNode->prev = prevNode;
                }
            }
            node = node->next;
        }
    }
    if (ptr) {
        free(memBlockPtr);
    }
}

void HTMemPrintDebugInfo(void *ptr) {
    HTMem *memBlock = (HTMem *)((unsigned char *)ptr - sizeof(HTMem));
    HTMemPrintMemBlockDebugInfo(memBlock);
}

void HTMemPrintMemBlockDebugInfo(void *block) {
    HTMem *memBlock = (HTMem *)block;
    char *identifier = malloc(memBlock->identifierSize + 1);
    memcpy(identifier, memBlock->identifier, memBlock->identifierSize);
    identifier[memBlock->identifierSize] = 0;
    printf("Mem Block : %s\n", identifier);
    printf("Total Size: %d\n", memBlock->memTotalSize);
    printf("Data Size: %d\n", memBlock->memTotalSize - memBlock->identifierSize - sizeof(HTMem));
    printf("==============\n");
    free(identifier);
}

void HTMemPrintAllBlocks() {
    HTMemList *node = memList;
    size_t size = 0;
    while (node) {
        size++;
        node = node->next;
    }
    printf("<<<================ %d Mem Blocks ================>>>\n", size);
    node = memList;
    while (node) {
        HTMemPrintMemBlockDebugInfo(node->block);
        node = node->next;
    }
    printf(">>>================ END ================<<<\n", size);
}