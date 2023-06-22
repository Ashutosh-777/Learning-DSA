#include <bits/stdc++.h>
using namespace std;
int ZeroPairSum(int n, int a[]){
    unordered_map<int ,int> freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    int count=0;
    int same=a[0];
    //cout<<freq[-a[0]]<<"hell"<<a[0]<<endl;
    count =count + freq[a[0]]*freq[-a[0]];
    //cout<<count<<endl;
    for(int i=1;i<n;i++){
        if(a[i]>0){
            break;
        }
        if(a[i]==0){
            count+=freq[a[i]]*(freq[a[i]]-1)/2;
              break;
        }
        if(same!=a[i]){
            count+= freq[a[i]]*freq[-a[i]];
            same=a[i];
        }
        
    }
   
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<' ';
    // }
    // cout<<endl;
    int print=ZeroPairSum(n,a);
    cout<<print<<endl;
    }

    return 0;
}