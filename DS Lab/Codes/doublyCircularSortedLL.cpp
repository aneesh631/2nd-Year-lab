#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *prev,*next;
	Node(){
		prev = next = NULL;
	}
	Node(int d){
		data = d;
		prev = next = NULL;
	}
};
struct LinkedList{
	Node* head;
	LinkedList(){
		head = NULL;
	}
	void insert_at_head(int v){
		if(head == NULL){
			head = new Node(v);
			head->next = head->prev = head;
			return;
		}
		Node* newHead = new Node(v);
		newHead->next = head;
		newHead->prev = head->prev;
		head->prev->next = newHead;
		head->prev = newHead;
		head = newHead;
	}
	void print(){
		for(int i=0;i<10;i++)
			cout<< "-";
		cout<<endl;
		if(head == NULL){
			cout<<endl;
			return;
		}
		Node *start = head, *cur = head->next;
		cout<< head->data << " ";
		while(cur != head){
			cout<< cur->data << " ";
			cur = cur->next;
		}
		cout<<endl;
		for(int i=0;i<10;i++)
			cout<< "-";
		cout<<endl;
	}
	void insert(int v){
		if(head == NULL || v<= head->data){
			insert_at_head(v);
			return;
		}
		Node* p = head->next;
		while(p != head && p->data < v)
			p = p->next;
		Node* n = new Node(v);
		p = p->prev;

		n->next = p->next;
		n->prev = p;

		p->next->prev = n;
		p->next = n;
	}
	void remove(int d){
		if(head == NULL)
			return;
		if(head->next == head){
			if(head->data){
				delete head;
				head = NULL;
			}
			return;
		}
		if(head->data == d){
			head->prev->next = head->next;
			head->next->prev = head->prev;
			Node* newHead = head->next;
			delete head;
			head = newHead;
			return;
		}
		Node* p = head->next;
		while(p->data < d && p != head)
			p = p->next;
		p = p->prev;
		if(p->next->data != d)
			return;
		p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	void take_input(){
		int x;
		cin>>x;
		while(x!=-1){
			insert(x);
			cin>>x;
		}
	}
	int menu(){
		int op;
		cout<<"1 - Insert element\n";
		cout<<"2 - Remove element\n";
		cout<<"3 - Display\n";
		cout<<"4 - Exit\n";
		cin>>op;
		switch(op){
			int v;
			case 1:
				cout<< "Enter no to insert: ";
				cin>>v;
				insert(v);
				break;
			case 2:
				cout<< "Enter no to remove: ";
				cin>>v;
				remove(v);
				break;
			case 3:
				print();
				break;
		}
		return op;
	}
};
int main(){
	LinkedList ll;
	ll.take_input();
	while(ll.menu()!=4){}
	return 0;
}
