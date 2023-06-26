//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int indegree[N] = {0};
	    int n = prerequisites.size();
	    vector<int>  adj[N];
	    for(int i=0;i<n;i++){
	        indegree[prerequisites[i].first]++;
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    int count = 0;
	    while(q.size()!=0){
	        int front = q.front();
	        count++;
	        q.pop();
	        for(auto it: adj[front]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return count==N? 1:0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends