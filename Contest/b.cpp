#include <iostream>
using namespace std;
long long int func_up(long long int n){
    return 4*n*n;
}
long long int func_down(long long int n){
    return (2*n+1)*(2*n+1);
}
int main(){
    long long int n;
    cin>>n;
    long long int i=0;
    for(;func_up(i)<n;i++){
        ;
    }
    long long int j=0;
    // for(;func_down(j)<n;i++){
    //     ;
    // }
    cout<<j<<endl;
    // if(2*j>2*i-1){
    //     cout<<2*i-1<<endl;
    // }else{
    //     cout<<2*j<<endl;
    // }
    return 0;
}