#ifndef _EAGLE_
#define _EAGLE_

#include "animal.h"

//  @brief: an eagle, derived from TAnimal.
typedef struct TEagle {
    TAnimal; // the base class
    void (*fly)(void);
} *Eagle, TEagle;

//  @brief: creates a new eagle.
Eagle newEagle();

#endif // _EAGLE_

