#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void insertionSort(int A[], int n){
    int key,j;
    for(int i=1; i<n; ++i){
        j=0;
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j=j-1;
        }
        A[j+1]=key;
    }
}

int main(){
    int A[] = {31,24,7,4,8,12};
    int n = sizeof(A)/sizeof(int);
    insertionSort(A,n);
    printf("Sorted Array:");
    for(int i=0; i<n; ++i)
        printf(" %d", A[i]);
}