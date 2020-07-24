// Insert numbers in begining of list

#include<iostream>
using namespace std;


struct Node  
{
    int data;
    Node* next;
};
struct Node* head;

void Insert(int x);
void Print();

int main()
{
    head = NULL; //empty list
    printf("How many numbers: \n");
    int n,x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the numbers: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}

void Insert(int x){
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void Print(){
    struct Node* temp = head;
    printf("List is:  ");
    while (temp != NULL){
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    
}