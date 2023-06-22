//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
  void bfs( pair<int,int> start,vector<vector<int>> &vis,vector<vector<char>>& grid){
    vis[start.first][start.second] = 1;
        int m = grid.size();
        int n =grid[0].size();
    queue<pair<int,int>> q;
    q.push(start);
    while(q.size()!=0){
        pair<int,int> temp = q.front();
        int i,j;
        i=temp.first;
        j=temp.second;
        q.pop();
        for(int deltarow= -1;deltarow<=1;deltarow++){
            for(int deltacol=-1;deltacol<=1;deltacol++){
                int row = i +deltarow;
                int col = j + deltacol;
                if(row<m&&row>=0&&col>=0&&col<n&&grid[row][col]=='1'&&!vis[row][col]){
                    q.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
  }
  }
  
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        //int **vis = new int *[m];
        // vector<pair<int,int>> adj;
        
        // for(int i=0;i<m;i++){
        //     vis[i] = new int [ n];
        //     for(int j=0;j<n;j++){
        //         vis[i][j]=0;
        //         if(grid[i][j]=='1'){
        //             adj.push_back({i,j});
        //         }
        //     }
        // }
        // //instead we can use visited vector
        vector<vector<int>> vis(m,vector<int>(n,0));
        int island = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(grid[i][j]=='1'){
                    island++;
                    bfs({i,j},vis,grid);
                    }
                }
            }
        }
        return island;
        
    }
};    

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends