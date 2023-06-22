#include <bits/stdc++.h>
using namespace std;
void letter_case(string ip,string op){
    if(ip.length()==0){
        cout<<op<<' ';
        return ;
    }

    if(isalpha(ip[0])){
    string op1 = op;
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
        ip.erase(0,1);
    letter_case(ip,op1);
    letter_case(ip,op2);
    }else{
    string op1 = op;
    op1.push_back(ip[0]);
    ip.erase(0,1);
    letter_case(ip,op1);
    }

    return;
    
}
int main(){
    string ip;
    cin>>ip;
    string op="";
    letter_case(ip,op);
    return 0;
}