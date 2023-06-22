#include <bits/stdc++.h>
using namespace std;
void print_permutation(string ip,string op,vector<string>& v){
    if(ip.length()==0){
        cout<<op<<' ';
        v.push_back(op);
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back('*');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(0,1);
    print_permutation(ip,op1,v);
    print_permutation(ip,op2,v);
}
int main(){
    string ip;
    cin>>ip;
    string op;
    op=ip[0];
    ip.erase(0,1);
    vector<string> v;
    print_permutation(ip,op,v);
    cout<<v.size()<<endl;
    return 0;
}