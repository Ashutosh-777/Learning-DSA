#include <iostream>
using namespace std;
class Pair{
    int row;
    int col;
};
Pair 2DbinarySearch(int** a,int m,int n,int x){
    int j = n-1;
    int i = 0;
    while(i<m&&j>=0){
        if(a[i][j]==x){
            return Pair({i,j});
        }
        if(a[i][j]>x){
             j--;
        }else{
           i++;
        }
    }
    return Pair({-1,-1});
}
int main(){
    int m,n;
    cin>>m>>n;
    int **a= new int *[m];
    for(int i=0;i<m;i++){
         a[i]=new int [n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int x;
    cin>>x;
    Pair ans = 2DbinarySearch(a,m,n,x);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}