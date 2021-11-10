#include<stdio.h>
#include<stdlib.h>

int main(){

    int string[] = {4, 1, 2, 4, 5};
    int nFrames = 3;
    int frame[nFrames];
    int pageFaults = 0;
    int j = 0;

    //init empty frame slots to -1 
    for(int k = 0; k < sizeof(frame)/sizeof(frame[0]); k++){
        frame[k] = -1;
    }

    for(int i = 0; i < sizeof(string)/sizeof(string[0]); i++){
        if(j == nFrames){
            j = 0; 
            printf("------\n");
            for(int k = 0; k < sizeof(frame)/sizeof(frame[0]); k++){
                printf("%d \n", frame[k]);
            }
        }
        if(frame[j] != string[i]){
            frame[j] = string[i];
            j++;
            pageFaults++;
            printf("------\n");
            for(int k = 0; k < sizeof(frame)/sizeof(frame[0]); k++){
                printf("%d \n", frame[k]);
            }
        }
        
    }
    

    printf("Number of page faults = %d", pageFaults);

    return 0;
}
