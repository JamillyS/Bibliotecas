#include "libprg/arvore.h"

// Esta função cria um nó e inicializa seus campos
no_t *criar_no(struct Usuario usuario) {
    // aloca memória para o nó
    no_t *no = (no_t *)malloc(sizeof(no_t));
    no->usuario = usuario;
    no->esquerda = no->direita = NULL;
    return no;
}

// Esta função destrói um nó e libera a memória
void destruir_no_arvore(no_t *no) {
    if (no != NULL) {
        destruir_no_arvore(no->esquerda);
        destruir_no_arvore(no->direita);
        free(no);
    }
}

// todo nó é raiz de uma subárvore
no_t *inserir_valor(no_t *raiz, struct Usuario novoUsuario) {
    // se a árvore estiver vazia, retorna um novo nó
    if (raiz == NULL) {
        return criar_no(novoUsuario);
        // se não, percorre a árvore e adiciona o nó na posição correta
    } else if (strcmp(novoUsuario.login, raiz->usuario.login) < 0) {
        raiz->esquerda = inserir_valor(raiz->esquerda, novoUsuario);
        // se não, percorre a árvore e adiciona o nó na posição correta
    } else if (strcmp(novoUsuario.login, raiz->usuario.login) > 0) {
        raiz->direita = inserir_valor(raiz->direita, novoUsuario);
    }
    return raiz;
}

// Esta função busca o usuário na árvore
bool busca_usuario(no_t *raiz, char *login, char *senha) {
    if (raiz == NULL) {
        printf("Usuário ou Senha inválidos %s \n", raiz->usuario.login, login);
        return false;
    }
    if (strcmp(raiz->usuario.login, login) == 0 && strcmp(raiz->usuario.senha, senha) == 0) {
        printf("Usuário encontrado. Bem vindo %s !\n", raiz->usuario.nome);
        return true;
    }

    // se não, percorre a árvore e adiciona o nó na posição correta
    if (strcmp(login, raiz->usuario.login) < 0) {
        return busca_usuario(raiz->esquerda, login, senha);
    } else {
        return busca_usuario(raiz->direita, login, senha);
    }
}

// Esta função busca o maior usuário na árvore
struct Usuario busca_maior_usuario(no_t *raiz) {
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->usuario;
}

// Esta função imprime o maior usuário na árvore
void imprimir_maior_usuario(no_t *raiz) {
    struct Usuario maior = busca_maior_usuario(raiz);
    printf("O maior login: %s. Com o nome: %s, é o maior usuário da árvore\n", maior.login, maior.nome);
}

//Esta função busca o menor usuário na árvore
struct Usuario busca_menor_usuario(no_t *raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz->usuario;
}

// Esta função imprime o menor usuário na árvore
void imprimir_menor_usuario(no_t *raiz) {
    struct Usuario menor = busca_menor_usuario(raiz);
    printf("O maior login: %s. Com o nome: %s, é o menor usuário da ávore\n", menor.login, menor.nome);
}

