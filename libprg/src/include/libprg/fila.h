#ifndef LIBPRG_FILA_H
#define LIBPRG_FILA_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "libprg.h"
//Fila
typedef struct {
    int *valores;
    int inicio;
    int fim;
    int capacidade;
} Fila;

void cria_fila(Fila *fila, int capacidade);
void imprimi_fila(Fila *fila);
void enfileirar(Fila *fila, int x); //retorna codifo de erro
void desenfileirar(Fila *fila);
//void inserir_ordenada(Lista *lista, int x);

#endif