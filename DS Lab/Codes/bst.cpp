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
class BST{
	Node* root;
	pair<bool,Node*> find_parent(int v){
		if(root == NULL)
			return NULL;
		Node *prev = NULL, *cur = root;
		while(cur != NULL){
			if(cur->data == v)
				return make_pair(true,prev);
			else if(cur->data < v)
				cur = cur->right;
			else
				cur = cur->left;
			prev = cur;
		}
		return make_pair(false,prev);
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
		pair<bool,Node*> p = find_parent(v);
		if(!p.first) return NULL:
		if(p.second->data <= v)
			return p.second->right;
		else
			return p.second->left;
	}
	void remove(int v,Node* s = root){
		pair<bool,Node*> p = find_parent(v);
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

	}
};
int main(){
	BST b;
	b.insert(4);
	b.insert(3);
	b.insert(5);
	b.insert(2);
	Node* f = b.find(6);
	if(f == NULL)
		cout<<"Not found!";
	return 0;
}