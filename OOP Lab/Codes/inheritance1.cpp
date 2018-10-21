#include <iostream>
using namespace std;

class Father{
protected:
	int age;
public:
	Father(int x){age = x;}
	virtual void iam(){
		cout<<"I am the father, my age is "<<age<<endl;
	}
};
class Son: public Father{
public:
	Son(int x):Father(x){}
	void iam(){
		cout<<"I am the son, my age is "<<age<<endl;
	}
};
class Daughter: public Father{
public:
	Daughter(int x):Father(x){}
	void iam(){
		cout<<"I am the daughter, my age is "<<age<<endl;
	}
};
int main(){
	Father *ptr;
	ptr = new Father(55);
	ptr->iam();
	delete ptr;
	ptr = new Son(20);
	ptr->iam();
	delete ptr;
	ptr = new Daughter(18);
	ptr->iam();
	return 0;
}

