//Nqueen using backtarcking
//4X4 board 

#include<stdio.h>
#include<stdbool.h>
#define N 4

void printBoard(int board[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col){
    //check row on left
    for(int i = 0; i < col; i++){
        if(board[row][i]) return false;
    }

    //check upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]) return false;
    }

    //check lower left diagonal
    for(int  i = row, j = col; j >= 0 && i < N; i++, j--){
        if(board[i][j]) return false;
    }

    return true;
}

bool util(int board[N][N], int col){
    //base case: if all queens are placed
    if(col >= N) return true;

    for(int i = 0; i < N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;
            if(util(board, col + 1)) return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solveNQueen(){
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    
    if(util(board, 0) == false){
        printf("Solution does not exist :/");
        return false;
    }

    printBoard(board);
    return true;
}

int main(){
    solveNQueen();
    return 0;
}
