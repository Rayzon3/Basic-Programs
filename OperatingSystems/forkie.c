#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define MAX 100
#define BUFFER_SIZE 50

int main(){
    pid_t pid;
    char buff[BUFFER_SIZE];

    fork();
    pid = getpid();

    for(int i = 0; i <= MAX; i++){
        sprintf(buff, "This line is from pid %d value = %d\n", pid, i);
        write(1, buff, strlen(buff));
    }

    return 0;
}