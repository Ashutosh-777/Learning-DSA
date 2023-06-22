#include <iostream>
using namespace std;
int floor(int a[],int n,int x){
    if(n==0){
        return -1;
    }
    int start=0;
    int end=n-1;
    int ans=-1;
    while(start<=end){
        int middle = start + (end-start)/2;
        if(a[middle]==x){
            return middle;
        }
        if(a[middle]>x){
            end = middle-1;
        }else{
            ans = middle;
            start = middle + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    cout<<floor(a,n,x);
    return 0;
}