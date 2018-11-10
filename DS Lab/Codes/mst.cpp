#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <vector>
using namespace std;
template<class T>
class Graph;
template<class T>
class cmp;
template<typename T>
class DisjointSet{
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
template<class T>
class Edge{
	T u,v;
	int d;
public:
	Edge(){}
	Edge(T s,T e,int dist){
		u = s;
		v = e;
		d = dist;
	}
	friend class Graph<T>;
    friend class cmp<T>;
};
template<class T>
class cmp{
public:
	bool operator () (Edge<T> a,Edge<T> b){
	    return a.d > b.d;
	}
	bool operator () (pair<T,int> a,pair<T,int> b){
	    return a.second > b.second;
	}
};
template<class T>
class Graph{
	//undirected weighted graph
	unordered_map<T,list<pair<T,int> > > adj_list;
	const int INF = 1000000009;
public:
	void add_edge(T u,T v,int d){
		adj_list[u].push_back({v,d});
		adj_list[v].push_back({u,d});
	}
	void add_node(T u){
		adj_list[u];
	}
	int kruskal(){
		DisjointSet<T> ds;
		for(auto p:adj_list)
			ds.make_set(p.first);
		priority_queue<Edge<T>,vector<Edge<T> >,cmp<T> > pq;
		for(auto p:adj_list){
			T u = p.first;
			for(auto v:p.second)
				pq.push(Edge<T>(u,v.first,v.second));
		}
		int cost = 0;
		while(!pq.empty()){
			Edge<T> t = pq.top();
			pq.pop();
			T u = t.u;
			T v = t.v;
			if(ds.find_set(u) != ds.find_set(v)){
				cost += t.d;
				ds.merge(u,v);
			}
		}
		return cost;
	}
	int prim(){
		unordered_map<T,bool> included;
		unordered_map<T,int> weight;
		unordered_map<T,T> parent;
		for(auto p:adj_list)
			weight[p.first] = INF;
		T src = adj_list.begin()->first;
		weight[src] = 0;
		priority_queue<T,vector<pair<T,int> >,cmp<T> > pq;
		pq.push({src,0});
		int cost = 0;
		while(!pq.empty()){
			auto t = pq.top();
			T u = t.first;
			pq.pop();
			if(!included[u]){
				included[u] = true;
				cost += t.second;
				for(auto n:adj_list[u]){
					T v = n.first;
					int d = n.second;
					if(v != parent[u] && !included[v] && d < weight[v]){
						weight[v] = d;
						parent[v] = u;
						pq.push({v,weight[v]});
					}
				}
			}
		}
		return cost;
	}
};
int main(){
	Graph<int> g;
	g.add_edge(1,2,1);
	g.add_edge(1,3,3);
	g.add_edge(2,3,4);
	g.add_edge(2,4,9);
	g.add_edge(3,4,2);
	g.add_edge(3,5,8);
	g.add_edge(4,5,7);
	g.add_edge(4,6,5);
	g.add_edge(5,6,6);
    cout<<g.kruskal()<<endl;
    cout<<g.prim()<<endl;
}
