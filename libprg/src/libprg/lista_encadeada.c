#include "libprg/lista_encadeada.h"

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
    //Aloca memória para um novo nó
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    // Inicializa um ponteiro para o nó anterior ao novo
    no_t* anterior = NULL;
    no_t* atual = *inicio;

//    // Se a lista estiver vazia, o novo nó é o primeiro
    if (*inicio == NULL){
        novo->proximo = NULL;
        *inicio = novo;
        return;
   }
   // Percorre a lista até encontrar um nó com dado maior ou igual ao novo
    while(atual != NULL && atual->dado < novo->dado){
       anterior = atual;
        atual = atual->proximo;
    }
    // Se o nó anterior for NULL, o novo nó é o primeiro
    if (anterior == NULL){
        novo->proximo = *inicio;
        *inicio = novo;
    }
    //Caso contrário, o novo nó é inserido após o nó anterior
    else{
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
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

void imprimirLista(no_t** inicio) {
    no_t* atual = *inicio;
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

//O valor de retorno de strcmp é 0 se as duas strings forem iguais, menor que 0 se str1 for menor que str2 e maior que
// 0 se str1 for maior que str2. Nenhuma outra suposição deve ser feita sobre o valor retornado por strcmp.
void adicionar_ordenado_usu(no_t2** lista, no_t2* novo) {
    no_t2* atual;

    // Se a lista estiver vazia ou o novo nodo deve ser o primeiro
    if (*lista == NULL || strcmp((*lista)->usuario.login, novo->usuario.login) > 0) {
        novo->proximo = *lista;
        *lista = novo;
    } else {
        // Encontrar o local adequado para inserir o novo nodo
        atual = *lista;
        while (atual->proximo != NULL && strcmp(atual->proximo->usuario.login, novo->usuario.login) < 0) {
            atual = atual->proximo;
        }

        // Inserir o novo nodo na posição correta
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

void destruir_login_senha(no_t2** inicio){
    //inicializo o ponteiro para o inicio da lista
    no_t2* atual2 = *inicio;

    //Uso outro ponteiro para apontar para o próximo nó
    no_t2* prox2;

    //Enquanto minha lista não estiver vazia
    while(atual2 != NULL){
        //Salvo a príxima posição na minha lista
        prox2 = atual2->proximo;
        //Apago a posição anterior
        free(atual2);
        //Informo que prox2 é a posição atual
        atual2 = prox2;
    }
    //Início é nulo, apenas quando a lista ficar vazia
    *inicio = NULL;
}
