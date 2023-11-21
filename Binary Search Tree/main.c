#include <stdio.h>
#include <stdlib.h>
#include "arbore.h"

int main()
{
    t_arbore T;
    t_nod_arb *n, *r, *s;
    int x;
    printf ("Nodul radacina cu cheia x= ");
    scanf ("%d", &x);
    r = MAKE_ROOT (&T, x);
    printf("\n");

    //INSERARE ELEMENTE

    printf("Introduceti x pana la citirea lui 0: \n");
    printf("x= ");
    scanf ("%d", &x);
    while (x != 0)
    {
        n = CREATE_NODE (x);
        TREE_INSERT (&T, n);
        printf("Introduceti x pana la citirea lui 0: \n");
        printf("x= ");
        scanf ("%d", &x);
    }
    printf("\n");

    //INORDER WALK

    printf ("IN-ORDER walk: \n");
    INORDER_WALK (r);
    printf("\n");

    //PREORDER WALK

    printf ("PRE-ORDER walk: \n");
    PREORDER_WALK (r);
    printf("\n");

    //POSTORDER WALK

    printf ("POST-ORDER walk: \n");
    POSTORDER_WALK (r);
    printf("\n");

    // CAUTARE NOD

    printf("\n");
    printf ("Cautare nod cu cheia x= ");
    scanf ("%d", &x);
    //CAUTARE ITERATIVA
    n = IT_TREE_SEARCH (r, x);
    if (n != NULL )
        printf ("Nodul cu cheia %d a fost gasit ITERATIV! \n", n->key);
    else printf ("EROARE! Nodul nu a fost gasit ITERATIV! \n");

    //CAUTARE RECURSIVA
    n = TREE_SEARCH (r, x);
    if (n != NULL )
        printf ("Nodul cu cheia %d a fost gasit RECURSIV! \n", n->key);
    else printf ("EROARE! Nodul nu a fost gasit RECURSIV! \n");
    printf("\n");

    //MINIMUL ARBORELUI

     n= TREE_MIN (r);
     printf ("Tree minimum: %d", n->key);
     printf("\n");


    //MAXIMUL ARBORELUI

     n= TREE_MAX (r);
     printf ("Tree maximum: %d", n->key);
     printf("\n");


    //SUCCESORUL

    printf("\n");
    printf ("Succesorul lui x= ");
    scanf ("%d", &x);
    n = TREE_SEARCH (r, x);
    s = TREE_SUCCESOR (n);
    if (s != NULL)
        printf ("Nod succesor: %d \n", s->key);
    else printf ("Nodul introdus nu are succesor!");


    //STERGERE NOD

    printf("\n");
    printf ("Stergere nod cu cheia x= ");
    scanf ("%d", &x);
    n = TREE_SEARCH (r, x);
    if (n != NULL)
    {
        TREE_DELETE (&T, n);
        printf ("Nod sters! \n");
        INORDER_WALK (r);
    }
    else printf ("\n EROARE! Nodul nu a fost gasit!");
}

