#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
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
    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 55;
    s->top++;

    s->arr[1] = 67;
    s->top++;
    
    s->arr[2] = 78;
    s->top++;
    
    s->arr[3] = 80;
    s->top++;
    
    s->arr[4] = 90;
    s->top++;

    if (isempty(s))
        printf("the stack is empty\n");
    else
        printf("the stack is not empty\n");
    if (isfull(s))
        printf("stack is full\n");
    else
        printf("stack is not full\n");
}