//using tabulation

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 50

int max(int x, int y) { return(x > y ? x : y); }

int knapSack(int *wt, int *val, int n, int W){
    int table[n + 1][W + 1];

    //build table
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                table[i][j] = 0;
            }
            else if(wt[i - 1] <= j){
                table[i][j] = max(val[i - 1] + table[i - 1][j - wt[i - 1]], table[i - 1][j]);
            }
            else table[i][j] = table[i - 1][j];
        }
    }

    return table[n][W];
}

int main(){

    int val[] = { 1, 2, 5, 6 };
    int wt[] = { 2, 3, 4, 5 };
    int n = sizeof(val)/sizeof(val[0]);
    int W = MAX;

    printf("%d \n", knapSack(wt, val, n, W));

    return 0;
}
