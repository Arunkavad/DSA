#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int size;
    int rear;
    int front;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->rear == ptr->front)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *ptr)
{
    if ((ptr->rear + 1) % ptr->size == ptr->front)
    {
        return 1;
    }
    return 0;
}

void EnQueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arr[ptr->rear] = val;
        printf("ENQUED : %d\n\n", val);
    }
}

int DeQueue(struct queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("THE QUEUE IS EMPTY\n");
    }
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size;
        a = ptr->arr[ptr->front];
    }
    return a;
}

void display(struct queue *q)
{

    if (q->rear == q->front)
    {
        printf("THE QUEUE IS EMPTY\n");
    }
    else
    {
        for (int i = q->front+1; i <= q->rear; i++)
        {
            printf("%d\t", q->arr[i]);
        }
    }
}

int main()
{
    struct queue q;
    q.size = 5;
    q.front = -1;
    q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int ch, element;

    while (1)
    {

        printf("\n\nName : KAVAD ARUN\nEnroll : 210210116005\n\n");

        printf("MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &ch);
        int count;
        switch (ch)
        {
        case 1:
            printf("ENTER HOW MANY VALUES YOU WANT TO ENQUEUE : ");
            scanf("%d", &count);
            for (int i = 1; i <= count; i++)
            {
                printf("ENTER THE %d ELEMENT : ", i);
                scanf("%d", &element);
                EnQueue(&q, element);
            }

            break;
        case 2:
            printf("ENTER HOW MANY ELEMENTS YOU WANT TO DEQUEUE : ");
            scanf("%d", &count);

            for (int i = 1; i <= count; i++)
            {
                printf("DEQUEUED ELEMENTS ARE : %d\n", DeQueue(&q));
            }
            break;

        case 3:
            printf("\nTHE QUEUE IS \n");
            display(&q);

            break;

        case 4:
            exit(1);

        default:
            printf("INVALID CHOIS");
            break;
        }
    }
    return 0;
}