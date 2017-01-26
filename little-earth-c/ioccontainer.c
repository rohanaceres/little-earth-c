#include <stdlib.h>

#include "ioccontainer.h"
#include "abstract.h"
#include "keyvaluepair.h"

LinkedList _container = null;

// ioc functions
void
ioc_register (void *instance, int instanceId) {
}
void *
ioc_resolve (int instanceId) {
}
int
ioc_getNewId (void) {
}

// linked list functions

