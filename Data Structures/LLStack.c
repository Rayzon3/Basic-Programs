#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};
struct Node* top = NULL;


void Print();

void Push(int x)
{
    struct Node* temp = malloc(sizeof(struct Node*));
    temp -> data = x;
    temp -> link = top;
    top = temp;
    Print();
}

void Pop()
{
    struct Node* temp;
    printf("Poping.....\n");
    if(top == NULL) printf("ERROR: Can't pop, the stack is empty !!");
    temp = top;
    top = top -> link;
    free(temp);
    Print();
}

void Print(){
    struct Node* temp = top;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d ", temp -> data);
        temp = temp -> link;
    }
    printf("\n");

}

void Top()
{
    if(top == NULL) printf("ERROR: Can't return element at top, list is empty\n");
    else printf("The element at top of stack is %d\n", top -> data);
}

int main()
{
    int c, x, r = 1;
    /*
    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Pop();Print();
    Push(4);Print();
    Top();
    */
   while(r == 1)
   {
        printf("**-----------------^------------------**\n");
        printf("Choose from the following :\n");
        printf("1. Push element in list.\n");
        printf("2. Pop element in list.\n");
        printf("3. Return element in top of list.\n");
        printf("4. Exit\n");
        scanf("%d", &c);
        printf("**-----------------^------------------**\n");
        if(c == 1)
        {
            printf("Enter the element you wnat to push: \n");
            scanf("%d", &x);
            Push(x);
        }
        else if(c == 2)
        {
            Pop();
        }
        else if(c == 3)
        {
            Top();
        }
        else if(c == 4)
        {
            r = 0;
            printf("Exited...cya !!\n");
        }

 }

    return 0;
}
