#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class AVL;
class Node{
	int data, bf, h;
	Node *left, *right;
public:
	Node(){}
	Node(int d):data(d),h(1){
        left = right = NULL;
    }
	int get_data(){
		return data;
	}
	friend class AVL;
};
class AVL{
	Node* root;
	void assign(Node*& n){
		//assign height and balance factor
		if(n == NULL) return;
		int lh = (n->left) ? n->left->h : 0;
		int rh = (n->right) ? n->right->h : 0;
		n->h = 1 + max(lh,rh);
		n->bf = lh - rh;
	}
	void L(Node*& c,Node*& p){
		if(p){
			if(p->left == c){
				p->left = c->right;
				c->right = c->right->left;
				p->left->left = c;
				assign(c);
				assign(p->left);
			}
			else{
				p->right = c->right;
				c->right = c->right->left;
				p->right->right = c;
				assign(c);
				assign(p->right);
			}
		}
		else{
			root = c->right;
			c->right = root->left;
			root->left = c;
			assign(c);
			assign(root);
		}
	}
	void R(Node*& c,Node*& p){
		if(p){
			if(p->left == c){
				p->left = c->left;
				c->left = c->left->right;
				p->left->right = c;
				assign(c);
				assign(p->left);
			}
			else{
				p->right = c->left;
				c->left = c->left->right;
				p->right->left = c;
				assign(c);
				assign(p->right);
			}
		}
		else{
			root = c->left;
			c->left = root->right;
			root->right = c;
			assign(c);
			assign(root);
		}
	}

public:
	AVL(){
		root = NULL;
	}
	void insert(int v){
		if(root == NULL){
			root = new Node(v);
			return;
		}
		Node *prev = NULL, *cur = root;
		stack<Node*> a;
		a.push(prev);
		a.push(root);
		while(cur != NULL){
			prev = cur;
			if(cur->data <= v){
				a.push(cur->right);
				cur = cur->right;
			}
			else{
				a.push(cur->left);
				cur = cur->left;
			}
		}
        //pop NULL
		a.pop();
        Node* t = a.top();
		if(prev->data <= v){
			prev->right = new Node(v);
			a.push(prev->right);
		}
		else{
			prev->left = new Node(v);
			a.push(prev->left);
		}
		stack<Node*> ar;
		while(!a.empty()){
			Node*& t = a.top();
            if(t == NULL)
                break;
			a.pop();
			assign(t);
			if(abs(t->bf) > 1){
				Node*& parent = a.top();
                Node*& cur = t;
				Node*& child = ar.top();
				ar.pop();
				Node*& grand_child = ar.top();
                ar.pop();
				if(cur->left == child && child->left == grand_child){
					//left left
                    R(cur,parent);
				}
				else if(cur->left == child && child->right == grand_child){
					//left right
					L(child,cur);
					R(cur,parent);
				}
				else if(cur->right == child && child->right == grand_child){
					//right right
					L(cur,parent);
				}
				else if(cur->right == child && child->left == grand_child){
					//right left
					R(child,cur);
					L(cur,parent);
				}
				return;
			}
			ar.push(t);
		}
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
				cout<<f->data<<" ";//<<"("<<f->bf<<") ";
				if(f->left) q.push(f->left);
				if(f->right) q.push(f->right);
			}
		}
	}
};
int main(){
	AVL t;
    t.insert(5);
	t.insert(4);
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.insert(0);
    t.level_order();
    return 0;
}