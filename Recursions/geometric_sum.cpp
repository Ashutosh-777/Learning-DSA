#include <iostream>
using namespace std;
double power(int x, int n){
    if(n==1){
        return x;
    }
    else{
        return power(x,n-1)*x;
    }
}
double geometric_sum(int k){
    if(k==0){
        return 1;
    }
    
    double ans = geometric_sum(k-1)+1/power(2,k);
    return ans;
}
int main(){
    int k;
    cin>>k;
    cout<<geometric_sum(k)<<endl;
    return 0;
}