#include <iostream>
#include <climits>
template <typename T>
class StackUsingArrays{
    T *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArrays(){
        data =new T[1];
        nextIndex=0;
        capacity=1;
    }
    //returning the size
    int size(){
        return nextIndex;
    }
    //checking if itis empty or not
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
    void push(T value){
        if(nextIndex==capacity){
            T *newdata=new T[2*capacity];
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
    T top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
    //popping from the Stack
    T pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
};