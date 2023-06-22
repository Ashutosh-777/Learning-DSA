#include <bits/stdc++.h>
using namespace std;
void solve(string s,int n,vector<string> &v){
    if(n==1){
        string p(1,s[n-1]);
        v.push_back(p);
        return ;
    }
    solve(s,n-1,v);
    int l = v.size();
    string c[v.size()];
    for(int i=0;i<v.size();i++){
        c[i]=v[i];
    }
    v.erase(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            string str =c[j];
            str.insert(i, 1, s[n-1]);
            v.push_back(str);
        }
    }
    return ;
}
int main(){
    string s;
    cin>>s;
    vector<string> v;
    cout<<v.size()<<endl;
    solve(s,s.length(),v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
///better approach
/*
    Time Complexity: O(N! * log(N!))
    Space complexity: O(N * N!)
    
    Where N is the length of the given string.
*/

#include <algorithm>

void generatePermutationsHelper(string &str, int l, int r, vector<string> &ans)
{
    // base case
    if (l == r)
    {
        ans.push_back(str);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        generatePermutationsHelper(str, l + 1, r, ans);
        // backtrack
        swap(str[l], str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    // stores the permutations of the string
    vector<string> ans;

    int l = 0;
    int r = str.size() - 1;

    // call the recursive function
    generatePermutationsHelper(str, l, r, ans);

    // lexicographically increasing order
    sort(ans.begin(), ans.end());

    return ans;
}