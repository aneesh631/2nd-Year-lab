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
sparse a[20],b[20],ans[20];
void read_sparse(sparse *s){
	cin>>s[0].row>>s[0].col>>s[0].val;
	for(int i=1;i<=s[0].val;i++)
		cin>>s[i].row>>s[i].col>>s[i].val;
}
void print_sparse(sparse *s){
	cout<<endl;
	int k=s[0].val;
	for(int i=0;i<=k;i++)
		cout<<s[i].row<<" "<<s[i].col<<" "<<s[i].val<<endl;
	cout<<endl;

}
void add_sparse(sparse *a,sparse* b,sparse *c){
	int i=1,j=1,k=1;
	int i_max=a[0].val,j_max=b[0].val;
	while(i<=i_max && j<=j_max){
		if(a[i].row < b[j].row)
			c[k++]=a[i++];
		else if(a[i].row == b[j].row){
			if(a[i].col < b[j].col)
				c[k++]=a[i++];
			else if(a[i].col == b[j].col){
				c[k]=sparse(a[i].row,a[i].col,a[i].val+b[j].val);
				i++;j++;k++;
			}
			else
				c[k++]=b[j++];
		}
		else
			c[k++]=b[j++];
	}
	while(i<=i_max)
		c[k++]=a[i++];
	while(j<=j_max)
		c[k++]=b[j++];
	c[0] = sparse(a[0].row,a[0].col,k-1);
}
int main(){
	read_sparse(a);
	read_sparse(b);
	add_sparse(a,b,ans);
	cout<<"ans:\n";
	print_sparse(ans);	
	return 0;
}