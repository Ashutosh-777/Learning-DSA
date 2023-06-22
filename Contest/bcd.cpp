#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
     int t;
    cin>>t;
    while(t--){
     int n;
    cin>>n;
    vector< int> a;
    vector< int> b;
    for( int i=0;i<n;i++){
         int q;
        cin>>q;
        a.push_back(q);
    }
    for(int i=0;i<n;i++){
         int q;
        cin>>q;
        b.push_back(q);
    }
    bool sorted1=is_sorted(a.begin(), a.end());
    bool sorted2=is_sorted(b.begin(),b.end());
    vector< int> v;
    vector< int> w;
    bool v1=false;
    bool printed=false;
    if(sorted2){
        cout<<1<<" "<<n<<endl;
        printed=true;
    }else{
        for(int i=0;i<n-1;i++){
            if(b[i]<=b[i+1]){
                if(!v1){
                    v.push_back(i+1);
                    v1=true;
                    if(i==n-2){
                       w.push_back(i+2); 
                    }
                }else{
                    continue;
                }
            }else{
                if(v1){
                    w.push_back(i+1);
                }
                v1=false;
            }
        }
        if(v1){
            w.push_back(n);
        }
     int size=v.size();
     int max=0;
     int index;
    for( int i=0;i<size;i++){
         int c=w[i]-v[i]+1;
        if(c>max){
            max=c;
            index=i;
        }
    }
    if(size!=0){
        cout<<v[index]<<" "<<w[index]<<endl;
        printed=true;
    }else{
        cout<<1<<" "<<1<<endl;
        printed=true;
    }
    
    }
    if(!printed){
        cout<<1<<" "<<1<<endl;
    }
    }

    return 0;
}