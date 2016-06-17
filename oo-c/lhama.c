#include "lhama.h"
#include "animal.h"
#include "definitions.h"

// internals declarations
//  @brief: the lhama is chewing.
void lhama_chew(Animal self);
//  @brief: the lhama is about to spit.
void lhama_spit(Animal selt, Animal target);
//  @brief: the lhama saves water in it's body.
void lhama_saveWater(Lhama self);
//  @brief: the lhama drinks water.
void lhama_drinkWater(Lhama self);

// constructor
Lhama newLhama(string name) {
    Lhama self = newAnimal(name);

    self->litersOfWater = 0;
    self->chew = &lhama_chew;
    self->spit = &lhama_spit;
    self->saveWater = &lhama_saveWater;
    self->drinkWater = &lhama_drinkWater;

    return self;
}

// internals definitions
void lhama_chew(Animal self) {
    printf("%s is chewing...\n", self->name);
}
void lhama_spit(Animal self, Animal target) {
    printf("%s just spit %s! HAHAHA!!\n", self->name, target->name);
}
void lhama_saveWater(Lhama self) {
    self->litersOfWater++;
}
void lhama_drinkWater(Lhama self) {
    if (self->litersOfWater > 0) {
        self->litersOfWater--;
    }
    else {
        printf("%s does not have water in it's body.\n", self->name);
        self->die(self);
    }
}

