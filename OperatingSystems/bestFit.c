#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int main(){
    int n;
    int processes[MAX], partionSize[MAX], newPartionSize[MAX];
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter the size of process-%d : ", i);
        scanf("%d", &processes[i]);
    }

    for(int i = 0; i < n; i++){
        printf("Enter the of partion-%d : ", i);
        scanf("%d", &partionSize[i]);
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(partionSize[i] > partionSize[j]){
                int temp = partionSize[i];
                partionSize[i] = partionSize[j];
                partionSize[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        newPartionSize[i] = partionSize[i] - processes[i];
    }

     printf("Process ID \t Process Size \t Partion Size \t Left Partion Size \n");
    for(int i = 0; i < n; i++){
        if(newPartionSize[i] < 0){
             printf("    %d \t               %d \t          %d \t           Not Sufficient Space \n", i, processes[i], partionSize[i]);
        }
        else{
            printf("    %d \t               %d \t          %d \t           %d \n", i, processes[i], partionSize[i], newPartionSize[i]);
        }
    }

}
