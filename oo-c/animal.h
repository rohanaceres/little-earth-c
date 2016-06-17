#ifndef _ANIMAL_
#define _ANIMAL_

#include "definitions.h"

//typedef struct TAnimal, *Animal;

struct TAnimal {
    string name;
    int age;
    void (*makeSound)(void *self);
    void (*grow)(void *self);
    void (*poop)(void *self);
    void (*die)(void *self);
};

typedef struct TAnimal *Animal;

Animal newAnimal(string name);

#endif // _ANIMAL_
