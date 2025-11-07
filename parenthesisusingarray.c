#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr, int value)
{
    if ((isfull(ptr)))
    {
        printf("overflow condition :");
    }
    else
    {
        ptr->top++;
        value = ptr->arr[ptr->top];
    }
}
char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("underflow condition:");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int paranthesis(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {

            if (isempty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isempty(sp))
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
    char *exp = "(8+4)+(5+6";
    if (paranthesis(exp))
    {
        printf("thr character is paranthesis:");
    }
    else
    {
        printf("the character is not paranthesis:");
    }
    return 0;
}
