#include <iostream>
#include <cstdlib>
using namespace std;;
struct Node{
	int data;
	Node *left, *right;
	Node(){
		data = 0;
		left = right = NULL; 
	}
	Node(int d){
		data = d;
		left = right = NULL; 
	}
};
struct Tree{
	Node* root;
	Tree(){
		root = NULL;
	}
	Node* take_input_preorder(){
		int temp;
		cin>>temp;
		if(temp == -1) return NULL;
		else {
			Node* p = new Node(temp);
			p->left = take_input_preorder();
			p->right = take_input_preorder();
			return p;
		}
	}
	void build_tree(){
		root = take_input_preorder();
	}
	void print_inorder_helper(Node* p){
		if(p == NULL) return;
		print_inorder_helper(p->left);
		cout<<p->data<<" ";
		print_inorder_helper(p->right);
	}
	void print_inorder(){
		print_inorder_helper(root);
		cout<<endl;
	}
	void insert(int d){
		if(root == NULL){
			root = new Node(d);
			return;
		}
		Node *p = root;
		while(1){
			if(p->left == NULL){
				p->left = new Node(d);
				return;
			}
			else if(p->right == NULL){
				p->right = new Node(d);
				return;
			}
			else{
				int r = rand()%2;
				p = (r)?p->left:p->right;
			}
		}
	}
};
int main(){
	srand(time(0));
	Tree t;
	t.build_tree();
	t.print_inorder();
	t.insert(4);
	t.print_inorder();
	return 0;
}