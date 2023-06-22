#include <bits/stdc++.h>
using namespace std;
void generate_gray_code(vector<string>& v,int n){
    if(n==1){
        v.push_back("0");
        v.push_back("1");
        return;
    }
    generate_gray_code(v,n-1);
    int x= v.size()*2;
    for(int i=v.size();i<x;i++){
        v.push_back(v[x-i-1]);
    }
    for(int i =0;i<v.size();i++){
        string op=v[i];
        if(i<v.size()/2){
            op.insert(0,"0");
        }else{
            op.insert(0,"1");
        }
        v[i]=op;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<string> v;
    generate_gray_code(v,n);
    //cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}