#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "definitions.h"
#include "dog.h"
#include "animal.h"

// internals declarations
void dog_pursueTail(Animal self);
void dog_yowl(Animal self);

// public definitions
Dog newDog(string name) {
    Dog self = newAnimal(name);

    // functions
    self->makeSound = &dog_yowl;
    self->pursueTail = &dog_pursueTail;

    return self;
}

// internals definitions
void dog_pursueTail(Animal self) {
    printf("%s is pusuing it's tail! hahaha!\n", self->name);
}
void dog_yowl(Animal self) {
    printf("%s: YOOOOWWWL!!\n", self->name);
}
