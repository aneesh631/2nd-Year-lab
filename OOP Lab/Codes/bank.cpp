#include <iostream>
#include <cmath>
using namespace std;
class Bank{
	float balance,rate;
	float getBalance(){
		return balance;
	}
	float getRate(){
		return rate;
	}
	float deposit(float m){
		balance+=m;
		return balance;
	}
	float withdraw(float m){
		if(balance>=m)
			balance-=m;
		return balance;
	}
	float compound(int t){
		return balance*pow(1+rate/100,t);
	}
public:
	Bank(){
		cout<<"Enter balance and rate:";
		cin>>balance>>rate;
	}
	~Bank(){
		cout<<"I am destroyed."<<endl;
	}
	int menu(){
		int op;
		cout<<"1 - Deposit"<<endl;
		cout<<"2 - Withdraw"<<endl;
		cout<<"3 - Compound interest"<<endl;
		cout<<"4 - Get balance"<<endl;
		cout<<"5 - Exit"<<endl;
		cin>>op;
		switch(op){
			float money,time;
			case 1:
				cout<<"Enter amount to deposit: ";
				cin>>money;
				cout<<"Current balance: "<<deposit(money)<<endl;
				break;
			case 2:
				cout<<"Enter amount to withdraw: ";
				cin>>money;
				cout<<"Current balance: "<<withdraw(money)<<endl;
				break;
			case 3:
				cout<<"Enter time: ";
				cin>>time;
				cout<<"Compound interest: "<<compound(time)<<endl;
				break;
			case 4:
				cout<<"Current balance: "<<getBalance()<<endl;
				break;
		}
		return op;
	}
};
int main(){
	Bank aneesh;
	while(aneesh.menu()!=5){}
	return 0;
}