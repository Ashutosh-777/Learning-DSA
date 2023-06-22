#include <iostream>
using namespace std;
int subsequences(string s,string output[]){
    if(s.size()==0){
        output[0]="";
        return 1;
    }
    string p =s.substr(1);
    int ans = subsequences(p,output);
    for(int i=0;i<ans;i++){
        output[i+ans]=s[0]+output[i];
    }
    return ans*2;
}
int main(){
    string s;
    cin>>s;
    string* output = new string[1000];
    int count = subsequences(s,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}