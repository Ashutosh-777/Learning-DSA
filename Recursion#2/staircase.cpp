#include <iostream>
using namespace std;
int func(int n){
    if(n==0||n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    int ans = func(n-1)+func(n-2)+func(n-3);
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<func(n)<<endl;
    return 0;
}