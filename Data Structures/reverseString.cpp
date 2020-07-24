#include<iostream>
#include<stack> // stack from standard template lib (STL) 
using namespace std;


void reverse(char *c, int n){

    stack<char> S;

    for(int i = 0; i < n; i++){
        S.push(c[i]);
    }

    for(int i = 0; i < n; i++){
        c[i] = S.top();
        S.pop();
    }
     

}


int main(){
    
    char c[51];
    printf("Enter a string: ");
    gets(c);

    reverse(c, strlen(c));

    printf("reverse: %s \n", c);
    
    return 0;
}