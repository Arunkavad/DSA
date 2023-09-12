#include <stdio.h>
#include <stdlib.h>

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
        // printf("empty\n");
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

int main()
{
    struct queue q;
    q.size = 400;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS implimentation
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
        };

    printf("%d", i);
    visited[i] = 1;
    EnQueue(&q, i);

    while (!isEmpty(&q))
    {
        int node = DeQueue(&q);

        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j); 
                visited[j]=1;
                EnQueue(&q,j);
            }
        }
    }

    return 0;
}