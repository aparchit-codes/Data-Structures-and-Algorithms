#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int A[], int const p, int const q, int const r){
    int n1 = q-p+1, n2 = r-q, i, j, k;

    int *L=malloc((n1)*(sizeof(int))); 
    int *R=malloc((n2)*(sizeof(int)));
    
    for(i=0; i<n1; ++i)
        L[i] = A[p+i];
    
    for(j=0; j<n2; ++j)
        R[j] = A[q+j+1];

    i=0;j=0;k=p;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        } else{
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i<n1){
        A[k] = L[i];
        ++i;++k;
    }
    while(j<n2){
        A[k] = R[j];
        ++j;++k;
    }
}

void mergeSort(int A[], int p, int r){

    if(p<r){
        int q=p+(r-p)/2;
        mergeSort(A,p,q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i)
        scanf("%d", &A[i]);
    mergeSort(A, 0, n-1);
    printf("\n\n\nGiven Array: ");
    for(int i=0; i<n; ++i)
        printf("%d ", A[i]);
    printf("\n\n\nSorted Array: ");
    for(int i=0; i<n; ++i)
        printf("%d ", A[i]);
    return 0;
}