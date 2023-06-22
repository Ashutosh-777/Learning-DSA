#include <iostream>
using namespace std;
template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node (T data){
        this->data=data;
        this->next=NULL;
    }
};
template <typename T>
class Stack_using_LL{
    Node<T>* head;
    int size;
    public:
    Stack_using_LL(){
        head=NULL;
        size=0;
    }
    void push(T data){
        Node<T>*newnode =new Node<T>(data);
        newnode->next=head;
        head=newnode;
        size++;
    }
    T pop(){
        if(IsEmpty()){
            return 0;
        }else{
            size--;
            T ans =head->data;
            Node<T>* temp=head;
            head=head->next;
            delete(temp);
            return ans;
        }
    }
    bool IsEmpty(){
        // if(size==0){
        //     return true;
        // }else{
        //     return false;
        // }
        return size==0;
    }
    T top(){
        if(IsEmpty()){
            cout<<"Stack Is Empty"<<endl;
            return 0;
        }else{
            return head->data;
        }
    }
    int getSize(){
        return size;
    }
};