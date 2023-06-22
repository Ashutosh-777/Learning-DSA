#include <iostream>
using namespace std;
void Tower_of_Hanoi(int n,string s,string h,string d){
    if(n==1){
        cout<<"from "<<s<<" to "<<d<<endl;
        return;
    }
    Tower_of_Hanoi(n-1,s,d,h);
    cout<<"from "<<s<<" to "<<d<<endl;
    Tower_of_Hanoi(n-1,h,s,d);
}
int main(){
    string s="source";
    string d="destination";
    string h ="helper";
    Tower_of_Hanoi(3,s,h,d);
    return  0;
}