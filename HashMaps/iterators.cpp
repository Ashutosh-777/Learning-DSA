#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int> m;
    unordered_map<char,int>::iterator it;
    m['a']=1;
    m['b']=2;
    m['c']=3;
    m['d']=4;
    m['e']=5;
    m['f']=6;
    m['g']=7;
    m['h']=8;
    it=m.begin();
    while(it!=m.end()){
        cout<<"key : "<<it->first<<" value :" <<it->second<<endl;
        it++;
    }
}