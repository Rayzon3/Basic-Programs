#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX 100

int parentProcess();
int childProcess();

int main(){

    pid_t pid = fork();

    if(pid == 0) childProcess();
    else parentProcess();

    return 0;
}

int parentProcess(){
    for(int i = 0; i < MAX; i++){
        printf("## From Parent Process ## %d ## \n", i);
    }
    printf("** Parent Process Successfully Finished ** \n");
    return 0;
}

int childProcess(){
    for(int i = 0; i < MAX; i++){
        printf("## From Child Process ## %d ## \n", i);
    }
    printf("** Child Process Successfully Finished ** \n");
    return 0;
}
