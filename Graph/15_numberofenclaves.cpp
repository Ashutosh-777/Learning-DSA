//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void bfs(vector<vector<int>> &grid,vector<vector<int>> &vis){
      int m =grid.size();
      int n = grid[0].size();
      int delrow[]={-1,0,0,1};
      int delcol[]={0,-1,1,0};
      queue<pair<int,int>> q;
      for(int i=0;i<m;i++){
          if(grid[i][0]==1){
              q.push({i,0});
              vis[i][0]=1;
          }
          if(grid[i][n-1]==1){
              q.push({i,n-1});
              vis[i][n-1]=1;
          }
      }
      for(int i=1;i<n-1;i++){
          if(grid[0][i]==1){
              q.push({0,i});
              
              vis[0][i]=1;
          }
          if(grid[m-1][i]==1){
              q.push({m-1,i});
              vis[m-1][i]=1;
          }
      }
      
      while(q.size()!=0){
          pair<int,int> ans = q.front();
          q.pop();
          for(int i=0;i<4;i++){
            int nrow = ans.first + delrow[i];
            int ncol = ans.second + delcol[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&grid[nrow][ncol]==1&&!vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
          }
      }
  }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    bfs(grid,vis);
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&vis[i][j]==0){
                count++;
            }
        }
    }
    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends