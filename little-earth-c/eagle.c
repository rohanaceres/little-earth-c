#include "eagle.h"
#include "definitions.h"

// internals declarations
//  @brief: the eagle flyes!
void eagle_fly (void);
//  @brief: the eagle hoots.
void eagle_hoot (void);

int _id;

// constructor
Eagle newEagle(string name) {
    Eagle self = new(name, sizeof(TEagle), &_id);

    // functions
    self->fly = &eagle_fly;
    self->makeSound = &eagle_hoot;

    return self;
}

// internals definitions
void eagle_fly (void) {
    Eagle self = ioc_resolve(_id);
    printf("%s is flying! *O*\n", self->name);
}
void eagle_hoot(void) {
    Eagle self = ioc_resolve(_id);
    printf("%s: TU-WHOoO!\n", self->name);
}
