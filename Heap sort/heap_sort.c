#include <stdlib.h>
#include <stdio.h>
#include "heap_sort.h"

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

int LEFT(int X)
{
    return 2 * X;
}


int RIGHT(int X)
{
    return 2 * X + 1;
}


void MAX_HEAPIFY(int A[], int X, int *HEAP_SIZE)
{
    int l = LEFT(X);
    int r = RIGHT(X);
    int largest;

    if(l <= *HEAP_SIZE && A[l] > A[X])
        largest = l;
    else
        largest = X;


    if(r <= *HEAP_SIZE && A[r] > A[largest])
        largest = r;

    if(largest != X)
    {
        int aux = A[X];
        A[X] = A[largest];
        A[largest] = aux;
        MAX_HEAPIFY(A, largest, HEAP_SIZE);
    }
}


void BUILD_MAX_HEAP(int A[], int N, int *HEAP_SIZE)
{
    *HEAP_SIZE = N;
    for(int i = N/2; i>=1;i--)
        MAX_HEAPIFY(A, i, HEAP_SIZE);
}


void HEAP_SORT(int A[], int N, int *HEAP_SIZE)
{
    BUILD_MAX_HEAP(A,N, HEAP_SIZE);
    for(int i=N;i>=2;i--)
    {
        int aux = A[1];
        A[1] = A[i];
        A[i] = aux;
        (*HEAP_SIZE) = (*HEAP_SIZE) - 1;
        MAX_HEAPIFY(A,1, HEAP_SIZE);
    }
}
