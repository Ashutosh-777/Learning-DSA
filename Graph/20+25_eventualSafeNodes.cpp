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
  vector<int>* reverseGraph(int v,vector<int> adj[],vector<int> ans[]){
      for(int i=0;i<v;i++){
          for(auto it: adj[i]){
              ans[it].push_back(i);
          }
      }
      return ans;
  }
  vector<int> bfs(int v,vector<int> ans[]){
      vector<int> adj[v];
      reverseGraph(v,ans,adj);
      int in[v]={0};
      queue<int>q;
      for(int i=0;i<v;i++){
          for(auto it: adj[i]){
              in[it]++;
          }
      }
      for(int i=0;i<v;i++){
          if(in[i]==0){
              q.push(i);
          }
      }
      vector<int> topo;
      while(!q.empty()){
          int front = q.front();
          q.pop();
          topo.push_back(front);
          for(auto it:adj[front]){
              in[it]--;
              if(in[it]==0){
                  q.push(it);
              }
          }
      }
      sort(topo.begin(),topo.end());
      return topo;
  }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> ans(v,0);
        vector<int> vis(v,0);
        vector<int> path(v,0);
        //return bfs(v,adj);
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