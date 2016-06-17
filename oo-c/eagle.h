#ifndef _EAGLE_
#define _EAGLE_

#include "animal.h"

typedef struct TEagle {
    TAnimal;
    void (*fly)(void *self);
} *Eagle, TEagle;

Eagle newEagle();

#endif // _EAGLE_

