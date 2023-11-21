#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"

int main()
{
    int a[1001];
    int n;
    printf ("Introduceti lungimea sirului: ");
    scanf ("%d", &n);

    printf ("Introduceti %d numere ce vor fi sortate: \n", n);
    READ_ARRAY (a, n);

    INSERTION_SORT (a, n);

    printf ("Sirul introdus a fost sortat: \n");
    PRINT_ARRAY (a, n);

}

