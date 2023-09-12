#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal in linkedlist
void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// function for insertion at FIRST
struct Node *insertAtfirst(struct Node *head, int ndata)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = ndata;
    return ptr;
}

// function for insertion at END
struct Node *insertAtend(struct Node *head, int ndata)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;

    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    ptr->data = ndata;
    return head;
}

//function for insertion at GIVEN INDEX
struct Node *insertAtindex(struct Node *head, int ndata, int index)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = ndata;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// function for insertion after A GIVEN NODE
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int ndata)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = ndata;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printf("\n");
    printf("LL before insertion\n");
    linkedlisttraversal(head);
    printf("\n");

    head = insertAtfirst(head, 56);
    printf("LL after insertion at first\n");
    linkedlisttraversal(head);
    printf("\n");

    head = insertAtindex(head, 10, 2);
    printf("LL after insertion at index\n");
    linkedlisttraversal(head);
    printf("\n");

    head = insertAtend(head, 18);
    printf("LL after insertion at end\n");
    linkedlisttraversal(head);

    head = insertAfterNode(head, third, 27);
    printf("LL after insertion after a given node\n");
    linkedlisttraversal(head);

    return 0;
}