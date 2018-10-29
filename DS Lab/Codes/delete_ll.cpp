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
	void insert(int v){
		//at tail
		if(head == NULL){
			head = new Node(v);
			tail = head;
			return;
		}
		tail->next = new Node(v);
		tail = tail->next;
	}
	void delete_at(int i){
		if(head == NULL)
			return;
		Node *cur = head, *prev = NULL;
		while(i--){
			prev = cur;
			cur = cur->next;
		}
		if(prev == NULL){
			Node* temp = head->next;
			delete head;
			head = temp;
		}
		else{
			if(cur->next == NULL) tail = prev;
			prev->next = cur->next;
			delete cur;
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
	l.insert(1);l.insert(2);l.insert(3);l.insert(4);l.insert(5);l.insert(6);
	l.print();
	l.delete_at(0);
	l.print();
	l.delete_at(1);
	l.print();
	l.delete_at(3);
	l.print();
	return 0;
}