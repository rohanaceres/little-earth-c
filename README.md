# Little Earth in C

## O que é?

O projeto simula criação de alguns animais, com o objetivo de demonstrar técnicas de orientação a objetos na linguagem C.

## Como funciona?

Animais podem ser criados e cada um possui propriedades e métodos específicos da sua espécie; bem como também herda propriedades comuns de qualquer animal (como comer, por exemplo).

### IoC Container (Inversion of Control Container)

É uma implementação bem básica de um container IoC, onde cada animal é injetado quando "nasce", ou seja, quando é instanciado.

Para registrar uma instancia ao IoC, basta:

```
typedef struct TExampleStruct {
	int id;
	int something1;
	char something2 [128];
	double something3;
} TExampleStruct, *ExampleStruct;

ExampleStruct myInstance;
myInstance = ioc_getNewId();

ioc_register(myInstance->id, myInstance);
``` 

:warning: **Não é possível adicionar o mesmo ID no IoC.**

## Onde funfa?

Em qualquer plataforma com as seguintes configurações:

* GNU GCC compiler
* Configurar para utilizar o C99 (-std=c99).

### [:octopus: mail me](mailto:ceres.rohana@gmail.com)
