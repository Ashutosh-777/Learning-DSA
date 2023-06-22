#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//printing unique subset using vector
void print_uniquesubset(string ip,string op,vector<string>& v){
        if(ip.length()==0){
            if(count(v.begin(), v.end(), op)==0){
                 v.push_back(op);
                 cout<<op<<" ";
            }
        return ;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(0,1);
    print_uniquesubset(ip,op1,v);
    print_uniquesubset(ip,op2,v);
    return ;
}
//printing unique subset using map
void print_uniquesubset1(string ip,string op,unordered_map<string,bool>& m){
        if(ip.length()==0){
            if(m.count(op)==0){
                 cout<<op<<" ";
                 m[op]=true;
            }
        return ;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(0,1);
    print_uniquesubset1(ip,op1,m);
    print_uniquesubset1(ip,op2,m);
    return ;
}
//printing subset
void print_subset(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(0,1);
    print_subset(ip,op1);
    print_subset(ip,op2);
    return;
}
int main(){
    string ip;
    cin>>ip;
    vector<string> v;
    unordered_map<string,bool> m;
     string op="";
    print_subset(ip,op);
    cout<<endl;
    print_uniquesubset(ip,op,v);
    cout<<endl;
    print_uniquesubset1(ip,op,m);
    cout<<endl;
    return 0;
}