#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
  int elemento;
  struct Celula *prox;
}Celula;

void inserir_inicio(Celula *c ,int x)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->elemento = x;
  tmp->prox = c->prox;
  c->prox = tmp;
}
int remover_inicio(Celula *c)
{
  Celula *tmp = c->prox;
  int x = tmp->elemento;
  c->prox = tmp->prox;

  free(tmp);
  return x;  
}
void inserir_fim(Celula *c, int x)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->elemento = x;

  Celula *i;
  for(i = c; i->prox != NULL; i = i->prox );
  i->prox = tmp;
  tmp->prox = NULL;

}
int remover_fim(Celula *c)
{
  Celula *i;
  for(i = c; i->prox->prox != NULL; i = i->prox);
  Celula *tmp = i->prox;
  int x = tmp ->elemento;
  i->prox = NULL;

  free(tmp);
  return x;
}
void mostrar_fila(Celula *c)
{
  Celula *i;
  for(i = c->prox; i->prox != NULL; i = i->prox){
    printf("%d\n", i->elemento);
  }
}
int main()
{
  Celula *c = (Celula *)malloc(sizeof(Celula));
  c->prox = NULL;
  
  inserir_inicio(c, 10);
  inserir_inicio(c,14);
  inserir_inicio(c,20);
  remover_fim(c);
  mostrar_fila(c);

  free(c);
}
