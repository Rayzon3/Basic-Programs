#include<stdio.h>
#include<stdlib.h>

#define V 4
#define INF 99999

void Print(int dist[][V]){
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydsAlgo(int graph[][V]){
    int dist[V][V];
    
    //init dist matrix with the same values as in graph matrix
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
        }
    }
    
    /*
    k is an intermediate vertex in shortest path from i to j. 
    We update the value of dist[i][j] as dist[i][k] + dist[k][j] 
    if dist[i][j] > dist[i][k] + dist[k][j]
    */
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    Print(dist);

}

int main(){

    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    floydsAlgo(graph);

    return 0;
}


