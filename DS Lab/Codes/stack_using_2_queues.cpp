#include <iostream>
#include <queue>
using namespace std;
struct Stack{
	queue<int> q1,q2;
	void push(int v){
		bool e1 = !q1.empty(), e2 = !q2.empty();
		if(e1 && e2)
			q1.push(v);
		else if(e1){
			q2.push(v);
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
		}
		else{
            q1.push(v);
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
		}
	}
	int top(){
		bool e1 = q1.empty(), e2 = q2.empty();
		if(e1 && e2)
			return -1;
		else if(e1)
			return q2.front();
		else
			return q1.front();
	}
	void pop(){
		bool e1 = q1.empty(), e2 = q2.empty();
		if(e1 && e2)
			return;
		else if(e1)
			return q2.pop();
		else
			return q1.pop();
	}
	bool empty(){
		return top() == -1;
	}
};
int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
    s.push(4);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}