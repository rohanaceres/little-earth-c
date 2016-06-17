#include <stdio.h>
#include <stdlib.h>

#include "dog.h"
#include "animal.h"

int main()
{
    Dog alberta = newDog("alberta");

    alberta->grow(alberta);
    alberta->makeSound(alberta);
    alberta->pursueTail(alberta);

    return 0;
}
