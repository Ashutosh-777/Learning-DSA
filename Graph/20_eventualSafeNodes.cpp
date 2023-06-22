//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
  private:
  bool dfs(int start,vector<int> adj[],vector<int> &ans,vector<int> &vis,vector<int> &path){
      vis[start]=1;
      path[start]=1;
      for(auto it : adj[start]){
          if(!vis[it]){
             if( dfs(it,adj,ans,vis,path)){
                 ans[start]=0;
                 return true;
             };
          }else{
              if(path[it]==1){
                  ans[it]=0;
                  return true;
              }
          }
      }
      ans[start]=1;
      path[start]=0;
      return false;
      
  }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> ans(v,0);
        vector<int> vis(v,0);
        vector<int> path(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,ans,vis,path);
            }
        }
        vector<int> safeNodes;
        for(int i=0;i<v;i++){
            if(ans[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends