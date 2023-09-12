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

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    struct stack *s;
    s->size = 3;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    s->arr[0]=7;
    s->top++; 
    
    s->arr[0]=8;
    s->top++; 
    
    s->arr[0]=9;
    s->top++; 
 
    if (isFull(s))
    {
        printf("the stack is full\n");
    }
    else{
        printf("the stack is not full\n");
    }

    return 0;
}