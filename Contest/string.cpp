#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
         int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    char min=a[0];
    int index=-2;
    char first=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<=min){
            min=a[i];
            index=i;
        }
    }
     char p=a[index];
    // cout<<p<<index;
    for(int i=index;i>=0;i--){
        a[i]=a[i-1];
    }
    a[0]=p;
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
    }
   
    return 0;
}