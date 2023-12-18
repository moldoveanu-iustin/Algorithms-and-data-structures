#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cut_rod.h"

int MAX (int a, int b)
{
    if (a<b)
        return b;
    else return a;
}

    // READ & PRINT ARRAY

void READ_PRICES (int A[], int n)
{
    for (int i=1; i<=n; i++)
        scanf ("%d", &A[i]);
}

void PRINT_ARRAY (int A[], int n)
{
    for (int i=1; i<=n; i++)
        printf ("%d ", A[i]);
}

    // READ & PRINT ARRAY



int CUT_ROD (int p[], int n)
{
    if (n==0)
        return 0;
    int q = INT_MIN;
    for (int i=1; i<=n; i++)
        if (q < p[i]+ CUT_ROD (p, n-i))
            q = p[i]+ CUT_ROD (p, n-i);

    return q;
}


int MEMOIZED_CUT_ROD (int p[], int n)
{
    int r[500];
    for (int i=0; i<=n; i++)
    {
        r[i] = INT_MIN;
    }
    int q = MEMOIZED_CUT_ROD_AUX (p, n, r);

    PRINT_ARRAY (r, n);
    return q;
}

int MEMOIZED_CUT_ROD_AUX (int p[], int n, int r[])
{
    if (r[n]>=0)
        return r[n];
    int q;
    if (n==0)
        q = 0;
    else
    {
        q = INT_MIN;
        for (int i=1; i<=n; i++)
            if (q < p[i]+ MEMOIZED_CUT_ROD_AUX (p, n-i,r))
                q = p[i]+ MEMOIZED_CUT_ROD_AUX (p, n-i,r);
    }
    r[n] = q;
    return q;
}


int BOTTOM_UP_CUT_ROD (int p[], int n)
{
    int r[500];
    r[0] = 0;
    int q;
    for (int j=1; j<=n; j++)
        {
            q = INT_MIN;
            for (int i=1; i<=j; i++)
                {
                    if (q < p[i]+r[j-i])
                        q = p[i]+r[j-i];
                }
            r[j] = q;
        }
    return r[n];
}
