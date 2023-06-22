#include <iostream>
using namespace std;
int nearlySorted(int a[],int n,int x){
    if(n==0){
        return -1;
    }
    int start=0;
    int end =n-1;
    while(start<=end){
        int middle = start + (end-start)/2;
        if(a[middle]==x){
            return middle;
        }
        if(middle+1<n&&a[middle+1]==x){
            return middle+1;
        }
        if(middle-1>=0&&a[middle-1]==x){
            return middle-1;
        }
        if(a[middle]>x){
            end = middle-1;
        }else{
            start = middle+1;
        }
    }
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
    cout<<nearlySorted(a,n,x);
    return 0;
}