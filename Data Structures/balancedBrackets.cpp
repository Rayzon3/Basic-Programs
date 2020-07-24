#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isPair(char opening, char closing){
    if((opening == '(') && (closing == ')')) return true;
    else if((opening == '{') && (closing == '}')) return true;
    else if((opening == '[') && (closing == ']')) return true;
    else return false;
}


bool balanced(string a){

    stack<char> S;


    for(int i = 0; i < a.length(); i++){
        if(a[i] == '(' || '{' || '['){
            S.push(a[i]);
        }
        else if(a[i] == ')' || '}' || ']'){
            if((S.empty() == true) || !isPair(S.top(), a[i])){
                return printf("Not balanced \n");
            }  
        }
        else{
            S.pop();
        }
        
    }

    return S.empty() ? true : false;

}


int main(){

    string a;
    
    cout<<"Enter a string: "<<endl;
    cin>>a;
    if(balanced(a)){
        cout<<"Balanced"<<endl;
    }
    else
        cout<<"Not balanced"<<endl;

    return 0;
}