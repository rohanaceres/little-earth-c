#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "definitions.h"
#include "dog.h"
#include "animal.h"

// internals declarations
//  @brief: the dog pursues it's tail.
void dog_pursueTail(void);
//  @brief: the dog yowls.
void dog_yowl(void);

// TODO: Documentar.
int _id;

// public definitions
Dog newDog(string name) {
    Dog self = new(name, sizeof(TDog), &_id);

    // functions
    self->makeSound = &dog_yowl;
    self->pursueTail = &dog_pursueTail;

    return self;
}

// internals definitions
void dog_pursueTail(void) {
    Dog self = ioc_resolve(_id);
    printf("%s is pursuing it's tail! hahaha!\n", self->name);
}
void dog_yowl(void) {
    Dog self = ioc_resolve(_id);
    printf("%s: YOOOOWWWL!!\n", self->name);
}
