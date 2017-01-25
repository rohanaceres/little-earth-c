#ifndef _LHAMA_
#define _LHAMA_

#include "animal.h"
#include "definitions.h"

//  @brief: a lhama, derived from TAnimal.
typedef struct TLhama {
    TAnimal;
    int litersOfWater;
    void (*chew)(void);
    void (*spit)(Animal target);
    void (*saveWater)(void);
    void (*drinkWater)(void);
} *Lhama, TLhama;

//  @brief: crete a new lhama.
Lhama newLhama(string name);

#endif // _LHAMA_
