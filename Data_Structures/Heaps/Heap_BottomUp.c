// Construct a heap using a bottom up approach
#include<stdio.h>
#define MAX 100

void heapify(int arr[],int n){
    int k,j,val,heap;
    
    for(int i=(n/2-1);i>=0;i--){
        k=i;
        val = arr[k];
        heap = 0;

        while(heap == 0 && 2*k+1 <=n){
            j = 2*k+1;
            if(j<n)
                if(arr[j] < arr[j+1]) // finding the larger of the 2 childs
                    j = j+1;

            if(val >= arr[j]) // checking parental dominance 
                heap=1;
            else{
                arr[k] = arr[j];
                k=j;
            }   
        }
        arr[k] = val;
    }
}

int main(){
    
    int n,Heap[MAX];
    printf("Enter n ");
    scanf("%d",&n);

    printf("Enter array\n");
    for(int i=0;i<n;i++){ // inputing elements from 0 to n-1
        scanf("%d",&Heap[i]);
    }
    
    heapify(Heap,n);
    printf("\nConstructed Heap using top down approach\n");
    for(int i=0;i<n;i++){
        printf("%d ",Heap[i]);
    }
    
    return 0;
}