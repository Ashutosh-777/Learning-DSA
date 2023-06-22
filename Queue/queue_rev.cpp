#include <iostream>
using namespace std;
template <typename T>
class Queue{
    T *data;
    int firstindex;
    int nextindex;
    int size;
    int capacity;
    public:
    Queue(){
        data = new T[1];
        firstindex=-1;
        nextindex=0;
        size=0;
        capacity=1;
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
        }
        return INT_MIN;
    }
    void push(T element){
        if(nextindex<capacity){
            data[nextindex]=element;
            cout<<nextindex<<"hi"<<endl;
            nextindex++;
            if(firstindex==-1){
                firstindex++;
            }
        }else{
            T* newData = new T[2*capacity];
            int j = 0;
            for(int i=0;i<capacity;i++){
                newData[j]=data[i];
                j++;
            }
            delete [] data;
            data=newData;
            data[nextindex]=element;
            cout<<nextindex<<"hi2"<<endl;
            nextindex++;
            capacity *= 2;
        }
        size++;
    }
    void pop(){
        if(!isEmpty()){
            firstindex++;
            size--;
            return;
        }
        cout<<"Ah! Empty queue"<<endl;
    }
};
int main(){
    Queue<int> q;
    q.push(90);
    q.push(89);
    q.push(25);
    cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.isEmpty();
    return 0;
}