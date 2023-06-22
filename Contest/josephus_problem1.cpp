#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node (int data){
        this->data=data;
        this->next=NULL;
    }
};
//take input with less time complexity
Node *Take_Input_better(int n){
    Node* head = NULL;
    Node *tail=NULL;
    int i=1;
    while(i<=n){
        Node *newnode = new Node(i);
        if(head==NULL){
            head=newnode;
            tail=head;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
        i++;
    }
    return head;
}
//Finding length of linked list
int length(Node * head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    Node *head=Take_Input_better(n);
    Node *tail;
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    int size=length(head);
    tail=temp;
    tail->next=head;
    head=head->next;
    temp=temp->next;
    cout<<endl;
    while(size--){
        cout<<head->data<<' ';
        Node* delete1=head;
        temp->next=head->next;
        temp=head->next;
        head=head->next->next;
        delete(delete1);
    }
    return 0;
}