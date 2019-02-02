#include <iostream>
#include <cstdlib>
using namespace std;
int partition(int* a,int lo,int hi){
	//partions the array a acc to a[hi]
	int j = lo;
	for(int i = lo;i <= hi;i++){
		if(a[i] >= a[hi]) continue;
		else swap(a[i],a[j++]);
	}
	swap(a[j],a[hi]);
	return j;
}
void quicksort(int* a,int lo,int hi){
	if(lo >= hi) return;
	int id = partition(a,lo,hi);
	quicksort(a,lo,id - 1);
	quicksort(a,id + 1,hi);
}
void shuffle(int* a,int n){
	for(int i = n - 1;i > 0 ;i--){
		int id = rand() % i;
		swap(a[i],a[id]);
	}
}
void randomized_quicksort(int* a,int n){
	shuffle(a,n);
	quicksort(a,0,n - 1);
}
int main(){
	srand(time(0));
	int a[100];
	int n = rand() % 100;
	for(int i = 0;i < n;i++)
		a[i] = rand() % 1000;
	for(int i = 0;i < n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	randomized_quicksort(a,n);
	for(int i = 0;i < n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}