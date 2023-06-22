#include <iostream>
using namespace std;
int Multiply(int x,int y){
    if(y==0||x==0){
        return 0;
    }
    int ans =Multiply(x,y-1);
    return ans+x;
}
int main(){
    cout<<Multiply(0,200);
    return 0;
}