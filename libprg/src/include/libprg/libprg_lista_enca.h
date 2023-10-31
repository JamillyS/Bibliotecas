#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

//Lista_encadeada

//a. Lista circular encadeada (não ordenada e ordenada)
//b. Lista circular duplamente encadeada (não ordenada e ordenada)
//c. Fila representada em uma lista encadeada
//d. Pilha representada em uma lista encadeada

typedef struct{
    int dado;
    struct no* proximo;
} no_t;

void adicionar(no_t** inicio, int dado);
no_t* buscar(no_t* inicio, int dado);
bool remover(no_t** inicio, int dado);
void destruir(no_t** inicio);

void adicionar_ordenado(no_t** inicio, int dado);

//----------------------------------------------------------------------------------------------------------------------


#endif

