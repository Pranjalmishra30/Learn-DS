#include<stdio.h>
#define MAX 20
void InsertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int V = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > V){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = V;
    }

}

int main(){
    int arr[MAX],n;
    printf("Enter n ");
    scanf("%d",&n);
    printf("Enter array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    InsertionSort(arr,n);
    printf("\nSorted Array\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}