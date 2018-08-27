#include <iostream>
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
sparse a[20];
int m[10][10],r,c;
void create_sparse(sparse *s){
	s[0]=sparse(r,c,0);
	int k=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(m[i][j])
				s[k++]=sparse(i,j,m[i][j]);
		}
	}
	s[0].val = k-1;
}
void print_sparse(sparse *s){
	cout<<endl;
	int k=s[0].val;
	for(int i=0;i<=k;i++)
		cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val<<endl;
	cout<<endl;
}
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cin>>m[i][j];
	}
	create_sparse(a);
	print_sparse(a);
	return 0;
}