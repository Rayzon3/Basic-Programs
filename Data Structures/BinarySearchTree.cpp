#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right; // to store address of right child
    Node* left; // to store address of left child
};

Node* MakeNewNode(int data){
    Node* newNode = new Node(); // [ (Node*)malloc(sizeof(Node*)); in C ] creating new node
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* Insert(Node* rootPtr, int data){
    if(rootPtr == NULL){// if tree is empty
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
    else if(data <= rootPtr -> data) return Search(rootPtr -> left, data);
    else return Search(rootPtr -> right, data);  
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

Node* rootPtr; // to store address of root node
rootPtr = NULL; // setting tree empty
rootPtr = Insert(rootPtr, 15);
rootPtr = Insert(rootPtr, 10);
rootPtr = Insert(rootPtr, 43);
rootPtr = Insert(rootPtr, 23);
rootPtr = Insert(rootPtr, 25);
rootPtr = Insert(rootPtr, 8); 
int n;
cout<<"Enter the number to search: \n";
cin>>n;
if(Search(rootPtr, n) == true) cout<<"The number found!\n";
else cout<<"Not found!\n";
int min, max;
min = Min(rootPtr);
max = Max(rootPtr);
cout<<"Max number: "<<max<<endl;
cout<<"Min number: "<<min<<endl;            

return 0;
}


 