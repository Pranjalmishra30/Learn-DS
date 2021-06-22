// Implement Selection Sort
#include<stdio.h>

void display(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void SelectSort(int arr[],int n){
    int swap_count = 0;

    for(int i=0;i<n-1;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        swap_count++;
    }
    printf("Sorted Array:\n");
    display(arr,n);
    printf("Number of key swaps: %d\n",swap_count);

}

int main(){
    int arr[] = {70,46,65,92,15,3};
    // int arr[] = {92,70,65,46,15,3}; // Worst Case
    // int arr[] = {3,15,46,65,70,92}; // Best Case
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectSort(arr,n);
}