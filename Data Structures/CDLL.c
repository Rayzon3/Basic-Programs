#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
struct Node* tail;


struct Node* CreateNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertNode(int x){
    struct Node* newNode = CreateNewNode(x);
    newNode -> data = x;
    if(head == NULL){
        head = tail = newNode;
        head -> next = head;
        head -> prev = head;
    }
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        newNode -> next = head;
        head -> prev = newNode;
        tail = newNode;
    }
}

void Print() {
	struct Node* temp = head;
    if(head == NULL){
        printf("The list is empty \n");
    }
	printf("List is : ");
	while(temp != tail) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
    printf("%d", temp -> data);
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
            InsertNode(x);
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
