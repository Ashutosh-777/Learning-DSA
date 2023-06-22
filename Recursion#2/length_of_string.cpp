#include <iostream>
#include <string>
#include <vector>
using namespace std;
void removeDuplicate(string &s,int n){
    if(n==0){
        return;
    }
    if(s[n-2]==s[n-1]){
        s.erase(n-2,1);
    }
    removeDuplicate(s,n-1);
}
void removecharacter(char s[]){
    if(s[0]=='\0'){
        return;
    }
    removecharacter(s+1);
    if(s[0]=='x'){;
        int i=1;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        //because null character was not copied
    
        s[i-1]=s[i];
    }
    return;
}
void replaceChar(char s[],int n,char a,char x){
    if(n==0){
        return;
    }
    replaceChar(s+1,n-1,a,x);
    if(s[0]==a){
        s[0]=x;
    }
    return;
}
int lengthofstring(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int ans=lengthofstring(s+1);
    return ans+1;
}
// bool check_rule(String s){

// }
int main(){
    return 0;
}