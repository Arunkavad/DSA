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

void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        printf("stack is overflow! can not push %d to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack is underflow! can not pop from the stack\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int i)
{
    int ak = ptr->top - i + 1;
    if (ak < 0)
    {
        printf("not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[ak];
    }
}
int isempty(struct stack *ptr)
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
int isfull(struct stack *ptr)
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
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created succesfully\n");
    printf("before pushing %d\n", isfull(sp));
    printf("before pushing %d\n\n", isempty(sp));

    push(sp, 2);
    push(sp, 27);
    push(sp, 22);
    push(sp, 2);
    push(sp, 29);
    push(sp, 23);
    push(sp, 25);
    push(sp, 2);
    push(sp, 20);
    push(sp, 78);
    push(sp, 651);
    push(sp, 41);
    push(sp, 79);
    push(sp, 321); 
   
   
    printf("\after pushing%d\n", isfull(sp));
    printf("after pushing %d\n", isempty(sp));
    printf("popped %d from the stack \n", pop(sp));
    printf("popped %d from the stack \n", pop(sp));
    printf("popped %d from the stack \n", pop(sp));
   printf("\n");
   for (int j = 1; j < sp->top+2 ; j++)
   {
        printf("the value at position %d is %d\n", j, peek(sp,j));
   }
 
    return 0;}
