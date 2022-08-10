#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r){
    int pivot = A[p], i=p, j;
    for(j=p+1; j<=r; ++j){
        if(A[j]<=pivot){
            ++i;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[p], &A[i]);
    return i;
}

void quickSort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i)
        scanf("%d", &A[i]);
    quickSort(A, 0, n-1);
    printf("\n\n\nSorted Array:");
    for(int i=0; i<n; ++i)
        printf(" %d", A[i]);
    return 0;
}