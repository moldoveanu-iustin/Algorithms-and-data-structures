#include "coada.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void INIT_QUEUE(t_coada *Q, int INIT_SIZE)
{
    Q->data = malloc(INIT_SIZE* sizeof (int));
    Q->head = 0;
    Q->tail = 0;
    Q->length = 0;
}

void FREE_QUEUE(t_coada *Q)
{
    free(Q->data);
    Q->data = NULL;
    Q->head = -1;
    Q->tail = -1;
}

void DEQUEUE(t_coada *Q)
{
    int e = Q->data[Q->head];
    Q->length = Q->length - 1;
    if(Q->head == Q->length-1)
        Q->head = 0;
    else Q->head = Q->head + 1;
}

void ENQUEUE(t_coada *Q, int E)
{
    Q->data[Q->tail] = E;
    Q->length = Q->length + 1;
    if(Q->tail == Q->length)
        Q->tail = 1;
    else
        Q->tail = Q->tail + 1;
}

bool QUEUE_EMPTY(t_coada Q)
{
    if(Q.length == 0)
        return true;
    else return false;
}


void PRINT_QUEUE(t_coada Q)
{
    for(int i=Q.head;i<=Q.length + Q.head - 1;i++)
        printf("%d ", Q.data[i]);
    printf("\n");
}
