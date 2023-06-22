#include <iostream>
using namespace std;
int diff(int a[],int n,int x){
    int start=0;
    int end = n-1;
    while(start<=end){
        int middle = start + (end-start)/2;
        if(a[middle]==x){
            return x;
        }
        if(a[middle]>x){
            end = middle -1;
        }else{
            start = middle + 1; 
        }
    }
    int diff1 = abs(a[end]-x);
    int diff2 = abs(a[start]-x);
    return diff1>diff2 ? a[start] : a[end] ;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    cout<<diff(a,n,x)<<endl;
    return 0;
}