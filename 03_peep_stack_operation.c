#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int size;
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
    int i;
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

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 11);
    push(sp, 12);
    push(sp, 13);
    push(sp, 14);
    push(sp, 15);

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("the value at position  % is %d\n", j, peek(sp, j));
    }

    return 0;
}