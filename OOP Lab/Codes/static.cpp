#include <iostream>
using namespace std;

class cont{
	static int cnt;
public:
	cont(){
		cnt++;
	}
	~cont(){
		cnt--;
	}
	static int get_count(){
		return cnt;
	}
};
int cont::cnt;
int main(){
	cont a;
	cout<<"count = "<<cont::get_count()<<endl;
	cont *b = new cont[10];
	cout<<"count = "<<cont::get_count()<<endl;
	delete []b;
	cout<<"count = "<<cont::get_count()<<endl;
	return 0;
}

