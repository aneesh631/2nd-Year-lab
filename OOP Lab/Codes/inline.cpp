#include <iostream>
using namespace std;

class Operation{
public:
	inline int add(int x,int y){
		return x+y;
	}
	inline int subtract(int x,int y){
		return x-y;
	}
	inline int multiply(int x,int y){
		return x*y;
	}
	inline int divide(int x,int y){
		return x/y;
	}
};
int main(){
	Operation op;
	int x,y;
	cin>>x>>y;
	cout<<op.add(x,y)<<endl;
	cout<<op.subtract(x,y)<<endl;
	cout<<op.multiply(x,y)<<endl;
	cout<<op.divide(x,y)<<endl;
}