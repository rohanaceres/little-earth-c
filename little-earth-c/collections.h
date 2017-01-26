#ifndef _COLLECTIONS_
#define _COLLECTIONS_

#include "keyvaluepair.h"
#include "abstract.h"

typedef struct TLinkedList TLinkedList, * LinkedList;
struct TLinkedList {
    KeyValuePair head;
    KeyValuePair last;
    int length;

    void (*display)(LinkedList self);
    void (*add)(LinkedList self, int key, void * value);
    void *(*getValue)(LinkedList self, int key);
    void (*remove)(LinkedList self, int toRemove);
};

LinkedList newLinkedList(void);

#endif // _COLLECTIONS_
