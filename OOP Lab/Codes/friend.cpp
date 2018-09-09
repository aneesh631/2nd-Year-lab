#include <iostream>
using namespace std;

class friendfunc1;
class friendfunc2;

class friendfunc1 {
	int a,b;
public:
	friendfunc1(){
		cin>>a>>b;
	}
	friend float avg(friendfunc1,friendfunc2);
};
class friendfunc2 {
	int a,b,c;
public:
	friendfunc2(){
		cin>>a>>b>>c;
	}
	friend float avg(friendfunc1,friendfunc2);
};
float avg (friendfunc1 f1,friendfunc2 f2){
	return (f1.a+f1.b+f2.a+f2.b+f2.c)/5.0;
}
int main(){
	friendfunc1 a;
	friendfunc2 b;
	cout<<avg(a,b)<<endl;
	return 0;
}