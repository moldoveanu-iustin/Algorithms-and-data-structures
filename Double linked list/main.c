#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
    t_lista L;
    t_nod_lista* x;
    MAKENULL(&L);
    int key;
    int s=-1;

    while (s!=0)
    {
        printf("Selecteaza optiune: \n");
        printf("1.Inserare nod\n");
        printf("2.Cautare nod\n");
        printf("3.Stergere nod\n");
        printf("4.Afisare lista\n");

        scanf("%d", &s);
        switch (s)
        {
            case 1:  //INSERARE NOD
            {
                printf("Inserare nod cu cheia: \n");
                scanf("%d", &key);
                x = malloc(sizeof (t_nod_lista));
                x->cheie = key;
                LIST_INSERT(&L, x);
                break;
            }
            case 2:  //CAUTARE NOD
            {
                printf("Cauta nod-ul cu cheia: \n");
                scanf("%d", &key);
                x = LIST_SEARCH(L, key);
                if(x!=NULL)
                    printf("Nodul cu cheia %d a fost gasit \n", x->cheie);
                else printf("Cheie negasita\n");
                break;
            }
            case 3:  //STERGERE NOD
            {
                printf("Sterge nod-ul cu cheia:\n");
                scanf("%d", &key);
                x = LIST_SEARCH(L, key);
                if(x != NULL)
                {
                    LIST_DELETE(&L, x);
                    printf("Nodul cu cheia %d a fost sters \n", key);
                }
                else printf("Cheie negasita\n");
                break;
            }
            case 4:  //AFISARE LISTA
            {
                LIST_PRINT(L);
                printf("\n");
                break;
            }
            default: //OPTIUNE INVALIDA (!= 1,2,3,4)
            {
                printf("Optiune invalida!!!\n");
                break;
            }
        }
    }
    LIST_FREE(&L);
    return 0;
}
