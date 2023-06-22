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
bool check(Node* head,Node* next){
    Node* temp =head;
    while(temp!=next){
        int a =temp->data;
        int b =temp->next->data;
        if(a%2==0&&b%2==1){
            return false;
        }
        temp=temp->next;
    }
    return true;
}
void evenAfterOdd(Node* head){
    if(head==NULL){
        return ;
    }
    Node* prev = head;
    Node* next = head->next;
    while(prev->next!=NULL){
        if(prev->data%2==0&&next->data%2==1){
            int a =prev->data;
            prev->data = next->data;
            next->data=a;
        }
        if(!check(head,next)){
            prev=head;
            next=prev->next;
        }
        prev=next;
        next=prev->next;
    }
}
void swap(Node* head,int i,int j){
    if(head==NULL){
        return;
    }
    Node* node1=head;
    Node* node2=head;
    while(i--&&node1!=NULL){
        //if(i>=0){
            node1=node1->next;
        //}
       // if(j>0){
           // node2=node2->next;
        //}
    }
    while(j--&&node2!=NULL){
        node2=node2->next;
    }
    if(node1==NULL||node2==NULL){
        return;
    }
    int a =node1->data;
    node1->data=node2->data;
    node2->data = a;
    return;
}
Node* evenAfterOdd_2(Node* head){
    Node* oddHead=NULL,* oddTail=NULL,* evenHead=NULL,* evenTail=NULL;
    while(head!=NULL){
        if(head->data%2==0){
            if(evenHead==NULL){
                evenHead=head;
                evenTail=evenHead;
            }else{
                evenTail->next=head;
                evenTail=head;
            }
        }else{
            if(oddHead==NULL){
                oddHead=head;
                oddTail=oddHead;
            }else{
                oddTail->next=head;
                oddTail=head;
            }
        }
        head=head->next;
    }
    if(evenTail!=NULL){
        evenTail->next=NULL;
    }
    if(oddTail!=NULL){
        oddTail->next=evenHead;
    }else{
        oddHead=evenHead;
    }
    evenTail=NULL;
    return oddHead;
}
Node* deleteEveryN(Node* head,int i,int n){
    if(i==0&&n!=0){
        return NULL;
    }
    
    if(i==0&&n==0){
        return head;
    }
    
    cout<<"ddd"<<endl;
    if(head==NULL){
        return NULL;
    }
    Node* prev = head,*curr=prev->next;
    i--;
    int a = i;
    int b = n;
    bool k = false;
    cout<<a<<endl;
    hi:
    i=a;
    n=b;
    cout<<i<<endl;
    if(k){
        i++;
    }
    k=true;
    while(i--&&prev!=NULL){
        prev=prev->next;
        curr=prev->next;
    }
    while(n--&&curr!=NULL){
        //cout<<"prev : "<<prev->data<<prev->next->data<<"curr: "<<curr->data<<endl;
        Node* temp = curr->next;
        delete(curr);
        curr = temp;
        prev->next=curr;
        //cout<<"hi"<<endl;
    }
    if(curr!=NULL){
        goto hi;
    }
    //cout<<"hi"<<endl;
    return head;
}
class Pair{
    public:
    Node* head;
    Node* tail;
};
Pair reverseFirstK(Node* head,int k){
    Node* temp = head;
    if(head==NULL||head->next==NULL||k==1||k==0){
        Pair ans ;
        ans.head=head;
        ans.tail= head->next== NULL? head:head->next;
        return ans;
    }
    Pair smallAns = reverseFirstK(temp->next,k-1);
    Node* attach = temp->next->next;
    Node* temp2 = temp->next;
    head->next=attach;
    temp2->next = head;
    smallAns.tail=head;
   // print(smallAns.head);
    return smallAns;
}
Node* reverseEveryK(Node* head,int k){
    if(k==0){
        return head;
    }
    if(head==NULL){
        return head;
    }
    int a = k ;
    Pair smallAns =  reverseFirstK(head,k);
    ///print(smallAns.head);
    smallAns.tail->next = reverseEveryK(smallAns.tail->next,k);
    return smallAns.head;
}
void BubbleSort(Node* head){
    if(head==NULL||head->next==NULL){
        return;
    }
    Node* p1 =head,*c1=p1->next,*c2;
        c2=c1->next;
    
    if(p1->data>c1->data){
        p1->next = c2;
        c1->next = p1;
    }
    
    while(c2!=NULL){
        if(c1->data>c2->data){
            
        }
    }
}
int main(){
    Node* head= Take_Input_better();
    int k;
    cin>>k;
    // Pair ans = reverseFirstK(head,k);
    // cout<<ans.tail->data<<endl;
    // print(ans.head);
    Node* finalHead = reverseEveryK(head,k);
    print(finalHead);
    return 0;
}