#include <iostream>
#include <stack>
using namespace std;
struct Queue{
	stack<int> a,b;
	void insert(int v) {
		a.push(v);
	}
	int remove(){
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
		int ans=-1;
		if(!b.empty()){
			ans=b.top();
			b.pop();
		}
		while(!b.empty()){
			a.push(b.top());
			b.pop();
		}
		return ans;
	}
};
int main(){
	Queue q;
	int temp;
	cin>>temp;
	while(temp!=-1){
		q.insert(temp);
		cin>>temp;
	}
	while(1){
		int top=q.remove();
		if(top==-1)
			break;
		cout<<top<<" ";
	}
	cout<<endl;
	return 0;
}