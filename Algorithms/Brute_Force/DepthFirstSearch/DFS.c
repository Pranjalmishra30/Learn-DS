#include<stdio.h>
# define max 10
int V,adj_mat[max][max],visited[max],popOrder[max];
int x =0;

void dfs(int vertex){
    visited[vertex] = 1;
    printf("%d ",vertex);

    for(int i=0;i<V;i++){
        if(!visited[i] && adj_mat[vertex][i]==1){
            dfs(i);
            popOrder[x++] = i;
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

    // Initially Setting visited to 0 for all vertices
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }
    int X;
    printf("Enter source vertex "); // Source vertex is the vertex from where we begin our DFS ordering
    scanf("%d",&X);
    printf("DFS ordering: "); // This can also be called push order
    dfs(X);
    printf("\nPop ordering: ");
    for(int i=0;i<V;i++){
        printf("%d ",popOrder[i]);
    }

}