#include <iostream>
#include <vector>
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
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
}
//take input
Node *Take_Input(){
    int data;
    cin>>data;
    Node* head = NULL;
    while(data!=-1){
        Node *newnode = new Node(data);
        if(head==NULL){
            head=newnode;
        }else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;
    }
    return head;
}
//take input with less time complexity
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
//Finding length recursively
int length_recursively(Node *head){
    Node *temp=head;
    if(temp==NULL){
        return 0;
    }
    int length =length_recursively(temp->next);
    return length +1;
    }
//finding value at a given index
Node* value_at_index_is(Node *head,int i){
    Node *temp=head;
    i=i-1;
    while(i--&&temp!=NULL){
        temp=temp->next;
    }
    return temp;
}
//finding value recursively
Node* value_at_index_is_recursively(Node *head,int i){
    Node *temp=head;
    if(i==1){
        return head;
    }
    Node *temp1 = value_at_index_is_recursively(temp->next,i-1); 
    return temp1;
}
//Node insertion at ith index
Node * insert(Node *head,int data,int i){
    Node *temp=head;
    Node *newnode = new Node(data);
    i--;
    if(i==-1){
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(i-- && temp!=NULL){
        temp=temp->next;
    }
    if(temp!=NULL){
    newnode->next=temp->next;
    temp->next=newnode;
    }
    return head;
}
//insertion at ith index using recursion
Node *insert_recursively(Node*head,int i,int data){
    Node *temp =head;
    if(head==NULL&&i!=0){
        cout<<"index exceeded size of linked list"<<endl;
        return head;
    }
    if(i==0){
        Node * newnode =new Node(data);
        newnode->next = temp;
        return newnode;
    }
    if(i==1){
        Node * newnode =new Node(data);
        newnode->next = temp->next;
        temp->next=newnode;
        return temp;
    }
    Node *ans = insert_recursively(temp->next,i-1,data);
    return temp;
}
//Deleting Node at index i #covered all the corner cases
Node *Delete(Node* head ,int i){
    i--;
    Node *temp =head;
    if(i==-1){
        Node *b=head;
        head=head->next;
        delete(b);
    }else{
        while(i--&&temp!=NULL){
        temp=temp->next;
      }
    if(temp!=NULL){
        Node *a=temp->next;
    temp->next=a->next;
    delete(a);
    }
    }
    
    return head;
}
//Deleting node at index i recursively
Node* Delete_recursively(Node *head,int i){
    Node *temp = head;
    if(i==0){
        head=temp->next;
        delete(temp);
        return head;
    }
    if(temp->next==NULL&&i>1){
        return temp;
    }
    if(i==1&&temp!=NULL){
        Node * del = temp->next;
        temp->next=del->next;
        delete(del);
        return temp;
    }
    Node *ans = Delete_recursively(temp->next,i-1);
    return head;
}
//finding midpoint of linked list without finding length of linked list
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
//Merging two sorted linked list(not for case when head is null program will crash)
Node *merge(Node *head1,Node *head2){
    Node *finalhead =NULL;
    Node *finaltail =NULL;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data<head2->data){
            if(finalhead==NULL){
                finalhead = head1;
                //finalhead->next = head1->next;
                finaltail = finalhead;
                head1=head1->next;
            }else{
                finaltail->next=head1;
                finaltail=head1;
                head1=head1->next;
            }
        }else{
            if(finalhead==NULL){
                finalhead = head2;
                //finalhead->next = head2->next;
                finaltail = finalhead;
                head2=head2->next;
            }else{
                finaltail->next=head2;
                finaltail=head2;
                head2=head2->next;
            }
        }
    }
    if(head1==NULL){
        while(head2!=NULL){
            if(finalhead==NULL){
                finalhead = head2;
                finalhead->next = head2->next;
                finaltail = finalhead;
                head2=head2->next;
            }else{
                finaltail->next=head2;
                finaltail=head2;
                head2=head2->next;
            }  
        }
    }else{
        while(head1!=NULL){
            if(finalhead==NULL){
                finalhead = head1;
                finalhead->next = head1->next;
                finaltail = finalhead;
                head1=head1->next;
            }else{
                finaltail->next=head1;
                finaltail=head1;
                head1=head1->next;
            } 
        }
    }
    return finalhead;
    // Node *finalhead=NULL;
    // Node *finaltail =NULL;
    // while(head1!=NULL&&head2!=NULL){
    //     if(finalhead==NULL&&finaltail==NULL){
    //         if(head1->data>head2->data){
    //             finalhead=head2;
    //             finaltail=head2;
    //             head2=head2->next;
    //         }else{
    //             finalhead=head1;
    //             finaltail=head1;
    //             head1=head1->next;
    //         }
    //     }else{
    //         if(head1->data>head2->data){
    //             finaltail->next =head2;
    //             finaltail=head2;
    //             head2=head2->next;
    //         }else{
    //             finaltail->next =head1;
    //             finaltail=head1;
    //             head1=head1->next;
    //         }
    //     }
    // }
    // if(head1==NULL){
    //     finaltail->next=head2;
    // }
    // if(head2==NULL){
    //     finaltail->next=head1;
    // }
    // return finalhead;
}
//Merge Sort
// Node *merge_sort(Node *head){
// }
//Linked List Reversal iterative
//Linkd List Reversal Recursively
Node *reverse_recursively(Node *head){
    Node *temp =head;
    if(temp->next==NULL){
        return temp;
    }
    Node *head1 = reverse_recursively(temp->next);
    Node *temp1 =head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next = head;
    head->next =  NULL;
    return head1;
}
class Pair{
    public:
    Node* head;
    Node *tail;
};
Pair reverse_recursively_better(Node *head){
    Node *temp =head;
    if(temp->next==NULL||temp==NULL){
        Pair ans ;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns = reverse_recursively_better(temp->next);
    Node *temp1 =smallAns.tail;
    temp1->next = head;
    head->next =  NULL;
    smallAns.tail=head;
    return smallAns;
}
Node * reverse_LL3(Node* head){
    Node *temp =head;
    if(temp->next==NULL){
        return temp;
    }
    Node *head1 = reverse_recursively(temp->next);
    Node *tail =head->next;
    tail->next = head;
    head->next =  NULL;
    return head1;
}
Node * reverseLL_iteratively(Node *head){
    Node *p=NULL;
    Node *c=head;
    Node *n;
    while(c){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
Node* reverseEvenPosition(Node* A) {
 if(A==NULL || A->next==NULL || A->next->next==NULL)
    return A;
   
    Node * p = A;
    Node * odd=A, * temp;
    Node * even = NULL;
   
    int count=1;
    while(odd!=NULL && odd->next!=NULL)
    {
        temp=odd->next;
        odd->next=temp->next;
        temp->next=even;
        even=temp;
        odd=odd->next;
    }
    odd=A;
   
    while(even!=NULL)
    {
        temp=even->next;
        even->next=odd->next;
        odd->next=even;
        odd=odd->next->next;
        even=temp;
    }
    return A;
}
//using O(n) space
// Node* reorderList(Node* head) {
//     int length = 0;
//     Node* temp =head;
//     while(temp!=NULL){
//         length++;
//         temp=temp->next;
//     }
//     Node* temp2 = head;
//     vector<Node*> v;
//     //cout<<"hi"<<endl;
//     for(int i=0;i<length;i++){
//         v.push_back(temp2);
//         temp2=temp2->next;
//     }
//     int n = length/2;
//     for(int i=0;i<n;i++){
//         v[i]->next = v[ length-1-i];
//         v[length-1-i]->next = v[i+1];
//     }
//     v[n]->next=NULL;
//     return head;
// }
//using constan space 
Node* reorderList(Node* A) {
    if (!A || !A->next) {
        return A;
    }
    Node *slow = A, *fast = A;
    while (fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *secondHalf = slow->next;
    Node *firstHalf = A;
    slow->next = NULL;
    Node *curr = secondHalf, *prev = NULL, *next, *temp1, *temp2;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    secondHalf = prev;
    while (secondHalf) {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        firstHalf = temp1;
        secondHalf = temp2;
    }
    return A;
}
int main(){
    Node *head =Take_Input_better();
    //print(head);
    Node *finalhead = reorderList(head);
    print(finalhead);
    // cout<<length_recursively(head)<<endl;
    // Node* x= insert_recursively(head,2,23);
    // //head->next->next->next=x;
    // print(x);
    //cout<<Midpoint(head)->data<<endl;
    //print(head);
    // cout<<endl<<length(head)<<endl;
    // cout<<value_at_index_is(head,4)->data<<endl;
    // head = insert(head,24,4);
    // print(head);
    //     cout<<endl;
    //     cout<<head->data<<endl;
    // print(Delete(head,0));
    // Node *n1=new Node(10);
    // Node *n2=new Node(20);
    // Node *n3=new Node(30);
    // Node *n4=new Node(40);
    // Node *n5=new Node(50);
    // Node *head=n1;
    // n1->next=n2;
    // n2->next=n3;
    // n3->next=n4;
    // n4->next=n5;
    // print(head);
    return 0;
}