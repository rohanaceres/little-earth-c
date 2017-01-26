#ifndef _IOCCONTAINER_
#define _IOCCONTAINER_

//#define CONTAINER_LOG

void
ioc_register (void *instance, int instanceId);
void
ioc_unregister (int instanceId);
void *
ioc_resolve (int instanceId);
int
ioc_getNewId (void);

#endif // _IOCCONTAINER_
