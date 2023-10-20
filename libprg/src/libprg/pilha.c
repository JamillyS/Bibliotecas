#include "libprg/libprg.h"
#include "stdlib.h"
#include "stdio.h"

void cria_pilha(Pilha *pilha, int capacidade){
//    if (pilha->valores == NULL){
//        pilha->valores = malloc(sizeof (int) * capacidade);
//        //por convenção quando minha pilha está vazia comeca em -1
//        pilha->topo = 0;
//        pilha->capacidade = capacidade;
//    } else
    pilha->valores = malloc(sizeof (int) * capacidade);
//        //por convenção quando minha pilha está vazia comeca em -1
        pilha->topo = 0;
       pilha->capacidade = capacidade;
}
void empilhar(Pilha *pilha, int x){
    if(pilha->topo == pilha->capacidade - 1){
        printf("sua fila está cheia\n");
        //exit(1);
    }
    pilha->valores[pilha->topo] = x;
    pilha->topo++;

}
//retornar o valor espilhado
int desempilhar(Pilha *pilha){
    if (pilha->topo == 0){
        printf("Sua pilha está vazia\n");
       // exit(1);
    }
    pilha->topo--;
    return pilha->valores[pilha->topo];

}

int tamanho(Pilha *pilha){
    //printf("%d\n", pilha->topo);
    return pilha->topo;

}
int vazia(Pilha *pilha){
   if(pilha->topo == 0) return 1;

}

void imprimi_pilha(Pilha *pilha){
    for (int i = 0; i < pilha->topo; i++) {
        printf("%d ", pilha->valores[i]);
    }
    printf("\n");
}