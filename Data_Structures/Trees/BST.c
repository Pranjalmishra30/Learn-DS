//Binary Search Tree (BST) implementation
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* CreateNode(int X){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = X;
    temp->left=temp->right=NULL;
    return temp;
}

int Search(struct node* root,int key){
    if(root==NULL){
        return -1;
    }

    if (key == root->data)
        return 1;
    else if (key < root->data)
        Search(root->left,key);
    else
        Search(root->right,key);
}

struct node* Insert(struct node* NODE,int X){
    if (NODE == NULL){// if tree is empty
        return CreateNode(X);
    }

    if(X < NODE->data){
        NODE->left = Insert(NODE->left,X);
    }
    else if (X > NODE->data){
        NODE->right = Insert(NODE->right,X);
    } 
    else
        printf("Duplicate key not allowed");
    
    return NODE;
}

void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    int x,A=1;
    printf("Enter root: ");
    scanf("%d",&x);
    
    struct node* Root = NULL;
    Root = Insert(Root,x);
    
    printf("\nEnter Node values (-1 to exit)\n");
    while(1){
        printf("Enter node: ");
        scanf("%d",&A);
        if(A==-1)
            break;
        Insert(Root,A);
    }
    int key = 10; // Key to be searched
    printf("%d\n",Search(Root,key)); 

    return 0;
}




