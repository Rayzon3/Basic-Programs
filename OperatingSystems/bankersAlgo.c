#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int main()
{

    int n, m;
    n = 5; //no. of processes
    m = 3; //no. of resources
    int counter = 0;

    int allocation[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                            {2, 0, 0},  // P1
                            {3, 0, 2},  // P2
                            {2, 1, 1},  // P3
                            {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int available[3] = {3, 3, 2}; // Available Resources

    //init finished to false
    int finished[n];
    for (int i = 0; i < n; i++)
    {
        finished[i] = false;
    }

    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int ans[n], ind = 0;
    int y = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (finished[i] == false)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        counter++;
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        available[y] += allocation[i][y];
                    finished[i] = true;
                }
            }
        }
    }

    if (counter > n)
    {
        printf("Unsafe State \n");
    }

    if (counter < n)
    {
        printf("The Safe Sequence is :\n");
        for (int i = 0; i < n - 1; i++)
        {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    return 0;
}
