#include <bits/stdc++.h>
using namespace std;
int Mex(int a[],int n){
    int min=*min_element(a, a + n);
    sort(a,a+n);
    int mex=0;
    for(int i=0;i<n;i++){
        if(a[i]==mex){
            mex=mex+1;
        }
        if(mex<a[i]){
            break;
        }
    }
    return mex;
}
int main(){
    int t;
    cin>>t;
    while(t--){
            int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int max=*max_element(a, a + n);
    bool printed=false;
    if(n==1&&a[0]==1){
        cout<<"YES"<<endl;
        printed=true;      
    }
    if(n==1){
        cout<<"NO"<<endl;
        printed=true;
    }
    int mex=Mex(b,n)+1;
    int count=0;
    for(int i=0;i<n;i++){
        if(b[i]==mex){
            count++;
        }
        if(b[i]>mex){
            break;
        }
    }
    if(printed==false){
            if(count==0){
        //need to check if mex-1 can be accomodated or not
        if(mex>max){
            cout<<"NO"<<endl;
            printed=true;
        }else{
        cout<<"YES"<<endl;
        printed=true;
        }

    }
    }
    if(!printed){
            int steps=0;
    bool possible =true;
    for(int i=0;i<n;i++){
        if(steps<=count){
            if(a[i]==mex){
            a[i]=mex-1;
            steps++;
        }else{
            if(steps!=0&&(steps!=count)){
            if(a[i]<mex){
                possible=false;
            }
        }
        }
        }
    }
        if(possible){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    }


    return 0;
}
//s.count(key)=1 if key present