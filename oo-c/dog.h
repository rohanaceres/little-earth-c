#ifndef _DOG_
#define _DOG_

#include "animal.h"

typedef struct TDog {
    TAnimal;
    void (*pursueTail)(void *dog);
} *Dog, TDog;

Dog newDog();

#endif //_DOG_
