// Simple Stack implementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct STACK{
    int *arr;
    int top;
    int size;
};

struct STACK* CreateStack(int capacity){
    struct STACK* S = (struct STACK*)malloc(sizeof(struct STACK));
    S->size = capacity;
    S->top=-1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    return S;
}

bool isFull(struct STACK* S){
    if(S->top == S->size-1)
        return true;
    return false;
}

bool isEmpty(struct STACK* S){
    if(S->top==-1)
        return true;
    return false;
}

void Push(struct STACK* S,int data){
    if(isFull(S))
        printf("Stack is Full\n");
    else
        S->arr[++S->top]=data;
}

int pop(struct STACK* S){
    if(isEmpty(S)){
        printf("Stack is empty\n");
        return -1;
    }
    else
        return S->arr[S->top--];
}

void display(struct STACK* S){
    if(isEmpty(S))
        printf("Stack is empty, Can't be displayed\n");
    else{
        for(int i=S->top;i>-1;i--){
            printf("%d\n",S->arr[i]);
        }
    }
}
int main(){
    int n = 4;
    struct STACK* S = CreateStack(n);
    int x = pop(S);
    Push(S,4);
    Push(S,7);
    Push(S,8);
    Push(S,9);
    display(S);
    Push(S,10);
    
    return 0;
}