#include "libprg/tabela_hash.h"

int main(int argc, char **argv) {

   //crio a tabela hash como o tamanho m
   dicionario_t *dicionario = criar_dicionario(10);
   
   dicionario_t* meu_dicionario = (dicionario_t*)malloc(sizeof(dicionario_t));
   if (dicionario == NULL) {
       printf("Não foi possível reservar memória\n");
       exit(EXIT_FAILURE);
   }

   
   pessoa_t *p = malloc(sizeof(pessoa_t));
   // https://en.cppreference.com/w/c/string/byte/strdup
   // strdup reserva memória para fazer a cópia da string. Presente no padrão C23
   
   p->cpf = strdup("123");
   p->nome = strdup("Juca");
   p->email = strdup("juca@example.ogr");
   inserir(dicionario, p->cpf, p);
   //imprimir_pessoa(dicionario, "123");

   p = malloc(sizeof(pessoa_t));
   p->cpf = strdup("456");
   p->nome = strdup("jamilly");
   p->email = strdup("jamilly@example.ogr");
   inserir(dicionario, p->cpf, p);
   //imprimir_pessoa(dicionario, "456");

   p = malloc(sizeof(pessoa_t));
   p->cpf = strdup("456");
   p->cpf = strdup("789");
   p->nome = strdup("ana");
   p->email = strdup("ana@example.ogr");
   inserir(dicionario, p->cpf, p);
   //imprimir_pessoa(dicionario, "789");
   
   imprimir_pessoa(dicionario, "123");
   imprimir_pessoa(dicionario, "456");
   imprimir_pessoa(dicionario, "789");

   // free(p1->cpf);
   // free(p1->nome);
   // free(p1->email);
   // free(p1);

   // free(p2->cpf);
   // free(p2->nome);
   // free(p2->email);
   // free(p2);
   // 
   // free(p3->cpf);
   // free(p3->nome);
   // free(p3->email);
   // free(p3);
   free(meu_dicionario);
   destruir_dicionario(dicionario);
   
   return 0;
}
