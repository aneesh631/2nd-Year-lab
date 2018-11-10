#include <iostream>
using namespace std;
template<class T>
class Node;
template<class T>
class LinkedList;
template<class T,class U>
class Hashtable;
template<class T,class U>
class Pair{
	T key;
	U value;
public:
	Pair(){}
	Pair(T k,U v){
		key = k;
		value = v;
	}
	friend class Hashtable<T,U>;
	template<class V>
	friend class LinkedList;
};
template<class T>
class Node{
	T data;
	Node<T> *next;
public:
	Node(){
		data = T();
		next = NULL;
	}
	Node(T d){
		data = d;
		next = NULL;
	}
	friend class LinkedList<T>;
	template<class U, class V>
	friend class Hashtable;
};
template<class T>
class LinkedList{
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList(){
		head = tail = NULL;
	}
	~LinkedList(){
		Node<T>* c = head;
		while(c != NULL){
			Node<T>* nxt = c->next;
			delete c;
			c = nxt;
		}
	}
	void insert(T v){
		if(head == NULL){
			head = new Node<T>(v);
			tail = head;
			return;
		}
		tail->next = new Node<T>(v);
		tail = tail->next;
	}
	int count(T v){
		int ans = 0;
		T* c = head;
		while(c != NULL){
			if(c->data == v)
				ans++;
		}
        return ans;
	}
	template<class U>
	T get_node(U v){
		if(head == NULL)
			throw "Not found!";
		Node<T>* c = head;
		while(c != NULL){
			if(c->data.key == v)
				return c->data;
		}
	}
	bool empty(){
		return head == NULL;
	}
	template<class U, class V>
	friend class Hashtable;
};
template<class T,class U>
class Hashtable{
	int size,entries;
	float critical_load_factor;
	int (*hash)(T,int);
	LinkedList<Pair<T,U> >* Table;
	void rehash(){
		Hashtable<T,U>* new_table = new Hashtable(hash,2*size);
		for(int i = 0;i < size;i++){
			LinkedList<Pair<T,U> > ll = Table[i];
			Node<Pair<T,U> >* c = ll.head;
			while(c != NULL){
				new_table->insert(c->data.key,c->data.value);
				c = c->next;
			}
		}
		delete Table;
		*this = *new_table;
		size *= 2;
	}
public:
	Hashtable(int (*h)(T,int),int sz = 10){
		size = sz;
		entries = 0;
		critical_load_factor = 0.7;
		hash = h;
		Table = new LinkedList<Pair<T,U> > [size];
	}
	float load_factor(){
		return float(entries)/float(size);
	}
	void insert(T k,U v){
		Pair<T,U> p = Pair<T,U>(k,v);
		if(load_factor() >= critical_load_factor)
			rehash();
		int id = hash(p.key,size);
		Table[id].insert(p);
		entries++;
	}
	U get_value(T k){
		int id = hash(k,size);
		Pair<T,U> p = Table[id].get_node(k);
		return p.value;
	}
};
int hash_int(int k,int size){
	int p = 1, m = 37;
	int hashed_value = 0;
	while(k){
		hashed_value += p*(k%10);
		hashed_value %= size;
		k /= 10;
		p *= m;
		p %= size;
	}
	return hashed_value;
}
int main(){
	Hashtable<int,int> h(hash_int); 
	h.insert(1,100);
	h.insert(2,200);
	h.insert(3,300);
	h.insert(4,400);
	cout<<h.get_value(1)<<endl;
    cout<<h.get_value(2)<<endl;         
    cout<<h.get_value(3)<<endl;
    cout<<h.get_value(4)<<endl;
	return 0;
}