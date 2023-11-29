#include "libprg/tabela_hash.h"
//#include "libprg/lista_encadeada.h"

void separa_usu(FILE *arquivo, pessoa_t *usuario) {
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

    //Passo o nome do aquivo
    // char arq[] = "../usuarios.dat";
    char *arq = argv[1];
    char *usuario = argv[2];
    char *senha = argv[3];

    //Realizo a abertura do arquivo
    arquivo = fopen(arq, "r");

    //Caso haja algum problema com a abertura do arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }


    //crio a tabela hash como o tamanho m
    dicionario_t *dicionario = criar_dicionario(10);
    //dicionario_t *meu_dicionario = (dicionario_t *) malloc(sizeof(dicionario_t));
    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    //enquanto eu não chego ao fim do arquivo
    while (!feof(arquivo)) {
        pessoa_t *p = malloc(sizeof(pessoa_t));
        separa_usu(arquivo, p);

        inserir(dicionario, p->login, p);

    }

    //buscar_th(dicionario, usuario);


//    imprimir_pessoa(dicionario, usuario);
//    imprimir_pessoa(dicionario, "f.pingo");
//    imprimir_pessoa(dicionario, "g.enidi");
//    imprimir_pessoa(dicionario, "r.victoru");
//    imprimir_pessoa(dicionario, "a.simome");
//    imprimir_pessoa(dicionario, "m.arani");

//    buscar_th(dicionario, "f.pingo");
//    buscar_th(dicionario, usuario);
//    buscar_th(dicionario, "g.enidi");
//    buscar_th(dicionario, "r.victoru");
//    buscar_th(dicionario, "a.simome");
//    buscar_th(dicionario, "m.arani");

    verificar_login_senha(dicionario, usuario, senha);

    destruir_dicionario(dicionario);
    fclose(arquivo);

    return 0;
}


