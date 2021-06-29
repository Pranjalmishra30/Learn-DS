#include<stdio.h>
#define MAX 20

int BinarySearch(int arr[],int n,int key){
    int l=0,r=n-1;
    while(l<=r){
        int m = l + (r-l)/2 ; // To avoid overlfow in case of large size arrays
        if(key == arr[m])
            return m;
        else if(key > arr[m]){
            l = m+1;
        }
        else if(key < arr[m]){
            r = m-1;
        }   
    }
    return -1;
}

int main(){
    int arr[MAX],n,key;
    printf("Enter n ");
    scanf("%d",&n);
    printf("Enter array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter key to be searched ");
    scanf("%d",&key);   
    printf("%d found at index %d\n",key,BinarySearch(arr,n,key));

    return 0;
}