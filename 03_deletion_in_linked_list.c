#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deletAtfirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtindex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

struct Node *deletelastNode(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node *deletevalue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    if (p->data == value)
    {
        head = q;
        free(p);
    }
    else
    {

        while (q->data != value && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        if (q->data == value)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            printf("value doesn't exist in this linked list\n");
        }
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;
    struct Node *eighth;
    struct Node *ninth;
    struct Node *tenth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    eighth = (struct Node *)malloc(sizeof(struct Node));
    ninth = (struct Node *)malloc(sizeof(struct Node));
    tenth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = fifth;

    fifth->data = 11;
    fifth->next = sixth;

    sixth->data = 21;
    sixth->next = seventh;

    seventh->data = 35;
    seventh->next = eighth;

    eighth->data = 78;
    eighth->next = ninth;

    ninth->data = 98;
    ninth->next = tenth;

    tenth->data = 69;
    tenth->next = NULL;
    // printf("linked list before deletion\n");
    // linkedlisttraversal(head);

    // head = deletAtfirst(head);

    // printf("linked list after deletion of fisrt node \n");
    // linkedlisttraversal(head);

    // head = deleteAtindex(head, 2);

    // printf("linked list after deletion at index \n");
    // linkedlisttraversal(head);

    // head = deletelastNode(head);

    // printf("linked list after deletion of last node\n");
    // linkedlisttraversal(head);

    printf("linked list after deletion of given value\n");
    head = deletevalue(head, 3);
    linkedlisttraversal(head);

    return 0;
}