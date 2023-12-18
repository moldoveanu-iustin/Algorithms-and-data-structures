#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "matrix-chain-order.h"

void READ_ARRAY (int a[], int n)
{
    for (int i=1; i<=n; i++)
        scanf ("%d", &a[i]);
}

void PRINT_OPTIMAL_PARENS (int i, int j)
{
    if (i == j)
        printf ("A%d ", i);
    else
    {
        printf ("(");
        PRINT_OPTIMAL_PARENS (i, s[i][j]);
        PRINT_OPTIMAL_PARENS (s[i][j]+1, j);
        printf (")");
    }
}

void MATRIX_CHAIN_ORDER (int p[], int n)
{
    long long q;
    n = n-1;
    int m[n][n];
    for (int i=1; i<=n; i++)
        m[i][i] = 0;
    for (int t=2; t<=n; t++)
        {
            for (int i=1; i<=n-t+1; i++)
                {
                    int j = i + t - 1;
                    m[i][j] = INT_MAX;
                    for (int k=i; k<=j-1; k++)
                    {
                        q = m[i][k] + m[k+1][j] + (long long)p[i-1] * p[k] * p[j];
                        if (q < m[i][j])
                            {
                                m[i][j] = q;
                                s[i][j] = k;
                            }
                    }
                }
        }
}
