//we do implicit typecasting for integers or ohter variable
//but for address we perform explicit typecasting
//void pointer can point to any datat type but we cannot dereference it unless we typecast it
#include <iostream>
using namespace std;
int main(){
    int i=67;
    char c=i;
    int *p=&i;
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<c<<endl;
    char *pc =(char *)&i;
    cout<<p<<endl;
    cout<<pc<<endl;
    cout<<*(pc+1)<<endl;
    cout<<pc+2<<endl;
    void *pc3 =&i;
    cout<<*(char *)pc3<<endl;
    return 0;
}