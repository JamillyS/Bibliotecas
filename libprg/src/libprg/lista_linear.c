#include "libprg/libprg.h"

void cria_lista(Lista *lista, int tam_maximo){
    lista -> valores = malloc((sizeof (int))* tam_maximo); // sizeof da o tamanho de um tipo
    if (lista -> valores == NULL){
        printf("Falha na alocação de memoria\n");
        exit(1);
    }
    lista -> tam_maximo = tam_maximo;
    lista -> n_elementos = 0;
}

void imprime_lista(Lista *lista){
    for (int i = 0; i < lista->n_elementos; i++) {
        printf(" %d", lista->valores[i]);
    }
}

int busca_linear(Lista *lista, int x){
    for (int i = 0; i < lista->n_elementos; i++ ){
        if (x == lista->valores[i]){
            printf("\no valor está na lista\n");
            return 1;
        }
        printf("\no valor não está na lista\n");
        return 0;
    }
    //retorna 1 se o elemento x pertence a lista
    // ou 0, caso contrario.
}

void inserir_nao_ordenada(Lista *lista, int x){
    for (int i = 0; i < lista->n_elementos; i++ ){
        if (x == lista->valores[i]){
            printf("pertence a lista\n");
        }
    }

    // Percorro até o ultimo elemento da lista(que é NULL, logo está vazia)
    int i = lista->n_elementos - 1;
    while (lista->valores[i] != NULL){
        i--;
    }
    // Insere o novo elemento após o último elemento
    lista->valores[lista->n_elementos] = x;
    lista->n_elementos++;
    }

void remove_n(Lista *lista, int x){
    //percorro minha lista
    for (int i = 0; i < lista->n_elementos; i++ ){
        //se o valor informado for encontrado dentro da listra
        if (x == lista->valores[i]){
            // o indice[i] encontado = o valor do ultimo elemento da lista
            lista->valores[i] = lista->valores[lista->n_elementos - 1];
            //remove o número de elementos da lista
            lista->n_elementos--;
        }

    }
}
//----------------------------------------------------------------------------------------------------------------------
void busca_binaria(Lista *lista, int x, int alvo){

    int inicio = 1;
    int fim = lista->n_elementos;
    int meio = 0;

    for (int i = 0; i <= lista->n_elementos; i++ ){
        //meio ← inicio + (fim − inicio)/2;
        meio = (inicio + (fim - inicio)) / 2;
        if(x == lista->valores[i]){
            printf("\no valor está na lista\n");
           // return 1;
        }

    }

}

void inserir_ordenada(Lista *lista, int x){

}

void remove_n2(Lista *lista, int x){

}

//
//void inserir_ordenada(Lista *lista, int x){
//    inserir_nao_ordenada(lista, x);
//    int valor_anterior= 0;
//    int posicao_salva = 0;
//
//
//    for (int i = 0; i < lista->n_elementos; i++){
//        int valor_atual = lista->valores[i];
//
//        if (valor_atual >= x) {
//            // Salva o antigo valor que estava na posição c
//            valor_anterior = valor_atual;
//
//            // Armazena o novo na posição orenada "c"
//           lista->valores[i] = x;
//
//            // Salva a posição do qual os valores restantes devem ser copiados
//            posicao_salva = i+1;
//
//            break;
//        }
//       // x == lista->n_elementos[i];
//    }
//
//    // Cria uma lista temporária para guardar todos os valores restantes da lista principal
//    int lista_temporaria[lista->n_elementos-posicao_salva];
//    lista_temporaria[0] = valor_anterior; // Guardando o primeiro valor
//
//    // Salvar os valores restantes em uma lista temporária
//    int j = 1;
//    for (int i = posicao_salva; i < lista->n_elementos; i++){
//        lista_temporaria[j] = lista->valores[i];
//        j++;
//    }
//
//    // Realocar o valores da lista temporária de volta na lista principal
//    for (int i = 0; i < sizeof(lista_temporaria); i++){
//        lista->valores[posicao_salva] = lista_temporaria[i];
//        posicao_salva++;
//    }
//}
//
//
//
