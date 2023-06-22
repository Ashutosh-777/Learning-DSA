#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    b[n-1]=0;
    bool issorted=false;
    for(int i=0;i<n;i++){
        if(b[i]>=b[i+1]){
            issorted=true;
        }else{
            issorted=false;
        }
    }
    if(issorted){
        cout<<"sorted"<<endl;
    }else{
         if(b[0]==b[1]){
                int xmin = std::min(b[0], b[1]);
        int xmax = std::min(b[0], b[1]);
        if(xmin==xmax){
            b[n-1]=xmin;
        }else{
            int index;
            int min;
            for(int i=0;i<n-1;i++){
                if(b[i]==b[i+1]){
                    continue;
                }else{
                    index=i;
                   min = std::min(b[i], b[i+1]);
                }
            }
            for(int i=n-1;i>index+1;i--){
            b[i]=b[i-1];
            }
            b[index+1]=min;

        }

    }else{
        int x = std::min(b[0], b[1]);
        for(int i=n-1;i>1;i--){
            b[i]=b[i-1];
        }
        b[1]=x;
    }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    }
    return 0;
}