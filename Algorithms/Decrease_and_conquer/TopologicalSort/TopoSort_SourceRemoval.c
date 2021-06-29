// Topological Sort using Source Removal method
#include<stdio.h>
#define max 10

int visited[max],inDegree[max],adj_mat[max][max],V;
int TopSort[max],x=0;

// Reducing the inDegree for the deleted edges 
void DeleteEdge(int source){
     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i == source){
                if(adj_mat[i][j] == 1){
                    inDegree[j]--;
                }
            }
        }
    }
}

// Deleting the vertices with no incoming edges (inDegree = 0)
void TopoLogicalSort(){
    int count=0;
    while(count < V){ 
        for(int i=0;i<V;i++){
            if(!visited[i] && inDegree[i]==0){
                printf("Deleted %d\n",i);
                TopSort[x++] = i;
                visited[i] = 1;
                DeleteEdge(i);
                count++;
            }
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
 
    // Initialising visited and inDegree array                    
    for(int i=0;i<V;i++){
        visited[i]=0;
        inDegree[i]=0;
    }
    
    // Calculating Indegree of each vertices
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if (adj_mat[j][i] == 1)
                (inDegree[i])++;
        }
    }
    
    printf("\n");
    TopoLogicalSort();

    printf("TopoLogical Sort: ");
    // Printing TopSort array
    for(int i=0;i<V;i++) {
        printf("%d ",TopSort[i]);
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