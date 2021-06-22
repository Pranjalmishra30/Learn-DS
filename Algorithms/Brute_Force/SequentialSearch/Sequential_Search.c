// Implement Sequential Search
#include<stdio.h>
int SeqSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if (key == arr[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {70,46,65,92,15,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("Enter Key to be searched ");
    scanf("%d",&key);
    printf("Found at index %d\n",SeqSearch(arr,n,key));

}