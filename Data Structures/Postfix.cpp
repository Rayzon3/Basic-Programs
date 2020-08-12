#include<iostream>
#include<stack>
#include<string>

using namespace std;

int EvaluatePostfix(string exp);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);

bool IsNumericDigit(char C);

int main(){
	string exp; 
	cout<<"Enter Postfix Expression \n";
	getline(cin,exp);
	int result = EvaluatePostfix(exp);
	cout<<"Output = "<<result<<"\n";
}


int EvaluatePostfix(string exp){

	stack<int> S;

	for(int i = 0;i< exp.length();i++) {

		 
		if(exp[i] == ' ' || exp[i] == ',') continue; 
 
		else if(IsOperator(exp[i])) {
			
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();
			int result = PerformOperation(exp[i], operand1, operand2);
			S.push(result);
		}
		else if(IsNumericDigit(exp[i])){
			 
			int operand = 0; 
			while(i<exp.length() && IsNumericDigit(exp[i])) {
				 operand = (operand*10) + (exp[i] - '0'); 
				i++;
			} 
			i--;
			S.push(operand);
		}
	} 
	return S.top();
}


bool IsNumericDigit(char C){
	if(C >= '0' && C <= '9') return true;
	return false;
}


bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}


int PerformOperation(char operation, int operand1, int operand2){
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}
