#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<class T>
class DAG{
	unordered_map<T,list<T> > adj_list;
	void topo_dfs_helper(T node,unordered_map<T,bool>& visited,stack<T>& s){
		visited[node] = true;
		for(auto n:adj_list[node]){
			if(!visited[n])
				topo_dfs_helper(n,visited,s);
		}
		s.push(node);
	}
public:
	void add_edge(T u,T v){
		adj_list[u].push_back(v);
	}
	void add_node(T u){
		adj_list[u];
	}
	stack<T> topo_dfs(){
		unordered_map<T,bool> visited;
		stack<T> ts;
		for(auto p:adj_list){
			if(!visited[p.first])
				topo_dfs_helper(p.first,visited,ts);
		}
		return ts;
	}
	list<T> topo_bfs(){
		unordered_map<T,int> indegree;
		for(auto p:adj_list){
			for(T n:p.second)
				indegree[n]++;
		}
		queue<T> q;
		for(auto p:adj_list){
			if(indegree[p.first] == 0)
				q.push(p.first);
		}
		list<T> ts;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			ts.push_back(node);
			for(T n:adj_list[node]){
				indegree[n]--;
				if(indegree[n] == 0)
					q.push(n);
			}
		}
		return ts;
	}
};
int main(){
	DAG<int> g;
	g.add_edge(1,3);
	g.add_edge(1,4);
	g.add_edge(3,5);
	g.add_edge(4,5);
	g.add_edge(4,6);
	g.add_edge(5,6);
	g.add_edge(6,7);
	g.add_edge(2,4);

	stack<int> ts_dfs = g.topo_dfs();
	while(!ts_dfs.empty()){
		cout<<ts_dfs.top()<<" ";
		ts_dfs.pop();
	}
	cout<<endl;

	list<int> ts_bfs = g.topo_bfs();
	for(int e:ts_bfs)
		cout<<e<<" ";
	cout<<endl;
}
