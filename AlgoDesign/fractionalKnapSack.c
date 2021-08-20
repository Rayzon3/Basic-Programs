//Greedy Approach
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int partition(int *A, int start, int end){
    int pivot = A[end];
    int partionIndex = start;
    for(int i = start; i < end; i++){
        if(A[i] >= pivot){
            //swap
            int temp = A[i];
            A[i] = A[partionIndex];
            A[partionIndex] = temp;

            partionIndex++;
        }
    } 
    //swap
    int temp = A[partionIndex];
    A[partionIndex] = A[end];
    A[end] = temp;

    return partionIndex;

}

//quick sort
void sort(int *A, int start, int end){
    if(start < end){
        int partionIndex = partition(A, start, end);
        sort(A, start, partionIndex - 1);
        sort(A, partionIndex + 1, end);
    }
}

void fillSack(int *value, int *weight, int *v_per_w, int n){
    int sackCapacity = 0;
    int valueInSack = 0;

    for(int i = 0; i < n; i++){
        sackCapacity = weight[i] + sackCapacity;
        valueInSack = value[i] + valueInSack;
        if(sackCapacity > MAX){
            sackCapacity = sackCapacity - weight[i];
            valueInSack = valueInSack - value[i];
            if(MAX - sackCapacity < weight[i]){
                int fractionalWeight = MAX - sackCapacity;  
                sackCapacity = sackCapacity + fractionalWeight;
                int fractionalValue = v_per_w[i] * fractionalWeight;
                valueInSack = valueInSack + fractionalValue;
            }
        }
    }


   printf("Maximum value that can be stored in sack : %d \n", valueInSack);

}

int main(){

    int value[] = {40, 24, 30, 21, 12};
    int weight[] = {5, 4, 6, 7, 6};
    int n = sizeof(value)/sizeof(value[0]);
    int v_per_w[n]; 

    for(int i = 0; i < n; i++){
        v_per_w[i] = value[i]/weight[i];
    }

    sort(v_per_w, 0, n);

    fillSack(value, weight, v_per_w, n);

    return 0;
}
