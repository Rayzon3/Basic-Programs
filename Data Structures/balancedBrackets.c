#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

void Push(char C){
	if(top == MAX -1) { 
		printf("Error: Stack Overflow :/ \n");
		return;
	}
	stack[++top] = C;
}

void Pop(){
	if(top == -1) { 
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

char Top(){
	return stack[top];
}

bool IfPair(char opening, char closing){
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	else return false;

}

bool Check(char *exp){
	for(int i = 0; i < strlen(exp); i++){
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
			Push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
			if(IfPair(Top(), exp[i]) == true){
				return true;
			}
			else return false;
		}
	}

	return NULL;
}


int main(){

	char exp[MAX];
	
	printf("Enter the expression : ");
	gets(exp);

	if(Check(exp) == true){
		printf("Balanced\n");
	}
	else printf("Not balanced\n");
	
	return 0;
}
