#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int elemento;
    struct Node *esq, *dir;
}Node;

typedef struct Arvore{
    int elemento;
    Node *raiz;
}Arvore;

Arvore *criar_arvore(){
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;

    return arvore;
}
void inserir(Arvore *a, int x)
{ 
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->elemento = x;
    novo->esq = NULL;
    novo->dir = NULL;

    if(a->raiz == NULL){
        a->raiz = novo;
        return;
    }

    Node *pai = NULL;
    Node *atual = a->raiz;

    while(atual != NULL){
        if(atual->elemento > x){
            pai = atual;
            atual = atual->esq;
        }else{
            pai = atual;
            atual = atual->dir;
        }
    }
    if(pai->elemento > x)
        pai->esq = novo;
    else
        pai->dir = novo;
}
void pesquisar(Arvore *a, int y)
{
    if(a->raiz == NULL){
        printf("N\n");
        return;
    }

    Node *atual = a->raiz;
    atual = a->raiz;

    while(atual != NULL && atual->elemento != y){
        if(atual->elemento > y){
            printf("%d ", atual->elemento);
            atual = atual->esq;
        }else{
            printf("%d ", atual->elemento);
            atual = atual->dir;
        }
    }
    if(atual == NULL)
        printf("N\n");
    else
        printf("%d S\n", atual->elemento);
}
void caminharPre(Node *i)
{
    if(i != NULL){
        printf("%d " , i->elemento);
        caminharPre(i->esq);
        caminharPre(i->dir);
    }
}
void caminharPos(Node *i)
{
    if(i != NULL){
        caminharPos(i->esq);
        caminharPos(i->dir);
        printf("%d ", i->elemento);
    }
}
void caminharOrdem(Node *i)
{   
    if(i != NULL){
        caminharOrdem(i->esq);
        printf("%d " , i->elemento);
        caminharOrdem(i->dir);
    }
}
int main()
{
    Arvore *arvore = criar_arvore();
    int valor;
    char *comando = (char *)malloc(10 * sizeof(char));


    while(scanf("%s", comando) != EOF){
        if(strcmp(comando, "I") == 0){
            scanf("%d" , &valor);
            inserir(arvore, valor);
        }else if(strcmp(comando, "P") == 0){
            scanf("%d" , &valor);
            pesquisar(arvore, valor);
        }else if(strcmp(comando, "PRE") == 0){
            if(arvore->raiz == NULL) 
                printf("V\n");
            else{
                caminharPre(arvore->raiz);
                printf("\n");
            }
        }else if(strcmp(comando, "POS") == 0){
            if(arvore->raiz == NULL)
                printf("V\n");
            else{
                caminharPos(arvore->raiz);
                printf("\n");
            }
        }else if(strcmp(comando, "EM") == 0){
            if(arvore->raiz == NULL)
                printf("V\n");
            else{
                caminharOrdem(arvore->raiz);
                printf("\n");
            }
        }
    }
}
