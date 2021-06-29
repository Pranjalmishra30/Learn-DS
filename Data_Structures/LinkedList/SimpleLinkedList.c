#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* CreateNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void DisplayLinkedList(struct Node* Head){
    while(Head!=NULL){
        printf("%d ",Head->data);
        Head = Head->next;
    }
}

int main(){
    struct Node* Head = CreateNode(10);
    struct Node* First = CreateNode(20);
    struct Node* Second = CreateNode(35);
    Head->next = First;
    First->next = Second;
   
    DisplayLinkedList(Head);
}
