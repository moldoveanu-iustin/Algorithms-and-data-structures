#include <stdio.h>
#include <stdlib.h>
#include "greedy.h"

void READ_ARRAY (int A[], int n)
{
    for (int i=1; i<=n; i++)
        scanf ("%d", &A[i]);
}

void PRINT_ARRAY (int A[], int n)
{
    for (int i=1; i<=n; i++)
        printf ("%d ", A[i]);
}

int RECURSIVE_ACTIVITY_SELECTOR (int S[], int F[], int k, int n, int A[])
{
    int na = 0;
    int m = k+1;
    while (m <= n && S[m] < F[k])
        m++;
    if (m <= n)
    {
        na++;
        A[na] = m;
        RECURSIVE_ACTIVITY_SELECTOR (S, F, m, n, A);
    }
    return na;
}

int GREEDY_ACTIVITY_SELECTOR (int S[], int F[], int n, int A[])
{
    int na = 0;
    int k = 0;
    for (int m=1; m<=n; m++)
    {
        if (S[m] >= F[k])
        {
            na++;
            A[na] = m;
            k = m;
        }
    }
    return na;
}
