#include <stdio.h>

/* Chamada das funções */
void limpar_buffer();



/* Função principal sem argumentos */
int main(void) {
  long long int numero = 0;
  unsigned long long int fatorial = 1;


  return 0;
}

/* Função para limpar conteúdo do buffer */
void limpar_buffer(void) {
  char clear;
  /* Conclui após buffer se buffer estiver limpo */
  while ((clear = getchar()) != '\n' && clear != EOF);
}