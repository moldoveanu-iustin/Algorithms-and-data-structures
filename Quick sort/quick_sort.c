#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

void READ_ARRAY (int V[], int n)
{
    for (int i=1; i<=n; i++)
        scanf ("%d", &V[i]);
}

void PRINT_ARRAY (int V[], int n)
{
    for (int i=1; i<=n; i++)
        printf ("%d ", V[i]);
}

int PARTITION (int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++)
        if (A[j] <= x)
            {
                i++;
                int aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
    A[r] = A[i+1];
    A[i+1] = x;
    return i+1;
}

void QUICK_SORT (int A[], int p, int r)
{
    int q = 0;
    if (p < r)
    {
        q = PARTITION (A, p, r);
        QUICK_SORT (A, p, q-1);
        QUICK_SORT (A, q+1, r);
    }
}
