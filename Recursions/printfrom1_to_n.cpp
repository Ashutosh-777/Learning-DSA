#include <iostream>
using namespace std;
void print(int x){
    if(x==0){
        return;
    }
    print(x-1);
      cout<<x<<' ';
}
int main(){
    print(7845);
    return 0;
}