#include <iostream>
#include <queue>
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
	void remove_node(Node*& root,Node* p,int v){
		if(root == NULL) return;
		Node* c = root;
		while(c != NULL){
			if(c->data == v) break;
			else if(c->data < v){
				p = c;
				c = c->right;
			}
			else{
				p = c;
				c = c->left;
			}
		}
		if(c){
			if(c->left == NULL && c->right == NULL){
				//no children
				if(p){
					if(p->left == c) p->left = NULL;
					else p->right = NULL;
				}
				else root = NULL;
				delete c;
				return;
			}
			else if(c->left && c->right == NULL){
				//only left child exists
				if(p){
					if(p->left == c) p->left = c->left;
					else p->right = c->left;
				}
				else root = c->left;
				delete c;
			}
			else if(c->right && c->left == NULL){
				//only right child exists
				if(p){
					if(p->left == c) p->left = c->right;
					else p->right = c->right;
				}
				else root = c->right;
				delete c;
			}
			else{
				//both children exist
				//pick the largest value of the left subtree
				Node* l = c->left, *lp = c;
				while(l->right){
					lp = l;
					l = l->right;
				}
				c->data = l->data;
				remove_node(l,lp,l->data);
			}
		}
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
		Node* p = NULL;
		Node* c = root;
		while(c != NULL){
			if(c->data == v) return c;
			else if(c->data < v){
				p = c;
				c = c->right;
			}
			else{
				p = c;
				c = c->left;
			}
		}
		return NULL;
	}
	void remove(int v){
		remove_node(root,NULL,v);
	}
	void level_order(){
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()){
			Node* f = q.front();
			q.pop();
			if(f == NULL){
				cout<<endl;
				if(!q.empty())
					q.push(NULL);
			}
			else{
				cout<<f->data<<" ";
				if(f->left) q.push(f->left);
				if(f->right) q.push(f->right);
			}
		}
	}
};
int main(){
	BST b;
	b.insert(4);
	b.insert(2);
	b.insert(6);
	b.insert(1);
    b.insert(3);
    b.insert(5);
    b.insert(7);
    /*       4
           /   \
          2     6
         / \   / \
        1   3 5   7
    */

	b.level_order();
	b.remove(2);
	b.level_order();
}