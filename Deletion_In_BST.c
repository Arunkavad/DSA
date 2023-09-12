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
        printf("\nNODE INSERTED\n");
    }
    else
    {
        prev->right = new;
        printf("\nNODE INSERTED\n");
    }
}

void InOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf(" %d ", root->data);
        InOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf(" %d ", root->data);
    }
}

void PreOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

struct node * inorderpredecessor(struct node* root){

    root =root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
 }

struct node* deletenode(struct node *root,int value){
    struct node* ipre;
    if (root==NULL)
    {
        return NULL;
    }
    if (root->left==NULL && root->right ==NULL)
    {
        free(root);
        return NULL;
    }
             
     if (value < root->data)
     {
        root->left = deletenode(root->left,value);
     }
     else if(value>root->data)
     {
       root->right= deletenode(root->right,value);
     }
     else
     {
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left,ipre->data);
     }  
     return root;   
}

int main()
{
    struct node *p = createnode(50);
    struct node *p1 = createnode(30);
    struct node *p2 = createnode(60);
    struct node *p3 = createnode(10);
    struct node *p4 = createnode(40);
    struct node *p5 = createnode(42);
    struct node *p6 = createnode(35);
    struct node *p7 = createnode(70);
    struct node *p8 = createnode(58);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->right = p5;
    p4->left = p6;
    p2->right =p7;
    p2->left =p8;

//        50
//       /  \
//      /    \
//     30     60
//     /\     / \
//    /  \   58 70
//   10  40     
//       / \ 
//      35  42 
    InOrderTraversal(p);
    printf("\n");
    deletenode(p,50);
    printf("\n");
    printf(" root data is : %d",p->data);
    return 0;
}