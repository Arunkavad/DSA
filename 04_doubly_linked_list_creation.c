#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// FORWARD TRAVERSAL IN DOUBLY LINKED LIST
void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// REVERSE TRAVERSAL IN DOUBLY LINKED LIST
void reversetraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct Node *n1;
    struct Node *n2;
    struct Node *n3;
    struct Node *n4;

    n1 = (struct Node *)malloc(sizeof(struct Node));
    n2 = (struct Node *)malloc(sizeof(struct Node));
    n3 = (struct Node *)malloc(sizeof(struct Node));
    n4 = (struct Node *)malloc(sizeof(struct Node));

    n1->data = 21;
    n1->next = n2;
    n1->prev = NULL;

    n2->data = 22;
    n2->next = n3;
    n2->prev = n1;

    n3->data = 23;
    n3->next = n4;
    n3->prev = n2;

    n4->data = 24;
    n4->next = NULL;
    n4->prev = n3;

    printf("Forward traversaled linked list\n");
    traversal(n1);

    printf("\n");
    printf("Reverse traversaled linked list\n");
    reversetraversal(n4);

    return 0;
}