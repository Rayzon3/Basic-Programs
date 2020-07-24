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
        rootPtr -> left = Insert(rootPtr -> left, data); 
    }
    else{
        rootPtr -> right = Insert(rootPtr -> right, data);
    }

    return rootPtr;
}

bool Search(Node* rootPtr, int data){
    if(rootPtr == NULL) return false;
    else if(rootPtr -> data == data) return true;
    else if(rootPtr -> data <= data) return Search(rootPtr -> left, data);
    else return Search(rootPtr -> right, data);  
}

int main(){
    
    Node* rootPtr = NULL; // creating empty tree
    rootPtr = Insert(rootPtr, 5);
    rootPtr = Insert(rootPtr, 7);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 4);
    int n;
    cout<<"Enter the number to search: \n";
    cin>>n;
    if(Search(rootPtr, n) == true){
        cout<<"Found!\n";
    }
    else{
        cout<<"Not found\n";
    }
    
    return 0;
}