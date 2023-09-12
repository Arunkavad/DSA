#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{

    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->left = NULL;
    n->height = 1;

    return n;
}

int getbalancefac(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rRotate(struct node *y)
{

    struct node *x = y->left;
    struct node *t2 = x->left;

    x->right = y;
    y->left = t2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    return x;
}

struct node *lRotate(struct node *x)
{

    struct node *y = x->right;
    struct node *t2 = y->right;

    y->left = x;
    x->right = t2;

    y->height = max(getheight(y->right), getheight(y->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return (createnode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;

    node->height = 1+ max(getheight(node->left),getheight(node->right)); 
    int bf = getbalancefac(node);
}

int main()
{

    return 0;
}