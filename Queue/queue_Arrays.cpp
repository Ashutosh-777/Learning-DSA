#include <iostream>
using namespace std;
template <typename T>
class QueueUsingArrays {
    T* data;
    int firstindex;
    int size;
    int nextindex;
    int capacity;
    public:
    QueueUsingArrays(T s){
         data =new T[s];
        size=0;
        firstindex=-1;
        nextindex=0;
        capacity=s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    T front(){
        if(!isEmpty()){
            return data[firstindex];
        }else{
            cout<<"queue is empty"<<endl;
            return 0;
        }
    }
    void enqueue(T element){
        if(size==capacity){
            T *newdata= new T[2*capacity];
            int j=0;
            for(int i=firstindex;i<capacity;i++){
                newdata[j]=data[i];
                j++;
            }
            for(int i=0;i<firstindex;i++){
                newdata[j]=data[i];
                j++;
            }
            firstindex=0;
            nextindex=capacity;
            capacity=2*capacity;
            delete [] data;
            data=newdata;
        }
        if(firstindex==-1){
            firstindex=0;
        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        size++;
    }
    T dequeue(){
        if(!isEmpty()){
            int ans=data[firstindex];
            firstindex=(firstindex+1)%capacity;
            size--;
            if(size==0){
                firstindex=-1;
                nextindex=0;
            }
            return ans;
        }else{
            cout<<"queue is empty"<<endl;
            return 0;
        }
    }
};