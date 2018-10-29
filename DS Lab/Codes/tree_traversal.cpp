#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(){
		left = right = NULL;
	}
	Node(int d):data(d),left(NULL),right(NULL){}
};
Node* build_tree_preorder(){
	int d;
	cin>>d;
	if(d != -1){
		Node* root = new Node(d);
		root->left = build_tree_preorder();
		root->right = build_tree_preorder();
		return root;
	}
	else return NULL;
}
void preorder(Node* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int main(){
	Node* root = build_tree_preorder();
	cout<<"preorder: ";
	preorder(root);
	cout<<endl;
	cout<<"inorder: ";
	inorder(root);
	cout<<endl;
	cout<<"postorder: ";
	postorder(root);
	cout<<endl;
	return 0;
}