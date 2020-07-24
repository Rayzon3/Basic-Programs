#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct Node* head; //pointer to head node - global


// Funtion to create new node
struct Node* MakeNewNode(int x){
    struct Node* newNode = new(Node); 
    newNode -> data = x;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

// Function to insert node at begining of list
void insertAtBegining(int x){
     struct Node* newNode = MakeNewNode(x);
     if(head == NULL){
         head = newNode;
         return;
     }
     head -> prev = newNode;
     newNode -> next = head;
     head = newNode;
}

// Function to insert node at the end of the list
void insertAtTail(int x){
    struct Node* temp = head; //creating temperary var
    struct Node* newNode = MakeNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    } 
    while(temp -> next != NULL) temp = temp -> next; //Traversing to the last node
    temp -> next = newNode;
    newNode -> prev = temp;
}


// function to print elements of list in forward traversal order
void forwardPrint(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp -> next != NULL){
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

// function to print elements of list in reverse traversal order
void reversePrint(){
    struct Node* temp = head;
    if(head == NULL) return; // list is empty 
    // Moving to last node
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    printf("Reverse: ");
    // Traversing
    while(temp != NULL){
        printf(" %d",temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}

int main(){
    head = NULL;

    insertAtBegining(2); forwardPrint(); reversePrint();
    insertAtBegining(3); forwardPrint(); reversePrint();
    insertAtTail(4); forwardPrint(); reversePrint();
    insertAtBegining(5); forwardPrint(); reversePrint();

    return 0;
}