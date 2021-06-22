// Diameter of a tree is the number of nodes on the longest path between 2 nodes in the tree
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
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
}

int height(struct node* root){
    if(root==NULL)
        return 0;
    int Lheight = height(root->left);
    int Rheight = height(root->right);

    return (max(Lheight,Rheight) + 1);

}

int diameter(struct node* root){
    if(root == NULL)
        return 0;
    
    int Lheight = height(root->left) ;
    int Rheight = height(root->right);

    int Ldiameter = diameter(root->left);
    int Rdiameter = diameter(root->right);

    return (max( (Lheight+Rheight+1), max(Rdiameter,Ldiameter) ) );
}

int main(){
    struct node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->left->right->left = CreateNode(6);

    printf("Diameter of this tree is %d\n",diameter(root));

    return 0;
}

/*
            1
           / \
          2   3
         / \
        4   5
           /
          6

*/