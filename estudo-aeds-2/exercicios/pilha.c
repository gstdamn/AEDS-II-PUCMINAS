#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
  int elemento;
  struct Celula *topo;
}Celula;

void inserir_topo(Celula *c, int x)
{
 Celula *tmp = (Celula *)malloc(sizeof(Celula));
 tmp->elemento = x;
 tmp->topo = c->topo;
 c->topo = tmp;
}
int remover_topo(Celula *c)
{
  Celula *tmp = c->topo;
  int valor = tmp->elemento;
  c->topo = tmp->topo;
  free(tmp);

  return valor;
}
void mostrar_pilha(Celula *c)
{
  Celula *i = c->topo;
  while(i != NULL){
    printf("%d\n", i->elemento);
    i = i->topo;
  }
}
int main()
{
  Celula *c = (Celula *)malloc(sizeof(Celula));
  inserir_topo(c, 50);
  inserir_topo(c, 40);
  inserir_topo(c, 20);
  remover_topo(c);
  mostrar_pilha(c);

  free(c);
}
