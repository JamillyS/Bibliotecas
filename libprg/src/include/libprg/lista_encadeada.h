#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Nodo da lista encadeada
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

//APLICAÇÃO PARA TAREFA: Verifica login e senha utilizando lista

//um nodo guarda esses dados
struct Usuario{
    char login[10];
    char senha[10];
    char nome[30];
};

// Nodo da lista encadeada
typedef struct no{
    struct Usuario usuario;
    struct no* proximo;
} no_t2;

void adicionar_ordenado_usu(no_t2** lista, no_t2* novo);
void destruir_login_senha(no_t2** inicio);
no_t2* buscar_usuario(no_t2* lista, const char* login, const char* senha);

#endif

