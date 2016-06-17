#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "dog.h"
#include "eagle.h"
#include "lhama.h"

int main()
{
    // Create a puppy!
    Dog alberta = newDog("alberta");

    alberta->grow(alberta);
    alberta->makeSound(alberta);
    alberta->pursueTail(alberta);

    // Greate an eagle!
    Eagle guto = newEagle("guto");

    guto->grow(guto);
    guto->grow(guto);
    guto->grow(guto);
    guto->grow(guto);
    guto->fly(guto);

    Lhama marcy = newLhama("marcy");

    marcy->chew(marcy);
    marcy->saveWater(marcy);
    marcy->spit(marcy, alberta);
    marcy->drinkWater(marcy);
    marcy->drinkWater(marcy);

    return 0;
}
