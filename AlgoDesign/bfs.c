#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct Queue{
    int data[MAX];
    int front;
    int rear;
};

struct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int V;
    struct Node** adjList;
    int* visited;
};

struct Node* makeNewNode(int v){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
}

struct Graph* makeGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> V = vertices;

    graph -> adjList = malloc(vertices * sizeof(struct Node*));
    graph -> visited = malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; i++){
        graph -> adjList[i] = NULL;
        graph -> visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int des){
    // src to des
    struct Node* newNode = makeNewNode(des);
    newNode -> next = graph -> adjList[src];
    graph -> adjList[src] = newNode;

    // des to src
    newNode = makeNewNode(src);
    newNode -> next = graph -> adjList[des];
    graph -> adjList[des] = newNode;  
}

struct Queue* makeQueue(){
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue){
    if(queue -> rear == -1){
        return 1;
    }
    else return 0;
}

void enqueue(struct Queue* queue, int data){
    if(queue -> rear == MAX - 1){
        printf("The queue is full ! \n");
    }
    else{
        if(queue -> front == -1){
            queue -> front = 0;
        }
        queue -> rear++;
        queue -> data[queue -> rear] = data;
    }
}

int dequeue(struct Queue* queue){
    int data;
    if(isEmpty(queue)){
        printf("Queue is empty !\n");
        data = -1;
    }
    else{
        data = queue -> data[queue -> front];
        queue -> front++;

        if(queue -> front > queue -> rear){
            printf("Resetting Queue ! \n");
            queue -> front = queue -> rear = -1;
        }
    }
    
    return data;
}

void print(struct Queue* queue){
    int i = queue -> front;

    if(isEmpty(queue)){
        printf("Queue is Empty \n");
    }
    else{
        printf("Items in queue: ");
        for(i = queue -> front; i < queue -> rear + 1; i++){
            printf("%d ", queue -> data[i]);
        }

        printf("\n");
    }
}

void BFS(struct Graph* graph, int startVertex){
    struct Queue* queue = makeQueue();

    graph -> visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while(!isEmpty(queue)){
        print(queue);
        int currentVertex = dequeue(queue);
        printf("Visited: %d \n", currentVertex);

        struct Node* temp = graph -> adjList[currentVertex];

        while(temp){
            int adjVertex = temp -> vertex;

            if(graph -> visited[adjVertex] == 0){
                graph -> visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp -> next;
        }
    }
}

int main() {
  struct Graph* graph = makeGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 3);

  BFS(graph, 0);

  return 0;
}
