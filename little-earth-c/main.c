#include <stdio.h>
#include <stdlib.h>

#include "dog.h"
#include "eagle.h"
#include "lhama.h"

int main() {
    // Create a puppy!
    Dog alberta = newDog("alberta");

    alberta->grow(alberta->reflect.typeId);
    alberta->makeSound();
    alberta->pursueTail();

    // Greate an eagle!
    Eagle guto = newEagle("guto");

    guto->grow(guto->reflect.typeId);
    guto->grow(guto->reflect.typeId);
    guto->grow(guto->reflect.typeId);
    guto->grow(guto->reflect.typeId);
    guto->fly();

    // A cute lhama is about to born!
    Lhama marcy = newLhama("marcy");

    marcy->chew();
    marcy->saveWater();
    marcy->spit(alberta);
    marcy->drinkWater();
    marcy->drinkWater();

    printf("\nthe end.\n");

    return 0;
}
