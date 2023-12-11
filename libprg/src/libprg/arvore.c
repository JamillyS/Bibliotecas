#include "libprg/arvore.h"

no_t *criar_no(int valor){
    no_t *no = (no_t *) malloc(sizeof(no_t));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no(no_t *no) {
    if (no != NULL) {
    destruir_no(no->esquerda);
    destruir_no(no->direita);
    free(no);
    }
}

// todo nó é raiz de uma subárvore
no_t *inserir_valor(no_t *raiz, int valor){
    if (raiz == NULL) {
        return criar_no(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

bool busca(no_t *raiz, int valor){
    if (raiz == NULL) {
        printf("valor %d não encontrado\n", valor);
        return false;
    }
    if (valor == raiz->valor){
        printf("valor %d encontrado\n", valor);
        return true;
    }
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}

int buca_maior_valor(no_t *raiz) {
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->valor;
}

void imprimir_maior_valor(no_t *raiz) {
    int maior = buca_maior_valor(raiz);
    printf("O maior valor é %d\n", maior);
}

int busca_menor_valor(no_t *raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz->valor;
}

void imprimir_menor_valor(no_t *raiz) {
    int menor = busca_menor_valor(raiz);
    printf("O menor valor é %d\n", menor);
}
