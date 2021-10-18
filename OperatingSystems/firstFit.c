#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int main(){
    int n;
    int processes[MAX], prationSize[MAX], newPartionSize[MAX];
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter the size of Process-%d : ", i);
        scanf("%d", &processes[i]);

    }

    for(int i = 0; i < n; i++){
        printf("Enter the of Partion-%d : ", i);
        scanf("%d", &prationSize[i]);
    }

    for(int i = 0; i < n; i++){
        newPartionSize[i] = prationSize[i] - processes[i];
    }

    printf("Process ID \t Process Size \t Partion Size \t Left Partion Size \n");
    for(int i = 0; i < n; i++){
        if(newPartionSize[i] < 0){
                printf("    %d \t               %d \t          %d \t           Not Sufficient Space \n", i, processes[i], prationSize[i]);
        }
        else{
                printf("    %d \t               %d \t          %d \t           %d \n", i, processes[i], prationSize[i], newPartionSize[i]);
        }
    }

    return 0;
}
