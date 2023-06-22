#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    unordered_map<int,int> m;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    int max=m[a[0]];
    int size=m.size();
    int index=0;
    for(int i=0;i<size;i++){
        if(max<m[a[i]]){
            max=m[a[i]];
                index = i;
            
        }
    }
    cout<<a[index]<<endl;
    return 0;
}