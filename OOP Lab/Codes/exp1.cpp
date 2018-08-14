#include <iostream>
#include <string>
using namespace std;

class User{
	string id,password,firstName,lastName;
	char gender;
	int totalMarks;
	bool result;
	void printDetails(){
		cout<<"Name: "<<firstName<<" "<<lastName<<endl;
		cout<<"Gender: "<<gender<<endl;
		cout<<"Total marks: "<<totalMarks<<endl;
		cout<<"Result: "<<(result?"Pass\n":"Fail\n");
	}
public:
	User(string i,string pass,string fn,string ln,char g,int tm){
		id =i ;
		password = pass;
		firstName = fn;
		lastName = ln;
		gender = g;
		totalMarks = tm;
		result = (tm >= 50)?1:0;
	}
	void login(){
		string i,p;
		cout<<"Enter id: ";
		cin>>i;
		cout<<"Password: ";
		cin>>p;
		if(i == id && p == password)
			printDetails();
		else
			cout<<"Unauthorized!\n";
	}
};

int main(){
	User aneesh("aneesh","123456","Aneesh","Kundu",'M',100);
	aneesh.login();
	return 0;
}