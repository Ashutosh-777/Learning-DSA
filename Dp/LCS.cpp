#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print_uniquesubset(string ip,string op,vector<string>& v){
        if(ip.length()==0){
            if(count(v.begin(), v.end(), op)==0){
                 v.push_back(op);
                 //cout<<op<<" ";
            }
        return ;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(0,1);
    print_uniquesubset(ip,op1,v);
    print_uniquesubset(ip,op2,v);
    return ;
}
//time complexity very very  bad
int  func(string s,string t){
    vector<string> s_substring;
    vector<string> t_substring;
    print_uniquesubset(s,"",s_substring);
    print_uniquesubset(t,"",t_substring);
    int max=0;
    for(int i=0;i<s_substring.size();i++){
        for(int j =0;j<t_substring.size();j++){
            if(s_substring[i]==t_substring[j]){
                if(s_substring[i].length()>max){
                    max=s_substring[i].length();
                }
            }
        }
    }
    return max;
}
int func_rec(string s, string t){
    if(s.length()==0||t.length()==0){
        return 0;
    }
    if(s[0]==t[0]){
        int ans = func_rec(s.substr(1),t.substr(1));
        return ans+1;
    }else{
        int ans2 = func_rec(s.substr(1),t);
        int ans3 = func_rec(s,t.substr(1));
        return max(ans2,ans3);
    }
}
int func_helper(string s,string t,int **ans){
    int m = s.size();
    int n = t.size();
    if(m==0||n==0){
        return 0;
    }
    //checking if recursive call is already made or not
    if(ans[m][n]!=-1){
        return ans[m][n];
    }
    int smallAns;
    if(s[0]==t[0]){
        smallAns = 1+ func_helper(s.substr(1),t.substr(1),ans);
    }else{
        int a = func_helper(s.substr(1),t,ans);
        int b = func_helper(s,t.substr(1),ans);
        smallAns = max(a,b);
    }
    ans[m][n]=smallAns;
    return smallAns;
}
int func_memo(string s, string t){
    int m = s.length();
    int n = t.length();
    int **ans = new int *[m+1];
    for(int i=0;i<=m;i++){
        ans[i]=new int [n+1];
        for(int j=0;j<=n;j++){
            ans[i][j]=-1;
        }
    }
    return func_helper(s,t,ans);
}
int func_dp(string s,string t){
    int m =s.size(),n=t.size();
    int ans[m+1][n+1];
    for(int j=0;j<=n;j++){
        ans[0][j]=0;
    }
    for(int j=0;j<=m;j++){
        ans[j][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                ans[i][j]=ans[i-1][j-1] +1;
            }else {
            ans[i][j]= max(ans[i-1][j],max(ans[i-1][j-1],ans[i][j-1]));
            }
        }
    }
    return ans[m][n];
}
int main(){
    string s;
    string t;
    cin>>s>>t;
    cout<<func_memo(s,t)<<endl;
    cout<<func(s,t)<<endl;
    cout<<func_rec(s,t)<<endl;
    cout<<func_dp(s,t);
    return 0;
}