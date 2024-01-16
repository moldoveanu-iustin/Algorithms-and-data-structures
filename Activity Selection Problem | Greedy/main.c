#include <stdio.h>
#include <stdlib.h>
#include "greedy.h"

int main()
{
    int SOL_REC[500], SOL_ITER[500];
    int s[500], f[500];
    int n;
    scanf ("%d", &n);
    READ_ARRAY (s, n);
    READ_ARRAY (f, n);
    f[0] = 0;

    int lenght_sol_rec = RECURSIVE_ACTIVITY_SELECTOR (s, f, 0, n, SOL_REC);
    printf ("Solutie recursiva: ");
    PRINT_ARRAY (SOL_REC, lenght_sol_rec);

    printf ("\n");

    int lenght_sol_it = GREEDY_ACTIVITY_SELECTOR (s, f, n, SOL_ITER);
    printf ("Solutie iterativa: ");
    PRINT_ARRAY (SOL_ITER, lenght_sol_it);

}
