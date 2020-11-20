#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int a[], int n){
   for(int k = 0; k < n - 1; k++){
        for(int i = 0; i < n - k - 1; i++){
            if(a[i] > a[i + 1]){
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
   }
}


int main(){
    int a[] = {2, 7, 4, 1, 5, 3};

    BubbleSort(a, 6);

    for(int i = 0; i < 6; i++){
        printf(" %d", a[i]);
    }   
    printf("\n");

    return 0;
}
