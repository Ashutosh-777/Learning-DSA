#include <iostream>
using namespace std;
#define ll long long
long long int func(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 3;
    }
    long long int ans1 = func(n-1);
    long long int ans2 = func(n-2);
    long long int finalAns = ans1*ans1 + 2*ans1*ans2;
    return finalAns;
}
long long int func_dp(int n){
    long long int ans[n+1];
    ans[1]=1;
    ans[2]=3;
    for(int i=3;i<=n;i++){
        ans[i]=ans[i-1]*ans[i-1] + 2*ans[i-1]*ans[i-2];
    }
    return ans[n];
}
long long int func_helper(int n, ll int *ans){
    if(ans[n]!=-1){
        return ans[n];
    }
    if(n==1){
        ans[1]=1;
        return ans[1];
    }
    if(n==2){
        ans[2]=3;
        return ans[2];
    }
     ll int ans1 = func(n-1);
     ll int ans2 = func(n-2);
    ans[n] = ans1*ans1 + 2*ans1*ans2;
    return ans[n];
}
long long int func_memo(int n){
     ll int *ans =new  ll int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
        
    }
    return func_helper(n,ans);
}
int main(){
    int n;
    cin>>n;
    cout<<func_dp(n)<<endl;
    cout<<func_memo(n)<<endl;
    return 0;
}