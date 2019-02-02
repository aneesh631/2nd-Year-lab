#include <iostream>
using namespace std;
void bubblesort(int* a,int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1])
				swap(a[j + 1],a[j]);
		}
	}
}
int main(){
	int n,a[20];
	cin>>n;
	cout<<"Enter "<<n<<" nos:\n";
	for(int i = 0; i < n ;i++)
		cin>>a[i];
	bubblesort(a,n);
	cout<<"Sorted array:\n";
	for(int i = 0; i < n ;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}