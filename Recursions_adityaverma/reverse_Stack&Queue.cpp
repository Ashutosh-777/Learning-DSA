#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// void insert(stack<int>& s,int target){
//     if(s.size()==0){
//         s.push(target);
//         return;
//     }
//     int val=s.top();
//     s.pop();
//     insert(s,target);
//     s.push(val);
// }
// void reverse(stack<int>& s){
//     //Base case
//     if(s.size()==0){
//         return;
//     }
//     int val=s.top();
//     s.pop();
//     //recursive calling
//     reverse(s);
//     //induction
//     insert(s,val);
// }
void reverse_queue(queue < int > & q) {
    if(q.size()==0){
        return;
    }
    int val = q.front();
    q.pop();
    reverse(q);
    q.push(val);
    return;
}
int main(){
    // stack<int> s;
    // for(int i=0;i<6;i++){
    //     int x;
    //     cin>>x;
    //     s.push(x);
    // }
    // reverse(s);
    // for(int i=0;i<6;i++){
    //     cout<<s.top()<<' ';
    //     s.pop();
    // }
        queue<int> q;
    for(int i=0;i<2;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    reverse_queue(q);
    for(int i=0;i<2;i++){
        cout<<q.front()<<' ';
        q.pop();
    }
    return 0;
}