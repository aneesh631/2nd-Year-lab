#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int d){
		data = d;
		next = NULL;
	}
};
struct LinkedList{
	Node* head;
	Node* tail;
	LinkedList(){
		head = tail = NULL;
	}
	void insert_at_tail(int v){
		if(head == NULL){
			head = new Node(v);
			tail = head;
			return;
		}
		tail->next = new Node(v);
		tail = tail->next;
	}
	void insert_at_head(int v){
		if(head == NULL){
			head = tail = new Node(v);
			return;
		}
		Node* new_head = new Node(v);
		new_head->next = head;
		head = new_head;
	}
	void insert_at(int i,int v){
		//insert at index i, or at the end if greater than length
		if(i == 0){
			insert_at_head(v);
			return;
		}
		Node* p = head;
		while(p != NULL && --i)
			p = p->next;
		if(i) insert_at_tail(v);
		else{
			Node* new_node = new Node(v);
			new_node->next = p->next;
			p->next = new_node;
		}
	}
	void print(){
		Node* p = head;
		if(p == NULL)
			return;
		while(p != NULL){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};
int main(){
	LinkedList l;
	l.insert_at_head(1);
	l.print();
	l.insert_at_head(2);
	l.print();
	l.insert_at_tail(3);
	l.insert_at_tail(4);
	l.print();
	l.insert_at(2,5);
	l.print();
	return 0;
}