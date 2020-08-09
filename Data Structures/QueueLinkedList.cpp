#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear -> next = temp;
    rear = temp;
}

void Dequeue(){
    cout<<"Dequeueing....\n";
    Node* temp = front;
    if(front == NULL) return;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front -> next;
    }
    free(temp);
}

void Front(){
    Node* temp = front;
    cout<<"The element in front of queue is "<<temp -> data<<endl; 
}

void Print(){
    Node* temp = front;
    cout<<"The elements in queue are: ";
    while(temp != NULL){
        cout<<" "<<temp -> data;
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Enqueue(1);Print();
    Enqueue(2);Print();
    Enqueue(3);Print();
    Enqueue(4);Print();
    Dequeue();Print();
    Enqueue(5);Print();
    Front();

    return 0;
}
