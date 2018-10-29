#include <iostream>
#include <map>
using namespace std;
template<typename T>
class DisjointSet{
	//map gives more freedom over unordered map
	map<T,T> parent;
	map<T,int> rank;
public:
	void make_set(T u){
		parent[u] = u;
		rank[u] = 1;
	}
	T find_set(T u){
		if(parent[u] == u) return u;
		T representative = find_set(parent[u]);
		if(representative != parent[u])
			parent[u] = representative;
		return representative;
	}
	void merge(T u,T v){
		//union
		T rep1 = find_set(u);
		T rep2 = find_set(v);
		if(rep1 == rep2) return;
		if(rank[rep1] >= rank[rep2]){
			parent[rep2] = rep1;
			rank[rep1]++;
		}
		else{
			parent[rep1] = rep2;
			rank[rep2]++;
		}
	}
};
int main(){
	DisjointSet<int> d;
	d.make_set(1);
	d.make_set(2);
	d.make_set(3);
	d.make_set(4);
	d.make_set(5);
	d.make_set(6);
	d.make_set(7);
	d.make_set(8);

	cout<<d.find_set(2)<<" "<<d.find_set(3)<<endl;
	d.merge(2,3);
	cout<<d.find_set(2)<<" "<<d.find_set(3)<<endl;

	cout<<d.find_set(4)<<" "<<d.find_set(5)<<endl;
	d.merge(4,5);
	cout<<d.find_set(4)<<" "<<d.find_set(5)<<endl;

	cout<<d.find_set(2)<<" "<<d.find_set(3)<<" "<<d.find_set(4)<<" "<<d.find_set(5)<<endl;
	d.merge(2,4);
	cout<<d.find_set(2)<<" "<<d.find_set(3)<<" "<<d.find_set(4)<<" "<<d.find_set(5)<<endl;

	return 0;
}