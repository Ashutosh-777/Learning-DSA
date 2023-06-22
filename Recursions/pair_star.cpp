#include <iostream>
#include <vector>
using namespace std;
void print(vector<char> c){
        for(int i=0;i<c.size();i++){
        cout<<c[i];
    }
}
void pair_star(string s, int n, vector<char>& v){ 
    if(n==0){
        return ;
    }
    //cout<<"hello22"<<endl;
    pair_star(s,n-1,v);
    if(s[n-2]==s[n-1]){
        //cout<<"hello"<<endl;
        v.push_back('*');
        v.push_back(s[n-1]);
    }else{
       v.push_back(s[n-1]); 
    }
    return;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<char> output;
    cout<<output.size()<<endl;
    pair_star(s,n,output);
    cout<<output.size()<<endl;
    print(output);

   // pair_star(s);
    return 0;
}