#include<stdio.h>
#define MAX 10

int Q[MAX],front=-1,rear=-1;

int V,adj_mat[MAX][MAX],visited[MAX];

void EnQ(int x){
    if(front == -1)
        front=0;
    rear++;
    Q[rear] = x;
}

int DeQ(){
    if (front == -1)
        return -1;
    else{
        int x = Q[front];
        front++;
        if(front > rear)
            front = rear = -1;
        return x;
    }
}

void BFS(int X){
    // Setting all vertices as unvisited
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }

    EnQ(X);
    int a;
    while(a !=-1){
        a = DeQ();
        if(a!=-1 && !visited[a]){

            visited[a] = 1;
            printf("%d ",a);

            for(int i=0;i<V;i++){
                if(visited[i]==0 && adj_mat[a][i] == 1){
                    EnQ(i);
                }
            }
        }
    }

}

int main(){
    printf("Enter number of vertices ");
    scanf("%d",&V);
    printf("Enter Adjacency Matrix\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&adj_mat[i][j]);
        }
    }
    
    int X;
    printf("Enter source vertex "); // Source vertex is the vertex from where we begin our BFS ordering
    scanf("%d",&X);
    printf("BFS ordering: "); 
    BFS(X);

    return 0;
}