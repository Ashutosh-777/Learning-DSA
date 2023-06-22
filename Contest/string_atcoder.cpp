#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s[n];
    int j=n;
    while(j--){
        cin>>s[j];
    }
    bool printed=false;
    for(int i=0;i<n;i++){
        if(s[i]=="and"||s[i]=="not"||s[i]=="that"||s[i]=="the"||s[i]=="you"){
            cout<<"YES";
            printed=true;
            break;
        }
    }
    if(!printed){
        cout<<"NO";
    }
    return 0;
}