#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Employee{
	int employeeNo;
	string employeeName;
public:
	void getData(){
		cout<<"Enter Name: ";
		cin.ignore();
		getline(cin,employeeName);
		cout<<"Enter employee no: ";
		cin>>employeeNo;
	}
	void display(){
		cout<<"Employee no: "<<employeeNo<<endl;
		cout<<"Employee Name: "<<employeeName<<endl;
	}
	int getID(){
		return employeeNo;
	}
	string getName(){
		return employeeName;
	}
};

bool cmp_id(Employee a,Employee b){
	return a.getID() < b.getID();
}

bool cmp_name(Employee a,Employee b){
	return a.getName() < b.getName();
}

int main(){
	int n;
	cout<<"Enter no of employees: ";
	cin>>n;
	Employee emps[n];

	for(int i=0;i<n;i++){
		cout<<"Employee "<<i+1<<endl;
		emps[i].getData();
	}

	cout<<"\nDisplaying entered details:\n";

	for(int i=0;i<n;i++)
		emps[i].display();

	cout<<"\nSorted according to id:\n";
	sort(emps,emps+n,cmp_id);
	for(int i=0;i<n;i++)
		emps[i].display();

	cout<<"\nSorted according to name:\n";
	sort(emps,emps+n,cmp_name);
	for(int i=0;i<n;i++)
		emps[i].display();

	return 0;
}