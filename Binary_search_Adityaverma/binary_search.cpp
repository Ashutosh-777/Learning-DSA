#include <iostream>
using namespace std;
int  Binary_search(int a[],int n,int x){
        int start,middle,end;
        start=0;
        end=n-1;
        while(end>=start){
            middle = start + (end-start)/2;
            if(a[middle]==x){
             return middle;
            }
            if(a[middle]<x){
             start=middle+1;
             continue;
            }else{
             end=middle-1;
             continue;
            }
        } 
        return -1;
}
int helper(int a[],int start,int end,int x){
    if(start>end){
        return -1;
    }
    if(start==end&&a[start]==x){
        return start;
    }
    int middle = start + (end-start)/2;
    if(a[middle]==x){
        return middle;
    }
    if(a[middle]>x){
        return helper(a,start,middle-1,x);
    }else{
        return helper(a,middle+1,end,x);
    }
}
int binarySearchRecursive(int a[],int n,int x){
    return helper(a,0,n-1,x);
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
    cout<<binarySearchRecursive(a,n,x)<<endl;
    cout<<Binary_search(a,n,x)<<endl;
    
    return 0;
}