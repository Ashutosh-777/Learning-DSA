#include <iostream>
using namespace std;
int string_to_int(string s,int n){
    if(n==0){
        return 0;
    }
    int ans=string_to_int(s,n-1);
    ans =ans*10 + s[n-1]-'0';
    return ans;

}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int integer=string_to_int(s,n);
    cout<<integer-5;
    return 0;
}