// Construct a heap using a top down approach
#include<stdio.h>
#define MAX 100

void HeapTopDown(int heap[],int index){
    int parentIndex = (index - 1)/2;
    
    while(parentIndex >=0)
    {
        if(heap[parentIndex] < heap[index]){ // Checking Parental dominance
        
            int temp = heap[parentIndex]; // Swap
            heap[parentIndex] = heap[index];
            heap[index] = temp;

            index = parentIndex;
            parentIndex = (index - 1)/2;
        }

        else
            return;
    }
}

int main(){
    int n,Heap[MAX];
    printf("Enter n ");
    scanf("%d",&n);

    printf("Enter array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&Heap[i]);
        HeapTopDown(Heap,i);
    }

    printf("\nConstructed Heap using top down approach\n");
    for(int i=0;i<n;i++){
        printf("%d ",Heap[i]);
    }
        
    return 0;
}