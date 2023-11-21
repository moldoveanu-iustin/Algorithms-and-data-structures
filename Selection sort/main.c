#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int a[1001];
    int n;
    printf("Introduceti lungimea sirului: ");
    scanf ("%d", &n);

    printf("\nIntroduceti %d elemente: \n", n);
    READ_ARRAY (a, n);

    int minim = INT_MAX;
    for (int i=1; i<=n; i++)
    {

        int aux = a[ MINIM_ARRAY(a, i, n)];
        a[MINIM_ARRAY (a, i, n)] = a[i];
        a[i] = aux;

    }

    PRINT_ARRAY (a, n);
}


int MINIM_ARRAY (int v[], int i, int n) // minimul arrayului incepand cu pozitia i pana la n
{
    int minim = INT_MAX;
    int poz = 0;
    for (int k=i; k<=n; k++)
        if (v[k] < minim)
            {
                minim = v[k];
                poz = k;
            }
    return poz;

}


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
