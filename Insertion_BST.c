#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct node *SearchNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return SearchNode(root->left, key);
    }
    else
    {
        return SearchNode(root->right, key);
    }
}

void Insert(struct node *root, int data)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (data == root->data)
        {
            printf(" data can not Insert\n");
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node* new = createnode(data);
    if (data < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{

    struct node *p = createnode(50);
    struct node *p1 = createnode(30);
    struct node *p2 = createnode(60);
    struct node *p3 = createnode(10);
    struct node *p4 = createnode(40);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

//        50
//       /  \
//      /    \
//     30     60
//     /\     / \
//    /  \   58 70
//   10  40     
//       / \ 
//      35  42 

    Insert(p, 58);
    Insert(p, 42);
    Insert(p, 35);
    Insert(p, 70);
    
    

    
    return 0;
}