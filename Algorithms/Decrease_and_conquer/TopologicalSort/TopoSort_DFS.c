// Topological Sort using DFS
#include<stdio.h>
#define max 10

int V,x = 0;
int visited[max],popOrder[max],adj_mat[max][max];

void DFS(int vertex){
    visited[vertex] = 1;

    for(int i=0;i<V;i++){
        if(!visited[i] && adj_mat[vertex][i] == 1){
            DFS(i);
        }
    }
    popOrder[x++] = vertex;
}

void TopoSort(){
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    printf("Enter the adjacent matrix\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&adj_mat[i][j]);
        }
    }

    for(int i=0;i<V;i++){ // Initialising visited array
        visited[i]=0;
    }

    TopoSort();
    
    printf("Topological Sort: ");
    for(int i=V-1;i>-1;i--){ // Printing pop order in reverse
        printf("%d ",popOrder[i]);
    }

    return 0;
}

/*
Sample Input
V = 5
adj_mat = 0 0 1 1 0
          0 0 1 0 1
          0 0 0 1 0
          0 0 0 0 0
          1 0 1 0 0
*/