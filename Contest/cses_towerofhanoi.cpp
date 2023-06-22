#include <bits/stdc++.h>
using namespace std;
void solve(int s,int h,int d,int n){
    if(n==1){
        cout<<s<<" "<<d<<endl;
        return;
    }
    solve(s,d,h,n-1);
    cout<<s<<" "<<d<<endl;
    solve(h,s,d,n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    solve(1,2,3,n);
    return 0;
}