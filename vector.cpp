#include <iostream>
using namespace std;
#include <vector>
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    for(int i=0;i<6;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<v.capacity()<<"size: "<<v.size()<<endl;
    v.pop_back();
    v.pop_back();
    cout<<v.capacity()<<"size: "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

}