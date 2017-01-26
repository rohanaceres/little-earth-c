#ifndef _KEYVALUEPAIR_
#define _KEYVALUEPAIR_

typedef struct TKeyValuePair TKeyValuePair, *KeyValuePair;
struct TKeyValuePair {
    int key;
    void * value;
    KeyValuePair next;
    KeyValuePair previous;
};

KeyValuePair newKeyValuePair(int key, void * value);

#endif // _KEYVALUEPAIR_
