#include <iostream>
using namespace std;
int func(string s,string t){
    int m= s.length();
    int n= t.length();
    if(m==0&&n==0){
        return 0;
    }
    if(m==0||n==0){
        return m==0? n:m;
    }
    if(m==1&&n==1){
        return s[0]==t[0] ? 0 : 1;
    }
    if(s[0]==t[0]){
        int a = func(s.substr(1),t.substr(1));
        return a;
    }else{
                int a = func(s,t.substr(1))+1;
                int b = func(s.substr(1),t)+1;
                int c = func(s.substr(1),t.substr(1))+1;
                return min(a,min(b,c));
        
    }
}
int func_helper(string s, string t, int**ans){
    int m = s.length();
    int n = t.length();
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    if(m==0&&n==0){
        ans[m][n]=0;
        return 0;
    }
    if(m==0||n==0){
        ans[m][n] = m==0? n:m;
        return ans[m][n];
    }
    if(m==1&&n==1){
        ans[m][n] = s[0]==t[0] ? 0 : 1;
        return ans[m][n];
    }
    if(s[0]==t[0]){
        int a = func_helper(s.substr(1),t.substr(1),ans);
        ans[m][n]=a;
        return a;
    }else{
                int a = func_helper(s,t.substr(1),ans)+1;
                int b = func_helper(s.substr(1),t,ans)+1;
                int c = func_helper(s.substr(1),t.substr(1),ans)+1;
                ans[m][n] = min(a,min(b,c));
                return ans[m][n];
    }
}
int func_memo(string s,string t){
    int m =s.size();
    int n =t.size();
    int **ans = new int *[m+1];
    for(int i=0;i<=m;i++){
        ans[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            ans[i][j]=-1;
        }
    }
    return func_helper(s,t,ans);
}
int func_dp(string s,string t){
    int m = s.size(),n=t.size();
    int ans[m+1][n+1];
    for(int i=0;i<=m;i++){
        ans[i][0]=i;
       
    }
    for(int i=1;i<=n;i++){
        ans[0][i]=i;
       
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]!=t[n-j]){
            ans[i][j] = min(ans[i-1][j-1],min(ans[i][j-1],ans[i-1][j]))+1;
            }else{
                ans[i][j] = ans[i-1][j-1];
            }
        }
    }
    return ans[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<func_memo(s,t)<<endl;
    cout<<func_dp(s,t)<<endl;
}