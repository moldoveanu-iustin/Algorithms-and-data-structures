#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

int main()
{
    int T[100];
    int m;
    printf ("Introduceti lungimea tabelei: ");
    scanf ("%d", &m);
    HASH_INIT (T, m);
    int key;
    printf ("Introduceti numere pana la citirea lui 0:");
    scanf ("%d", &key);
    int j = 0;
    while (key != 0)
    {
        j = HASH_INSERT(T, key, m);
        printf ("Cheie inserata la locatia %d \n", j);
        printf ("Introduceti numere pana la citirea lui 0:");
        scanf ("%d", &key);
    }

    HASH_PRINT (T, m);
    printf ("\n");

    printf ("Cautare cheie cu valoarea: ");
    scanf ("%d", &key);
    j = HASH_SEARCH (T, key, m);
    if (j > -1)
        printf ("Cheie gasita la locatia %d \n", j);
    else printf ("Cheia nu a fost gasita. \n");

    printf ("Stergere cheie: ");
    scanf ("%d", &key);
    j = HASH_DELETE (T, key, m);
    if (j > -1)
        {
            printf ("Cheie stearsa de la locatia %d \n", j);
            HASH_PRINT (T, m);
        }
    else printf ("Cheia nu a fost stearsa! \n");




}
