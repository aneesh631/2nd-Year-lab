#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(){
		data = 0;
		left = right = NULL;
	}
	Node(int d):data(d),left(NULL),right(NULL){}
	int get_data(){
		return data;
	}
};
struct BST{
	Node* root;
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
	void take_input(){
		int v,temp;
		cin>>v;
		while(v--){
			cin>>temp;
			insert(temp);
		}
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
	b.take_input();
	b.level_order();
	return 0;
}