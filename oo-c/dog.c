#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "definitions.h"
#include "dog.h"
#include "animal.h"

// internals declarations
//  @brief: the dog pursues it's tail.
void dog_pursueTail(Animal self);
//  @brief: the dog yowls.
void dog_yowl(Animal self);

// public definitions
Dog newDog(string name) {
    Dog self = newAnimal(name, sizeof(TDog));

    // functions
    self->makeSound = &dog_yowl;
    self->pursueTail = &dog_pursueTail;

    return self;
}

// internals definitions
void dog_pursueTail(Animal self) {
    printf("%s is pursuing it's tail! hahaha!\n", self->name);
}
void dog_yowl(Animal self) {
    printf("%s: YOOOOWWWL!!\n", self->name);
}
