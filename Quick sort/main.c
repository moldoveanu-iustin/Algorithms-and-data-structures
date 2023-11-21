#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[10001];
    printf ("Introduceti lungimea sirului: ");
    scanf ("%d", &n);

    printf ("Introduceti %d elemente: ", n);

    READ_ARRAY (a, n);

    QUICK_SORT (a, 1, n);

    PRINT_ARRAY (a, n);

}
