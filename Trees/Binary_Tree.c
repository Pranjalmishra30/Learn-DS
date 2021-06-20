// Binary tree implementation
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node)); // temporary node
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node* root = CreateNode(3);
    root->left = CreateNode(7);
    root->right = CreateNode(4);
    root->left->left = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(8);
    
    printf("PreOrder: ");
    preOrder(root);
    printf("\nInOrder: ");
    inOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
}