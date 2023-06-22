//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int start,int col,vector<int> adj[],int vis[]){
        vis[start]=col;
        for(auto it: adj[start]){
            if(vis[it]==-1){
                if(!dfs(it,!col,adj,vis)) return false;;
            }else{
                if(vis[it]==col){
                    return false;
                }
            }
        }
        return true;
    }
    bool bfs(int start,vector<int> adj[],int vis[]){
	    queue<int> q;
	    q.push(start);
	    vis[start]=0;
	    while(q.size()!=0){
	        int front = q.front();
	        q.pop();
	        for(auto it : adj[front]){
	            if(vis[it]==-1){
	                vis[it]=!vis[front];
	                q.push(it);
	            }else{
	                if(vis[it]==vis[front]){
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int v, vector<int> adj[]){
	    //coloured array
        int vis[v];
	    for(int i=0;i<v;i++){
	        vis[i]=-1;
	    }
	   // for(int i=0;i<v;i++){
	   //     if(vis[i]!=-1) continue;
	   //     if(!bfs(i,adj,vis)) return false;
	   // }
	   for(int i=0;i<v;i++){
	        if(vis[i]!=-1) continue;
	        if(!dfs(i,0,adj,vis)) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends