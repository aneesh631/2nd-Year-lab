#include <iostream>
using namespace std;
class pntr_obj{
	char name[20];
	int roll_no;
public:
	void set_data(){
		cin>>name>>roll_no;
	}
	void print(){
		cout<<"Name: "<<this->name<<endl;
		cout<<"Roll#: "<<this->roll_no<<endl;
	}
};
int main(){
	pntr_obj a,b,c;
	a.set_data();
	b.set_data();
	c.set_data();
	a.print();
	b.print();
	c.print();
	return 0;
}