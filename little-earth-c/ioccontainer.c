#include <stdlib.h>

#include "ioccontainer.h"
#include "abstract.h"

typedef struct TKeyValuePair {
    int key;
    void * value;
} TKeyValuePair, * KeyValuePair;

// internal functions
void
log (const char * format, ...) {
    #ifdef SHOWLOG
    printf(format);
    #endif // SHOWLOG
}

TKeyValuePair * _container = null;
int _autoIncrementIndex = 1;
int _containerLength = 0;

void
ioc_register (void *instance, int instanceId) {
    _containerLength++;

    if (_container == null) {
        _container = (TKeyValuePair *) malloc (sizeof(TKeyValuePair));
        log("*** CONTAINER CREATED WITH <%d> BYTES ***\n",
               _containerLength * sizeof(TKeyValuePair));
    }
    else {
        int newSize = _containerLength * sizeof(TKeyValuePair);
        log("*** NEW SIZE = %d * %d = %d***\n", _containerLength, sizeof(TKeyValuePair),
               _containerLength * sizeof(TKeyValuePair));
        _container = (TKeyValuePair *) realloc(_container, newSize);
        log("*** CONTAINER REALLOCATED TO <%d> ***\n", newSize);
    }

    _container[_containerLength - 1].key = instanceId;
    _container[_containerLength - 1].value = instance;

    log("*** INSERTED <%p, %d> ON INDEX <%d>***\n", instance, instanceId,
           _containerLength - 1);
}
void *
ioc_resolve (int instanceId) {
    log("*** CONTAINER SIZE <%d> ***\n", _containerLength);

    for (int i = 0; i < _containerLength; i++) {
        if (_container[i].key == instanceId) {
            return _container[i].value;
        }
    }

    log("*** <%d> NOT FOUND! ***\n", instanceId);
    return (void *) 0;
}
int
ioc_getNewId (void) {
    return _autoIncrementIndex++;
}
