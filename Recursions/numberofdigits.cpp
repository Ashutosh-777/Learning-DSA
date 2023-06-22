#include <iostream>
using namespace std;
int number_of_digits(int x){
    if(x==0){
        return 0;
    }
    else{
        x=x/10;
        return number_of_digits(x)+1;
    }
}
int main(){
    cout<<number_of_digits(253);
    return 0;
}