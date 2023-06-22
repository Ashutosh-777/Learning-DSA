#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> ip,vector<int> op1,vector<vector<int>> &op){
    if(ip.size()==0){
        op.push_back(op1);
        return ;
    }
    vector<int> op2=op1;
    vector<int> op3=op1;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0,ip.begin()+1);
    helper(ip,op2,op);
    helper(ip,op3,op);
    return;
}
vector<vector<int>> FindAllSubsets( vector<int> &v){
    vector<vector<int>> a;
    vector<int> op1 = {};
    cout<<"op1: "<<v.size()<<endl;
     helper(v,op1,a);
     return a;
}
int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<vector<int>> a = FindAllSubsets(v);
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}