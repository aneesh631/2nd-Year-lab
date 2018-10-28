#include <iostream>
using namespace std;
class BST;
class Node{
	int data;
	Node *left, *right;
public:
	Node(){
		data = 0;
		left = right = NULL;
	}
	Node(int d):data(d),left(NULL),right(NULL){}
	int get_data(){
		return data;
	}
	friend class BST;
};
class Pair{
	bool first;
	Node* second;
	friend class BST;
public:
	Pair(){}
	Pair(bool r,Node* p){
		first = r;
		second = p;
	}
};
class BST{
	Node* root;
	Pair find_parent(int v,Node *s){
		if(s == NULL)
			return Pair(false,NULL);
		Node *prev = NULL, *cur = s;
		while(cur != NULL){
			if(cur->data == v)
				return Pair(true,prev);
			else if(cur->data < v)
				cur = cur->right;
			else
				cur = cur->left;
			prev = cur;
		}
		return Pair(false,prev);
	}
public:
	BST(){
		root = NULL;
	}
	void insert(int v){
		if(root == NULL){
			root = new Node(v);
			return;
		}
		Node *prev = NULL, *cur = root;
		while(cur != NULL){
			prev = cur;
			if(cur->data <= v)
				cur = cur->right;
			else
				cur = cur->left;
		}
		if(prev->data <= v)
			prev->right = new Node(v);
		else
			prev->left = new Node(v);
	}
	Node* find(int v){
		Pair p = find_parent(v,root);
		if(!p.first) return NULL;
		if(p.second->data <= v)
			return p.second->right;
		else
			return p.second->left;
	}
	void remove(int v,Node* s){
		if(s == NULL) s = root;
		Pair p = find_parent(v,s);
		if(!p.first) return;
		Node* c;
		int side;

		if(p.second->data <= v){
			side = 1;
			c = p.second->right;
		}
		else{
			side = 0;
			c = p.second->left;
		}
		//only 1 child
		if(c->left == NULL){
			if(side)
				p.second->right = c->right;
			else
				p.second->left = c->right;
			delete c;
			return;
		}
		if(c->right == NULL){
			if(side)
				p.second->right = c->left;
			else
				p.second->left = c->left;
			delete c;
			return;
		}
		//2 childeren
		// pick the largest from the left subtree
		Node *pl = NULL, *l = c;
		while(l->right != NULL){
			pl = l;
			l = l->right;
		}
		c->data = l->data;
		remove(l->data,pl);
	}
};
int main(){
	BST b;
	b.insert(4);
	b.insert(3);
	b.insert(5);
	b.insert(2);

	Node* f = b.find(4);
	if(f == NULL) cout<<"Not found!\n";
	else cout<<"Found!\n";

	f = b.find(5);
	if(f == NULL) cout<<"Not found!\n";
	else cout<<"Found!\n";

	return 0;
}