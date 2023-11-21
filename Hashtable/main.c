#include <stdio.h>
#include <stdlib.h>
#include "tabela_prin_inlantuire.h"

int main()
{
    t_lista T[100];
    printf ("Functia de dispersie h(k)=k k mod m: \n");
    printf ("\n");

    int m;
    printf ("Introduceti lungimea tabelei de dispersie: ");
    scanf ("%d", &m); //lungimea  tabelei de dispersie
    printf ("\n");
    INIT_HASHTABLE (&T, m);

    printf ("Introduceti numere pana la citirea lui 0: ");
    int key;
    scanf ("%d", &key);
    printf ("\n");

    while (key != 0)   // INSERARE CHEI
    {
        int j = CHAINED_HASH_INSERT (&T, key, m);
        printf ("Tabela actualizata: \n");
        PRINT_HASHTABLE (T, m);
        printf ("\n");
        printf ("Introduceti urmatoarea cheie: ");
        scanf ("%d", &key);
        printf ("\n");

    }

    printf ("Cautare cheie: ");   // CAUTARE CHEIE
    scanf ("%d", &key);
    int j = CHAINED_HASH_SEARCH (T, key, m);
    if (j > -1)
        printf ("Cheia a fost gasita la locatia: %d \n", j);
    else printf ("EROARE! Cheia nu a fost gasita! \n");
    printf ("\n");


    printf ("Stergere cheie:");  // STERGERE CHEIE
    scanf ("%d", &key);
    j = CHAINED_HASH_DELETE (&T, key, m);
    if (j > -1)
        {
            printf ("Cheie stearsa de la locatia %d \n", j);
            printf ("Noua lista: ");
            PRINT_HASHTABLE (T, m);
        }
    else printf ("EROARE! Cheia nu a fost gasita!");


}
