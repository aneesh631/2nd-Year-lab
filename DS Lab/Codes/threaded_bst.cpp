#include <iostream>
#include <queue>
using namespace std;
class Threaded_BST;
class Node{
	int data;
	Node *left, *right;
	bool lthread,rthread;
public:
	Node(){
		data = 0;
		left = right = NULL;
		lthread = rthread = true;
	}
	Node(int d):data(d),left(NULL),right(NULL){
		lthread = rthread = true;
	}
	friend class Threaded_BST;
};
class Threaded_BST{
	Node* root;
	Node* left_most(Node* root){
        int itr = 0;
		if(root == NULL) return NULL;
		while(!(root->lthread)) {
            root = root->left;
            itr++;
            if(itr == 3) break;
        }
		return root;
	}
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
	Threaded_BST(){
		root = NULL;
	}
	void insert(int v){
		if(root == NULL){
			root = new Node(v);
			root->lthread = root->rthread = false;
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
		if(prev->data < v){
			Node* nn = new Node(v);
			nn->right = prev->right;
			nn->left = prev;
			prev->right = nn;
			prev->rthread = false;
		}
		else{
			Node* nn = new Node(v);
			nn->right = prev;
			nn->left = prev->left;
			prev->left = nn;
			prev->lthread = false;
		}
	}
	void remove(int v){
		remove_node(root,NULL,v);
	}
	void inorder(){
        cout<<"here\n";
        return;
		Node* c = left_most(root);
        cout<<c->data<<endl;
		while(c != NULL){
			cout<<c->data<<"\n";
            break;
			if(c->rthread){
                cout<<"rthread found!\n";
                c = c->right;
            }
			else c = left_most(c->right);
		}
	}
};
int main(){
	Threaded_BST b;
	b.insert(4);
	b.insert(2);
	b.insert(6);
	b.insert(1);
    // b.insert(3);
    // b.insert(5);
    // b.insert(7);
    /*       4
           /   \
          2     6
         / \   / \
        1   3 5   7
    */
    b.inorder();
}