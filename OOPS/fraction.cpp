#include <iostream>
using namespace std;
class fraction{
    private:
    int numerator;
    int denominator;
    public:
    fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    //need only one argument because when we use f1.add address of f1 is automatically passed to the classs

    // fraction add(fraction f1,fraction f2){
    //     int LCM = f1.denominator * f2.denominator ;
    //     int newNumerator = f1.numerator * f2 .denominator + f2.numerator * f2.denominator ;
    //     fraction ans;
    //     ans.numerator = newNumerator;
    //     ans.denominator = LCM;
    //     return ans;
    // }

    //we will keep function type void and we will store the answer in the same variable f1;
    void simplify(){
        int gcd = 1;
        int j =min(numerator,denominator);
        for(int i=1;i<=j;i++){
            if(numerator%i==0&&denominator%i==0) gcd=i;
        }
        numerator/=gcd;
        denominator/=gcd;
    }
    //passing by constant reference in order to avoid calling copy constructors and changing its value
    void add(fraction const &f2){
        int LCM = denominator * f2.denominator;
        int newNumerator = numerator*f2.denominator + f2.numerator*denominator;
        denominator = LCM;
        numerator = newNumerator;
        simplify();
    }
    void multiply(fraction const &f2){
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }
};
int main(){
    fraction f1(15,4);
    fraction f2(10,2);
    f1.print();
    f2.print();
    f2.simplify();
    f2.print();
    f1.add(f2);
    f1.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0;
}