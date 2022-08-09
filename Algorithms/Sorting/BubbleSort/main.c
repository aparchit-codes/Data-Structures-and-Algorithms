#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i)
        scanf("%d", &A[i]);
    printf("\n\n\nGiven Array: ");
    for(int i=0; i<n; ++i)
        printf("%d ", A[i]);
    bubbleSort(A, n);
    printf("\n\n\nSorted Array: ");
    for(int i=0; i<n; ++i)
        printf("%d ", A[i]);
    return 0;
}