#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct nod_lista{
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;

typedef struct {
    t_nod_lista *head;
}t_lista;

#endif // LIST_H_INCLUDED
