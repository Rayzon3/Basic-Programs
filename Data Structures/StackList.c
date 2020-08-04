#include<stdio.h>
#define MAX_SIZE 100

int A[MAX_SIZE]; 
int top = -1; 

void Push(int x) 
{
  if(top == MAX_SIZE -1) { 
		printf("Error: stack overflow\n");
		return;
	}
	A[++top] = x;
}

void Pop() 
{
	if(top == -1) { 
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}


int Top() 
{
	printf("Element at top : %d \n", A[top]);
}


int IsEmpty()
{
    if(top == -1) return 1;
    return 0;
}


void Print() {
	int i;
	printf("Stack: ");
	for(i = 0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}

int main() {	
	Push(2);Print();
	Push(6);Print();
	Push(7);Print();
	Pop();Print();
	Push(26);Print();
    Top();

    return 0;
}
