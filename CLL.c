#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* ptr = NULL;

void Insert(int x){
    struct Node* newNode = malloc(sizeof(struct Node*));
    newNode -> data = x;
    
    if(head == NULL){
        head = ptr = newNode;
    }
    else{
        ptr -> next = newNode;
        ptr = newNode;
    }
    ptr -> next = head;
}


void Print(){
    struct Node* temp = head;
    if(head == NULL){
        printf("The list is empty \n");
    }
    printf("List is:  ");
    while (temp -> next != head){
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf(" %d", temp -> data);
    printf("\n");
    
}


int main(){
    
    bool check = true;
    int c, x;

    while(check != false){
        printf("###########################################\n");
        printf("Choose from the following: \n");
        printf("1. Insert element in the list \n");
        printf("2. Print all elements in the list \n");
        printf("3. Exit \n");
        scanf("%d", &c);      
        printf("###########################################\n");
  
        if(c == 1){
            printf("Enter the number you want to insert: \n");
            scanf("%d", &x);
            Insert(x);
        }
        else if(c == 2){
            Print();
        }
        else if(c == 3){
            printf("Imma head out.... :/ \n");
            check = false;
        }
        else{
            printf("Enter correct choice !! \n");
        }
    }
    
    return 0;
}
