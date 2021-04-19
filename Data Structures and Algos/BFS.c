#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int head = -1;
int tail = -1;
int queue[MAX];

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

bool IsEmpty(){
    if(head == -1 && tail == -1) return true;
    else return false;
}

void Enqueue(int x){
    if(tail == MAX - 1){
        printf("The Queue is full !! \n");
        return;
    }
    else if(IsEmpty() == true){
        head = 0;
        tail = 0;
    }
    else{
        tail = tail + 1;
    }
    queue[tail] = x;
}

void Dequeue(){
    if(IsEmpty() == true){
        printf("Nothing to dequeue, the queue is empty !! \n");
    }
    else if(tail == head){
        tail = -1;
        head = -1;
    }
    else{
        head = head + 1;
    }
}


void BFS(struct Graph* graph){
    int v_num = 6;
    int visit_arr[6];

    // non-visited vertices = 0
    for(int i = 0; i < 6; i++){
        visit_arr[i] = 0;
    }
    printf("BFS traversal of the given graph is : \n");
    for(int i = 0; i < graph -> V; i++){
        struct Node* temp = graph -> array[i].head;
        if(visit_arr[i] != 1){
            Enqueue(i);
        }
		while(temp != NULL){
			int neighbour = temp -> data;
            Enqueue(neighbour);
            visit_arr[neighbour] = 1;
			temp = temp -> next;
		}
        printf(" %d", head);
        Dequeue();
    }

    printf("\n");
}

int main(){

    int v;

    printf("Enter the number of vertices in the graph: \n");
    scanf("%d", &v);

    struct Graph* graph = MakeGraph(v);

    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 4, 5);

    BFS(graph);

    return 0;
}
