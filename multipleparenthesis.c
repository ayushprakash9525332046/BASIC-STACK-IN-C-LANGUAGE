#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
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
        printf("overflow condition :");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("underflow condition:");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int match(char a,char b){
    if(a=='('&&b==')'){
        return 1;
    }
     if(a=='{'&&b=='}'){
        return 1;
    }
     if(a=='['&&b==']'){
        return 1;
    } 
    return 0;
}
int parenthesis(char *exp){
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++){

        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isempty(sp)){
                return 0;
            }
            int popped=pop(sp);
            if(!match(popped,exp[i])){
                return 0;
            }
        }
    }
    if(isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char *exp="{[(3+4)]}+[(5+9)]";
    if(parenthesis(exp)){
        printf("the stack is paranthesisis:");
    }
    else{
        printf("the stack is not paranthesis:");
    }
    return 0;

}