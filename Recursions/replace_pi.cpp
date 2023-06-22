#include <iostream>
using namespace std;
void replace_pi(string& s,int n){

    if(n==1){
        return;
    }
    if(s.substr(n-2,2)=="pi"){
        s.replace(n-2,2,"3.14");
    }
    replace_pi(s,n-1);
}
void remove_x(string& s,int n){
    if(n==0){
        return ;
    }
    remove_x( s, n-1);
    if(s[n-1]=='x'){
        s.erase(n-1,1);
    }
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    remove_x(s,n);
    cout<<s<<endl; 
    n=s.size();
    replace_pi(s,n);
    cout<<s<<endl; 
    return 0;
}