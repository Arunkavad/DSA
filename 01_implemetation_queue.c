#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *ptr)
{

    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        printf("empty\n");
        return 1;
    }
    return 0;
}

void EnQueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("This Queue is OverFlow\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int DeQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("No Element to Deque\n");
    }
    else
    {
        q->front++;
    }
    return q->arr[q->front];
}

void display(struct queue * q)
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
    q.size = 100;
    q.front = -1;
    q.rear = -1;
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
                printf("ENTER THE %d ELEMENT : ",i);
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