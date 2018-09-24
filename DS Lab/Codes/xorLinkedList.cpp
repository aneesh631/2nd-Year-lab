#include <iostream>
using namespace std;
class Node{
	int data;
	Node* xr;
public:
	Node(){
		xr = NULL;
	}
	Node(int d){
		data = d;
	}
	friend class XorLinkedList;
};
class XorLinkedList{
	Node *head,*tail;
	int length;
	template <typename T>
	T* getXOR(T* t1, T* t2){
		return (Node*)((uintptr_t)t1^(uintptr_t)t2);
	}
public:
	XorLinkedList(){
		head = NULL;
		tail = NULL;
		length = 0;
	}
	int size(){
		return length;
	}
	void insert_at_tail(int v){
        length++;
		if(head == NULL){
			head = new Node(v);
			tail = head;
			return;
		}
		Node* newTail = new Node(v);
		newTail->xr = tail;
		tail->xr = getXOR(tail->xr, newTail);
		tail = newTail;
	}
	void insert_at_head(int v){
		if(head == NULL){
			insert_at_tail(v);
			return;
		}
		Node* newHead = new Node(v);
		newHead->xr = head;
		head->xr = getXOR(head->xr,newHead);
		head = newHead;
	}
	bool contains(int v){
		Node *cur = head, *prev = NULL, *temp = cur;
		while(cur){
			if(cur->data == v)
				return true;
			temp = cur;
			cur = getXOR(cur->xr,prev);
			prev = temp;
		}
		return false;
	}
	void insert_at(int v, int i){
		Node *cur = head, *prev = NULL, *next = cur;
		if(i >= length+1){
			insert_at_tail(v);
			return;
		}
		else if(i==0){
			insert_at_head(v);
			return;
		}
		int id = 1;
		while(cur != NULL){
            next = getXOR(cur->xr,prev);
			if(id == i)
				break;
			prev = cur;
			cur = next;
			id++;
		}
		Node* n = new Node(v);
		cur->xr = getXOR(getXOR(cur->xr,next),n);
		n->xr = getXOR(cur,next);
		next->xr = getXOR(getXOR(next->xr,cur),n);
	}
	void remove_at(int i){
		if(head == NULL || length < i)
			return;
		Node *cur = head, *prev = NULL, *next = cur;
		if(i==0){
			if(length == 1){
				delete head;
				head = tail = NULL;
			}
			else{
				Node* newHead = head->xr;
				newHead->xr = getXOR(newHead->xr,head);
				delete head;
				head = newHead;
			}
            length--;
			return;
		}
		int id = 0;
		while(cur != NULL){
            next = getXOR(cur->xr,prev);
			if(id == i)
				break;
			prev = cur;
			cur = next;
			id++;
		}
        if(next == NULL){
            prev->xr = getXOR(prev->xr,cur);
            tail = cur->xr;
            delete cur;
            return;
        }
		prev->xr = getXOR(getXOR(prev->xr,cur),next);
        next->xr = getXOR(getXOR(next->xr,cur),prev);
        delete cur;
        length--;
	}
    void remove_at_tail(){
		if(head == NULL)
			return;
        length--;
		if(length == 0){
			delete head;
            head = tail = NULL;
            return;
		}
		Node* newTail = tail->xr;
		newTail->xr = getXOR(newTail->xr,tail);
		delete tail;
		tail = newTail;
	}
	void clear(){
		while(head != NULL)
			remove_at_tail();
	}
	void print(){
		Node *cur = head, *prev = NULL, *temp = cur;
		while(cur != NULL){
			cout<< cur->data << " ";
			temp = cur;
			cur = getXOR(cur->xr,prev);
			prev = temp;
		}
		cout<<endl;
	}
};
int main(){
	XorLinkedList ll;
	ll.insert_at_tail(1);
	ll.insert_at_tail(2);
    ll.insert_at_tail(3);
    ll.insert_at_tail(4);
    ll.print();
}