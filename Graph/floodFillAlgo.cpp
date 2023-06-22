//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(int nc,int sr,int sc,vector<vector<int>>& image,vector<vector<int>> &vis,int delrow[],int delcol[],int ic){
        int m =image.size();
        int n =image[0].size();
        image[sr][sc]=nc;
        vis[sr][sc]=1;
        for(int i=0;i<4;i++){
        int nrow = sr + delrow[i];
        int ncol = sc + delcol[i];
        if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&image[nrow][ncol]==ic&&!vis[nrow][ncol]){
            dfs(nc,nrow,ncol,image,vis,delrow,delcol,ic);
        }
        }
    }
    void bfs(int nc,int sr,int sc,vector<vector<int>>& image,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        int m = image.size();
        int n = image[0].size();
        int ic = image[sr][sc];
        image[sr][sc]=nc;
        vis[sr][sc]=1;
        q.push({sr,sc});
        while(q.size()!=0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row+1<m){
                if(image[row+1][col]==ic&&!vis[row+1][col]){
                    vis[row+1][col]=1;
                    q.push({row+1,col});
                    image[row+1][col]=nc;
                }
            }
            if(row-1>=0){
                if(image[row-1][col]==ic&&!vis[row-1][col]){
                    vis[row-1][col]=1;
                    q.push({row-1,col});
                    image[row-1][col]=nc;
                }                
            }
            if(col+1<n){
                if(image[row][col+1]==ic&&!vis[row][col+1]){
                    vis[row][col+1]=1;
                    q.push({row,col+1});
                    image[row][col+1]=nc;
                }                
            }
            if(col-1>=0){
                if(image[row][col-1]==ic&&!vis[row][col-1]){
                    vis[row][col-1]=1;
                    q.push({row,col-1});
                    image[row][col-1]=nc;
                }                 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        //bfs(newColor,sr,sc,image,vis);
        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};
        int ic= image[sr][sc];
        dfs(newColor,sr,sc,image,vis,delrow,delcol,ic);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends