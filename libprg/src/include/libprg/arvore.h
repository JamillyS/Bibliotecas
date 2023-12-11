#ifndef LIBPRG_ARVORE_H
#define LIBPRG_ARVORE_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "libprg.h"

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no_t;

no_t *criar_no(int valor);
void destruir_no(no_t *no);
no_t *inserir_valor(no_t *raiz, int valor);
bool busca(no_t *raiz, int valor);

int buca_maior_valor(no_t *raiz);
void imprimir_maior_valor(no_t *raiz);
int busca_menor_valor(no_t *raiz);
void imprimir_menor_valor(no_t *raiz);


#endif