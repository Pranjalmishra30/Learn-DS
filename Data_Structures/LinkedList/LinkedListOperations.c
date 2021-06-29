#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

// HeadPtr is a pointer to the pointer Head 
void InsertBeginning(struct Node** HeadPtr,int x){
    struct Node* NewNode = CreateNode(x);
    NewNode->next = *HeadPtr;
    *HeadPtr = NewNode;
}

void Append(struct Node** HeadPtr,int x){
    struct Node* NewNode = CreateNode(x);
    struct Node* Last = *HeadPtr;

    if(*HeadPtr==NULL){ // If LL is empty
        *HeadPtr = NewNode;
        return;
    }
    while(Last->next!=NULL){
        Last = Last->next;
    }
    Last->next = NewNode;
    return;
}

void DeleteNode(struct Node** HeadPtr,int key){
    struct Node* temp = *HeadPtr;
    struct Node* prev;

    // If Node to be deleted is head
    if(temp!=NULL && temp->data == key){
        *HeadPtr = temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data !=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) // Key not present
        return;

    prev->next = temp->next;
    free(temp);
}
bool Search(struct Node* Head,int key){
    while(Head!=NULL){
        if(key == Head->data)
            return true;
        Head = Head->next;
    }
    return false;
}

void DisplayLL(struct Node* Head){
    while(Head!=NULL){
        printf("%d ",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

int main(){
    struct Node* Head = NULL;    

    int x,ch=1;
    printf("----------------MENU-------------------\n");
    printf("1.Append\n2.Insert at Beginning\n3.Delete\n4.Search\n5.Display\n6.Exit\n\n");
    while(ch!=6){
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter data: ");
            scanf("%d",&x);
            Append(&Head,x);
        }

        else if(ch==2){
            printf("Enter data: ");
            scanf("%d",&x);
            InsertBeginning(&Head,x);
        }
        
        else if(ch==3){
            printf("Enter node to be deleted: ");
            scanf("%d",&x);
            DeleteNode(&Head,x);
        }

        else if(ch==4){
            printf("Enter key to be searched: ");
            scanf("%d",&x);
            if(Search(Head,x))
                printf("%d is found in the list\n",x);
            else
                printf("%d is not found in the list\n",x);

        }

        else if(ch==5){
            DisplayLL(Head);
        }
    }
}
