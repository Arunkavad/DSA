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
       return 1;
    }
    return 0;
}

 void insert_queue(struct  queue* ptr, int value){

    if (isFull(ptr))
    {
        printf("This Queue is OverFlow\n");
    }
     
    if(ptr->front==-1){
    ptr->front++;}

    while (ptr->rear>=0 && value<ptr->arr[ptr->rear])
    {
        ptr->arr[ptr->rear+1]=ptr->arr[ptr->rear];
        ptr->rear--;
    }
    ptr->arr[ptr->rear+1]=value;
    ptr->rear++;

 }

 void display(struct queue *ptr){

    printf("the queue is : \n");
if(!isEmpty(ptr)){
    for (int i = 0; i <= ptr->rear; i++)
    {
        printf("%d ",ptr->arr[ptr->front]);
    }
    }
    else
    {
        printf("the queue is empty\n");
    }
    
    
 }
int main()
{

struct queue *q;
    q->size = 100;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));


    insert_queue(q,32);
    insert_queue(q,33);
    
    display(q);
    
    return 0;
}