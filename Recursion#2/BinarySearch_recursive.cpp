#include <iostream>
using namespace std;
int solve(int a[],int x,int s,int e){
    int mid  = s+(e-s)/2;
    if(a[mid]==x){
        return mid;
    }
    if(s>=e){
        return -1;
    }
    if(a[mid]>x){
        return solve(a,x,s,mid);
    }else{
        return solve(a,x,mid+1,e);
    }
}
int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,x,0,n-1)<<endl;
    return 0;
}