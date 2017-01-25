#include "lhama.h"
#include "animal.h"
#include "definitions.h"

// internals declarations
//  @brief: the lhama is chewing.
void lhama_chew(void);
//  @brief: the lhama is about to spit.
void lhama_spit(Animal target);
//  @brief: the lhama saves water in it's body.
void lhama_saveWater(void);
//  @brief: the lhama drinks water.
void lhama_drinkWater(void);

int _id;

// constructor
Lhama newLhama(string name) {
    Lhama self = new(name, sizeof(TLhama), &_id);

    self->litersOfWater = 0;
    self->chew = &lhama_chew;
    self->spit = &lhama_spit;
    self->saveWater = &lhama_saveWater;
    self->drinkWater = &lhama_drinkWater;

    return self;
}

// internals definitions
void lhama_chew(void) {
    Lhama self = ioc_resolve(_id);
    printf("%s is chewing...\n", self->name);
}
void lhama_spit(Animal target) {
    Lhama self = ioc_resolve(_id);
    printf("%s just spit %s! HAHAHA!!\n", self->name, target->name);
}
void lhama_saveWater(void) {
    Lhama self = ioc_resolve(_id);
    self->litersOfWater++;
}
void lhama_drinkWater(void) {
    Lhama self = ioc_resolve(_id);

    if (self->litersOfWater > 0) {
        self->litersOfWater--;
    }
    else {
        printf("%s does not have water in it's body.\n", self->name);
        self->die(_id);
    }
}

