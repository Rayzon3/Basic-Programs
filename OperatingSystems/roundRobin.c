#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void red () {
  printf("\033[1;31m");
}

void green(){
    printf("\033[0;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue(){
    printf("\033[0;34m");
}

void purple(){
    printf("\033[0;35m");
}

void cyan(){
    printf("\033[0;36m");
}

void white(){
    printf("\033[0;37m");
}

void reset () {
  printf("\033[0m");
}

void (*func_Pointer[8]) () = {red, green, yellow, blue, purple, cyan, white, reset};

void waitingTime(int processes[], int n, int bt[], int wt[], int q){
    int current_time = 0;
    int rem_bt[n];
    for(int i = 0; i < n; i++){
        rem_bt[i] = bt[i]; 
    }
    while(true){
        bool finished = true;

        for(int i = 0; i < n; i++){
            if(rem_bt[i] > 0){
                finished = false;
                if(rem_bt[i] > q){
                    current_time += q;
                    rem_bt[i] -= q;
                }
                else{
                    current_time = current_time + rem_bt[i];
                    wt[i] = current_time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if(finished == true){
            break;
        }
    }
}

void turnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i = 0; i < n ; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void avgTime(int processes[], int n, int bt[], int q){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waitingTime(processes, n, bt, wt, q);
    turnAroundTime(processes, n, bt, wt, tat);

    printf("-----------------------------------------------------------------\n");
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("            %d ", bt[i]);
        printf("           %d",wt[i] );
        printf("                %d\n",tat[i] );
        printf("-----------------------------------------------------------------\n");
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d \n",s);
    printf("Average turn around time = %d \n",t);

    red();
    for(int i = 0; i < (tat[n - 1] + n*18); i++){
        printf("-");
    }
    printf("\n");
    printf(" | ");
    for(int i = 0; i < n; i++){
        (*func_Pointer[i])();
        int x =  bt[i]/2;
        for(int i = 0; i < x; i++){
            printf("#");
        }
        printf(" Process %d (%d) ", processes[i], bt[i]);
        for(int i = 0; i < x; i++){
            printf("#");
        }
        printf(" | ");
    }
    printf("\n");
    for(int i = 0; i < (tat[n - 1] + n*18); i++){
        printf("-");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        (*func_Pointer[i])();
        printf("  %d ", wt[i]);
        int x =  bt[i]/2;
        for(int i = 0; i < x; i++){
            printf(" ");
        }
        printf("             ");
        for(int i = 0; i < x; i++){
            printf(" ");
        }
        if(i == n - 1){
            printf("%d", tat[i]);
        }
    }
    printf("\n");
}

int main(){

    int processes[] = {1, 2, 3};
    int n = sizeof(processes)/sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int q = 2;

    avgTime(processes, n, burst_time, q); 

    return 0;
}

