#include <iostream>
#include <climits>
class StackUsingArrays{
    int *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArrays(){
        data =new int[1];
        nextIndex=0;
        capacity=1;
    }
    //returning the size
    int size(){
        return nextIndex;
    }
    //checking if it is empty or not
    bool isEmpty(){
        // if(nextIndex==0){
        //     return true;
        // }else{
        //     return false;
        // }
        return nextIndex==0;
    }
    //pushing new data in the stack
    // void push(int value){
    //     if(nextIndex==capacity){
    //         cout<<"Stack is already full"<<endl;
    //         return;
    //     }
    //     data[nextIndex]=value;
    //     nextIndex++;
    // }
    //better push function
    void push(int value){
        if(nextIndex==capacity){
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete [] data;
            data=newdata;
        }
        data[nextIndex]=value;
        nextIndex++;
    }
    //reading top value
    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    //popping from the Stack
    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
};