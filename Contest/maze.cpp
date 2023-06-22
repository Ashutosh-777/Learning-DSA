#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
            int n,m;
    cin>>n>>m;
    bool printed=false;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if((x1==n&&y1==m)||(x2==n&&y2==m)||(x2==1&&y2==1)||(x1==1&&y1==1)||(x1==1&&y1==m)||(x2==n&&y2==1)||(x2==1&&y2==m)||(x1==n&&y1==1)){
        cout<<2<<endl;
        printed=true;
    }
    if(!printed){
        if((x1==1&&y1!=1&&y1!=m)||(x1==n&&y1!=m&&y1!=1)||(x2==1&&y2!=1&&21!=m)||(x2==n&&y2!=m&&y2!=1)||(y1==1&&x1!=n&&x1!=1)||(y1==m&&x1!=n&&x1!=1)||(y2==1&&x2!=n&&x2!=1)||(y2==m&&x2!=n&&x2!=1)){
        cout<<3<<endl;
        printed=true;
    }
    }
    if(!printed){
        cout<<4<<endl;
    }
    }
    return 0;
}