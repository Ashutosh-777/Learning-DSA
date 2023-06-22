#include <iostream>
using namespace std;
bool isValid(int a[],int n,int k,int mid){
    int student = 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>mid){
            student++;
            sum = a[i];
        }
        if(k<student){
            return false;
        }
    }
        //cout<<"student"<<student<<"   k"<<k<<endl;
    return true;
}
int numberofPages(int a[],int n,int k ){
    if(k>n){
        return -1;
    }
    int sum = 0;
    int max =0;
    for(int i = 0;i<n;i++){
        sum+=a[i];
        if(max<a[i]){
            max= a[i];
        }
    }
    int start = max;
    //cout<<start<<sum<<endl;
    int end = sum;
    int result = -1;
    int l =0;
    while(start<=end){
        int  middle = start + (end-start)/2;
        if(isValid(a,n,k,middle)){
            //cout<<l<<"hi"<<endl;
            result = middle;
            end = middle -1;
        }else{
            start=middle+1;
            //cout<<l<<"elsehello"<<endl;
        }
        l++;
    }
    return result;
}
int main(){
    int n;
    return 0;
}