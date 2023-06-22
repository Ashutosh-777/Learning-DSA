#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int n){
    int a[n+1];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=n;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    return a[n];
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    int s = sqrt(226.00);
    cout<<s<<endl;
    return 0;
}
