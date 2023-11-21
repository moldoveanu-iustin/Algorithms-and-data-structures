#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void MAKENULL(t_lista *L){
    L->head = malloc(sizeof (t_nod_lista));
    L->head->next = NULL;
}

void PRINTLIST(t_lista L){
    t_nod_lista *x = malloc(sizeof( t_nod_lista));
    x = L.head->next;
    if(x == NULL){
        printf("Lista e nula!");
    }
    while (x != NULL){
        printf("%d ", x->cheie);
        x = x->next;
    }
}

t_nod_lista* NEXT(t_nod_lista X){
    return X.next;
}

t_nod_lista* PREVIOUS(t_lista L, t_nod_lista *X){

    t_nod_lista *x = L.head;
    if(x == NULL || X == NULL){
        return NULL;
    }
    if(x == X){
        return NULL;
    }
    while (x!= NULL && x->next != X){
        x = x->next;
    }
    return x;
}

t_nod_lista* FIRST(t_lista L){
    return L.head;
}

void INSERT(t_lista* L, t_nod_lista* X){
    if(X == NULL){
        return;
    }
    X->next = L->head->next;

    if(L->head->next != NULL){
        t_nod_lista *x = PREVIOUS(*L, L->head->next);
        x = X;
    }

    L->head->next = X;

    t_nod_lista *x = PREVIOUS(*L, X);
    x = L->head;
}

void DELETE(t_lista *L, t_nod_lista *X){

    if(PREVIOUS(*L, X) != NULL){
        t_nod_lista *x = PREVIOUS(*L, X);
        x->next = X->next;
    } else{
        L->head->next = X->next;
    }

    if(X->next != NULL){
        t_nod_lista *x = PREVIOUS(*L, X->next);
        x = PREVIOUS(*L, X);
    }
    free(X);
}

void LIST_FREE(t_lista *L){
    t_nod_lista *x = malloc(sizeof (t_nod_lista));
    x = L->head->next;
    while (x!= NULL){
        DELETE(L, x);
        free(x);
        x = L->head->next;
    }
    free(L->head);
    L->head = NULL;
};

t_nod_lista* RETRIEVE(t_lista L, int key){
    t_nod_lista *x;
    x = L.head;
    while (x!=NULL && x->cheie!=key){
        x=x->next;
    }
    return x;
}
