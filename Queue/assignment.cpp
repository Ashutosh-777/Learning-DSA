#include <bits/stdc++.h>
using namespace std;
void reverse_stack_using_stack(stack<int> &s){
    stack<int> extra;
    int n = s.size();
    for(int i=0;i<n;i++){
        int temp=s.top();
        s.pop();
        for(int j=0;j<n-i-1;j++){
            extra.push(s.top());
            s.pop();
        }
        s.push(temp);
        for(int j=0;j<n-i-1;j++){
            s.push(extra.top());
            extra.pop();
        }
    }
}
void insertRecursivelyStack(stack<int> &stack,int temp){
    if(stack.size()==0){
        stack.push(temp);
        return ;
    }
    int temp1 = stack.top();
    stack.pop();
    insertRecursivelyStack(stack, temp);
    stack.push(temp1);
}
void reverseStack(stack<int> &stack) {
    if(stack.size()==0){
        return;
    }
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertRecursivelyStack(stack,temp);
   // Write your code here
}
void reverseQueue(queue<int>& q){
       
}
int main(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    reverseQueue(q);
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}