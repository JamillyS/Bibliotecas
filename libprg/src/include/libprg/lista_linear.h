#ifndef LIBPRG_LISTALINEAR_H
#define LIBPRG_LISTALINEAR_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "libprg.h"
//Lista
typedef struct {
    int *valores;
    int tam_maximo;     //quantia de inteiros
    int n_elementos;    //quantos elementos guarno no momento
} Lista;

void cria_lista(Lista *lista, int tam_maximo);
void imprime_lista(Lista *lista);
int busca_linear(Lista *lista, int x);
//void inserir_nao_ordenada(Lista *lista, int x);
void remove_n(Lista *lista, int x);

void busca_binaria(Lista *lista, int x, int alvo);
void inserir_ordenada(Lista *lista, int x);
void remove_n2(Lista *lista, int x);

#endif