#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int>& s,int target){
    if(s.size()==0||s.top()<=target){
        s.push(target);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,target);
    s.push(val);
}
void sort(stack<int>& s){
    cout<<"hi"<<endl;
    if(s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main(){
    stack<int> s;
    for(int i=0;i<6;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    sort(s);
    for(int i=0;i<6;i++){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}