#include <iostream>
using namespace std;
int first_index(int a[],int n){
    if(n==0){
        return -1;
    }
    
    int ans;
    ans=first_index(a+1,n-1);
    if(a[0]==8){
        return 0;
    }
    if(ans==-1){
        return -1;
    }else{
        return ans+1;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<first_index(a,n);
    return 0;
}