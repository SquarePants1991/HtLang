#ifndef __HTList_H_
#define __HTList_H_

#include "HTTypeKit.h"

HTClassBegin
    HTTypeRef ptr;
    struct HTListNode * next;
    struct HTListNode * prev;
HTClassEnd(HTListNode)

HTClassBegin
    HTListNodeRef head;
    HTListNodeRef tail;
HTClassEnd(HTList)

void HTListAppend(HTListRef listRef, HTTypeRef data);

HTTypeRef HTListAt(HTListRef listRef, int index);
void HTListRemove(HTListRef listRef, int index);
void HTListClear(HTListRef listRef);
size_t HTListSize(HTListRef listRef);


#endif