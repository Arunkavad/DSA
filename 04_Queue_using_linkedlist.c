#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    printf("printing the elements of linked list\n");

    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue(void)
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
        return val;
}

int main()
{
    traversal(f);
    printf("dequeueing element %d\n",dequeue());
    printf("dequeueing element %d\n",dequeue());
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    printf("dequeueing element %d\n",dequeue());
    
    traversal(f);
    
    return 0;
}