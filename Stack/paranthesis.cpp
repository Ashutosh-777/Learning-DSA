#include <iostream>
using namespace std;
#include <stack>

int main(){
    string str;
    cin>>str;
    int size=str.size();
    stack<char> stack;
    bool balanced = true;
    for(int i=0;i<size;i++){
        if(str[i]==')'||str[i]=='}'||str[i]==']'){
            if(stack.size()==0){
                balanced=false;
                break;
            }
        }
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            stack.push(str[i]);
        }else{
            if(str[i]==')'&&stack.top()=='('){
                stack.pop();
            }
            if(str[i]=='}'&&stack.top()=='{'){
                stack.pop();
            }
            if(str[i]==']'&&stack.top()=='['){
                stack.pop();
            }
        }
    }
    if(!balanced){
        cout<<"False";
    }
    if(stack.size()==0){
        if(balanced){
            cout<<"True";
        }
    }else{
        cout<<"False";
    }
    return 0;
}