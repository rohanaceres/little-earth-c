#ifndef _DOG_
#define _DOG_

typedef struct TDog {
    char *name;
    int age;
    void (*grow)(void *dog);
    void (*pursueTail)(void *dog);
    void (*makeSound)(void *dog);
    void (*poop)(void *dog);
    void (*dispose)();
} *Dog, TDog;

Dog newDog();

#endif //_DOG_
