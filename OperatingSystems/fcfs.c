#include<stdio.h>
#include<stdlib.h>

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

void waitingTime(int processes[], int n, int bt[], int wt[]){
    wt[0] = 0;

    for(int  i = 1; i < n; i++){
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void turnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
    for(int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i]; 
    }
}

void avgTime(int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waitingTime(processes, n, bt, wt);
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
}

int main(){
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes)/sizeof(processes[0]);
    int burst_time[n];

    printf("Enter burst time for the following processes: \n");
    for(int i = 0; i < n; i++){
        printf("Enter burst time for processes no.: %d -> ", i);
        scanf("%d", &burst_time[i]);
    }

    avgTime(processes, n, burst_time);

    printf("------------------------------------------------------------------\n");
    cyan();
    printf("\t \t \tGantt Chart\n");
    reset();
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        (*func_Pointer[i])();
        printf("|#Process %d (%d)", i, burst_time[i]);
        for(int j = 0; j < burst_time[i]; j++){
            printf("#");
        }
        printf("|");
    }
    printf("\n");
    return 0; 
}
