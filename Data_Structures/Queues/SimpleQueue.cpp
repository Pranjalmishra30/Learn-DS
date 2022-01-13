#include<iostream>
using namespace std;

class Queue{
    int front,rear;
    int *arr;
    int size;
    
public:
    Queue(int capacity){
        front=rear=-1;
        size = capacity;
        arr = new int[size]; 
    }

    bool isEmpty();
    bool isFull();
    void enQueue(int x);
    int deQueue();
    void display();
};

bool Queue:: isEmpty(){
    return(front==-1);
}

bool Queue:: isFull(){
    return(rear == size-1);
}

void Queue:: enQueue(int x){
    if(isFull())
        printf("Queue is full\n");
    else{
        if(isEmpty())
            front=0;
        rear++;
        printf("Enqueued %d\n",x);
        arr[rear] = x;
    }
}

int Queue:: deQueue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int data = arr[front];
        printf("Dequeued %d\n",data);
        front++;
        if(front>rear)
            front=rear=-1;
        return data;
    }
}

void Queue:: display(){
    if(isEmpty())
        printf("Queue is empty\n");
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue Q(3);
    Q.deQueue();
    Q.enQueue(7);
    Q.enQueue(8);
    Q.enQueue(10);
    Q.display();
    Q.deQueue();
    Q.display();
}