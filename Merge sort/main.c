#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

int main()
{
    int a[1001];
    int n;
    printf ("Introduceti lungimea sirului: ");
    scanf ("%d", &n);

    printf ("Introduceti %d numere ce vor fi sortate: \n", n);
    READ_ARRAY (a, n);

    MERGE_SORT (a, 1, n);

    printf ("Sirul a fost sortat: \n");
    PRINT_ARRAY (a, n);


}
