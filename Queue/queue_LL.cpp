#include <iostream>
using namespace std;
template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node(T data){
       this->data=data;
       next=NULL; 
    }
};
template <typename T>
class Queue_LL{
    Node<T> *head;
    Node<T> *tail;
    int size;
    public:
    Queue_LL(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(!isEmpty()){
            return head->data;
        }else{
            cout<<"empty queue"<<'\n';
            return 0;
        }
    }
    void enqueue(T data){
        Node<T>* newnode=new Node<T>(data);
        if(head==NULL){
            head=tail=newnode;
            size++;
        }else{
            tail->next=newnode;
            tail=newnode;
            size++;
        }
    }
    T dequeue(){
        if(!isEmpty()){
            int ans=head->data;
        Node<T>* headnext=head->next;
        delete(head);
        head=headnext;
        size--;
        return ans;
        }else{
            cout<<"Empty Queue"<<endl;
            return 0;
        }
    }
};