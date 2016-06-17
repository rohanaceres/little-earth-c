#include "eagle.h"
#include "definitions.h"

// internals declarations
void eagle_fly (Eagle self);
void eagle_hoot (Eagle self);

// constructor
Eagle newEagle(string name) {
    Eagle self = newAnimal(name);

    // functions
    self->fly = &eagle_fly;
    self->makeSound = &eagle_hoot;
}

// internals definitions
void eagle_fly (Eagle self) {
    printf("%s is flying! *O*\n", self->name);
}
void eagle_hoot(Eagle self) {
    printf("%s: TU-WHOoO!\n", self->name);
}