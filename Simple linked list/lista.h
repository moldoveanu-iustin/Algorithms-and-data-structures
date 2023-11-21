#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct nod_lista{
    int cheie;
    struct nod_lista *next;
}t_nod_lista;

typedef struct {
    t_nod_lista *head;
}t_lista;

#endif // LISTA_H_INCLUDED
