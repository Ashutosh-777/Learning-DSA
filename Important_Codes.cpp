#include <iostream>
using namespace std;
int main(){
    return 0;
}
//for n test case
while(n--){
    //code goes here
}
//taking input for an arrray of size n
int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
//Swap Functions
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Linked list Node
class Node {
    public:
    int data;
    Node *next;
    Node (int data){
        this->data=data;
        this->next=NULL;
    }
};
