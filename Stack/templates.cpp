#include <iostream>
using namespace std;
#include "templates_class.cpp"
int main(){
    // Pair<int,int> p1;
    // p1.setX(20);
    // p1.setY(44);
    // cout<<p1.getX()<<endl;
    // cout<<p1.getY()<<endl;
    Pair<Pair<int,string>,int> p2;
    p2.setY(88);
    Pair <int,string> p3;
    p3.setX(89);
    p3.setY("askalsdosdojsa");
    p2.setX(p3);
    cout<<"y :"<<p2.getY()<<endl<<"X : x: "<<p2.getX().getX()<<endl<<"X : y: "<<p2.getX().getY()<<endl;
    
    return 0;
}
