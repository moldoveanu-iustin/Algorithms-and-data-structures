#include <stdio.h>
#include <stdlib.h>
#include "rb_arbore.h"

t_rb_node* MAKE_ROOT (t_rb_arbore *T, int key)
{
    T->root = malloc (sizeof(t_rb_node));
    T->root->key = key;
    T->root->left = NULL;
    T->root->right = NULL;
    T->root->parent = NULL;
    T->root->color = black;
    return T->root;
}

t_rb_node* CREATE_NODE (int key)
{
    t_rb_node *n;
    n = malloc (sizeof(t_rb_node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->color = black;
    return n;
}

//   INSERT

void RB_INSERT (t_rb_arbore *T, t_rb_node *z)
{
    t_rb_node *y = NULL;
    t_rb_node *x = T->root;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        {
        T->root = z;
        }
        else
            {
            if (z->key < y->key)
                {
                y->left = z;
                }
                else
                    {
                    y->right = z;
                    }
            }
    z->left = NULL;
    z->right = NULL;
    z->color = red;
    RB_INSERT_FIXUP (T, z);
}


//   INSERT FIX

void RB_INSERT_FIXUP (t_rb_arbore *T, t_rb_node *z)
{
    while (z->parent != NULL && z->parent->color == red)
    {

        if (z->parent == z->parent->parent->left)
        {
            t_rb_node *y = z->parent->parent->right;
            if (y != NULL && y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    LEFT_ROTATE (T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                RIGHT_ROTATE (T, z->parent->parent);
            }
        }

        else

        {
            t_rb_node *y = z->parent->parent->left;
            if (y != NULL && y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    RIGHT_ROTATE (T, z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                LEFT_ROTATE (T, z->parent->parent);
            }
        }
    }
    T->root->color = black;
}



//   ROTIRE STANGA

void LEFT_ROTATE (t_rb_arbore *T, t_rb_node *x)
{
    t_rb_node *y;
    y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent ==  NULL)
    {
        T->root = y;
    }
    else
    {
        if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else x->parent->right = y;
    }
    y->left= x;
    x->parent = y;
}


//   ROTIRE DREAPTA

void RIGHT_ROTATE (t_rb_arbore *T, t_rb_node *x)
{
    t_rb_node *y;
    y = x->left;
    x->left = y->right;
    if (y->right != NULL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent ==  NULL)
    {
        T->root = y;
    }
    else
    {
        if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else x->parent->right = y;
    }
    y->right= x;
    x->parent = y;
}


//   IN-ORDER WALK

void INORDER_WALK (t_rb_node *root)
{
    if (root != NULL)
    {
        INORDER_WALK (root->left);
        printf ("%d", root->key);
        if (root->color == black)
            printf ("[b] ");
        else printf ("[r] ");
        INORDER_WALK (root->right);
    }
}

//   CAUTARE

t_rb_node* TREE_SEARCH (t_rb_node *n, int key)
{
    if (n == NULL || key == n->key)
        return n;
    if (key < n->key)
        return TREE_SEARCH (n->left, key);
    else return TREE_SEARCH (n->right, key);
}
