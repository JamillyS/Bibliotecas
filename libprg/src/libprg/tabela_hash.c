#include "libprg/tabela_hash.h"
//#include "libprg/lista_encadeada.h"
//#include "libprg/lista_encadeada.h"

//função que cria e aloca memoria para a tabela hash
dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    //Verifico se o tamanho "m" passado é menor que 1
    if (m < 1) {
        return NULL;
    }
    //Aloco memória para um novo dicionário. Se a alocação falhar, a função retorna `NULL`.
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    //Atribui o tamanho especificado ao dicionário.
    d->tamanho = m;

    //Aloco memória para um vetor de ponteiros para `no_t`. Se a alocação falhar, a função retorna `NULL`.
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }
    // Verifica se o vetor foi alocado com o valor `NULL`. Se foi, a função atribui `NULL` a cada elemento do vetor.
    for (int i = 0; i < m; i++) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    free(pessoa);
}


void destruir_no(no_t *no) {
    if (no != NULL) {
        if(no->prox != NULL){
            destruir_no(no->prox);
        }
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }else{
        return;
    }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; i++) {
            no_t *primeiro_no = d->vetor[i];

            // Percorre a lista encadeada e libera cada nó
           // while (primeiro_no != NULL) {
                //no_t *no_temp = primeiro_no->prox;

                // Libera a memória alocada para o nó
                destruir_no(primeiro_no);

                // Atualiza o ponteiro para o próximo nó
               // primeiro_no = no_temp;
        }

        // Libera a memória alocada para o vetor
        free(d->vetor);

        // Libera a memória alocada para o dicionário
        free(d);


    }
}


// método por divisão com chave alfanumérica, a função que irá definir o indice
int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

void adicionar_na_lista_encadeada(no_t** inicio, char* chave, pessoa_t* valor) {
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    novo->chave = strdup(chave);
    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
}


bool inserir(dicionario_t* d, char* chave, pessoa_t* valor) {
    int indice = hash(chave, d->tamanho);

    // Aloca memória para o novo nó
    no_t* no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    // Faz uma cópia da chave usando strdup para evitar problemas com o ponteiro
    //aponta um ponteiro para uma nova string
    no->chave = strdup(chave);
    //no->chave = chave;
    if (no->chave == NULL) {
        free(no);
        return false;
    }

    // Atribui o valor ao nó
    no->valor = valor;

    //Tratamento de colisões com lista encadeada
    if (d->vetor[indice] == NULL) {
        // Se a posição estiver vazia, atribuo o novo nó
        no->prox = NULL;
        d->vetor[indice] = no;
    } else {
        // Se houver colisão, adiciona o novo nó à lista encadeada
        //adicionar_na_lista_encadeada(&d->vetor[indice], chave, valor);

        no->prox = d->vetor[indice];
        //aponta pra novo nó
        d->vetor[indice] = no;
    }

    return true;
}

pessoa_t *buscar_th(dicionario_t *d, char *chave) {
    //calcula o índice da chave na tabela hash
    int indice = hash(chave, d->tamanho);
    //percorre a lista encadeada no índice
    no_t *no = d->vetor[indice];
    while (no != NULL) {
        //se a chave for igual, retorna o valor
        if (strcmp(no->chave, chave) == 0) {
            printf("O usuário %s, está na base de dados \n", no->valor->nome);
            return no->valor;

        }
        //avanca para o próximo nó
        no = no->prox;
    }
    //chave não encontrada
    return NULL;
}


void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar_th(d, chave);
    if (p != NULL) {
        printf("Login: %s = %s\tSenha: %s\tNome: %s\n", p->login, chave, p->senha, p->nome);
    }else {
        printf("Login %s não encontrada\n", chave);
    }
}


//criei dois nó,
//já to apontando minha tabela hash