#ifndef LIBPRG_PILHA_H
#define LIBPRG_PILHA_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
//pilha está okay

//Pilha
typedef struct {
    int *valores;
    int topo;
    int capacidade;
} Pilha;

void cria_pilha(Pilha *pilha, int capacidade);
void empilhar(Pilha *pilha, int x);
int desempilhar(Pilha *pilha);
int tamanho(Pilha *pilha);
int vazia(Pilha *pilha);
void imprimi_pilha(Pilha *pilha);

#endif
