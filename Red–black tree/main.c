#include <stdio.h>
#include <stdlib.h>
#include "rb_arbore.h"

int main()
{
    int x;
    t_rb_arbore T;
    t_rb_node *r, *n;
    printf ("Radacina arborelui= ");
    scanf ("%d", &x);
    printf ("\n");

    r = MAKE_ROOT (&T, x);

    printf ("Introduceti elemente pana la citirea lui 0: \n");
    printf ("x= ");
    scanf ("%d", &x);
    printf ("\n");

    while (x != 0)
    {
        n = CREATE_NODE (x);
        RB_INSERT (&T, n);
        printf ("Introduceti elemente pana la citirea lui 0: \n");
        printf ("x= ");
        scanf ("%d", &x);
        printf ("\n");
    }
    printf ("\n");
    printf("IN-order walk: \n");
    INORDER_WALK(T.root);
    printf ("\n");

    printf ("\n");
    printf ("Cautare nod cu cheia x= ");
    scanf ("%d", &x);
    n = TREE_SEARCH (T.root, x);
    if (n != NULL)
        printf ("Nodul cu cheia %d a fost gasit!", n->key);
    else printf ("EROARE! Nodul nu a fost gasit!");
}
