#include "libprg/libprg_lista_enca.h"

void adicionar(no_t** inicio, int dado){
    // Aloca memória para um novo nó
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    // Define o campo 'dado' do novo nó com o valor passado como argumento
    novo->dado = dado;
    // O novo nó aponta para o início da lista
    novo->proximo = *inicio;
    // Atualiza o início da lista para apontar para o novo nó
    *inicio = novo;
}
void adicionar_ordenado(no_t** inicio, int dado){
    // Aloca memória para um novo nó
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    // Define o campo 'dado' do novo nó com o valor passado como argumento
    novo->dado = dado;

}

no_t* buscar(no_t* inicio, int dado){
    no_t* atual = inicio;  // Inicializa um ponteiro para o nó atual a partir do início da lista

    // Percorre a lista enquanto o nó atual não for nulo
    while (atual != NULL) {
        // Verifica se o valor do campo 'dado' do nó atual é igual ao valor procurado
        if (atual->dado == dado) {
            // Se encontrou o nó com o valor desejado, retorna o ponteiro para esse nó
            return atual;
        }else {
            // Atualiza o nó atual para o próximo nó na lista
            atual = atual->proximo;
        }
    }

    // Se o valor não for encontrado na lista, retorna NULL para indicar que o nó não existe
    return NULL;
}


bool remover(no_t** inicio, int dado){
    // Inicializa um ponteiro para o nó atual a partir do início da lista
    no_t* atual = *inicio;
    // Inicializa um ponteiro para o nó anterior como nulo
    no_t* anterior = NULL;
    // Entra em um loop para percorrer a lista
    while(atual != NULL){
        // Verifica se o valor do campo 'dado' do nó atual é igual ao valor fornecido
        if (atual->dado == dado){
            // Se o nó atual for o primeiro nó da lista
            if (anterior == NULL) {
                // Atualiza o início da lista para apontar para o próximo nó
                *inicio = atual->proximo;
            } else {
                // Se não for o primeiro nó, atualiza o ponteiro 'proximo' do nó anterior
                anterior->proximo = atual->proximo;
            }
            // Libera a memória alocada para o nó atual
            free(atual);
            // Retorna 'true' para indicar que a remoção foi bem-sucedida
            return true;
        }
        // Atualiza o nó anterior para o nó atual
        anterior = atual;
        // Atualiza o nó atual para o próximo nó na lista
        atual = atual->proximo;
    }
    // Retorna 'false' se o valor não foi encontrado na lista
    return false;
}

void destruir(no_t** inicio){
    // Inicializa um ponteiro para o nó atual a partir do início da lista
    no_t* atual = *inicio;
    // Declara um ponteiro para o próximo nó
    no_t* prox;
    // Entra em um loop para percorrer a lista
    while(atual != NULL){
        // Salva o próximo nó na variável 'prox'
        prox = atual->proximo;
        // Libera a memória alocada para o nó atual
        free(atual);
        // Atualiza o nó atual para o próximo nó na lista
        atual = prox;
    }
    // Define o início da lista como nulo, indicando que a lista está vazia
    *inicio = NULL;
}

