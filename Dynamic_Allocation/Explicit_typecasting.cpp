#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}
int main(){
    char ch = 'A';
    int *pc = (int *)&ch;
    updateValue(pc);
    cout << ch;
}