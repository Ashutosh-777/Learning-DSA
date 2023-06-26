//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Pair{
    public:
    int node;
    int dist;
};
class Solution {
  private:
    void bfs(int v,int src,vector<int> adj[],vector<int> &dis){
        queue<Pair> q;
        int vis[v]={0};
        vis[src]=1;
        q.push({src,0});
        dis[src]=0;
        //cout<<q.front().node<<"ferfef"<<q.front().dist;
        while(q.size()!=0){
            Pair front = q.front();
            q.pop();
            int node =front.node;
            int dist = front.dist;
            for(auto it: adj[node]){
                int newWt = 1 + dist;
                if(newWt<dis[it]){
                    dis[it]=newWt;
                }
                if(!vis[it]) {
                    vis[it]=1;
                    q.push({it,dis[it]});}
            }
        }
        for(int i=0;i<v;i++){
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int v,int e, int src){
        vector<int> dis(v);
        vector<int> adj[v];
        for(int i=0;i<e;i++){
            int u =edges[i][0];
            int v =edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<v;i++){
            dis[i]=INT_MAX;
        }
        dis[src] = 0;
        bfs(v,src,adj,dis);
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends