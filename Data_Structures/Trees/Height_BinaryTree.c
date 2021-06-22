/*
Height is the largest number of edges in a path from a leaf node to a target node.
An Empty tree has height -1 and a tree with a single node has height 0
*/

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return ((a>b)?a:b);
}

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
}

int Height(struct node* root){
    if(root == NULL)
        return -1;  
    
    int Lheight = Height(root->left);
    int Rheight = Height(root->right);

    return (max(Lheight,Rheight) + 1);
}

int main(){
    struct node* root = CreateNode(10);
    root->left = CreateNode(8);
    root->right = CreateNode(2);
    root->left->left = CreateNode(4);
    root->left->left->left = CreateNode(6);
    root->left->left->right = CreateNode(5);
    root->right->left = CreateNode(7);

    printf("Height of this Binary Tree is %d\n",Height(root));
    return 0;
}