#include <bits/stdc++.h>
using namspace std;
vector<int> nextSmaller(vector<int> height){
    int n =height.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(s.size()!=0&&s.top()!=-1&&height[i]>=height[s.top()]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> height){
    int n =height.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i--){
        while(s.size()!=0&&s.top()!=-1&&height[i]>=height[s.top()]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int main(){
 return 0;
}