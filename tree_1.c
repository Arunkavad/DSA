#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
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
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main()
{
    // root node(1st node)
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);
    struct node *p5 = createnode(15);

    p->left = p1;
    p->right = p2;
    p1->left = p4;
    p1->right = p3;
    p3->right=p5;

//           p=4
//         /    \
//       p1=1   p2=6
//     /    \
//  p4=2    p3=5
//           /  \
//        null     p5=15

    return 0;
}
