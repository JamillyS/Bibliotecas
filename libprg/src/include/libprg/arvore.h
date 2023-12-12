#ifndef LIBPRG_ARVORE_H
#define LIBPRG_ARVORE_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "libprg.h"
#include <string.h>

struct Usuario{
    char login[10];
    char senha[10];
    char nome[30];
};

typedef struct no {
    struct Usuario usuario;

    struct no *esquerda;
    struct no *direita;
} no_t;

no_t *criar_no(struct Usuario usuario);
void destruir_no_arvore(no_t *no);

no_t *inserir_valor(no_t *raiz, struct Usuario valor);

bool busca_usuario(no_t *raiz, char *login, char *senha);

struct Usuario busca_maior_usuario(no_t *raiz);
void imprimir_maior_usuario(no_t *raiz);

struct Usuario busca_menor_usuario(no_t *raiz);
void imprimir_menor_usuario(no_t *raiz);
//


#endif