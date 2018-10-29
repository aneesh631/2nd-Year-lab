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
	void menu(){
		cout<<"---------------------\n";
		cout<<"1 - Insert at head\n";
		cout<<"2 - Insert at tail\n";
		cout<<"3 - Insert at\n";
		cout<<"4 - Print\n";
		cout<<"5 - Exit\n";
		cout<<"---------------------\n";
		int choice, v, a;
		cin>>choice;
		switch(choice){
			case 1:
				cin>>v;
				insert_at_head(v);
				menu();
				break;
			case 2:
				cin>>v;
				insert_at_tail(v);
				menu();
				break;
			case 3:
				cin>>a>>v;
				insert_at(a,v);
				menu();
				break;
			case 4:
				print();
				menu();
				break;
			case 5:
				return;
		}
	}
};
int main(){
	LinkedList l;
	l.menu();
	return 0;
}