#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void MAKENULL(t_lista *L)
{
    L->head = malloc(sizeof(t_nod_lista));
    L->head->prev = L->head->next = NULL;
}

t_nod_lista* LIST_SEARCH(t_lista L, int key){
    t_nod_lista *x;
    x = L.head;
    while (x!=NULL && x->cheie!=key)
        x=x->next;
    return x;
}

void LIST_DELETE(t_lista *L, t_nod_lista *X){
    if(X->prev != NULL)
        X->prev->next = X->next;
    else L->head->next = X->next;

    if(X->next != NULL)
        X->next->prev = X->prev;
    free(X);
}

void LIST_FREE(t_lista *L){
    t_nod_lista *x = malloc(sizeof (t_nod_lista));
    x = L->head->next;
    while (x!= NULL)
    {
        LIST_DELETE(L,x);
        free(x);
        x = L->head->next;
    }
    free(L->head);
    L->head = NULL;
}

void LIST_INSERT(t_lista* L, t_nod_lista* X){
    if(X == NULL)
        return;
    X->next = L->head->next;

    if(L->head->next != NULL)
        L->head->next->prev = X;
    L->head->next = X;
    X->prev = L->head;
}

void LIST_PRINT(t_lista L){
    t_nod_lista *x = malloc(sizeof(t_nod_lista));
    x = L.head->next;
    if(x == NULL)
        printf("Lista e nula!");
    while (x != NULL)
    {
        printf("%d", x->cheie);
        printf(" ");
        x = x->next;
    }
}
