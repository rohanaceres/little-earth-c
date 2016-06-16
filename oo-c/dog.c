#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dog.h"

// internals declarations
void dog_grow(Dog self);
void dog_pursueTail(Dog self);
void dog_yowl(Dog self);
void dog_poop(Dog self);
void dog_dispose(Dog self);

// public definitions
Dog newDog() {
    Dog self = (Dog)malloc(sizeof(TDog));

    // properties
    self->name = (char*)malloc(32 * sizeof(char));
    strcpy(self->name, "alberta");
    self->age = 0;

    // functions
    self->grow = &dog_grow;
    self->pursueTail = &dog_pursueTail;
    self->makeSound = &dog_yowl;
    self->poop = &dog_poop;
    self->dispose = &dog_dispose;

    return self;
}

// internals definitions
void dog_grow(Dog self) {
    self->age++;
}
void dog_pursueTail(Dog self) {
    printf("%s is pusuing it's tail! hahaha!", self->name);
}
void dog_yowl(Dog self) {
    printf("%s: YOOOOWWWL!!", self->name);
}
void dog_poop(Dog self) {
    printf("%s is pooping. ew.", self->name);
}
void dog_dispose(Dog self) {
    free(self);
}
