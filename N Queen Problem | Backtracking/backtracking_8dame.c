#include <stdio.h>
#include <stdlib.h>
#include "backtracking_8dame.h"

void TIPARESTE_SOLUTIE (int x[], int n)
{
    printf ("\n");
    printf ("Solutia %d este: \n", nr_sol);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (x[i] == j)
                printf ("R ");
            else
                printf (". ");
        }
        printf ("\n");
    }
}

int SE_ATACA (int x[], int pos)
{
    for (int i=1; i<=pos-1; i++)
        if ( x[i] == x[pos] || abs(x[i]-x[pos]) == abs(i-pos) )
            return 1;
    return 0;
}

void DAME (int x[], int n)
{
    int k = 1;
    for (int i=1; i<=n; i++)
        x[i] = 0;
    while (k>0)
    {
        if (k > n)
        {
            nr_sol++;
            TIPARESTE_SOLUTIE (x, n);
            k--;
        }
        else
        {
            x[k] = x[k]+1;
            if (x[k] <= n)
            {
                if (SE_ATACA(x, k)==0)
                    k++;
            }
            else
            {
                x[k] = 0;
                k--;
            }
        }
    }
}
