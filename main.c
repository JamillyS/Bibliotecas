//TESTE

#include "libprg/arvore.h"
int main(){
    no_t *raiz = NULL;

    raiz = inserir_valor(raiz, 15);
    raiz = inserir_valor(raiz, 1);
    raiz = inserir_valor(raiz, 20);
    raiz = inserir_valor(raiz, 7);

    busca(raiz, 75);
    imprimir_maior_valor(raiz);
    imprimir_menor_valor(raiz);

}
