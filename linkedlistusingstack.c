#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
int isempty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *top)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void linkedlistTraversal(struct stack *ptr)
{
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct stack *push(struct stack *top, int data)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    if (n == NULL)
    {
        printf("overflow condition");
    }
    else
    {
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct stack *tp)
{
    if (tp == NULL)
    {
        printf("underflow condition");
    }
    else
    {
        struct stack *q = tp;
        top = tp->next;
        int x = q->data;
        free(q);
        return x;
    }
}
int main()
{

    top = push(top, 35);
    top = push(top, 45);
    top = push(top, 55);
    top = push(top, 65);
    linkedlistTraversal(top);
    printf("popped element:%d\n",pop(top));
    linkedlistTraversal(top);
    return 0;
}
