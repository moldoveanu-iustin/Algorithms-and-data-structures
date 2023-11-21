#ifndef TABELA_PRIN_INLANTUIRE_H_INCLUDED
#define TABELA_PRIN_INLANTUIRE_H_INCLUDED

typedef struct nod_lista{
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;

typedef struct lista {
    t_nod_lista *head;
}t_lista;

#endif // TABELA_PRIN_INLANTUIRE_H_INCLUDED
