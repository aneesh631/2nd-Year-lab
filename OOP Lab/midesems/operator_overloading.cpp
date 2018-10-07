#include <iostream>
using namespace std;
class Complex{
    double r,i;
public:
    Complex(){}
    Complex(int a,int b){
        r = a;
        i = b;
    }
    void operator - (){
        r = -r;
        i = -i;
    }
    friend ostream& operator << (ostream&,Complex);
    friend istream& operator >> (istream&,Complex);
};
ostream& operator << (ostream& os,Complex c){
    os<<c.r<<" + i"<<c.i<<endl;
    return os;
}
istream& operator >> (istream& is,Complex c){
    is>>c.r>>c.i;
    return is;
}
int main() {
    Complex c1,c2;
    cin>>c1>>c2;
    cout<<"c1:"<<c1<<endl;
    cout<<"c2:"<<c2<<endl;
    return 0;
}
