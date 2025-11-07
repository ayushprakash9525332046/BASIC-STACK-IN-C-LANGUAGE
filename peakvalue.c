#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
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
void push(struct stack *ptr, int value)
{
    if (ptr->size == ptr->top - 1)
    {
        printf("%d is over flow", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("The stack in empty");
    }
    else
    {
        int x = ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
}
int peek(struct stack *ptr, int i)
{
    int arrays = ptr->top - i + 1;
    if (arrays < 0)
    {
        printf("stack is empty");
    }
    else
    {
        return ptr->arr[arrays];
    }
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("%d\n", isfull(s));
    printf("%d\n", isempty(s));
    push(s, 45);
    push(s, 55);
    push(s, 65);
    push(s, 77);
    push(s, 88);
    printf("%d is popped \n", pop(s));
    for (int j = 0; j < s->top + 1; j++)
    {
        printf("%d is position of %d\n", j, peek(s, j));
    }
    printf("%d is stacktop\n ", stacktop(s));
    printf("%d is stackbottom\n", stackbottom(s));
    return 0;
}