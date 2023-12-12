//TESTE
#include "libprg/arvore.h"

//A seguinte função ler os dado do arquivo e armazena na estrutura Usuários
void separa_usu(FILE *arquivo, struct Usuario *usuario) {
    //sizeof é o responsavel por saber o tamanho se caracteres

    //Faço a leitura do login
    fgets(usuario->login, sizeof(usuario->login), arquivo);
    //Pula uma posição
    fgetc(arquivo);

    //Faço a leitura da senha
    fgets(usuario->senha, sizeof(usuario->senha), arquivo);
    fgetc(arquivo);

    //Faço a leitura do nome
    fgets(usuario->nome, sizeof(usuario->nome), arquivo);
    fgetc(arquivo);

    //Ao debugar foi notado que fgets voltava uma posição para trás
    //coloquei um fgetc logo após, para resolver isto, pois ele avança uma posição
}


int main(int argc, char **argv) {
    FILE *arquivo;
    // Cria a raiz da árvore
    no_t *raiz = NULL;
    struct Usuario novoUsuario;

    char arq[] = "../usuarios.dat";
    arquivo = fopen(arq, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o arquivo e insere os valores na árvore
    while (!feof(arquivo)) {
        separa_usu(arquivo, &novoUsuario);
        raiz = inserir_valor(raiz, novoUsuario);
    }

    fclose(arquivo);

    // Recebe o login do usuário
    char login[10];
    char senha[10];

//    printf("Qual o login?\n");
//    scanf("%s", login);
//
//    printf("Qual a senha?\n");
//    scanf("%s", senha);
//
//    // Busca o usuário na árvore
//    busca_usuario(raiz, login, senha);

    while (login[0] != 's' || login[0] != 'S'){
        printf("Qual o login?\n");
        scanf("%s", login);
        if (login[0] == 's' || login[0] == 'S') break;

        printf("Qual a senha?\n");
        scanf("%s", senha);

        // Busca o usuário na árvore
        busca_usuario(raiz, login, senha);
    }


    imprimir_maior_usuario(raiz);
    imprimir_menor_usuario(raiz);

    destruir_no_arvore(raiz);
    return 0;
}
