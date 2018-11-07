#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Huffman;
class Node{
	char c;
	int freq;
	Node *left, *right;
public:
	Node(int ch,int fr){
		c = ch;
		freq = fr;
		left = right = NULL;
	}
	friend class Huffman;
};

class Huffman{
	Node* tree;
	string s;
	unordered_map<char,string> codes;
	struct cmp{
		bool operator () (Node* a,Node* b){
			return a->freq > b->freq;
		}
	};
	void assign(Node* root, string prev = ""){
		if(root == NULL) return;
		if(root->c == '$'){
			assign(root->left,prev + "0");
			assign(root->right,prev + "1");
		}
		else{
			codes[root->c] = prev; 
			assign(root->left,prev + "0");
			assign(root->right,prev + "1");
		}
	}
public:
	void encode(string s){
		this->s = s;
		unordered_map<char,int> fm;
		for(char c:s){
			if(fm.find(c) == fm.end()) fm[c] = 1;
			else fm[c]++;
		}
		priority_queue<Node*,vector<Node*>,cmp > pq;
		for(auto e:fm)
			pq.push(new Node(e.first,e.second));
		while(pq.size() != 1){
			Node* t1 = pq.top();
			pq.pop();
			Node* t2 = pq.top();
			pq.pop();
            Node* new_node = new Node('$',t1->freq + t2->freq);
            new_node->left = t1;
            new_node->right = t2;
			pq.push(new_node);
		}
		tree = pq.top();
		pq.pop();
		assign(tree);
	}
   	string get_code(){
    	string c = "";
    	for(char e:s)
    		c += codes[e];
    	return c;
    }
    unordered_map<char,string> get_codes(){
    	return codes;
    }
	void print_codes(){
		for(auto e:codes)
			cout<<e.first<<" -> "<<e.second<<endl;
	}
    static string decode(string s,unordered_map<char,string> codes){
		string ans = "";
		unordered_map<string,char> rm;
		for(auto e:codes)
			rm[e.second] = e.first;
		string cur = "";
		for(int i = 0;i < s.length();i++){
			cur += s[i];
			auto f = rm.find(cur);
			if(f != rm.end()){
				ans += f->second;
				cur = "";
			}
		}
		return ans;
	}
};
int main(){
	string s = "this is a test";
	Huffman hc;
	hc.encode(s);
	string hfe = hc.get_code();
	cout<<hfe<<endl;
	unordered_map<char,string> codes = hc.get_codes();
    for(auto e:codes)
        cout<<e.first<<" -> "<<e.second<<endl;
	string decoded = Huffman::decode(hfe,codes);
    cout<<decoded<<endl;
}