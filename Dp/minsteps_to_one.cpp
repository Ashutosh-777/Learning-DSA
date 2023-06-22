#include <bits/stdc++.h>
using namespace std;
func(int n){
    if(n==1){
        return 0;
    }
    int a = INT_MAX,b=INT_MAX,c=INT_MAX;
    if(n%2==0){
        a=func(n/2);
    }
    if(n%3==0){
        b=func(n/3);
    }
    c=func(n-1);
    return min(a,min(b,c))+1;
}
int func_dp(int n){
    int a[n+1];
    a[0]=-1;
    a[1]=0;
    a[2]=1;
    a[3]=1;
    for(int i=4;i<=n;i++){
        int k = INT_MAX,b=INT_MAX,c=INT_MAX;
        k =a[i-1];
        if(i%2==0){
            b=a[i/2];
        }
        if(i%3==0){
            c=a[i/3];
        }
        a[i]= 1+min(k,min(b,c));
    }
    return a[n];
}
int main(){
    int n;
    cin>>n;
    cout<<func_dp(n)<<endl;
    //cout<<func(n)<<endl;
    return 0;
}