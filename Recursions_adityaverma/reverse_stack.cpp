#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int>& s,int target){
    if(s.size()==0){
        s.push(target);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,target);
    s.push(val);
}
void reverse(stack<int>& s){
    //Base case
    if(s.size()==1){
        return;
    }
    int val=s.top();
    s.pop();
    //recursive calling
    reverse(s);
    //induction
    insert(s,val);
}
int main(){
    stack<int> s;
    for(int i=0;i<6;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    reverse(s);
    for(int i=0;i<6;i++){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}