#include <iostream>
using namespace std;
int count(int n){
    if(n==0){
        return 0;
    }
    int ans = count(n/10);
    if(n%10==0){
        return ans+1;
    }else{
        return ans;
    }
}
int main(){
    cout<<count(802)<<endl;
    return 0;
}