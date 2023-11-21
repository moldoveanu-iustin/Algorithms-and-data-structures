#include <stdio.h>
#include <stdlib.h>
#include "tabela_prin_inlantuire.h"

void MAKENULL(t_lista *T)
{
    T->head = malloc(sizeof(t_nod_lista));
    T->head->prev = T->head->next = NULL;
}

        // FUNCTII LISTE

void LIST_INSERT(t_lista* T, t_nod_lista* x){
    if(x == NULL)
        return;
    x->next = T->head->next;

    if(T->head->next != NULL)
        T->head->next->prev = x;
    T->head->next = x;
    x->prev = T->head;
}

void LIST_PRINT(t_lista T){
    t_nod_lista *x = malloc(sizeof(t_nod_lista));
    x = T.head->next;
    if(x == NULL)
        printf("Lista e nula!");
    while (x != NULL)
    {
        printf("%d", x->cheie);
        printf(" ");
        x = x->next;
    }
}

t_nod_lista* LIST_SEARCH(t_lista T, int key){
    t_nod_lista *x;
    x = T.head;
    while (x!=NULL && x->cheie!=key)
        x=x->next;
    return x;
}

void LIST_DELETE(t_lista *T, t_nod_lista *x){
    if(x->prev != NULL)
        x->prev->next = x->next;
    else T->head->next = x->next;

    if(x->next != NULL)
        x->next->prev = x->prev;
    free(x);
}

         // FUNCTII HASH

void INIT_HASHTABLE (t_lista *T[], int m)
{
    for (int j=0; j<m; j++)
        MAKENULL (&T[j]);
}

int HASH_FUNCTION (int k, int m)
{
    return k%m;
}

int CHAINED_HASH_INSERT (t_lista *T, int k, int m)
{
    t_nod_lista *x;
    int j = HASH_FUNCTION (k, m);
    x = malloc(sizeof (t_nod_lista));
    int key;
    x->cheie = k;
    LIST_INSERT (&T[j], x);
    return j;
}

void PRINT_HASHTABLE (t_lista T[], int m)
{
    for (int j=0; j<m; j++)
        if (T[j].head->next != NULL)
        {
            printf ("T[%d]:", j);
            LIST_PRINT (T[j]);
            printf ("\n");

        }
}

int CHAINED_HASH_SEARCH (t_lista T[], int k, int m)
{
    int j = HASH_FUNCTION (k, m);
    t_nod_lista *x = LIST_SEARCH (T[j], k);
    if (x != NULL)
        return j;
    else return -1;
}

int CHAINED_HASH_DELETE (t_lista T[], int k, int m)
{
    int j = HASH_FUNCTION (k, m);
    t_nod_lista *x = LIST_SEARCH (T[j], k );
    if (x != NULL)
    {
        LIST_DELETE (&T[j], x);
        return j;
    }
    else return -1;
}
