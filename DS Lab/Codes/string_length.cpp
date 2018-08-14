#include <iostream>
using namespace std;

char s[50];

int length(char *s){
	int i=0;
	while(s[i++]!='\0'){}
	return i-1;
}
int main(){
	cin.getline(s,50);
	cout<<"Length of "<<s<<" is "<<length(s)<<endl;
	
	return 0;
}