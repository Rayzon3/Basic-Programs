//Implementation of graph adjacency list

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct List{
	struct Node* head;
};

struct Graph{
	int V;
	struct List* array;
};

struct Node* MakeNewNode(int x){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode -> data = x;
	newNode -> next = NULL;

	return newNode;
}

struct Graph* MakeGraph(int v){
	struct Graph* graph = malloc(sizeof(struct Graph));

	graph -> V = v;
	graph -> array = malloc(sizeof(struct List)*v);

	for(int i = 0; i < v; i++){
		graph -> array[i].head = NULL;
	}

	return graph;
}

void AddEdge(struct Graph* graph, int src, int des){
	struct Node* temp = MakeNewNode(des);
	temp -> next = graph -> array[src].head;
	graph -> array[src].head = temp;
}

void Print(struct Graph* graph){
	for(int i = 0; i < graph -> V; i++){
		struct Node* temp = graph -> array[i].head;
		printf("\n Adjacency list of vertex %d \n head", i);
		while(temp != NULL){
			printf(" -> %d", temp -> data);
			temp = temp -> next;
		}
		printf("\n");
	}
}


int main(){
	
	int v = 5;

	printf("Enter the number of vertices the graph has : \n");
	struct Graph* graph = MakeGraph(v);
	AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);

	Print(graph);
	
	return 0;
}
