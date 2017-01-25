#ifndef _DOG_
#define _DOG_

#include "animal.h"

//  @brief: a dog, derived from TAnimal.
typedef struct TDog {
    TAnimal; // the base class
    void (*pursueTail)(void);
} *Dog, TDog;

//  @brief: creates a new dog.
Dog newDog();

#endif //_DOG_
