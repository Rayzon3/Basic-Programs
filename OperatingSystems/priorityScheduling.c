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

    int n, q;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
   
    printf("Enter burst time for the following processes: \n");
    for(int i = 0; i < n; i++){
        printf("Enter burst time for process with ID: %d -> ", i + 1);
        scanf("%d", &process[i].burst_time);
        process[i].ID = i + 1;
        
    }

    printf("Enter the time quantum: ");
    scanf("%d", &q);

    return 0;
}
