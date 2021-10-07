#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 4

void Print(int color[]){
    printf(
        "Solution Exists:"
        " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf("Color for vertex %d -> %d \n", i, color[i]);
    printf("\n");
}

/*
the below function checks wether an edge exits or not(graph[v][i] == 1)
and checks if the color to be filled in the new vertex is already 
used by it's adj vertex
*/
bool isSafe(bool graph[V][V], int colors[], int v, int c){
    for(int i = 0; i < V; i++){
        if(graph[v][i] && c == colors[i]) return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[V][V], int nColors, int colors[], int v){
    //base case, if all vertices are assigned a color then return true
    if(v == V) return true;

    //trying different colors
    for(int c = 1; c <= nColors; c++){
        //check if color can be defined 
        if(isSafe(graph, colors, v, c)){
            colors[v] = c;
            //recurssive call to assign colors to rest of the vertices
            if(graphColoringUtil(graph, nColors, colors, v + 1) == true){
            return true;
            }
        }
        // if assigning color c doesn't lead to a solution then remove it
        colors[v] = 0;
    }

    return false;
} 

bool graphColoring(bool graph[V][V], int ncolors){
    //init all colors as 0
    int colors[V];
    for(int i = 0; i < V; i++){
        colors[i] = 0;
    }

    //starting with vertex 0
    if(graphColoringUtil(graph, ncolors, colors, 0) == false){
        printf("Solution does not exist :/ \n");
        return false;
    }

    Print(colors);
    return true;
}

int main(){

    // adjacency matrix where 0 represents no edge b/w nodes
    // 1 represents an edge b/w nodes
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };

    int nColors = 3; //number of colors

    graphColoring(graph, nColors);

    return 0;
}
