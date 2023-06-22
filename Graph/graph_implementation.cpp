#include <iostream>
#include <vector>
using namespace std;
int main(){
    int v,e;
    cin>>v>>e;
    vector<int> adj[v+1];
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }
}