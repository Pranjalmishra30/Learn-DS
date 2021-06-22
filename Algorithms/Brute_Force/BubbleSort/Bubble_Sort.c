// Implement Bubble Sort
#include<stdio.h>

void display(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void BubbleSort(int arr[],int n){
    int swap_count=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swap_count++;
            }
        }
    }
    display(arr,n);
    printf("\nNumber of Key Swaps: %d ",swap_count);

}
int main(){
    //int arr[] = {70,46,65,92,15,3};
    // int arr[] = {92,70,65,46,15,3}; // Worst Case
    int arr[] = {3,15,46,65,70,92}; // Best Case
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr,n);
   
}