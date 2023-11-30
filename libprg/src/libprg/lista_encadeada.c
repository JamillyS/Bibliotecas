#include "libprg/lista_encadeada.h"

void adicionar(no_t** inicio, int dado){
    //Aloco memória para um novo nó
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    //Defino "dado" do novo nó
    novo->dado = dado;
    //O novo nó aponta para o início da lista
    novo->proximo = *inicio;
    //Atualizo o início da lista para apontar para o novo nó
    *inicio = novo;
}

void adicionar_ordenado(no_t** inicio, int dado){
    //Aloca memória para um novo nó
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    // Inicializa um ponteiro para o nó anterior ao novo
    no_t* anterior = NULL;
    no_t* atual = *inicio;

    //Se a lista estiver vazia, o novo nó é o primeiro
    if (*inicio == NULL){
        novo->proximo = NULL;
        *inicio = novo;
        return;
    }
    //Percorro a lista até encontrar um nó com dado maior ou igual ao novo
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

    return NULL;
}

bool remover(no_t** inicio, int dado){
    //Inicializo o ponteiro para o nó no início da lista
    no_t* atual = *inicio;

    //Inicializo um ponteiro para o nó anterior como nulo
    no_t* anterior = NULL;

    //Enquanto a lista encadeada não estiver vazia
    while(atual != NULL){

        //Verifica se o valor de "dado" do nó atual é igual ao valor fornecido
        if (atual->dado == dado){

            //Se o nó atual for o primeiro nó da lista
            if (anterior == NULL) {

                //Atualizo o início da lista e aponto para o próximo nó
                *inicio = atual->proximo;

            } else {
                //Se não for o primeiro nó, atualiza o ponteiro 'proximo' do nó anterior
                anterior->proximo = atual->proximo;
            }

            //Libero a memória alocada para o nó atual
            free(atual);

            return true;
        }
        anterior = atual;

        //Atualizo o nó atual para o próximo nó na lista
        atual = atual->proximo;
    }
    return false;
}

void destruir(no_t** inicio){
    //Inicializo o ponteiro para o nó no início da lista
    no_t* atual = *inicio;

    //Declaro o ponteiro para o próximo nó
    no_t* prox;

    //Enquanto a lista encadeada não estiver vazia
    while(atual != NULL){

        //Salvo o próximo nó na variável 'prox'
        prox = atual->proximo;

        //Libero a memória alocada para o nó atual
        free(atual);

        //Atualizo o nó atual para o próximo nó na lista
        atual = prox;
    }
    *inicio = NULL;
}

void imprimirLista(no_t** inicio) {
    no_t* atual = *inicio;
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

//----------------------------------------------------------------------------------------------------------------------

//O valor de retorno de strcmp é 0 se as duas strings forem iguais, menor que 0 se str1 for menor que str2 e maior que
// 0 se str1 for maior que str2. Nenhuma outra suposição deve ser feita sobre o valor retornado por strcmp.
void adicionar_ordenado_usu(no_t2** lista, no_t2* novo) {
    no_t2* atual;

    //Se a lista estiver vazia ou o novo nodo deve ser o primeiro
    if (*lista == NULL || strcmp((*lista)->usuario.login, novo->usuario.login) > 0) {
        novo->proximo = *lista;
        *lista = novo;
    } else {
        //Encontro o local adequado para inserir o novo nodo
        atual = *lista;
        while (atual->proximo != NULL && strcmp(atual->proximo->usuario.login, novo->usuario.login) < 0) {
            atual = atual->proximo;
        }

        //Insero o novo nodo na posição correta
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
    *inicio = NULL;
}

no_t2* buscar_usuario(no_t2* lista, const char* login) {
    no_t2* atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->usuario.login, login) == 0) {
            // Usuário encontrado
            printf("Olá %s \n", atual->usuario.nome );
            return atual;
        }

        atual = atual->proximo;
    }
    printf("Usuário não encontado\n");
    // Usuário não encontrado
    return NULL;
}