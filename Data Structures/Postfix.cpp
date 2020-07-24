#include<iostream>
#include<string>
#include<stack>
using namespace std;

int evaluate(string a){

    stack<char> S;
    int x, y, z;

    for(int i; i < a.length(); i++){
        
        if(a[i] == ' '  || ',') continue;
        else if(a[i] != '+' || '-' || '*' || '/'){
            S.push(a[i]);
        }
        else if(a[i] == '+'){
            x = S.top();
            S.pop();
            y = S.top();
            S.pop();
            z = x + y;
            S.push(z);
            }
        else if(a[i] == '-'){
            x = S.top();
            S.pop();
            y = S.top();
            S.pop();
            z = x - y;
            S.push(z);
            }
        else if(a[i] == '*'){
            x = S.top();
            S.pop();
            y = S.top();
            S.pop();
            z = x + y;
            S.push(z);
            }
        else if(a[i] == '/'){
            x = S.top();
            S.pop();
            y = S.top();
            S.pop();
            z = x + y;
            S.push(z);
            }
    }

    return S.top();


}

int main(){
    
    string a;

    cout<<"Enter an expression: "<<endl;
    cin>>a;

    evaluate(a);


    
    
    return 0;
}