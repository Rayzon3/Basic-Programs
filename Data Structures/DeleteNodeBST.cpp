#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* MakeNewNode(int data){
    Node* newNode = new(Node);
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* Insert(Node* rootptr, int data){
    if(rootptr == NULL){
        rootptr = MakeNewNode(data);
    }
    else if(rootptr -> data <= data){
        rootptr -> left = Insert(rootptr -> left, data);
    }
    else{
        rootptr -> right = Insert(rootptr -> right, data);
    }

    return rootptr;
}

Node* FindMinVal(Node* rootPtr){
    while(rootPtr -> left != NULL){
        rootPtr = rootPtr -> left;
    } 
	return rootPtr;   
}


Node* Delete(Node* rootPtr, int data){
    if(rootPtr == NULL) return NULL;
    else if(data <= rootPtr -> data){
        rootPtr -> left = Delete(rootPtr -> left, data);
    }
    else if(data > rootPtr -> data){
        rootPtr -> right = Delete(rootPtr -> right, data);
    }
    else //Get ready to be deleted!!
    {
        //case:1 No child or leaf node
        if(rootPtr -> left == NULL && rootPtr -> right == NULL){
            delete rootPtr;
            rootPtr = NULL;
        }
        // case:2 Node has one child
        else if(rootPtr -> left == NULL){
            Node* temp = rootPtr;
            rootPtr = rootPtr -> right;
            delete temp;
        }
        else if(rootPtr -> right == NULL){
            Node* temp = rootPtr;
            rootPtr = rootPtr -> left;
            delete temp;
        }

        //case:3 Node has two children
        else{
            Node* temp = FindMinVal(rootPtr -> right);
            rootPtr -> data = temp -> data;
            rootPtr -> right = Delete(rootPtr -> right, temp -> data);
        }
        
     }

     return rootPtr;
}

void Inorder(Node *rootPtr){
    if(rootPtr == NULL) return;
    Inorder(rootPtr -> left);
    cout<<rootPtr -> data<<" ";
    Inorder(rootPtr -> right);
}


int main(){
    Node* rootPtr = NULL;
    rootPtr = Insert(rootPtr, 45);
    rootPtr = Insert(rootPtr, 32);
    rootPtr = Insert(rootPtr, 56);
    rootPtr = Insert(rootPtr, 23);
    rootPtr = Insert(rootPtr, 34);
    rootPtr = Insert(rootPtr, 1);

    cout<<"Elements in BST before deletion: ";
    Inorder(rootPtr);

    Delete(rootPtr, 56);

    cout<<endl;
    cout<<"Elements in BST after deletion:  ";
    Inorder(rootPtr);
    
    return 0;
}
