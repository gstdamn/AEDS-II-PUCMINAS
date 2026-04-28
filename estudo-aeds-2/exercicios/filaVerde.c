#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Celula{
  int elemento;
  struct Celula *prox;
}Celula;

Celula *criar_fila()
{
  Celula *primeiro = (Celula *)malloc(sizeof(Celula));
  primeiro->prox = NULL;

  return primeiro; 
}
void inserir(Celula *c,int x)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->elemento = x;
  tmp->prox = NULL;

  Celula *i;
  for(i = c; i->prox != NULL; i = i->prox);
  i->prox = tmp;

  
}
int remover(Celula *c)
{
  if(c->prox == NULL)
    return -1;

  Celula *tmp = c->prox;;
  int valor = tmp->elemento;
  c->prox = tmp->prox;

  return valor;
}
void mostrar(Celula *c)
{
  if(c->prox == NULL){
    printf("V\n");
    return;
  }
  
  Celula *i;
  for(i = c->prox; i != NULL; i = i->prox){
    if(i->prox != NULL)
      printf("%d ", i->elemento);
    else
      printf("%d", i->elemento);
  }
  printf("\n");
}
void pesquisar(Celula *c, int x)
{
  bool answer = false;
  Celula *i;
  for(i = c; i != NULL; i = i->prox){
    if(i->elemento == x)
      answer = true;
  }
  printf("%s" , answer ? "S\n" : "N\n");
}
int main()
{
  Celula *c = (Celula *)malloc(sizeof(Celula));
  c = criar_fila();

  char *entrada = (char *)malloc(10 * sizeof(char));
  int numero;

  while(scanf("%s", entrada) != EOF){
    if(strcmp(entrada, "E") == 0){
      scanf("%d" , &numero);
      inserir(c, numero);
    }else if(strcmp(entrada, "D") == 0){
      printf("%d\n" , remover(c));
    }else if(strcmp(entrada, "P") == 0){
      scanf("%d" , &numero);
      pesquisar(c,numero);
    }else if(strcmp(entrada, "M") == 0){
      mostrar(c);
    }
  }
  free(c);
  free(entrada);
}
