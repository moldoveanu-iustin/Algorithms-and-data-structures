#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    t_lista L;
    t_nod_lista* x;
    MAKENULL(&L);
    int key;
    int s=-1;

    while (s!=0){
        printf("Selecteaza optiune: \n");
        printf("1.Inserare nod\n");
        printf("2.Cautare nod\n");
        printf("3.Stergere nod\n");
        printf("4.Afisare nod anterior:\n");
        printf("5.Afisare lista\n");

        scanf("%d", &s);
        switch (s) {
            case 1:{
                printf("Insereaza nod cu cheia: \n");
                scanf("%d", &key);
                x = malloc(sizeof (t_nod_lista));
                x->cheie = key;
                INSERT(&L, x);
                break;
            }
            case 2:{
                printf("Cauta nod-ul cu cheia: \n");
                scanf("%d", &key);
                x = RETRIEVE(L, key);
                if(x!=NULL){
                    printf("Nodul cu cheia %d a fost gasit \n", x->cheie);
                } else{
                    printf("Cheie negasita \n");
                }
                break;
            }
            case 3:{
                printf("Sterge nod-ul cu cheia: \n");
                scanf("%d", &key);
                x = RETRIEVE(L, key);
                if(x != NULL){
                    DELETE(&L, x);
                    printf("Nodul cu cheia %d a fost sters \n", key);
                } else{
                    printf("Cheie negasita \n");
                }
                break;
            }
            case 4:{
                printf("Cheia nodului dinaintea nodului cu cheia: \n");
                scanf("%d", &key);
                x = RETRIEVE(L, key);
                t_nod_lista* y = PREVIOUS(L, x);
                printf("%d \n", y->cheie);
                break;
            }
            case 5:{
                PRINTLIST(L);
                printf("\n");
                break;
            }
            default:{
                printf("Optiune invalida \n");
                break;
            }
        }
    }
    LIST_FREE(&L);
    return 0;
}
