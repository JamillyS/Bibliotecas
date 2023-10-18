#include "libprg/libprg.h"
#include "stdlib.h"
#include "stdio.h"

void cria_fila(Fila *fila, int capacidade){
    fila->valores = malloc(sizeof(int) * capacidade);

    fila->inicio = 0;
    fila->fim = 0;
    //fila->tamanho = 0;
    //capacidade - 1, pois minha fila vai de 0 a 9
    fila->capacidade = capacidade;
}

void enfileirar(Fila *fila, int x) {
    int tamanho;
    // printf("inicio: %d, fim: %d. elemento: %d, tamanho: %d\n", fila->inicio, fila->fim, x;
    if(fila->fim - fila->inicio == fila->capacidade ){
        printf("sua fila está cheia\n");
    }
    else if(fila->fim >= fila->inicio){
        //tamanho = fila->fim - fila->inicio;
        fila->valores[fila->fim] = x;
        fila->fim++;

    } else if(fila->inicio >= fila->fim){
        fila->fim =  fila->capacidade - (fila->inicio - fila->fim);
        fila->valores[fila->fim] = x;
        fila->fim++;

    }

//        fila->valores[fila->fim] = x;
//        fila->fim++;



//    if(fila->fim >= fila->inicio){
//       int tamanho;
//       tamanho = fila->capacidade - (fila->fim - fila->inicio);
//        fila->valores[fila->fim] = x;
//        fila->fim++;
//
//    } else if (fila->inicio >= fila->fim){
//        fila->capacidade - (fila->inicio - fila->fim);
//        fila->valores[fila->fim] = x;
//        fila->fim++;
//
//    } else if(fila->inicio == fila->fim){
//        fila->valores[fila->fim] = x;
//        fila->fim++;
//    }



//    if (fila->tamanho == fila->capacidade) {
//        printf("Sua fila está cheia 1\n");
//    } // Valida quando está cheia no meio do vetor
//    else if (fila->inicio == fila->fim && fila->tamanho > 0) {
//        printf("Sua fila está cheia 2\n");
//
//    // valida quando está cheia no final do vetor
//    } else if (fila->tamanho == fila->capacidade + 1 && fila->inicio == fila->fim) {
//        printf("Sua fila está cheia 3\n");
//
//    } else if (fila->tamanho != fila->capacidade+1) {
//        //no fim da fila adiciono o valor x
//        //fila->valores[fila->fim] = x;
//        //avanço uma posição da minha fila
//        if (fila->fim == fila->capacidade) {
//            fila->valores[fila->fim] = x;
//            fila->tamanho++;
////            fila->fim = 0;
//
//        } else {
//            fila->valores[fila->fim] = x;
//            fila->fim++;
//            //fila->tamanho++;
//        }
////        fila->valores[fila->fim] = x;
////        fila->fim++;
//        printf("Passou aqui\n");
//
//    }

    // printf("inicio (depois): %d, fim (depois): %d. elemento: %d, tamanho (depois): %d\n\n", fila->inicio, fila->fim, x, fila->tamanho);
}


void desenfileirar(Fila *fila){
//    //se a fila estiver vazia
//    if (fila->inicio == fila->fim) {
//        printf("estou aqui");
//      //  exit(1);
//    }
//    if (fila->tamanho == 0) {
//        printf("estou aqui 2 ");
//       // exit(1);
//    }

    //digo que o inicio é 0, para poder remover o que tem dentro
    fila->valores[fila->inicio] = 0;
    //inicio++, para indicar que a proxima posição é o inicio
    fila->inicio++;

//    if (fila->fim == fila->capacidade){
//        fila->fim = 0;
//        printf("estou aqui 3 ");
//
//    }

    //fila->tamanho--;
}


void imprimi_fila(Fila *fila){
//isso caso a fila esteja na volta certa
    for (int i = fila->inicio; i < fila->fim; i++) {
        printf("%d ", fila->valores[i]);
    }
//    if(fila->inicio >= fila->fim){
//        for (int i = fila->inicio; i < fila->fim; i++) {
//            printf("%d ", fila->valores[i]);
//    }
//        //fim > inicio
//    }
////    else{
////
////    }
//    printf("\n");
//    //tem que fazer o caso que meu inicio esteja no final da fila
}







//
////printf("inicio: %d, fim: %d, capacidade: %d\n", fila->inicio, fila->fim, fila->capacidade);
////retorna codigo de erro
//
//// quando o fim for um a menos que o inicio a fila está cheia portanto
//
//// if(fila->inicio != 0 && fila->inicio - 1 == fila->fim || fila->inicio == 0 && fila->fim == fila->capacidade)
////fila->fim == fila->capacidade && fila->inicio != 0
//if(fila->fim == fila->capacidade && fila->inicio != 0) { // No primeiro momento
//printf("A fila está cheia\n");
//exit(1);
//} else if(fila->fim % fila->capacidade == 0){
//fila->fim = 0;
//} else if (fila->inicio - 1 == fila->fim)
//
//fila->valores[fila->fim] = x;
//fila->fim++;