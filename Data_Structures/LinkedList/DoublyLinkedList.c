#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* CreateNode(int x){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->next = NewNode->prev = NULL;
    return NewNode;
}

void InsertBeginning(struct Node** Headptr,int x){
    struct Node* NewNode = CreateNode(x);
    
    NewNode->prev = NULL;
    NewNode->next = (*Headptr);
    if(*Headptr !=NULL)
        (*Headptr)->prev = NewNode;
    (*Headptr) = NewNode;
}

void Append(struct Node** Headptr,int x){
    struct Node* NewNode = CreateNode(x);
    struct Node* Current = *Headptr;

    if(*Headptr==NULL){ // if LL is empty
        *Headptr = NewNode;
        return;
    }
    while(Current->next != NULL){
        Current = Current->next;
    }
    Current->next = NewNode;
    NewNode->prev = Current;
    return;
}

void DeleteNode(struct Node** Headptr,int key){
    struct Node* temp = *Headptr;

    if(temp!=NULL && temp->data == key){ // If node to be deleted is head
        *Headptr = temp->next;
        temp->prev = NULL;
        free(temp);
        return ;
    }

    while(temp!=NULL && temp->data !=key){
        temp=temp->next;
    }

    if(temp==NULL) // Node does not exist
        return;
    
    if (temp->next == NULL){ // Node to be deleted is last node
        (temp->prev)->next = NULL;
        free(temp);
        return;
    }

    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    free(temp);

}
void DisplayDLL(struct Node* Head){
    while(Head!=NULL){
        printf("%d ",Head->data);
        Head = Head->next; 
    }
    printf("\n");
}

int main(){
    struct Node* Head = NULL;
    Append(&Head,20);    
    InsertBeginning(&Head,10);
    Append(&Head,30);    
    DisplayDLL(Head);
    DisplayReverse(Head);
    
    int x;
    printf("Enter node to be deleted ");
    scanf("%d",&x);
    DeleteNode(&Head,x);
    DisplayDLL(Head);
}