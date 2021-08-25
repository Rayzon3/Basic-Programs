//Recursion Brute Force
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int max(int x, int y) { return(x > y ? x : y); }

int knapSack(int *wt, int *val, int n, int W){
    if(n == 0 || W == 0) return 0;
    if(wt[n - 1] > W) return knapSack(wt, val, n - 1, W);
    else return max(
        val[n - 1] + knapSack(wt, val, n - 1, W - wt[n - 1]), knapSack(wt, val, n - 1, W)
    ); 
}


int main(){

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int n = sizeof(val)/sizeof(val[0]);
    int W = MAX;

    printf("%d ", knapSack(wt, val, n, W));
    printf("\n");
    return 0; 
}
