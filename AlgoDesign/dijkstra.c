#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define V 5

void print(int dist[]){
    printf("Vertex \t\t Distance from Source\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < V; i++){
        printf("%d \t\t %d\n", i, dist[i]);
        printf("--------------------------------------\n");
    }
}

int minDistance(int dist[], bool sptSet[]){ 
    int min = INT_MAX; //init min value
    int min_index;

    for(int i = 0; i < V; i++){
        if(sptSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V]; //will hold the shortest distance from src to ith vertex
    bool sptSet[V]; //will be true if vertex i is included in the shortest path

    //init all distances to INFINITE and sptSet to FALSE
    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    } 
    
    //distance from src to src is always 0
    dist[src] = 0;

    //find shortest path
    for(int count = 0; count < V - 1; count++){
        //find the minimum distance vertex from the set of vertices
        int u = minDistance(dist, sptSet);

        //mark the processed vertex
        sptSet[u] = true;

        //update the distance values of the vertices adjacent to the picked vertex
        for(int v = 0; v < V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist);

}

int main(){

    int graph[V][V] = {{2, 4, 0, 1, 5},
                       {1, 0, 6, 0, 3},
                       {2, 4, 7, 8, 12},
                       {0, 0, 0, 2, 3},
                       {4, 6, 1, 0, 0}};

    dijkstra(graph, 0);

    return 0;
}
