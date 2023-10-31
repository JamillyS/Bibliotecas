#include "lista_encadeada.c"

int main(){
    no_t* inicio = 0;

    adicionar(&inicio, 15);
    adicionar(&inicio, 25);
    adicionar(&inicio, 37);
    adicionar(&inicio, 48);
    adicionar(&inicio, 54);
    adicionar(&inicio, 61);


    buscar(inicio, 61);

    remover(&inicio, 54);

    no_t* atual = inicio;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo; // Avança para o próximo nó na lista
    }

    destruir(&inicio);


    return 0;
}
