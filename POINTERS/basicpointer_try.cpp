#include <iostream>
using namespace std;
int main(){
    int i=10;
    int* p=&i;
    int *q=p;
    int**r=&p;
    // i stores value 10
    //p stores address of i
    //q stores address of i
    //r store address of p
    cout<<
    "value of i :"<<i<<' '<<*p<<' '<<*q<<' '<<**r<<endl<<
    "address of i:"<<':'<<p<<' '<<q<<' '<<&i<<endl<<
    "value of p/q: "<<' '<<p<<' '<<*r<<" "<<q<<endl<<
    "address of p/q/p: "<<&p<<" "<<&q<<" "<<r<<endl<<
    "address of r: "<<&r<<" "<<r<<endl;
    double d=10.90;
    double*x=&d;
    cout<<"d: "<<d<<"x :"<<x<<"  "<<++x;
    return 0;
}