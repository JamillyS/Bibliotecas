#include "libprg/tabela_hash.h"
//#include "libprg/lista_encadeada.h"
//#include "libprg/lista_encadeada.h"

//função que cria e aloca memoria para a tabela hash
dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    //Verifico se o tamanho "m" passado é menor que 1, pois a tabela hash deve ter um tamanho maior
    if (m < 1) {
        return NULL;
    }
    //Aloco memória para um novo dicionário. Caso a alocação falhar retorna NULL.
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    //Atribui o tamanho ao dicionário.
    d->tamanho = m;

    //Aloco memória para um vetor de ponteiros para `no_t`. Caso a alocação falhar retorna NULL.
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }
    //Verifico se o vetor foi alocado com o valor NULL. Se foi, a função atribui NULL para o elemento do vetor.
    for (int i = 0; i < m; i++) {
        d->vetor[i] = NULL;
    }
    return d;
}

bool inserir(dicionario_t* d, char* chave, pessoa_t* valor) {
    //Chamo a função que calcula o índice da tabela hash para a chave
    int indice = hash(chave, d->tamanho);

    //Aloco memória para o novo nó. Caso a alocação falhar retorna NULL.
    no_t* no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    //Faço uma cópia da chave usando strdup para evitar problemas com o ponteiro
    //Aponto um ponteiro para uma nova string
    no->chave = strdup(chave);

    if (no->chave == NULL) {
        free(no);
        return false;
    }

    //Atribuo o valor ao nó
    no->valor = valor;

    //Tratamento de colisões com lista encadeada
    if (d->vetor[indice] == NULL) {
        //Se estiver vazia atribuo o novo nó
        no->prox = NULL;
        d->vetor[indice] = no;
    } else {
        //Se houver colisão, adiciono o novo nó no início da lista encadeada
        no->prox = d->vetor[indice];
        //aponta pra novo nó
        d->vetor[indice] = no;
    }

    return true;
}


int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

pessoa_t *buscar_th(dicionario_t *d, char *chave) {
    //Chamo a função hash para calcular o índice da chave passada
    int indice = hash(chave, d->tamanho);

    //Percorro a lista encadeada no índice
    no_t *no = d->vetor[indice];

    //Se não for vazia
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

int verificar_login_senha(dicionario_t *dicionario, char *login, char *senha) {
    //Chamo a função buscar_th para verificar o login passado
    pessoa_t *usuario = buscar_th(dicionario, login);
    //Verifico se não é vazia
    if (usuario == NULL) {
        return 0;
    }
    //Comparo se a senha fornecida com a senha do usuário encontrado
    if (strcmp(usuario->senha, senha) == 0) {
        printf("Login e senha corretos.\n");
        return 1;
    } else {
        printf("Senha incorreta.\n");
        return 0;
    }
}

void destruir_pessoa(pessoa_t *pessoa) {
    //Libero a memória alocada para o objeto pessoa
    free(pessoa);
}

void destruir_no(no_t *no) {
    //Verifico se o nó é vazio
    if (no != NULL) {
        //Se o próximo nó não for nulo
        if(no->prox != NULL){
            //Chamo a função para destruir
            destruir_no(no->prox);
        }
        //Libero a memória que foi alocada a chave
        free(no->chave);
        //Chamo a função "destruir_pessoa", que está associada ao nó
        destruir_pessoa(no->valor);
        //Libero a memória alocada para o nó
        free(no);
    }else{
        return;
    }
}

void destruir_dicionario(dicionario_t *d) {
    //Se dicionário não é nulo
    if (d != NULL) {

        for (int i = 0; i < d->tamanho; i++) {
            //Tenho o primeiro nó da posição "i"
            no_t *primeiro_no = d->vetor[i];

            //Chamo a função "destruir_no" que destroi os nós da llista encadeda
            destruir_no(primeiro_no);

        }
        //libero a memória alocada para o vetor
        free(d->vetor);
        //libero a memória alocada para o dicionário
        free(d);
    }
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    //Chamo a função "buscar_th" para encontrar o a chave associada
    pessoa_t *p = buscar_th(d, chave);
    if (p != NULL) {
        //Imprimo as informações do usuário
        printf("Login: %s = %s\tSenha: %s\tNome: %s\n", p->login, chave, p->senha, p->nome);
    }else {
        //Imprimo uma mensagem que indica se o usuário não foi encontrado
        printf("Login %s não encontrada\n", chave);
    }
}


void imprimir_logins(dicionario_t* d) {
    for (int i = 0; i < d->tamanho; i++) {
        no_t* no = d->vetor[i];
        while (no != NULL) {
            printf("Login: %s\n", no->chave);
            no = no->prox;
        }
    }
}






bool inserir_ordenado(dicionario_t* d, char* chave, pessoa_t* valor) {
    int indice = hash(chave, d->tamanho);

    // Aloca memória para o novo nó
    no_t* no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }

    // Faz uma cópia da chave usando strdup para evitar problemas com o ponteiro
    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }

    // Atribui o valor ao nó
    no->valor = valor;

    // Tratamento de colisões com lista encadeada
    no->prox = NULL;  // inicializa o próximo como NULL

    if (d->vetor[indice] == NULL || strcmp(d->vetor[indice]->chave, chave) > 0) {
        // Se a posição estiver vazia ou o novo nó deve ser o primeiro
        no->prox = d->vetor[indice];
        d->vetor[indice] = no;
    } else {
        // Encontro o local adequado para inserir o novo nó
        no_t* atual = d->vetor[indice];
        while (atual->prox != NULL && strcmp(atual->prox->chave, chave) < 0) {
            atual = atual->prox;
        }

        // Insero o novo nó na posição correta
        no->prox = atual->prox;
        atual->prox = no;
    }

    return true;
}


