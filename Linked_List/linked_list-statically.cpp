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
void print(Node *head){
    while(head->next!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
    cout<<head->data;
}
void print_better(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}
int main(){
    // Node n1(125556);
    // cout<<n1.data<<"  "<<n1.next<<endl;
    // Node n2(2536);
    // cout<<n2.data<<"  "<<n2.next<<endl;
    // Node *head =&n1;
    // cout<<(*head).data<<"  "<<(*head).next;
    // (*head).next=&n2;
    //     cout<<(*head).data<<"  "<<(*head).next;

    Node a1(1);
    Node a2(2);
    Node a3(3);
    Node a4(4);
    Node a5(5);
    Node *head = &a1;
    Node *tail=&a5;
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    a4.next=&a5;
    print(head);
    cout<<endl;
    //here head main does not changes to NULL because main function passed value of its head to print function
    print_better(head);


    return 0;
}