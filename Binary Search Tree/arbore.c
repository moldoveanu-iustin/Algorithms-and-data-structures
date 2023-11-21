#include <stdlib.h>
#include <stdio.h>
#include "arbore.h"

t_nod_arb* MAKE_ROOT (t_arbore *T, int key)
{
    T->root = malloc (sizeof(t_nod_arb));
    T->root->key = key;
    T->root->left = NULL;
    T->root->right = NULL;
    T->root->parent = NULL;
    return T->root;
}

t_nod_arb* CREATE_NODE (int key)
{
    t_nod_arb *n;
    n = malloc (sizeof(t_nod_arb));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

void TREE_INSERT (t_arbore *T, t_nod_arb *n)
{
    t_nod_arb *y, *x;
    y = NULL;
    x = T->root;
    while (x != NULL)
    {
        y = x;
        if (n->key < x->key)
            {
                x = x->left;
            }

        else
        {
            x = x->right;
        }
    }
    n->parent = y;
    if (y == NULL)
        {
            T->root = n;
        }
    else
    {
        if (n->key < y->key)
            {
                y->left = n;
            }
        else
        {
            y->right = n;
        }
    }
}

void INORDER_WALK (t_nod_arb *root)
{
    if (root != NULL)
    {
        INORDER_WALK (root->left);
        printf ("%d ", root->key);
        INORDER_WALK (root->right);
    }
}

void PREORDER_WALK (t_nod_arb *root)
{
    if (root != NULL)
    {
        printf ("%d ", root->key);
        PREORDER_WALK (root->left);
        PREORDER_WALK (root->right);
    }
}

void POSTORDER_WALK (t_nod_arb *root)
{
    if (root != NULL)
    {
        POSTORDER_WALK (root->left);
        POSTORDER_WALK (root->right);
        printf ("%d ", root->key);
    }
}

t_nod_arb* IT_TREE_SEARCH (t_nod_arb *n, int key)
{
    while (n != NULL && key != n->key)
    {
        if (key < n->key)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }
    return n;
}

t_nod_arb* TREE_SEARCH (t_nod_arb *n, int key)
{
    if (n == NULL || key == n->key)
    {
        return n;
    }

    if (key < n->key)
    {
        return TREE_SEARCH (n->left, key);
    }
    else
    {
        return TREE_SEARCH (n->right, key);
    }
}

t_nod_arb* TREE_MIN (t_nod_arb *n)
{
    while (n->left != NULL)
        n = n->left;
    return n;
}

t_nod_arb* TREE_MAX (t_nod_arb *n)
{
    while (n->right != NULL)
        n = n->right;
    return n;
}

t_nod_arb* TREE_SUCCESOR (t_nod_arb *n)
{
    t_nod_arb *y;
    if ( n->right != NULL)
    {
        return TREE_MIN (n->right);
    }
    y = n->parent;
    while (y != NULL && n == y->right)
    {
        n = y;
        y = y->parent;
    }
    return y;
}

void TRANSPLANT (t_arbore *T, t_nod_arb *u, t_nod_arb *v)
{
    if (u->parent == NULL)
        T->root = v;
    else if (u == u->parent->left)
            u->parent->left = v;
            else u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

void TREE_DELETE (t_arbore *T, t_nod_arb *n)
{
    t_nod_arb *y;
    if (n->left == NULL)
    {
        TRANSPLANT (&T, n, n->right);
    }
    else
    {
        if (n->right == NULL)
        {
            TRANSPLANT (&T, n, n->left);
        }
        else
        {
            y = TREE_MIN (n->right);
            if (y->parent != n)
            {
                TRANSPLANT (&T, y, y->right);
                y->right = n->right;
                y->right->parent = y;
            }
        }
    }
}


