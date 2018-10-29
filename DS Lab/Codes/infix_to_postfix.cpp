#include <iostream>
#include <stack>
#include <cstring>
#include <unordered_map>
using namespace std;
unordered_map<char,int> prec;
void set_prec(){
	prec['('] = 4;
	prec[')'] = 4;
	prec['/'] = 3;
	prec['*'] = 2;
	prec['+'] = 1;
	prec['-'] = 0;
}
bool is_op(char c){
	return prec.count(c);
}
char* to_postfix(char* infix){
	stack<char> s;
	int i = 0,k = 0,n = strlen(infix);
	char* postfix = new char[n];
	while(i < n){
		char c = infix[i];
		if(!is_op(c))
			postfix[k++] = c;
		else if(c == ')'){
			while(s.top() != '('){
				postfix[k++] = s.top();
				s.pop();
			}
			s.pop();
		}
        else if(c == '(')
            s.push(c);
		else if(!s.empty() && prec[s.top()] > prec[c]){
            while(!s.empty() && prec[s.top()] > prec[c]){
                if(s.top() == '(')
                    break;
                postfix[k++] = s.top();
                s.pop();
            }
            s.push(c);
        }
        else
            s.push(c);
		i++;
	}
    while(!s.empty()){
        postfix[k++] = s.top();
        s.pop();
    } 
	return postfix;
}
int main(){
	set_prec();
	char infix[100];
	cin>>infix;
	char* postfix = to_postfix(infix);
	cout<<postfix<<endl;
	return 0;
}