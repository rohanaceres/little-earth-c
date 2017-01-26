#ifndef _KEYVALUEPAIR_
#define _KEYVALUEPAIR_

typedef struct TKeyValuePair TKeyValuePair, *KeyValuePair;
struct TKeyValuePair {
    int key;
    void * value;
    KeyValuePair next;
    KeyValuePair previous;
};

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
KeyValuePair newKeyValuePair(int key, void * value);

#endif // _KEYVALUEPAIR_
