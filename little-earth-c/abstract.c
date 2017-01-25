#include <stdlib.h>

#include "abstract.h"

void *
abstract_malloc(int sizeToAlloc) {
    return malloc(sizeToAlloc);
}
void
abstract_free(void * toAlloc) {
    free(toAlloc);
}
