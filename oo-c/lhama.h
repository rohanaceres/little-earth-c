#ifndef _LHAMA_
#define _LHAMA_

#include "animal.h"
#include "definitions.h"

//  @brief: a lhama, derived from TAnimal.
typedef struct TLhama {
    TAnimal;
    int litersOfWater;
    void (*chew)(void *self);
    void (*spit)(void *self, Animal target);
    void (*saveWater)(void *self);
    void (*drinkWater)(void *self);
} *Lhama, TLhama;

//  @brief: crete a new lhama.
Lhama newLhama(string name);

#endif // _LHAMA_
