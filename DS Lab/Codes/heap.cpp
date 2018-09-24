#include <iostream>
#define MAX 100
using namespace std;
struct Min_Heap{
	int a[MAX];
	int n;
	Min_Heap(){
		n=-1;
	}
	void insert(int v){
		a[++n] = v;
		int cur = n;
		while(cur!=0){
			int parent = cur>>1;
			if(a[parent] < a[cur])
				break;
			swap(a[parent],a[cur]);
			cur = parent;
		}
	}
	void heapify(int i){
		int left = 2*i + 1, right = 2*i + 2;
        if(left > n)
            return;
		if(a[i] >= a[left]){
			swap(a[i],a[left]);
			heapify(left);
		}
        if(right > n)
            return;
		if(a[i] >= a[right]){
			swap(a[i],a[right]);
			heapify(right);
		}
	}
	int pop(){
		if(n == -1)
			return -1;
		swap(a[0],a[n]);
		int ans = a[n];
		n--;
        heapify(0);
		return ans;
	}
};
int main(){
	Min_Heap h;
	h.insert(3);
	h.insert(2);
	h.insert(5);
	h.insert(1);
	h.insert(4);
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	cout<<h.pop()<<endl;
	return 0;
}