// Implement Brute Force String Matching
#include<stdio.h>
#include<string.h>
# define max 10

int BruteForceStringMatch(char text[],char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    // int comp_count=0;
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && text[i+j] == pattern[j]){
            j=j+1;
        }
        if (j==m){        
            return i;
        }
    }
    return -1;
}

int main(){
    int flag =0;
    char text[max];
    char pattern[max];
    printf("Enter Text ");
    scanf("%s",text);
    printf("Enter pattern to be searched ");
    scanf("%s",pattern);
    printf("\nPattern found at %d\n",BruteForceStringMatch(text,pattern));
    
}