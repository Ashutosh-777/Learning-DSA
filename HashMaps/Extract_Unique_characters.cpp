#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<char,bool> m;
    string str;
    cin>>str;
    int n=str.length();
    m[str[0]]=false;
    for(int i=0;i<str.size();i++){
        if(m[str[i]]==true){
            str.erase(i,1);
            i--;
        }else{
            m[str[i]]=true;
        }
    }
    cout<<str<<endl;
    return 0;
}