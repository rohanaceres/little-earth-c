#ifndef _ABSTRACT_
#define _ABSTRACT_

#define null ((void *) 0)

typedef struct TObject {
    int typeId;
} TObject, *Object;

void *
abstract_malloc(int sizeToAlloc);
void
abstract_free(void * toAlloc);

#endif // _ABSTRACT_
