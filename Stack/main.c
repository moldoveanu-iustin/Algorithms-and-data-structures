#include <stdio.h>
#include "stiva.h"

int main()
{
    t_stiva S;
    int e = -1;
    INIT_STACK(&S, 20);
    while (e!=0)
    {
        printf("Adauga in stiva elementul: ");
        scanf("%d", &e);
        PUSH(&S, e);
        PRINT_STACK(S);
    }

    while (!STACK_EMPTY(S))
    {
        POP(&S);
        PRINT_STACK(S);
    }

    FREE_STACK(S);
    return 0;
}
