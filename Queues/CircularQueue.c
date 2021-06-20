#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct CQUEUE {
    int front,rear;
    int size;
    int *arr;
};

struct CQUEUE * CreateCqueue(int capacity){
    struct CQUEUE * temp = (struct CQUEUE*)malloc(sizeof(struct CQUEUE));
    temp->size = capacity;
    temp->front=temp->rear=-1;
    temp->arr = (int *)malloc(temp->size*sizeof(int));
    return temp;
}

bool isEmpty(struct CQUEUE* CQ){
    if(CQ->front == -1)
        return true;
    return false;
}

bool isFull(struct CQUEUE* CQ){
    if( (CQ->front == (CQ->rear + 1)) || (CQ->front==0 && CQ->rear == CQ->size - 1) ) // Another approach is to use (rear+1)%size in the first condition
        return true;
    return false;
}

void Enqueue(struct CQUEUE* CQ,int data){
    if(isFull(CQ))
        printf("Queue is full\n");
    else{
        if(isEmpty(CQ))
            CQ->front=0;
        CQ->rear=(CQ->rear+1)%(CQ->size);
        CQ->arr[CQ->rear] = data;
    }
}

int Dequeue(struct CQUEUE* CQ){
    if(isEmpty(CQ)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int x = CQ->arr[CQ->front];
        if(CQ->front == CQ->rear)
            CQ->front = CQ->rear = -1;
        else
            CQ->front = (CQ->front+1)%(CQ->size);
        return x;
    }
}

void display(struct CQUEUE* CQ){
    int i;
    if(isEmpty(CQ))
        printf("Queue is empty\n");
    
    else{
        for(i=CQ->front; i!=CQ->rear; i=(i+1)%(CQ->size)){
            printf("%d ",CQ->arr[i]);
        }
        printf("%d",CQ->arr[i]);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter Queue size\n");
    scanf("%d", &n);
    struct CQUEUE* myQ = CreateCqueue(n);
    
    // Testing the Circular Queue
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
    display(myQ);
    
    return 0;
}