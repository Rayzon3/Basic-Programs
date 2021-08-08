#include<iostream>

using namespace std;

void merge(int *A, int *L, int *R, int leftCount, int rightCount){

    int i,j,k;
    i = 0;
    j = 0; 
    k = 0;

    while(i < leftCount && j < rightCount){
        if(L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void mergeSort(int *A, int n){
    int mid = n/2;
    
    if(n < 2) return;

    mid = n/2;
    //creating left and right sub-arrays
    int *L = (int*)malloc(mid*sizeof(int));
    int *R = (int*)malloc((n - mid)*sizeof(int));
    //populate
    for(int i = 0; i < mid; i++) L[i] = A[i];
    for(int i = mid; i < n; i++) R[i] = A[i];

    //sorting left sub-array
    mergeSort(L, mid);
    //sorting right sub-array
    mergeSort(R, n - mid);
    //Merging
    merge(A, L, R, mid, n - mid);
    free(L);
    free(R);
}

int main(){

    int A[] = {6,2,3,1,9,10,15,13,12,17}; 

    int numberOfElements = sizeof(A)/sizeof(A[0]); 

    mergeSort(A,numberOfElements);

	for(int i = 0; i < numberOfElements; i++) printf("%d ",A[i]);

    return 0; 
}