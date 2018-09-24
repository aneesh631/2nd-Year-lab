#include <iostream>
using namespace std;

int absolute_value(int x){
	return x>0?x:-x;
}
float absolute_value(float x){
	return x>0?x:-x;
}
int main(){
	int x;
	float y;
	cin>>x>>y;
	cout<<absolute_value(x)<<endl;
	cout<<absolute_value(y)<<endl;
}