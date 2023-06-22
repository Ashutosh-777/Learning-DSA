#include <iostream>
#include <stack>
using namespace std;
void deletemid(stack<int>& s,int position){
    if(s.size()==0){
        return;
    }
    if(position==1){
        s.pop();
        return;
    }
    int val=s.top();
    s.pop();
    deletemid(s,position-1);
    s.push(val);
    return;
}
int main(){
    stack<int> s;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    deletemid(s,3);
    cout<<s.size()<<endl;
    int n=s.size();
    for(int i=0;i<n;i++){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}