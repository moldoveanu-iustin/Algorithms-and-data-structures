#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "merge_sort.h"

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

void MERGE (int A[], int p, int q, int r)
{
    int left[500], right[500];
    int n1 = q-p+1;
    int n2 = r-q;

    for (int i=1; i<=n1; i++)
        left[i] = A[p+i-1];

    for (int j=1; j<=n2; j++)
        right[j] = A[q+j];

    left[n1+1] = INT_MAX;
    right[n2+1] = INT_MAX;

    int i = 1;
    int j = 1;

    for (int k=p; k<=r; k++)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
    }
}

void MERGE_SORT (int A[], int p, int r)
{
    int q = 0;
    if (p < r)
    {
        q = (p+r)/2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE (A, p, q, r);
    }
}
