#include <bits/stdc++.h>
using namespace std;
void case_change(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" ";
        return ;
    }
    string op1=op;
    string op2=op;
    op1.push_back(ip[0]);
    op2.push_back(ip[0]-32);
    ip.erase(0,1);
    case_change(ip,op1);
    case_change(ip,op2);
    return;
}
int main(){
    string ip;
    cin>>ip;
    string op;
    case_change(ip,op);
    
    return 0;
}