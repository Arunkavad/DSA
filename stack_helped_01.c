#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *st, int val)
{
    if (isFull(st))
    {
        printf("can not able to push");
    }

    else
    {
        st->top++;
        st->arr[st->top] = val;
    }
}

int pop(struct stack *st)
{
    int a;

    if (isEmpty(st))
    {
        printf("Can not able to pop");
    }

    else
    {
        st->top--;
        return st->arr[st->top];
    }
}

int peep(struct stack *st, int p)
{

    if (st->top - p + 1 < 0)
    {
        printf("not valid \n");
        return -1;
    }

    else
    {
        return st->arr[st->top - p + 1];
    }
}

int change(struct stack *st, int p, int element)
{

    if (st->top - p + 1 < 0)
    {
        printf("not valid \n");
        return -1;
    }

    else
    {
        return st->arr[st->top - p + 1] = element;
    }
}

int display(struct stack *st)
{
    if (st->top >= -1)
    {
        printf("ELEMENTS \n");

        for (int i = st->top; i > -1; i--)
        {
            printf("%d \n", st->arr[i]);
        }
    }
    else
    {
        printf("EMPTY");
    }
}

int main()
{
    int p;
    int element;

    struct stack st;

    st.top = -1;
    st.size = 5;
    st.arr = (int *)malloc(sizeof(int) * st.size);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);

    display(&st);

    printf("ENTER THE POSITION \n");
    scanf("%d", &p);

    printf("ENTER THE VALUE WHICH YOU WANT TO CHANGE \n");
    scanf("%d", &element);

    change(&st, p, element);

    display(&st);

    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);
    // pop(&st);

    // printf("value at index %d is %d\n", st.top - p + 1, peep(&st, p));

    // printf("Top is %d \n", st.top);

    // if (isEmpty(&st))
    // {
    //     printf("finally stack is empty \n");
    // }

    // if (isFull(&st))
    // {
    //     printf("finally stack overflow \n");
    // }

    return 0;
}
