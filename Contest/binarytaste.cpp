#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll int  sum(int n){
    return pow(2,n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        k=k-1;
        int  a =log2(n);
        k= min(a,k);
        if(k==0){
            cout<<1<<endl;
        }
        int count=0;
        while(pow(2,k)<=n){
            count = count + sum(k);
            n=n-sum(k);
            k=log2(n);
            if(k==1&&n>=3){
                count+=4;
                break;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}