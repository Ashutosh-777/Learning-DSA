#include <bits/stdc++.h>
using namespace std;
int func(int n){
    if(n==2||n==3){
        return n;
    }
    int a =sqrt(n);
    if(a*a==n){
        return 1 ;
    }
    int ans = INT_MAX;
    for(int i = 1;i*i<n;i++){
        int smallAns = func(n-i*i);
        if(ans>smallAns){
            ans = smallAns;
        }
    }
    return ans + 1;
}
int func_memoisation(int n,int *ans){
    if(ans[n]!=0){
        return ans[n];
    }
    if(n==2||n==3){
        return n;
    }
    int a =sqrt(n);
    if(a*a==n){
        return 1 ;
    }
    int ANS= INT_MAX;
    for(int i=1;i*i<n;i++){
        int smallAns = func(n-i*i);
        if(ANS>smallAns){
            ANS = smallAns;
        }
    }
    ans[n]=ANS+1;
    return ans[n];
}
int func_2(int n){
    int* ans =new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]= 0;
    }
    return func_memoisation(n,ans);
}
long long int func_dp(long long int n){
    long long int ans[n+1];
    ans[0]=1;
    for(int i=1;i<n+1&&i<4;i++){
        ans[i]=i;
    }
    long long int b= sqrt(n);
    if(b*b==n){
        return 1;
    }
    for(long long int i=4;i<=n;i++){
        long long int a =sqrt(i);
        if(a*a==i){
            ans[i]=1;
            continue;
        }
        long long int min =   INT_MAX;
        for(int j=1;j*j<=i;j++){
            if(ans[i-j*j]<min){
                min=ans[i-j*j];
            }
        }
        ans[i]=min+1;
    }
    return ans[n];
}
int main(){
    long long int n;
    cin>>n;
    cout<<func_dp(n)<<endl;
    // cout<<func_2(n)<<endl;
    // cout<<func(n)<<endl;
    return 0;
}