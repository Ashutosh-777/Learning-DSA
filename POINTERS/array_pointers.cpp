#include <iostream>
using namespace std;
int main(){
    int a[10];
    a[0]=10;
    a[1]=20;
    cout<<a<<endl;
    cout<<&a<<endl;
    int*p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<a[1]<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(a+1)<<endl;
    cout<<a+1<<endl;
    cout<<p+1<<endl;
    cout<<&a[1]<<endl;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(p)<<endl;
    //a++; can not do this because a is not assigned any memory
    return 0;
}