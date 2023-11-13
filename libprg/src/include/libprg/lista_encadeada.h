#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef struct{
    int dado;
    struct no* proximo;
} no_t;

void adicionar(no_t** inicio, int dado);
no_t* buscar(no_t* inicio, int dado);
bool remover(no_t** inicio, int dado);
void destruir(no_t** inicio);
void adicionar_ordenado(no_t** inicio, int dado);
void imprimirLista(no_t** inicio);

//----------------------------------------------------------------------------------------------------------------------


#endif

