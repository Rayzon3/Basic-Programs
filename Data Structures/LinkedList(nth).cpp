// insert node at nth position

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next; 
};

struct Node* head;

void Insert(int data, int n);
void Print();

int main(){

    head = NULL; //empty list
    Insert(2,1); // List: 2
    Insert(3,2); // List: 3 2
    Insert(4,3); // List: 4 3 2
    Insert(5,4); // List: 5 4 3 2
    Insert(6,5); // List: 6 5 4 3 2

}



