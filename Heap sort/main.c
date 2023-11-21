#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

int main()
{
    int HEAP_SIZE = 0;
    int n, a[1001];
    printf ("Introduceti lungimea sirului: ");
    scanf ("%d", &n);

    printf ("Introduceti %d elemente: ", n);

    READ_ARRAY (a, n);

    HEAP_SORT (a, n, &HEAP_SIZE);

    PRINT_ARRAY (a, n);

}
