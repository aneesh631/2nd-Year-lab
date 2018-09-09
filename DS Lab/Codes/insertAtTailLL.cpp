#include <iostream>
#define MAX 10000
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(){
		data=0;
		next=NULL;
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
		head=tail=NULL;
	}
	void insert_at_tail(int v){
		if(head==NULL){
			// cout<<"head is null\n";
			head = new Node(v);
			tail = head;
			return;
		}
		tail->next = new Node(v);
		tail = tail->next;
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
	l.insert_at_tail(1);
	l.insert_at_tail(2);
	l.insert_at_tail(3);
	l.print();
}