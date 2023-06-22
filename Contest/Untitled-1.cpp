#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // int t;
    // cin>>t;
    // while(t--){
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    b[n-1]=0;
    cout<<endl;
    
    return 0;
}