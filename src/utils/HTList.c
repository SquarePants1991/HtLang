#include "HTList.h"

void HTListNodeAlloc(HTListNodeRef self) {
    HTPropAssignStrong(self, ptr, NULL);
    HTPropAssignStrong(self, next, NULL);
    HTPropAssignStrong(self, prev, NULL);
}

void HTListAlloc(HTListRef self) {
    HTPropAssignStrong(self, head, NULL);
    HTPropAssignStrong(self, tail, NULL);
}

void HTListNodeDealloc(HTListNodeRef self) {
    HTPropAssignStrong(self, ptr, NULL);
}

void HTListDealloc(HTListRef self) {
    HTListNodeRef node = HTPropGet(self, head);
    while(node) {
        HTPropAssignStrong(node, prev, NULL);
        HTListNodeRef nextNode = HTPropGet(node, next);
        HTPropAssignStrong(node, next, NULL);
        node = nextNode;
    }
    HTPropAssignStrong(self, head, NULL);
    HTPropAssignStrong(self, tail, NULL);
}

void HTListAppend(HTListRef listRef, HTTypeRef data) {
    HTListNodeRef node = HTListNodeCreate();
    HTPropAssignStrong(node, ptr, data);
    if (HTPropGet(listRef, head) == NULL) {
        HTPropAssignStrong(listRef, head, node);
        HTPropAssignStrong(listRef, tail, node);
    } else {
        HTPropAssignStrong(HTPropGet(listRef, tail), next, node);
        HTPropAssignStrong(node, prev, HTPropGet(listRef, tail));
        HTPropAssignStrong(listRef, tail, node);
    }
    HTTypeRelease(node);
}

HTTypeRef HTListAt(HTListRef listRef, int index) {
    HTListNodeRef node = HTPropGet(listRef, head);
    int currentIndex = 0;
    while(node) {
        if (currentIndex == index) {
            return HTPropGet(node, ptr);
        }
        node = HTPropGet(node, next);
        currentIndex++;
    }
    return NULL;
}

void HTListRemove(HTListRef listRef, int index) {
    HTListNodeRef node = HTPropGet(listRef, head);
    int currentIndex = 0;
    while(node) {
        if (currentIndex == index) {
            HTListNodeRef prev = HTPropGet(node, prev);
            HTListNodeRef next = HTPropGet(node, next);
            HTPropAssignStrong(prev, next, next);
            HTPropAssignStrong(next, prev, prev);
            HTPropAssignStrong(node, prev, NULL);
            HTPropAssignStrong(node, next, NULL);
            return;
        }
        node = HTPropGet(node, next);
        currentIndex++;
    }
}

size_t HTListSize(HTListRef listRef) {
    size_t size = 0;
    HTListNodeRef node = HTPropGet(listRef, head);
    while(node) {
        size++;
        node = HTPropGet(node, next);
    }
    return size;
}
