#include <iostream>
using namespace std;
//increment1 just copies value and changes that nno change in main
void increment1(int **p){
    p++;
}
void increment2(int **p){
    (*p)++;
    //change in main in address of p
}
void increment3(int **p){
    (**p)++;
}
int main(){
    int i=10;
    int *p=&i;
    //p stores address of i
    int **p2=&p;
    //p2 stores address of p
    cout<<"address of i :"<<endl;
    cout<<&i<<" "<<p<<" "<<*p2<<endl;
    cout<<"address of p :"<<endl;
    cout<<&p<<" "<<p2<<" "<<endl;
    cout<<"value of i : "<<endl;
    cout<<i<<" "<<*p<<" "<<**p2<<endl;
    increment1(&p);
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
     increment2(&p);
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
     increment3(&p);
    cout<<i<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;

    
    return 0;
}