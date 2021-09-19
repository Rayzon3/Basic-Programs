#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10, x = 0;

void producer(){
    --mutex;
    ++full;
    --empty;

    // item produced
    x++;
    printf("Producer produced item : %d \n", x);
    ++mutex;
}

void consumer(){
    --mutex;
    --full;
    ++empty;

    printf("Consumer consumed item : %d \n", x);
    x--;
    ++mutex;
}

int main(){
    int n;
    printf("1. Press 1 for Producer \n"
           "2. Press 2 for Consumer \n"
           "3. Press 3 for Exit \n");

#pragma opm critical // specifies that code is exec by only 1 thread
    for (int i = 1; i > 0; i++){
        printf("Choose your option: ");
        scanf("%d", &n);

        switch (n){
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full :/ \n");
            break;
        case 2: 
            if((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty :/ \n"); 
            break;   
        case 3:
            printf("Exiting.... cya :) \n");
            exit(0);
            break;
        default: printf("Enter valid option !! \n");
        } 
    }

    return 0;
}
