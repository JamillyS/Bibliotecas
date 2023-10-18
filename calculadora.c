#include "libprg/libprg.h"
#include "stdio.h"

// Funções da calculadora RPN
int calcular(Pilha *pilha, char operacao) {
    //soma
    if (operacao == '+') {
        return desempilhar(pilha) + desempilhar(pilha);

        //subtração
    } else if (operacao == '-') {
        return desempilhar(pilha) - desempilhar(pilha);

        //multiplicação
    } else if (operacao == '*') {
        return desempilhar(pilha) * desempilhar(pilha);

        //divisão
    } else if (operacao == '/') {
        return desempilhar(pilha) / desempilhar(pilha);

        //caso contrario
    } else {
        return 0;
    }
}

int escolherAcao() {
    int condicao;
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Digite algum destes números para realizar a ação que você deseja:\n");
    printf("Para sair: 0\n");
    printf("Para realizar uma nova operação (limpar a pilha): 1\n");
    printf("Para continuar com o resultado anterior: 2\n");
    scanf("%d", &condicao);
    return condicao;
}

int main() {
    Pilha pilha_calculadora;
    cria_pilha(&pilha_calculadora, 20);

    int numero;
    char operacao;
    int condicao = 1;

    while (condicao == 1){
      //  desempilhar(&pilha_calculadora);

        printf("\n");
        printf("Digite um número: ");
        scanf("%d", &numero);
        empilhar(&pilha_calculadora, numero);

        printf("Digite outro número: ");
        scanf("%d", &numero);
        empilhar(&pilha_calculadora, numero);

        printf("Digite a operação (+, -, *, /): ");
        scanf(" %c", &operacao);

        if (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/') {
            int resultado = calcular(&pilha_calculadora, operacao);
            empilhar(&pilha_calculadora, resultado);
        } else {
            printf("Operação inválida\n");
        }

        printf("O resultado é: ");
        imprimi_pilha(&pilha_calculadora);

        condicao = escolherAcao();

        while (condicao == 2) {

            printf("Digite um número: ");
            scanf("%d", &numero);
            empilhar(&pilha_calculadora, numero);

            printf("Digite a operação (+, -, *, /): ");
            scanf(" %c", &operacao);

            if (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/') {
                int resultado = calcular(&pilha_calculadora, operacao);
                empilhar(&pilha_calculadora, resultado);
            } else {
                printf("Operação inválida\n");
            }
            printf("O resultado é: ");
            imprimi_pilha(&pilha_calculadora);
            condicao = escolherAcao();

            if (condicao == 1){
                desempilhar(&pilha_calculadora);
            }
        }
    }
    return 0;
}