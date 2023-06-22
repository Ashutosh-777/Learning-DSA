//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int v,int start,vector<int> adj[] , int vis[],int path[],vector<int> &cycle){
      vis[start]=1;
      path[start]=1;
      for(auto it : adj[start]){
          if(!vis[it]){
              dfs(v,it,adj,vis,path,cycle);
          }else{
              if(path[it]==1){
                  for(int i=0;i<v;i++){
                      if(path[i]==1){
                          cycle.push_back(i);
                      }
                  }
              }
          }
      }
      path[start] = 0 ;
  }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> cycle;
        int vis[v]={0};
        int path[v]={0};
        if(v==1) {
            cycle.push_back(0);
            return cycle;
        };
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(v,i,adj,vis,path,cycle);
            }
        }
        vector<int> ans;
        int j = 0;
        int size = cycle.size();
        cycle[size]=-1;
        for(int i=0;i<v&&j<=size;i++){
            if(i==cycle[j]){
                j++;
                continue;
            }
            ans.push_back(i);
        }
        return ans;
        // code here
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