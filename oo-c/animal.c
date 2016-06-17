#include "animal.h"
#include "definitions.h"

// internal definitions
//  @brief: the animal grows one year.
void animal_grow(Animal self);
//  @brief: the animal poops.
void animal_poop(Animal self);
//  @brief: the animal dies. :-(
void animal_dispose(Animal self);

// constructor
Animal newAnimal(string name) {
    Animal self = (Animal)malloc(sizeof(Animal));
    self->name = (string)malloc(strlen(name) * sizeof(char));
    self->name = strdup(name);
    self->age = 0;
    self->grow = &animal_grow;
    self->poop = &animal_poop;
    self->die = &animal_dispose;
    return self;
}

// internal declarations
void animal_grow(Animal self) {
    self->age++;
    printf("%s is now %d years old! congrats, (lady) dude!\n", self->name, self->age);
}
void animal_poop(Animal self) {
    printf("%s is pooping. ew.\n", self->name);
}
void animal_dispose(Animal self) {
    printf("%s has died. :-(\n", self->name);
    free((void*)self);
}
