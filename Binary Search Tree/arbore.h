#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

typedef struct nod_arb {
    int key;
    struct nod_arb *left, *right, *parent;
} t_nod_arb;

typedef struct {
    t_nod_arb *root;
} t_arbore;

#endif // ARBORE_H_INCLUDED
