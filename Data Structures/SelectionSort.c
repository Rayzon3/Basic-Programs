#include<stdio.h>
#include<stdlib.h>


void SelectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int iMin = i;
        for(int j = 0; j < n; j++){
            if(a[iMin] < a[j]){
                iMin = j;
            }
            int temp = a[i];
            a[i] = a[iMin];
            a[iMin] = temp;
        }
    }
}


int main(){

    int a[] = {2, 7, 4, 1, 5, 3};
    SelectionSort(a, 6);

    for(int i = 0; i < 6; i++){
        printf(" %d", a[i]);
    }   
    printf("\n");
    return 0;
}
