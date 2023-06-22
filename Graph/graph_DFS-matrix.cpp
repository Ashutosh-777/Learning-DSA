#include <iostream>
using namespace std;
//while printing we need visited array to make sure we do not call upon those who are already printed
void print(int **edges,int sv,int n,bool *visited){
    cout<<sv<<" ";
    visited[sv]=true;
    for(int i=0;i<n;i++){
        // if(i==sv){
        //     continue;
        // }
        if(edges[sv][i]==1){
            if(!visited[i])
            print(edges,i,n,visited);
        }
    }
}
int main(){
    int n,e;
    // get the number of edges and vertices
    cin>>n>>e;
    //now create adjacency matrix with allvalue equal to 0 in it and its size should be n^2 so that each vertices has option with all other vertices
    int **edges = new int *[n];
    for(int i=0;i<n;i++){
        edges[i] = new int [n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool [n];
    print(edges,0,n,visited);
    return 0;
}