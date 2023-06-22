#include <iostream>
using namespace std;
int power(int x, int n){
    if(n==1){
        return x;
    }
    else{
        return power(x,n-1)*x;
    }
}
int main(){
    cout<<power(3,5)<<endl;
    return 0;
}