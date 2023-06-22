#include <iostream>
#include <queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
            queue<int> q;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int p=k;
    for(int i=0;i<n;i++){
    while(k--){
        int x = q.front();
        q.pop();
        q.push(x);
        //cout<<x<<endl;
    }
    k=p;
    cout<<q.front()<<' ';
    q.pop();
    }
    }

    return 0;
}