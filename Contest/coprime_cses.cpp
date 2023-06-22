#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coprime(int a,int b){
    if(__gcd(a,b)==1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            count+=coprime(a[i],a[j]);
        }
    }
    cout<<count;
    return 0;
}