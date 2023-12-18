#include <stdio.h>
#include <stdlib.h>
#include "matrix-chain-order.h"

int main()
{
    int n, a[9999];
    printf ("Introduceti numarul matricilor= ");
    scanf ("%d", &n);

    READ_ARRAY (a, n);
    MATRIX_CHAIN_ORDER (a, n);
    PRINT_OPTIMAL_PARENS (1, n-1);
}
