#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr,int value){
   if(isfull(ptr)){
    printf("overflow the stack cannot be push %d\n",value);
 }  
 else{
    ptr->top++;
    ptr->arr[ptr->top]=value;
 }
}
int  pop(struct stack *ptr){
    if (isempty(ptr)){
        printf("the stck is empty");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
void print(struct stack *ptr){
    if (isempty(ptr)){
        printf("the array is empty:");
    }
    else{
        for(int i=ptr->top;i>=0;i--){
            printf("element :%d\n",ptr->arr[i]);
        }
    }
}
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=8;
    s->top=-1;
    s->arr=(int *)malloc(s->size *sizeof(int));
    printf("%d\n",isfull(s));
    printf("%d\n",isempty(s));
    push(s,34);
    push(s,45);
    push(s,54);
    push(s,63);
    push(s,71);
    push(s,82);
    push(s,88);
    push(s,89);
    printf("%d\n",isfull(s));
    printf("%d\n",isempty(s));
    print(s);
    printf("pooped %d in the stack\n",pop(s));
    print(s);    
    return 0;
}