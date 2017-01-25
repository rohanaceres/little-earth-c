#ifndef _ANIMAL_
#define _ANIMAL_

#include "definitions.h"
#include "abstract.h"

#define new newAnimal

//  @brief: Definitions of the base class of all animals
typedef struct TAnimal {
    TObject reflect;
    string name;
    int age;
    void (*grow)(int animalId);
    void (*poop)(int animalId);
    void (*die)(int animalId);

    // Is implemented by derived classes
    // because each animal sounds different.
    void (*makeSound)(void);
} *Animal, TAnimal;

//  @brief: creates a new animal.
Animal newAnimal(string name, int derivedSize, int * id);

#endif // _ANIMAL_
