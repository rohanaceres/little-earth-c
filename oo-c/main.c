#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

int main()
{
    Dog alberta = newDog();
    alberta->grow(alberta);
    alberta->makeSound(alberta);

    return 0;
}
