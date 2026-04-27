#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
  int elemento;
  struct Celula *ant;
  struct Celula *prox;
}Celula;

void inserir_inicio(Celula *p, Celula **u, int x)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->ant = p;
  tmp->prox = p->prox;
  tmp->elemento = x;
  if(p == *u)
    *u = tmp;
  else
  p->prox->ant = tmp;

  p->prox = tmp;
}

int remover_inicio(Celula *p)
{
  Celula *tmp = p;
  p = p->prox;
  int valor = p->elemento;
  tmp->prox->ant= tmp->prox  = NULL;
  tmp = NULL;

  return valor;  
}
void inserir_fim(Celula **u, int x)
{
  Celula *tmp = (Celula *)malloc(sizeof(Celula));
  tmp->elemento = x;
  tmp->ant = *u;
  tmp->prox = NULL;
  (*u)->prox = tmp;
  *u = tmp;
}
int remover_fim(Celula **u)
{
  *u = (*u)->ant;
  (*u)->ant->prox = NULL;
  int valor = (*u)->elemento;

  return valor;
}
void mostrar_lista(Celula *p)
{
  Celula *i;
  for(i = p->prox; i != NULL; i = i->prox ){
    printf("%d\n" , i->elemento);
  }
}

int main()
{
  Celula *primeiro = (Celula *)malloc(sizeof(Celula));
  primeiro->prox = NULL;
  primeiro->ant = NULL;
  Celula *ultimo = primeiro;
  

  inserir_inicio(primeiro,&ultimo, 10);
  inserir_inicio(primeiro,&ultimo, 20);
  inserir_inicio(primeiro,&ultimo, 40);
  inserir_fim(&ultimo, 15);

  mostrar_lista(primeiro);
  
}
