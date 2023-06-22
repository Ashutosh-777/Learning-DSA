#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next=NULL;
    }
};
Node *Take_Input_better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
            tail=head;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}
int index_of_Node(Node *head,int data){
    int index=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            return index;
        }else{
            index++;
        }
        temp=temp->next;
    }
    return -1;
}
int length_recursively(Node *head){
    Node *temp=head;
    if(temp==NULL){
        return 0;
    }
    int length =length_recursively(temp->next);
    return length +1;
    }
Node* append(Node*head,int n){
    if(n==0){
        return head;
    }
    int l = length_recursively(head)-n-1;
    if(l==-1){
        cout<<"Invalid data n must be less than siz eof linked list"<<endl;
        return head;
    }
    Node* temp = head;
    Node* tail = head;
    while(l--){
        temp=temp->next;
    }
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head;
    Node* finalHead = temp->next;
    temp->next=NULL;
    return finalHead;

}
void removeDuplicates(Node* head){
    Node* temp = head->next;
    Node* prev = head;
    int data = head->data;
    while(temp!=NULL){
        if(data==temp->data){
            Node* rem =temp;
            prev->next = temp->next;
            temp=temp->next;
            delete(rem);
        }else{
            data = temp->data;
            prev = temp;
            temp=temp->next;
        }
    }
}
Node* reverse_LL(Node* head){
    Node* temp =head;
    if(temp==NULL||temp->next==NULL){
        return temp;
    }
    Node* finalHead = reverse_LL(temp->next);
    Node* tail =temp->next;
    tail->next = temp;
    temp->next=NULL;
    return finalHead;
}
Node *midpoint(Node *head){
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL){    
        if(fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }else{
            break;
        }
    }    
    return slow;
}
bool palindrome(Node* head){
    Node* tail = midpoint(head);
    Node* mid =reverse_LL(tail->next);
    tail->next=NULL;
    print(mid);
    cout<<endl;
    print(head);
    // cout<<temp->data<<mid->data<<endl;
    while(head!=NULL&&mid!=NULL){
        if(head->data==mid->data){
            head=head->next;
            mid=mid->next;
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    Node* head= Take_Input_better();
    bool output = palindrome(head);
    cout<<endl;
    cout<<output<<endl;
    return 0;
}