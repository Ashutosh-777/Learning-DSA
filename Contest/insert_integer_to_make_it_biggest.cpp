#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
            int n;
    char d;
    cin>>n>>d;
    char c[n+1];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    if(d=='0'){
        c[n]=d;
        for(int i=0;i<n+1;i++){
        cout<<c[i];
        }
    }else{
    int index=n;
    for(int i=0;i<n;i++){
    if(c[i]<d){
            index=i;
            break;
        }
    }
    for(int i=n+1;i>index;i--){
        c[i]=c[i-1];
    }
    c[index]=d;
    for(int i=0;i<n+1;i++){
        cout<<c[i];
        }
    }
    cout<<endl;
    }
    return 0;
}