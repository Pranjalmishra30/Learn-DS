#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct QUEUE{
    int front,rear;
    int size;
    int* arr;
};

struct QUEUE * CreateQ(int capacity){
    struct QUEUE * temp = (struct QUEUE*)malloc(sizeof(struct QUEUE));
    temp->size=capacity;
    temp->front=temp->rear=-1;
    temp->arr = (int *)malloc(temp->size*sizeof(int));
    return temp;
}

bool isEmpty(struct QUEUE* Q){
    if(Q->front == -1)
        return true;
    return false;
}

bool isFull(struct QUEUE* Q){
    if(Q->rear == Q->size - 1)
        return true;
    return false;
}

void Enqueue (struct QUEUE* Q,int data){
    if(isFull(Q))
        printf("Queue is full\n");
    else{
        if(isEmpty(Q))
            Q->front=0;
        Q->rear++;
        Q->arr[Q->rear] = data;
    }
}

int Dequeue (struct QUEUE* Q){
    if(isEmpty(Q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int x = Q->arr[Q->front];
        Q->front++;
        if(Q->front > Q->rear) // Reseting Queue
            Q->front=Q->rear=-1;
        return x;
    }
}

void display(struct QUEUE* Q){
    if(isEmpty(Q))
        printf("Queue is empty\n");
    else{
        for(int i=Q->front;i<=Q->rear;i++){
            printf("%d ",Q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter Queue size\n");
    scanf("%d", &n);
    struct QUEUE* myQ = CreateQ(n);
    
    // Testing the Queue
    Dequeue(myQ);
    Enqueue(myQ,7);
    Enqueue(myQ,8);
    display(myQ);
    Enqueue(myQ,10);
    Enqueue(myQ,12);
    display(myQ);
    Enqueue(myQ,1);
    printf("Dequeue'd %d\n",Dequeue(myQ));
    printf("Dequeue'd %d\n",Dequeue(myQ));
    Enqueue(myQ,18);

    return 0;
}