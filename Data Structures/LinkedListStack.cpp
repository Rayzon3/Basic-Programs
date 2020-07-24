#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = new(Node);
    temp -> data = x;
    temp -> link = top;
    top = temp;
}

void pop(){
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top -> link;
    free(temp);
}

void print(){
    struct Node* temp = top;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d ", temp -> data);
        temp = temp -> link;
    }

    printf("\n");

}

int main(){
    push(2);
    print();
    push(3);
    print();
    push(4);
    print();
    pop();
    print();

    return 0;
}
