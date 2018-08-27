#include <iostream>
using namespace std;

void swap_value(int a,int b){
	int c=b;
	b=a;
	a=c;
}
void swap_reference(int &a,int &b){
	int c=b;
	b=a;
	a=c;
}

int main(){
	int a=1,b=3;
	cout<<"a: "<<a<<" b: "<<b<<endl;
	cout<<"1 - swap by value\n";
	cout<<"2 - swap by swap by reference\n";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
			swap_value(a,b);
			cout<<"a: "<<a<<" b: "<<b<<endl;
			break;
		case 2:
			swap_reference(a,b);
			cout<<"a: "<<a<<" b: "<<b<<endl;
			break;
	}
	return 0;
}