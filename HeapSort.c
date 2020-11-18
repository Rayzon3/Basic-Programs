#include<stdio.h>
#include<stdlib.h>

void MaxHeapify(int a[], int n, int i){
    int largest = i;
    int left_child = (i * 2) + 1;
    int right_child = (i * 2) + 2;


    if(left_child < n && a[left_child] > a[largest]){
        largest = left_child;
    }

    if(right_child < n && a[right_child] > a[largest]){
        largest = right_child;
    }

    if(largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        MaxHeapify(a, n, largest);
    }
}

void HeapSort(int a[], int n){
    for(int i = (n/2) - 1; i >= 0; i--){
        MaxHeapify(a, n, i);
    }

    for(int i = n -1; i > 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        MaxHeapify(a, i, 0);
    }
}

void Print(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf(" %d ", a[i]);
    }
    printf("\n");
}

int main(){
    
    
    int a[] = {9, 5, 2, 4, 1, 6, 3, 8, 7};
    int n = sizeof(a)/sizeof(a[0]);

    HeapSort(a, n);

    printf("Sorted array is : \n");
    Print(a, n);
    
    return 0;
}
