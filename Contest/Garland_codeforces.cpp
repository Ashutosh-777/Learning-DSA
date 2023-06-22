#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    while(x--){
        int n;
    cin>>n;
    int a[4];
    for(int i=0;i<4;i++){
        a[i]=n%10;
        n=n/10;
    }
    sort(a,a+4);

    bool s3d1=false;
   
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3]){
        s3d1=true;
    }
    if(a[2]==a[1]&&a[2]==a[3]&&a[0]!=a[3]){
        s3d1=true;
    }
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]){
        cout<<-1<<endl;
    }else{
        if(s3d1){
        cout<<6<<endl;
    }else{
        cout<<4<<endl;
    }
    }
    }

    return 0;
}