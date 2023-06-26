#include <bits/stdc++.h>
using namespace std;
class complexNum{
    private:
    int real;
    int imag;
    public:
    complexNum(int real,int imag){
        this->real = real;
        this->imag = imag;
    }
    void print(){
        cout<<real<<" + "<<imag<<'i'<<endl;
    }
    void add(complexNum const &c2){
        real += c2.real;
        imag += c2.imag;
    }
    void multiply(complexNum const &c2){
        int newReal = real * c2.real - imag*c2.imag;
        int newImag = real*c2.imag + imag*c2.real;
        real =newReal;
        imag =newImag;
    }
};
int main(){
    complexNum c1(10,4);
    complexNum c2(20,5);
    c1.print();
    c2.print();
    c1.add(c2);
    c1.print();
    c2.print();
    c1.multiply(c2);
    c1.print();
    complexNum c3(10,-1);
    complexNum c4(10,1);
    cout<<"c3 : ";
    c3.print();
    cout<<endl<<"c4 : ";
    c4.print();
    c3.multiply(c4);
    cout<<endl<<"product : ";
    c3.print();
 return 0;
}