// Implement an AVL tree 
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return ((a>b)?a:b);
}

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

int height(struct node* NODE){
    if(NODE==NULL)
        return -1;
    int Lheight = height(NODE->left);
    int Rheight = height(NODE->right);

    return (max(Lheight,Rheight) + 1);
}

int BalanceFactor(struct node* NODE){ 
    if(NODE==NULL){
        return -1;
    }
    return ( height(NODE->left) - height(NODE->right) );    
}

struct node* Lrotate(struct node* NODE){ // NODE is root
    struct node* y = NODE->right;
    struct node* z = y->left;

    // Apply Rotation
    y->left = NODE;
    NODE->right = z;

    return y;
}

struct node* Rrotate(struct node* NODE){ // NODE is root
    struct node* y = NODE->left;
    struct node* z = y->right;

    // Apply Rotation
    y->right = NODE;
    NODE->left = z;

    return y;
}

struct node* Insert(struct node* NODE,int key){
    if (NODE == NULL){
        return CreateNode(key);
    }

    if(key < NODE->data)
        NODE->left = Insert(NODE->left,key);
    else if (key > NODE->data)
        NODE->right = Insert(NODE->right,key);
    else
        return NODE; // duplicate keys are not allowed
    
    int B = BalanceFactor(NODE);

    // L rotation
    if(B < -1 && key > NODE->right->data){
        printf("L rotation\n");
        return Lrotate(NODE);
    }

    // R rotation
    if(B > 1 && key < NODE->left->data){
        printf("R rotation\n");
        return Rrotate(NODE);
    }

    // LR rotation
    if(B > 1 && key > NODE->left->data){
        printf("LR rotation\n");
        NODE->left = Lrotate(NODE->left);
        return Rrotate(NODE);
    }

    // RL rotation
    if(B < -1 && key < NODE->right->data){
        printf("RL rotation\n");
        NODE->right = Rrotate(NODE->right);
        return Lrotate(NODE);
    }

    return NODE;
}

void preOrder(struct node* NODE){
    if(NODE!=NULL){
        printf("%d ",NODE->data);
        preOrder(NODE->left);
        preOrder(NODE->right);
    }
}

int main(){
    int n,x;
    struct node* Root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter node: ");
        scanf("%d",&x);
        Root = Insert(Root,x);
    }

    printf("\nPreorder: ");
    preOrder(Root);
    printf("\n");

    return 0;
}




