#include<stdio.h>
#include<stdlib.h>
#include<math.h>

merge(int A[], int p, int q, int r){
    int n1 = q-p+1, n2 = r-q, i, j, k;
    int *L=malloc((n1+1)*(sizeof(int))), *R=malloc((n2+1)*(sizeof(int)));
    for(i=0; i<n1; ++i)
        L[i] = A[p+i-1];
    printf("\n\nArray L[]:");
    for(int i=0; i<n1; ++i)
        printf("%d ", L[i]);
    for(j=0; j<n2; ++j)
        R[j] = A[q+j];
    // L[n1+1]=INT_MAX, R[n2+1]=INT_MAX;
    i=j=0;
    for(k=p; k<=r; ++k){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i=i+1;
        }else{
            A[k]=R[j];
            j=j+1;
        }
    }
}

mergeSort(int A[], int p, int r);

int main(){
    int n;
    scanf("%d", &n);
    int *A = malloc(n*sizeof(int));
    for(int i=0; i<n; ++i)
        scanf("%d", &A[i]);
    mergeSort(A, 0, n-1);
    printf("\n\n\nSorted Array: ");
    for(int i=0; i<n; ++i)
        printf("%d ", A[i]);
    return 0;
}

mergeSort(int A[], int p, int r){
    // printf("\nvalue of p: %d", p);
    // printf("\nvalue of r: %d", r);

    if(p<r){
        int q=floor((p+r)/2);
        // printf("\nvalue of q: %d", q);
        mergeSort(A,p,q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}