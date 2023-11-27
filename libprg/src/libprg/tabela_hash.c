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
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa->cpf != NULL) {
        free(pessoa->cpf);
    }if (pessoa->nome != NULL) {
        free(pessoa->nome);
    }if (pessoa->email != NULL) {
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no(no_t *no) {
    if (no != NULL) {
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}

//implementada
void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            no_t *primeiro_no = d->vetor[i];

            //percorro a lista encadeada e libera cada nó
            while (primeiro_no != NULL) {
                no_t *no_temp = primeiro_no->prox;

                //libera a memória alocada para o nó
                free(primeiro_no);

                //atualizo o ponteiro para o próximo nó
                primeiro_no = no_temp;
            }
        }
        free(d->vetor);
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

//implementada
//acho que aqui que tá errada, a questão do vazamento
bool inserir(dicionario_t* d, char* chave, pessoa_t* valor) {
    int indice = hash(chave, d->tamanho);

    // Aloca memória para o novo nó
    no_t* no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    // Faz uma cópia da chave usando strdup para evitar problemas com o ponteiro
    //aponta um ponteiro para uma nova string
//    no->chave = strdup(chave);
    no->chave = chave;
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
        adicionar_na_lista_encadeada(&d->vetor[indice], chave, valor);
    }
    return true;
}


pessoa_t *buscar(dicionario_t *d, char *chave) {
int indice = hash(chave, d->tamanho);
    if (d->vetor[indice] != NULL) {
    // TODO Abaixo só pega o primeiro elemento da lista encadeada
    // é necessário percorrer a lista encadeada e não apenas o primeiro
    // elemento
        if (strcmp(d->vetor[indice]->chave, chave) == 0) {
            return d->vetor[indice]->valor;
        }
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar(d, chave);
    if (p != NULL) {
        printf("CPF: %s = %s\tNome: %s\tEmail: %s\n", p->cpf, chave, p->nome, p->email);
    }else {
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}