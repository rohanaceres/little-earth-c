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

    //alberta->grow();
    //alberta->makeSound();
    alberta->pursueTail();

    // Greate an eagle!
    Eagle guto = newEagle("guto");

    //guto->grow();
    //guto->grow();
    //guto->grow();
    //guto->grow();
    guto->fly();

    Lhama marcy = newLhama("marcy");

    marcy->chew();
    marcy->saveWater();
    marcy->spit(alberta);
    marcy->drinkWater();
    marcy->drinkWater();

    printf("the end.");

    return 0;
}
