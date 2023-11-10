#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções da calculadora RPN
int calcular(Pilha *pilha, char condicao2) {
    //soma
    if (condicao2 == '+') {
        return desempilhar(pilha) + desempilhar(pilha);

    } else if (condicao2 == '-') {
        return desempilhar(pilha) - desempilhar(pilha);

    } else if (condicao2 == '*') {
        return desempilhar(pilha) * desempilhar(pilha);

    } else if (condicao2 == '/') {
        return desempilhar(pilha) / desempilhar(pilha);

    } else {
        return 0;
    }
}


int main() {
    Pilha pilha_calculadora;
    cria_pilha(&pilha_calculadora, 20);

    char condicao2[20];

    printf("Se você digitar 'S' você sai da calculadora\n");

    while (1) {


        printf("Insira um número ou a operação que você deseja realizar: ");
        scanf("%s", condicao2);
        if (condicao2[0] == '+' || condicao2[0] == '-' || condicao2[0] == '*' || condicao2[0] == '/') {
            int resultado = calcular(&pilha_calculadora, condicao2[0]);
            empilhar(&pilha_calculadora, resultado);
            printf("O resultado é: ");
            imprimi_pilha(&pilha_calculadora);
        }else if (condicao2[0] == 'S' || condicao2[0] == 's'){
            printf("Saindo da calculadora...\n");
            break;
        }else {
            empilhar(&pilha_calculadora, atoi(condicao2));
        }

    }
    return 0;
}
