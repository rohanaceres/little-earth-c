#include "keyvaluepair.h"
#include "abstract.h"

// construction
KeyValuePair newKeyValuePair(int key, void * value) {
    KeyValuePair self = (KeyValuePair) abstract_malloc(sizeof(TKeyValuePair));

    self->next = null;
    self->previous = null;
    self->key = key;
    self->value = value;

    return self;
}

