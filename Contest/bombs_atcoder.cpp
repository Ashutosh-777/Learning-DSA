#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    char a[x][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a[i][j]=='.'||a[i][j]=='#'){
                continue;
            }else{
                int x=a[i][j];
                for(int p=j;p<y;p++){
                    if(a[i][p]=='#'){
                        a[i][p]='.';
                    }
                }
                for(int p=i;p<y;p++){
                    if(a[p][i]=='#'){
                        a[p][i]='.';
                    }
                }
                for(int p=j;p>0;p--){
                    if(a[i][p]=='#'){
                        a[i][p]='.';
                    }
                    
                }
                for(int p=i;p>0;p--){
                    if(a[p][j]=='#'){
                        a[p][j]='.';
                    }
                }
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}