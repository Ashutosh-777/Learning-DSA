#include <iostream>
using namespace std;
int main(){
    char a[]="abcdef";
    cout<<a<<endl;
    //In case of character it does not printed address like it did in integer;
    cout<<&a<<endl;
    char *ptr=&a[0];
    cout<<ptr<<endl;
    //It does not acted like a pointer instead it printed the data stored
    // char*ptr = "abcdefghij"; not advisable because in character array cout starts printing strings until it finds a null;
    // cout<<*ptr<<endl;
    char c1='a';
    cout<<c1<<endl;
    char *p=a;
    //here p also get converted into array
    cout<<a[0]<<" "<<p[5];
    return 0;
}