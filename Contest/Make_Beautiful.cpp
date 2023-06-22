#include <iostream>
using namespace std;
int ugly(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
        if(a[i+1]==sum){
            return 1;
        }
    }
    return 0;
}
int beautiful(int a[],int n){
    return !ugly(a, n);
}
int  makebeautiful(int a[],int n){
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum=sum+a[i];
        if(a[i+1]==sum){
               int temp = a[i];
              a[i]=a[i+1];
              a[i+1]=temp;
              if(ugly(a,n)){
                if(i==n-2){
                    return 0;
                }
                makebeautiful(a,n);
                
              }else{
                return 1;
              }
        }
    }
    return 0;
}
int main(){
    //  int t;
    //  cin>>t;
    //     while(t--){
         int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(beautiful(a,n)){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        }
        if(ugly(a,n)){
            if(makebeautiful(a,n)){
                cout<<"YES"<<endl;
                for(int i=0;i<n;i++){
                    cout<<a[i]<<" ";
                }
                cout<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        // }
    return 0;
}