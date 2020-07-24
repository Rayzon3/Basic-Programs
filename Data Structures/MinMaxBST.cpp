#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* MakeNewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* Insert(Node* rootPtr, int data){
    if(rootPtr == NULL){
        rootPtr = MakeNewNode(data);
    }
    else if(data <= rootPtr -> data){
        rootPtr -> left = Insert(rootPtr, data);
    }
    else{
        rootPtr -> right = Insert(rootPtr, data);
    }

    return rootPtr;
}

int Min(Node* rootPtr){
    if(rootPtr == NULL){
        cout<<"The tree is empty\n";
        return -1;
    }
    else if(rootPtr -> left == NULL){
        return rootPtr -> data;
    }

    return Min(rootPtr -> left);
}

int Max(Node* rootPtr){
    if(rootPtr == NULL){
        cout<<"The tree is empty\n";
        return -1;
    }
    else if(rootPtr -> right == NULL){
        return rootPtr -> data;
    }

    return Max(rootPtr -> right);
}


int main(){

    Node* rootPtr = NULL;
    rootPtr = Insert(rootPtr, 12);
    rootPtr = Insert(rootPtr, 3);
    rootPtr = Insert(rootPtr, 45);
    rootPtr = Insert(rootPtr, 7);
    int min, max;
    min = Min(rootPtr);
    max = Max(rootPtr);
    cout<<"Max number: "<<max<<endl;
    cout<<"Min number: "<<min<<endl;
    
    return 0;
}