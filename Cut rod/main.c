#include <stdio.h>
#include <stdlib.h>
#include "cut_rod.h"
int main()
{
    int n, a[500];
    printf ("Introduceti lungimea barei: ");
    scanf ("%d", &n);

    READ_PRICES (a, n);
    int maxvalue;

    // CUT ROD
    printf ("Cut rod: ");
    maxvalue = CUT_ROD (a, n);
    printf ("%d ", maxvalue);
    printf("\n");

    // MEMOIZED CUT ROD
    maxvalue = MEMOIZED_CUT_ROD (a, n);
    printf("\n");
    printf ("Memoized cut rod: ");
    printf ("%d ", maxvalue);
    printf("\n");

    //BOTTOM-UP CUT ROD
    maxvalue = BOTTOM_UP_CUT_ROD (a, n);
    printf ("Bottom-up cut rod: ");
    printf ("%d ", maxvalue);
    printf("\n");

}
