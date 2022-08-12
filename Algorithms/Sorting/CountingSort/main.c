#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void countSort(int A[], int n, int k){
    int *B = malloc(n*sizeof(int));
    int *C = malloc(k*sizeof(int));
    memset(C, 0, k*sizeof(int));
    for(int j=0; j<n; ++j)
        C[A[j]] = C[A[j]]+1;
    for(int j=1; j<k; ++j)
        C[j] = C[j]+C[j-1];
    for(int j=n-1; j>=0; --j){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]]-1;
    }
    for(int i=0; i<n; ++i)
        A[i] = B[i];
}

int find_k(int A[], int n){
    int max=A[0];
    for(int i=1; i<n; ++i)
        if(A[i]>max)
            max = A[i];
    return max;
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i)
        scanf("%d", &A[i]);
    countSort(A, n, find_k(A,n)+1);
    printf("\nSorted Array: ");
    for(int i=0; i<n; ++i)
        printf(" %d", A[i]);
    return 0;
}