#ifndef _ANIMAL_
#define _ANIMAL_

#include "definitions.h"

//  @brief: Definitions of the base class of all animals
typedef struct TAnimal {
    string name;
    int age;
    void (*grow)(void *self);
    void (*poop)(void *self);
    void (*die)(void *self);

    // Is implemented by derived classes
    // because each animal sounds different.
    void (*makeSound)(void *self);
} *Animal, TAnimal;

//  @brief: creates a new animal.
Animal newAnimal(string name);

#endif // _ANIMAL_
