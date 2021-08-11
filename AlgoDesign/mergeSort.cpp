//Merge Sort
#include<iostream>
using namespace std;

void merge(int A[], int l, int r, int m){
    int lengthOfSubArray_1 = m - l + 1;
    int lengthOfSubArray_2 = r - m;

    //temp arrays
    int L[lengthOfSubArray_1];
    int R[lengthOfSubArray_2];

    for(int i = 0; i < lengthOfSubArray_1; i++){
        L[i] = A[l + i];
    }     
    for(int j = 0; j < lengthOfSubArray_2; j++){
        R[j] = A[m + 1 + j];
    }

    //merge to [l....r]
    int i = 0; //1st subarray
    int j = 0; //2nd subarray
    int k = l; //merged subarray

    while(i < lengthOfSubArray_1 && j < lengthOfSubArray_2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //copy remaining elements from R[] and L[]
    while(i < lengthOfSubArray_1){
        A[k] = L[i];
        i++;
        k++;
    }

    while(j < lengthOfSubArray_2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int l, int r){
    if(l < r){
        int m = l + (r - l)/2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);

        merge(A, l, r, m);
    }
}

void print(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[] = {10, 2, 3, 1, 12};
    int size = sizeof(A)/sizeof(A[0]);

    printf("Unsorted Array: ");
    print(A, size);
    printf("\n");

    mergeSort(A, 0, size - 1);

    printf("Sorted Array: ");
    print(A, size);
    printf("\n");

    return 0;
}
