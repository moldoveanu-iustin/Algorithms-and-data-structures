#include <stdio.h>
#include <stdlib.h>
#include "backtracking_8dame.h"

int main()
{
    int x[500];
    int n; // nr de dame
    scanf("%d", &n);
    DAME (x, n);
    printf ("\n");
    printf ("Numarul total de solutii este: %d", nr_sol);
}
