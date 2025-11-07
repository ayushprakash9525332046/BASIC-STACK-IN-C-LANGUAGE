#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void linkedlistTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct node *top)
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
struct node *push(struct node *top, int x)
{
    if (isfull(top))
    {
        printf("stack is overflow");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int peek(int pos)
{
    struct node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stacktop(struct node *top)
{
    return top->data;
}
int stackbottom(struct node *ptr)
{
    struct node *k = ptr;
    while (k->next != NULL)

    {
        k = k->next;
    }
    return k->data;
}
int main()
{
    top = push(top, 45);
    top = push(top, 55);
    top = push(top, 65);
    top = push(top, 75);
    linkedlistTraversal(top);
    for (int i = 1; i < 5; i++)
    {
        printf("%d is at psition %d\n", i, peek(i));
    }
    printf("%d is the stack top data\n", stacktop(top));
    printf("%d is thr stack bottom", stackbottom(top));
}
