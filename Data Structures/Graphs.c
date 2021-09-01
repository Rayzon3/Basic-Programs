//undirected graph

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct AdjList{
    struct Node* head;
};

struct Graph{
    int V;
    struct AdjList* array;
};

struct Node* makeNewNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;

    return newNode; 
}

struct Graph* makeGraph(int V){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> V = V;
    graph -> array = malloc(V * sizeof(struct AdjList));

    //init
    for(int i = 0; i < V; i++){
        graph -> array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest){
    struct Node* newNode = makeNewNode(dest);
    newNode -> next = graph -> array[src].head;
    graph -> array[src].head = newNode;

    //dest to src
    newNode = makeNewNode(src);
    newNode -> next = graph -> array[dest].head;
    graph -> array[dest].head = newNode;
}

void printGraph(struct Graph* graph){
    for(int v = 0; v < graph -> V; v++){
        struct Node* pCrawl = graph -> array[v].head;
        printf("\n Adjacency list of vertex %d \n head ", v);
        while(pCrawl){
            printf("-> %d", pCrawl -> data);
            pCrawl = pCrawl -> next;
        }
        printf("\n");
    }
}

int main(){

    int V = 5;
    struct Graph* graph = makeGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
