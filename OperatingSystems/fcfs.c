#include<stdio.h>
#include<stdlib.h>

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

    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for(int i = 0; i < n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d ", bt[i]);
        printf("       %d",wt[i] );
        printf("       %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
}

int main(){
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes)/sizeof(processes[0]);
    int burst_time[] = {7, 10, 9, 6, 5};

    avgTime(processes, n, burst_time);

    return 0; 
}
