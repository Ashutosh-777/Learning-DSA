//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(int start,vector<int> adj[],int vis[]){
        queue<pair<int,int>> q;
        q.push({start,-1});
        vis[start]=1;
        while(q.size()!=0){
            pair<int,int> ans = q.front();
            q.pop();
            for(auto it : adj[ans.first]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,ans.first});
                }else{
                    if(it!=ans.second){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int start,vector<int> adj[],int vis[],int parent){
        vis[start]=1;
        for(auto it : adj[start]){
            if(!vis[it]){
                if(dfs(it,adj,vis,start)){
                    return true;
                }
            }
            else if(parent!=it) return true;
        }
        //cout<<"hi";
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v]={0};
        // for(int i = 0 ;i<v;i++){
        //     if(!vis[i]){
        //         if(bfs(i,adj,vis)==true){
        //             return true;
        //         }
        //     }
        // }
        for(int i = 0 ;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,-1)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends