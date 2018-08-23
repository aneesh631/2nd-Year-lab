#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
struct sparse{
	int row,col,val;
	sparse(){}
	sparse(int r,int c,int v){
		row=r;
		col=c;
		val=v;
	}
};
void print_sparse(sparse *s){
	int k=s[0].val;
	for(int i=0;i<=k;i++)
		cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val<<endl;
	cout<<endl;

}
sparse a[20],b[20],c[20];
void take_input_sparse(sparse* s){
	int r,c,v;
	cin>>r>>c>>v;
	s[0]=sparse(r,c,v);
	for(int i=1;i<=s[0].val;i++){
		cin>>r>>c>>v;
		s[i]=sparse(r,c,v);
	}
}
//sort for transpose
bool cmp(sparse a,sparse b){
	if(a.row != b.row)
		return a.row<b.row;
	return a.col<b.col;
}
void transpose_sparse(sparse* s){
	//O(k*log(k))
	for(int i=0;i<=s[0].val;i++)
		swap(s[i].row,s[i].col);
	sort(s+1,s+1+s[0].val,cmp);
}

void multiply(sparse* a,sparse* b,sparse* c){
	//O(k^2)
	transpose_sparse(b);
	/*
	 * now we store the starting index
	 * and ending index of every row (of the original matrix)
	 * in the sparse matrix
	 */
	//row#, lower index, upper index
	vector<pair<int,pair<int,int> > > la,lb;
	la.push_back(make_pair(a[1].row,make_pair(1,1)));
	for(int i=2;i<=a[0].val;i++){
		sparse current = a[i];
		int current_row = la[la.size()-1].first;
		if(current.row == current_row)
			la[la.size()-1].second.second++;
		else
			la.push_back(make_pair(a[i].row,make_pair(i,i)));
	}

	lb.push_back(make_pair(b[1].row,make_pair(1,1)));
	for(int i=2;i<=b[0].val;i++){
		sparse current = b[i];
		int current_row = lb[lb.size()-1].first;
		if(current.row == current_row)
			lb[lb.size()-1].second.second++;
		else
			lb.push_back(make_pair(b[i].row,make_pair(i,i)));
	}
	int k=1;
	/* now multiply every row
	 * of a with every row of b
	 */
	for(auto i:la){
		for(auto j:lb){
			int cell=0;
			int ai=i.second.first,bj=j.second.second;
			while(ai<=i.second.second && bj<=j.second.second){
				if(a[ai].col == b[bj].col)
					cell+=a[ai++].val*b[bj++].val;
				if(a[ai].col < b[bj].col)
					ai++;
				else
					bj++;
			}
			if(cell)
				c[k++]=sparse(i.first,j.first,cell);
		}
		
	}
	c[0].row=a[0].row;
	c[0].col=b[0].col;
	c[0].val=k-1;
}
int main(){
	take_input_sparse(a);
	take_input_sparse(b);
	multiply(a,b,c);
	print_sparse(c);
	return 0;
}