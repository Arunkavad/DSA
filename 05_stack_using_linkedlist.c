#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{

    int data;
    struct node *next;
};
struct node *top = NULL;
int isEmpty(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *ptr)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *ptr, int x)
{

    if (isFull(ptr))
    {
        printf("Stack is overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = ptr;
        ptr = n;
        return ptr;
    }
}
int pop(struct node* t){
    if (isEmpty(t))
    {
        printf("Stack is underflow\n");
    }
    else
    {
        struct node* n = t;
        top = t->next;
        int x =n->data;
        free (n);
        return x;
        
    }
}

int peek(int x ){
    struct node * ptr=top;
    for ( int i = 0; (i < x-1&&ptr!=NULL); i++)
    {
       ptr=ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }    
}

void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    

    printf("status is %d\n",isEmpty(top));
    top = push(top, 78);
    top = push(top, 79);
    top = push(top, 80);
    top = push(top, 81);
    // int x = pop(top);
    // printf("popped element is %d\n", x);
    linkedlisttraversal(top);
    for (int i = 1; i <= 4; i++)
    {
        printf("value at %d is : %d\n",i,peek(i));
    }
    
    return 0;
}