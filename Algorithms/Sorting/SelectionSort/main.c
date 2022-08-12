#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int A[], int n){
    int i,j;
    for(j=0;j<n;++j){
        int iMin=j;
        for(i=j+1; i<n;++i)
            if(A[i]<A[iMin])
                iMin = i;
        if(iMin!=j)
            swap(&A[j], &A[iMin]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i){
        scanf("%d", &A[i]);
    }
    selectionSort(A,n);
    printf("\nSorted Array:");
    for(int i=0; i<n; ++i)
        printf(" %d", A[i]);
    return 0;
}