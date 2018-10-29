#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
vector<string> split(string pf){
	istringstream iss(pf);
    string token;
    vector<string> tokens;
    while (getline(iss, token, ' '))
        tokens.push_back(token);
    return tokens;
}
int perform_op(int a,int b,string op){
	if(op == "/")
		return a / b;
	else if (op == "*")
		return a * b;
	else if (op == "+")
		return a + b;
	else
		return a - b;
}
int evaluate_postfix(string pf){
	vector<string> postfix = split(pf);
	stack<int> s;
	int b, a;
	for(int i = 0;i < postfix.size();i++){
		if(isdigit(postfix[i][0]))
			s.push(stoi(postfix[i]));
		else{
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			s.push(perform_op(a,b,postfix[i]));
		}
	}
	return s.top();
}
int main(){
	string postfix;
	getline(cin,postfix);
	cout<<evaluate_postfix(postfix)<<endl;
	return 0;
}