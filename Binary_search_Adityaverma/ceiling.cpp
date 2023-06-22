#include <iostream>
using namespace std;
int ceiling(int a[],int n,int x){
    int start = 0;
    int end = n-1;
    int ans = n;
    while(start<=end){
        int middle = start + (end-start)/2;
        if(a[middle]==x){
            return middle;
        }
        if(a[middle]>x){
            ans = middle;
            end = middle -1;
        }else{
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
    cout<<ceiling(a,n,x);
    return 0;
}