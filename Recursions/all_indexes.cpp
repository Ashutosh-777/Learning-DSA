#include <iostream>
using namespace std;
//Method I
int allindex(int a[],int n,int output[]){
    if(n==0){
        return -1;
    }
    int ans = allindex(a,n-1,output);
    if(a[n-1]==8){
        output[ans+1]=n-1;
        return ans+1; 
    }
    if(ans==-1){
        return -1;
    }else{
        return ans;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int output[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<allindex(a,n,output)+1<<endl;
    for(int i=0;i<=allindex(a,n,output);i++){
        cout<<output[i]<<' ';
    }

    return 0;
}
//Method II
