#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,bool> m;
    for(int i=0;i<n;i++){
        if(m.count(a[i])>0){
             continue;
        }
        m[a[i]]=true;
        v.push_back(a[i]);
    }
    cout<<m[1]<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    return 0;
}