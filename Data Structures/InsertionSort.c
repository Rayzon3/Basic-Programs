#include<stdio.h>
#include<stdlib.h>


void InsertionSort(int a[], int n){
    for(int i = 0; i < n; i++){
       int  value = a[i];
        int hole = i;
        while(hole > 0 && a[hole - 1] > value){
            a[hole] = a[hole - 1];
            hole = hole - 1;
        }
        a[hole] = value;
    }
}


int main(){
    
    int a[] = {2, 7, 4, 1, 5, 3};

    InsertionSort(a, 6);

    for(int i = 0; i < 6; i++){
        printf(" %d", a[i]);
    }   
    printf("\n");

    return 0;
}
