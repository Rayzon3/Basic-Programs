#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *A, int n, int x){
    int start = 0;
    int end = n;
    int mid;

    while(start < end){
        mid = (start + end)/2;
        if(A[mid] == x){
            return mid;
        }
        else if(x < mid){
            end = mid - 1;
        }
        else start = mid + 1;
    }

    return -1;
}

int main(){

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(A)/sizeof(A[0]);
    int x;
    
    printf("Enter the number you want to find: \n");
    scanf("%d", &x);

    int var = binarySearch(A, n, x);

    if(var == -1){
        printf("Number not found !! \n");
    }
    else{
        printf("Number found at %dth position.\n", var);
    }
    
    return 0;
}
