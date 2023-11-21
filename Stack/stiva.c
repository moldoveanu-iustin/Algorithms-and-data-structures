#include "stiva.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void INIT_STACK(t_stiva *S, int INIT_SIZE)
{
    S->data = malloc(sizeof (int));
    S->top = 0;
}

void FREE_STACK(t_stiva S)
{
    free(S.data);
    S.data = NULL;
    S.top = -1;
}

bool STACK_EMPTY(t_stiva S)
{
    if (S.top == 0)
        return true;
    else return false;
}

void PUSH(t_stiva *S, int E)
{
    S->top = S->top+1;
    S->data[S->top]=E;
}

int POP(t_stiva *S)
{
    int e;
    if(STACK_EMPTY(*S))
    {
        printf("Stiva e goala");
        return -1;
    }
    else
    {
        e = S->data[S->top];
        S->data[S->top] = 0;
        S->top = S->top - 1;
        return e;
    }
}

void PRINT_STACK(t_stiva S)
{
    for(int i=1;i<=S.top;i++)
        printf("%d ", S.data[i]);
    printf("\n");
}
