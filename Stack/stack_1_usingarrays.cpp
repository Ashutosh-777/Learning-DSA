#include <iostream>
using namespace std;
// #include "stack_using_Arrays.cpp"
//#include "stack_using_template.cpp"
//#include "stack_using_LL.cpp"
#include <stack>
// int main(){
//     StackUsingArrays s;
//     s.push(20);
//     cout<<s.pop()<<endl;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(10);
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.size()<<endl;
//     cout<<s.isEmpty()<<endl;
//     cout<<s.top()<<endl;
//     return 0;
// }
//using template
// int main(){
//     Stack_using_LL<int> s;
//     s.push(100);
//     cout<<s.pop()<<endl;
//     s.push(200);
//     s.push(300);
//     s.push(400);
//     s.push(500);
//     s.push(600);
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.getSize()<<endl;
//     cout<<s.IsEmpty()<<endl;
//     cout<<s.top()<<endl;
//     return 0;
// }
//Inbuilt Stack
int main(){
    stack<int> s;
    s.push(100);
    cout<<s.top()<<endl;
    s.pop();
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);
    s.push(600);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    return 0;
}