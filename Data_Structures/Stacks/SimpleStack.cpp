#include<iostream>

using namespace std;

class SimpleStack{
    
    int top;
    int *arr;
    int size;

public:
    SimpleStack(int capacity){
        top = -1;
        size = capacity;
        arr = new int[size];
    }
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    void display();
};

bool SimpleStack:: isEmpty(){
    return (top<0);
}

bool SimpleStack:: isFull(){
    return (top == size-1);
}

void SimpleStack:: push(int x){
    if(isFull())
        printf("Stack is full\n");
    else{
        arr[++top] = x;
        printf("Pushed %d into the stack\n",x);
    }
}

int SimpleStack:: pop(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }    
    else{
       int data = arr[top];
       printf("Popped %d from the stack\n",data);
       return arr[top--];
    }
}

void SimpleStack:: display(){
    if(isEmpty())
        printf("Stack is empty\n");
    else{
        for(int i=top;i>-1;i--){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    SimpleStack Stack(3);
    Stack.pop();
    Stack.push(2);
    Stack.push(4);
    Stack.push(6);
    Stack.display();
    Stack.push(9);
    int a = Stack.pop();
    Stack.display();

}