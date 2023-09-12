#include <stdio.h>
#include <stdlib.h>


// structure for representation of stack using array
struct stack
{
    int size;
    int top;
    int *arr;
};

// function for checking the stack is empty or not
int isEmpty(struct stack *ptr){

    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function for checking the stack is full or not
int isFull(struct stack *ptr){
    
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

// function for pushing values into the stack
void push(struct stack *ptr, int val){
    
    if (isFull(ptr) == 1){
        printf("the stack is over flow ,can not push value\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Function  for popping the values from the stack
int pop(struct stack *ptr){
    
    if (isEmpty(ptr)){
        printf("the stack is empty , can not pop value\n");
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}

// function for peeking the values from the stack
int peek(struct stack *ptr, int i){

    if (ptr->top - i + 1 < 0){
        printf("not a valid position\n");
        // return -1;
    }
    else{
        return ptr->arr[ptr->top - i + 1];
    }
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

    printf("popped value is : %d\n",pop(sp));

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("the value at position  % is %d\n", j, peek(sp, j));
    }

    return 0;
}