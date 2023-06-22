#include <iostream>
#include <string>
using namespace std;
bool palindrome(char s[],int n){
    if(n==0||n==1){
        return true;
    }

    bool ans =palindrome(s+1,n-2);
    if(ans){
        if(s[0]==s[n-1]){
            return ans;
        }else{
            return false;
        }
    }else{
        return ans;
    }
}
// int  palindrome(char s[],int n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     int  ans = palindrome(s+1,n-2);
//     if((s[0]==s[n-1])){
//         return ans+1;
//     }
//     return ans;

   
// }
int main(){
    string s;
    cin>>s;
    int n=s.length();
    char a[n];
    for(int i=0;i<n;i++){
        a[i]=s[i];
    }
    //cout<<palindrome(a,n)<<endl;
    if(palindrome(a,n)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}