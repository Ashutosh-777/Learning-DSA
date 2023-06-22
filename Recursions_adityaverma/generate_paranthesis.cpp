#include <bits/stdc++.h>
using namespace std;
void generate_balanced_paranthesis(int o,int c,string op){
    if(o==0&&c==0){
        cout<<op<<' ';
        return ;
    }
    if(o!=0){
            string op1 = op;
    op1.push_back('(');
    generate_balanced_paranthesis(o-1,c,op1);
    }
    if(o<c){
        string op2 = op;
        op2.push_back(')');
        generate_balanced_paranthesis(o,c-1,op2);
    }
}
int main(){
    int n;
    cin>>n;
    string op="";
    int o=n;
    int c=n;
    generate_balanced_paranthesis(o,c,op);
    return 0;
}