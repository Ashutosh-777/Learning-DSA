//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
   void dfs(int start,vector<int> adj[],int vis[]){
       vis[start] = 1;
       for(auto it : adj[start]){
           if(!vis[it]){
               dfs(it,adj,vis);
           }
       }
   }
  public:
    int numProvinces(vector<vector<int>> adj, int v ) {
        int vis[v]={0};
        vector<int> adjLS[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adj[i][j]==1){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }
        int province = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                province++;
                dfs(i,adjLS,vis);
            }
        }
        return province;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends