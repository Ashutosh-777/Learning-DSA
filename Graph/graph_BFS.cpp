//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        queue<int> q;
        vector<int> visited(v,0);
        q.push(0);
        visited[0]=1;
        vector<int> bfs;
        while(q.size()!=0){
            int front = q.front();
            q.pop();
            bfs.push_back(front);
            int n = adj[front].size();
            // for(int i=0;i<n;i++){
            //     if(!visited[adj[front][i]]){
            //         q.push(adj[front][i]);
            //         visited[adj[front][i]]=1;
            //     }
            // }
            for( auto it : adj[front]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return bfs;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends