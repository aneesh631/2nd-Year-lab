#include <iostream>
#include <cstring>
using namespace std;

class String{
	char* s;
	int len;
public:
	String(){
		s = NULL;
		len = 0;
	}
	String(char* p){
		len = strlen(p);
		s = new char[len+1];
		strcpy(s,p);
	}
    //concatenates the 2 strings
	String operator+(String& b) const {
		char* n = new char[len + b.len + 1];
		strcpy(n,s);
		strcat(n,b.s);
		String ans =  String(n);
		delete n;
		return ans;
	}
    //deletes last few chars
	String operator-(String& b) const {
		int new_len = (len >= b.len)?len - b.len:0;
		char* n = new char[new_len + 1];
		strncpy(n,s,new_len);
        n[new_len] = '\0';
		String p(n);
		delete n;
		return p;
	}
	void print(){
		cout<<s<<endl;
	}
};

int main(){
	String a("abc"), b("d"), c;
    c = a + b;
    c.print();
    c = a - b;
	c.print();
    return 0;
}