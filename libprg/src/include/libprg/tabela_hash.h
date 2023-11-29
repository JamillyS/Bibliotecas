#ifndef LIBPRG_TABELA_HASH_H
#define LIBPRG_TABELA_HASH_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char login[10];
    char senha[10];
    char nome[30];

} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;


typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m);
void destruir_pessoa(pessoa_t *pessoa);
void destruir_no(no_t *no);
void destruir_dicionario(dicionario_t *d);
int hash(const char *chave, int m);
bool inserir(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar_th(dicionario_t *d, char *chave);
void imprimir_pessoa(dicionario_t *d, char *chave);
char * copia_string(char *s);

int verificar_login_senha(dicionario_t *dicionario, char *login, char *senha);

bool inserir_ordenado(dicionario_t* d, char* chave, pessoa_t* valor);

void imprimir_logins(dicionario_t* d);



#endif