#include <iostream>
using namespace std;
int xori(int a,int x){
    int p=a^x;
    return p; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=a[0];
    for(int i=1;i<n;i++){
        x=x^a[i];
    }
    int f=a[0]^x;
    for(int i=1;i<n;i++){
        f=f^xori(a[i],x);
    }
    if(f==0){
           if(x==0){
           }else{
            cout<<x;
           }
    }else{
        cout<<-1;
    }
    cout<<endl;
    }
 
    return 0;
}