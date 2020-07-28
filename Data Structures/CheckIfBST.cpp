#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left; 
};

Node* MakeNewNode(int data){
    Node* newNode = new(Node);
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

bool isSubTreeLesser(Node* rootPtr, int data){
    if(rootPtr == NULL) return true;
    if((rootPtr -> data <= data) && isSubTreeLesser(rootPtr -> left, data)
    &&  isSubTreeLesser(rootPtr -> right, data)){
        return true;
    }
    else return false;
}

bool isSubTreeGreater(Node* rootPtr, int data){
    if(rootPtr == NULL) return true;
    if((rootPtr -> data > data) && isSubTreeGreater(rootPtr -> right, data)
    && isSubTreeGreater(rootPtr -> right, data)){
        return true;
    }
    else return false;
}

bool isBST(Node* rootPtr){
    if(rootPtr == NULL) return true;
    if(isSubTreeLesser(rootPtr -> left, rootPtr -> data)
    && isSubTreeGreater(rootPtr -> right, rootPtr -> data)
    && isBST(rootPtr -> left) && isBST(rootPtr -> right)){
        return true;
    }
    else return false;
}

int main(){
    Node* rootPtr = NULL;    
    rootPtr = Insert(rootPtr, 4);
    rootPtr = Insert(rootPtr, 67);
    rootPtr = Insert(rootPtr, 98);
    rootPtr = Insert(rootPtr, 23);
    rootPtr = Insert(rootPtr, 12);   

    if(isBST(rootPtr) == true){
        cout<<"The Binary Tree is Binary Search Tree.\n";
    }
    else cout<<"The Binary Tree is not a Binary Search Tree.\n";
    
    return 0;
}
