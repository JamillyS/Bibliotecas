#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

//----------------------------------------------------------------------------------------------------------------------
typedef struct {
    int *valores;
    int tam_maximo;     //quantia de inteiros
    int n_elementos;    //quantos elementos guarno no momento
} Lista;

void cria_lista(Lista *lista, int tam_maximo);
void imprime_lista(Lista *lista);
int busca_linear(Lista *lista, int x);
void inserir_nao_ordenada(Lista *lista, int x);
void remove_n(Lista *lista, int x);

void busca_binaria(Lista *lista, int x, int alvo);
void inserir_ordenada(Lista *lista, int x);
void remove_n2(Lista *lista, int x);

//----------------------------------------------------------------------------------------------------------------------

typedef struct {
    int *valores;
    int inicio;
    int fim;
    int capacidade;
} Fila;

void cria_fila(Fila *fila, int capacidade);
void imprimi_fila(Fila *fila);
void enfileirar(Fila *fila, int x); //retorna codifo de erro
void desenfileirar(Fila *fila);

//----------------------------------------------------------------------------------------------------------------------
typedef struct {
    int *valores;
    int topo;
    int capacidade;
} Pilha;

void cria_pilha(Pilha *pilha, int capacidade);
void empilhar(Pilha *pilha, int x);
int desempilhar(Pilha *pilha);
int tamanho(Pilha *pilha);
int vazia(Pilha *pilha);
void imprimi_pilha(Pilha *pilha);
//----------------------------------------------------------------------------------------------------------------------
//Lista circular encadeada (não ordenada e ordenada)
//b. Lista circular duplamente encadeada (não ordenada e ordenada)
//c. Fila representada em uma lista encadeada
//d. Pilha representada em uma lista encadeada


//não é pra usar o array contunuo
//é para usar nodos


typedef struct {
    int *primeiro;      //o primeiro nodo da lista
    int *ultimo;       //o ultimo nodo da lista
    int comprimento;   // o comprimento da lista (quantos nodos existem)

} Lista_encadeada;

//struct Nodo {
//    // um dado armazenado
//    string dado;
//    // isto indica qual o próximo nodo da sequência
//    Nodo * proximo;
//};



void cria_lista_encadeada();



//----------------------------------------------------------------------------------------------------------------------


#endif


