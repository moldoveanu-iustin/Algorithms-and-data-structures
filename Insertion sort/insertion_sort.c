#include <stdlib.h>
#include <stdio.h>
#include "insertion_sort.h"

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

void INSERTION_SORT (int A[], int n)
{
    for (int j=2; j<=n; j++)
    {
        int key = A[j];
        int i = j-1;
        while (i>0 && A[i]>key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
