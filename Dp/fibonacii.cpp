#include <iostream>
using namespace std;
//time complexity O(2^n)
int fibo_1(int n){
    if(n<=1){
        return n;
    }
    return fibo_1(n-1)+fibo_1(n-2);
}
int fibo_2_helper(int n,int* ans ){
    if(n<=1){
        return n;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int a = fibo_2_helper(n-1,ans);
    //cout<<"a"<<a<<endl;
    int b  = fibo_2_helper(n-2,ans);
    //cout<<"b"<<b<<endl;
    ans[n]=a+b;
    return ans[n];
}
int fibo_2(int n){
    int* ans =new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]= -1;
    }
    return fibo_2_helper(n,ans);
}
int fibo_3(int n){
    int ans[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibo_2(n)<<"   "<<fibo_3(n)<<endl;
    return 0;
}