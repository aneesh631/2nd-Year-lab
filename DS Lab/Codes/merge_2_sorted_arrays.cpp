#include <iostream>
using namespace std;
int a[10],b[10],c[20];
int x,y;
void merge(int *a,int *b,int *c){
	int i=0,j=0,k=0;
	while(i<x && j<y){
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];
	}
	while(i<x)
		c[k++]=a[i++];
	while(j<y)
		c[k++]=b[j++];
}
int main(){
	cin>>x;
	for(int i=0;i<x;i++)
		cin>>a[i];
	cin>>y;
	for(int i=0;i<y;i++)
		cin>>b[i];
	cout<<"array 1:\n";
	for(int i=0;i<x;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"array 2:\n";
	for(int i=0;i<y;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	merge(a,b,c);
	cout<<"merged array :\n";
	for(int i=0;i<x+y;i++)
		cout<<c[i]<<" ";
	cout<<endl;	
	return 0;
}