#include <stdio.h>
#include <string.h>

#include "animal.h"
#include "definitions.h"
#include "abstract.h"
#include "ioccontainer.h"

// internal definitions
//  @brief: the animal grows one year.
void animal_grow(int animalId);
//  @brief: the animal poops.
void animal_poop(int animalId);
//  @brief: the animal dies. :-(
void animal_dispose(int animalId);

// constructor
Animal newAnimal(string name, int derivedSize, int * id) {
    Animal self = (Animal)abstract_malloc(derivedSize);

    self->name = (string)abstract_malloc(strlen(name) * sizeof(char));
    self->name = strdup(name);
    self->age = 0;
    self->grow = &animal_grow;
    self->poop = &animal_poop;
    self->die = &animal_dispose;
    self->reflect.typeId = ioc_getNewId();

    (*id) = self->reflect.typeId;
    ioc_register(self, self->reflect.typeId);

    printf("%s has born! :-)\n\n", name);

    return self;
}

// internal declarations
void animal_grow(int animalId) {
    Animal self = ioc_resolve(animalId);
    self->age++;
    printf("%s is now %d years old! congrats, (lady) dude!\n", self->name, self->age);
}
void animal_poop(int animalId) {
    Animal self = ioc_resolve(animalId);
    printf("%s is pooping. ew.\n", self->name);
}
void animal_dispose(int animalId) {
    Animal self = ioc_resolve(animalId);
    printf("%s has died. :-(\n", self->name);
    ioc_unregister(animalId);
    abstract_free(self);
}
