#include <iostream>
#define MAX 10000
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
	int len;
	LinkedList(){
		head = tail = NULL;
		len = 0;
	}
	void insert_at_tail(int v){
		if(head == NULL){
			head = new Node(v);
			tail = head;
			return;
		}
		tail->next = new Node(v);
		tail = tail->next;
		len++;
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
	void take_input(){
		int v;
		cin>>v;
		while(v != -1){
			insert_at_tail(v);
			cin>>v;
		}
	}
};
int get_common_node(LinkedList l1,LinkedList l2){
	if(l1.tail->data != l2.tail->data)
		return -1;
	int len1 = l1.len, len2 = l2.len;
	int diff = abs(len1 - len2);
	Node *h1 = l1.head, *h2 = l2.head;
	while(diff){
		if(len1 > len2)
			h1 = h1->next;
		else
			h2 = h2->next;
		diff--;
	}
	while(h1->data != h2->data){
		h1 = h1->next;
		h2 = h2->next;
	}
	return h1->data;
}
int main(){
	LinkedList l1,l2;
	l1.take_input();
	l2.take_input();
	cout<<"l1 : ";
	l1.print();
	cout<<"l2 : ";
	l2.print();
	cout<<get_common_node(l1,l2)<<endl;
	return 0;
}