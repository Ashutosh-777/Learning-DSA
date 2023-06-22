#include <iostream>
using namespace std;
#include "queue_LL.cpp"
#include <queue>
int main(){
    Queue_LL<int> q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);
    q.enqueue(500);
    q.enqueue(600); 
    q.enqueue(700);
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}
//using inbuilt queue
//int main(){
//     queue<int> q;
//     q.push(100);
//     q.push(200);
//     q.push(300);
//     q.push(400);
//     q.push(500);
//     q.push(600); 
//     q.push(700);
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     cout<<q.size()<<endl;
//     cout<<q.empty()<<endl;
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     cout<<q.front()<<endl;
//     q.pop();
//     return 0;
// }