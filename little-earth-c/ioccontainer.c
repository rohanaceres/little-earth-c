#include <stdlib.h>

#include "ioccontainer.h"
#include "keyvaluepair.h"
#include "collections.h"

LinkedList _container = null;
int _autoIncrement = 1;

// ioc functions
void
ioc_register (void *instance, int instanceId) {
    if (_container == null) {
        _container = newLinkedList();
    }

    _container->add(_container, instanceId, instance);
    ioc_log();
}
void
ioc_unregister (int instanceId) {
    if (_container != null) {
        _container->remove(_container, instanceId);
    }
    ioc_log();
}
void *
ioc_resolve (int instanceId) {
    return _container->getValue(_container, instanceId);
}
int
ioc_getNewId (void) {
    return _autoIncrement++;
}
int
ioc_log(void) {
    #ifdef CONTAINER_LOG
    if (_container != null) {
        _container->display(_container);
    }
    #endif // CONTAINER_LOG
}

// linked list functions

