#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{

    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr) == 1)
    {
        printf("the stack is over flow ,can not push value\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("the stack is empty , can not pop value\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}

int peek(struct stack *ptr, int i)
{

    if (ptr->top - i + 1 < 0)
    {
        printf("not a valid position\n");
        // return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}


int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 31);
    push(sp, 32);
    push(sp, 33);
    push(sp, 34);
    push(sp, 35);

    //int val = pop(sp);

    printf("the top value of the stack is %d\n",stackTop(sp));
    printf("the bottom value of the stack is %d\n",stackBottom(sp));

    return 0;
}