#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){

    int n;
    cin>>n;
    int a[n];
    unordered_map<int,bool> map;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
        }
        sort(b,b+m);
    if(n>m){
        for(int i=0;i<m;i++){
        map[b[i]]=false;
        }
        for(int i=0;i<n;i++){
        if(map.count(a[i])>0){
            map[a[i]]=true;
        }
        }
        for(int i=0;i<m;i++){
        if(map[b[i]]){
            cout<<b[i]<<' ';
        }
        }
    cout<<endl;
    }else{
        for(int i=0;i<n;i++){
            map[a[i]]=false;
        }
        for(int i=0;i<m;i++){
        if(map.count(b[i])>0){
            map[b[i]]=true;
        }
        }
        for(int i=0;i<n;i++){
        if(map[a[i]]){
            cout<<a[i]<<' ';
        }
        }
    }
    }
}