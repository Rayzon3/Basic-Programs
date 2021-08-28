//non-preemptive
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

struct Process{
    int ID;
    int burst_time;
    int wt;
    int tat;
}process[5], temp;

int main(){
 
    int n = 5;
   
    printf("Enter burst time for the following processes: \n");
    for(int i = 0; i < n; i++){
        printf("Enter burst time for process with ID: %d -> ", i + 1);
        scanf("%d", &process[i].burst_time);
        process[i].ID = i + 1;
        
    }

    //sort
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(process[i].burst_time > process[j].burst_time){
                //swap
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;
            }
        }
    }

    //waiting time
    process[0].wt = 0;
    for(int i = 1; i < n; i++){
        process[i].wt = process[i - 1].burst_time + process[i - 1].wt;
    }

    //turn around time
    for(int i = 0; i < n; i++){
        process[i].tat = process[i].burst_time + process[i].wt;
    }

    //average time
    int total_wt = 0, total_tat = 0;
    printf("-----------------------------------------------------------------\n");
    printf("Process_ID   Burst time   Waiting time   Turn around time\n");
    printf("-----------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        total_wt = total_wt + process[i].wt;
        total_tat = total_tat + process[i].tat;
        printf("   %d ", process[i].ID);
        printf("            %d ", process[i].burst_time);
        printf("           %d",process[i].wt);
        printf("                %d\n",process[i].tat);
        printf("-----------------------------------------------------------------\n");
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d \n",s);
    printf("Average turn around time = %d \n",t);

    printf("------------------------------------------------------------------\n");
    cyan();
    printf("\t \t \tGantt Chart\n");
    reset();
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        (*func_Pointer[i])();
        printf("|#Process %d (%d)", process[i].ID, process[i].burst_time);
        for(int j = 0; j < process[i].burst_time; j++){
            printf("#");
        }
        printf("|");
    }
    return 0;
}
