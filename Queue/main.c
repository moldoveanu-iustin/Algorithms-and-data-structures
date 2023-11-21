#include <stdio.h>
#include "coada.h"

int main() {
    t_coada Q;
    int e = -3;
    INIT_QUEUE(&Q, 20);

    while (e!=0){
        scanf("%d", &e);
        ENQUEUE(&Q, e);
        PRINT_QUEUE(Q);
    }
    printf("\n");
    while (!QUEUE_EMPTY(Q)){
        DEQUEUE(&Q);
        PRINT_QUEUE(Q);
    }
    FREE_QUEUE(&Q);
    return 0;
}
